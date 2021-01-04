#include "DinoServer.h"

void elabora()
{

}

int main()
{
    DinoServer dinoServer(elabora);
    dinoServer.config.address = "127.0.0.1";
    dinoServer.config.port = 8888;
    dinoServer.config.thread_pool_size = 4;
    dinoServer.start();

    return 0;
}