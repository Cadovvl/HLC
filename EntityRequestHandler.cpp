#include "EntityRequestHandler.h"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>


void EntityRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &res) {
    std::ostream& reply = res.send();
    reply << entity << ":" << id << "\n";
    res.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);

}

EntityRequestHandler::EntityRequestHandler(const std::string &entity, const int id) : entity(entity), id(id) {}

