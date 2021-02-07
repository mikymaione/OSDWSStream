#include "DinoServer.h"

void elaborate(DinoServer *dinoServer)
{

}

void Rendering()
{

}

void StartServer()
{
	DinoServer dinoServer(elaborate);
	dinoServer.config.address = "127.0.0.1";
	dinoServer.config.port = 8888;
	dinoServer.config.thread_pool_size = 4;
	dinoServer.start();
}

int main()
{
	Rendering();
	//StartServer();

	return 0;
}