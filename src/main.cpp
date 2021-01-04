#include "server_ws_impl.hpp"

void elabora()
{

}

int main()
{
    webpp::ws_server wsServer;
    wsServer.config.address = "127.0.0.1";
    wsServer.config.port = 8888;
    wsServer.config.thread_pool_size = 4;
    wsServer.start();

    return 0;
}