#include <spdlog/spdlog.h>

#define HTTPSERVER_IMPL

#include "httpserver.h"

int main() {
  http_server_listen(http_server_init(80, [](http_request_s *const request) {
    auto response = http_response_init();
    std::string text = "asa";
    http_response_status(response, 200);
    http_response_header(response, "Content-Type", "text/plain");
    http_response_body(response, text.c_str(), size(text));
    auto x = http_request_body(request);

    spdlog::info("{}", (char *) request->data);
    http_respond(request, response);
  }));
}