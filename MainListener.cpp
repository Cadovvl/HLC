#include "MainListener.h"
#include "src/EntityRequestHandlerFactory.h"

#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>


int MainListener::main(const std::vector<std::string>& args) {
    Poco::Net::HTTPServerParams* params = new Poco::Net::HTTPServerParams();
    params->setMaxQueued(50);
    params->setMaxThreads(4);

    Poco::Net::ServerSocket socket(8765); // argument is a port

    Poco::Net::HTTPServer server(new EntityRequestHandlerFactory(),
                                 socket,
                                 params);

    server.start();
    waitForTerminationRequest();
    server.stop();

    return 0;
}
