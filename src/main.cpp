#include "TCPServer.hpp"

void elabora()
{

}

int main()
{
    printf("FM_Server - Maione Miky\n");

    int porta = 50000; //default

    if (porta >= 49152 && porta <= 65535)
    {
        int IDConnessioneInAscolto = -1;
        printf("Creazione server su porta %i\n", porta);

        TCPServer tcpServer;
        tcpServer.TCP_Crea(porta, &IDConnessioneInAscolto);

        if (IDConnessioneInAscolto >= 0)
        {
            printf("Server connesso! ID: %i\n", IDConnessioneInAscolto);
            printf("Server in ascolto su porta %i\n", porta);

            tcpServer.TCP_Ascolta(IDConnessioneInAscolto, elabora);
        }
    }

    return 0;
}