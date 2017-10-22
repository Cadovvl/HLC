#include "EntityRequestHandlerFactory.h"
#include "EntityRequestHandler.h"

#include <Poco/Net/HTTPServerRequest.h>

#include <regex>

namespace {
    std::regex userPathRegex("/(users|locations|visits)/(\\d+)$");
}

Poco::Net::HTTPRequestHandler* EntityRequestHandlerFactory::createRequestHandler(
        const Poco::Net::HTTPServerRequest &request) {
    if (request.getMethod() == "GET") {
        {
            std::smatch sm;
            if (std::regex_search(request.getURI(), sm, userPathRegex)) {
                return new EntityRequestHandler(sm.str(1), std::atoi(sm.str(2).c_str()));
            }
        }
    }
    return nullptr;
}
