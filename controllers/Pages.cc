// controllers/Pages.cc
#include "Pages.h"

// Includes for getting and formatting time
#include <chrono>
#include <ctime>
#include <iomanip> // for std::put_time
#include <sstream> // for formatting time string


// Implementation for the showIndex method defined in Pages.h
void Pages::showIndex(const HttpRequestPtr& req,
                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    // 1. Prepare dynamic data
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    // Using stringstream for potentially better portability than put_time in some minimal environments
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    std::string time_str = ss.str();


    // 2. Create HttpViewData to pass data to the view
    HttpViewData data;
    data.insert("pageTitle", std::string("Drogon Dynamic Page")); // Key matches @{pageTitle} in CSP
    data.insert("message", std::string("Welcome to the Dynamic Site!")); // Key matches @{message} in CSP
    data.insert("currentTime", time_str);                       // Key matches @{currentTime} in CSP

    // 3. Create an HttpResponse by rendering the specified view with the data
    //    "index.csp" is the filename in the 'views' directory.
    auto resp = HttpResponse::newHttpViewResponse("index.csp", data);

    // 4. Send the response back to the client via the callback
    callback(resp);
}