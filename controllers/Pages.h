// controllers/Pages.h
#pragma once

// Use HttpController for easier view rendering
#include <drogon/HttpController.h>

using namespace drogon;

// Inherit from HttpController, not HttpSimpleController
class Pages : public drogon::HttpController<Pages>
{
  public:
    // Use METHOD_LIST for HttpController path mapping
    METHOD_LIST_BEGIN
    // Map the root path "/" to the showIndex method for GET requests
    METHOD_ADD(Pages::showIndex, "/", Get);
    METHOD_LIST_END

    // Declare the handler method for the "/" path
    void showIndex(const HttpRequestPtr& req,
                   std::function<void (const HttpResponsePtr &)> &&callback);
};