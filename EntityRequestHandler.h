#ifndef HIGHLOADCUP_USERSREQUESTHANDLER_H
#define HIGHLOADCUP_USERSREQUESTHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class EntityRequestHandler  : public Poco::Net::HTTPRequestHandler {
    const std::string entity;
    const int id;

public:

    EntityRequestHandler(const std::string &entity, const int id);

    virtual void handleRequest(Poco::Net::HTTPServerRequest &req,
                               Poco::Net::HTTPServerResponse &res);
};


#endif //HIGHLOADCUP_USERSREQUESTHANDLER_H
