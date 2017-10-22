#include "EntityRequestHandlerFactory.h"
#include "MessageGetter.h"
#include "MessageAdder.h"

#include <Poco/Net/HTTPServerRequest.h>

#include <regex>

namespace {
    std::regex userPathRegex("/message$");
}

Poco::Net::HTTPRequestHandler *EntityRequestHandlerFactory::createRequestHandler(
        const Poco::Net::HTTPServerRequest &request) {

    std::smatch sm;
    if (std::regex_match(request.getURI(), sm, userPathRegex)) {

        if (request.getMethod() == "GET") {
            return new MessageGetter();
        } else if (request.getMethod() == "POST") {
            return new MessageAdder();
        }
    }
    return nullptr;
}
