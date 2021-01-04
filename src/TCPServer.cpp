#include "TCPServer.hpp"

void TCPServer::Chiudi(void)
{
    InEsecuzione = false;
}

void TCPServer::TCP_Crea(const int portno, int *IDConnessioneInAscolto)
{
    *IDConnessioneInAscolto = socket(AF_INET, SOCK_STREAM, 0);
    if (*IDConnessioneInAscolto < 0)
        throw std::invalid_argument("TCPServer: Errore apertura socket" + std::to_string(*IDConnessioneInAscolto));

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    auto bi = bind(*IDConnessioneInAscolto, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (bi < 0)
        throw std::invalid_argument("TCPServer: Errore creazione porta" + std::to_string(bi));
}

void TCPServer::TCP_Ascolta(const int IDConnessioneInAscolto, void (*f)())
{
    pid_t miopid = 0;
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    IDConnessioneInAscolto_ = IDConnessioneInAscolto;

    listen(IDConnessioneInAscolto, TCP_MAX_CLIENT);

    while (InEsecuzione)
    {
        auto IDNuovaConnessione = accept(IDConnessioneInAscolto, (struct sockaddr *) &cli_addr, &clilen);

        if (IDNuovaConnessione < 0)
            throw std::invalid_argument(
                    "TCPServer: Errore apertura socket con client " + std::to_string(IDNuovaConnessione));

        if ((miopid = fork()) == 0) //processo nasce
        {
            close(IDConnessioneInAscolto);

            f(); // gioca!

            //processo muore
        }
    }

    close(IDConnessioneInAscolto_);
    printf("\nTCPServer: Bye!\n");
}