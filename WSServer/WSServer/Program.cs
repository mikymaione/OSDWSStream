using Fleck;
using System;
using System.Collections.Generic;

namespace WSServer
{
    class Program
    {

        static void Main(string[] args)
        {
            var sockets = new List<IWebSocketConnection>();
            var server = new WebSocketServer("ws://127.0.0.1:8888/");
            server.ListenerSocket.NoDelay = true;
            server.RestartAfterListenError = true;

            server.Start(conn =>
            {
                conn.OnOpen = () =>
                {
                    Console.WriteLine("Connection open.");
                    sockets.Add(conn);
                };

                conn.OnClose = () =>
                {
                    Console.WriteLine("Connection closed.");
                    sockets.Remove(conn);
                };

                /*
                conn.OnMessage = message =>
                {
                    Console.WriteLine("Client Says: " + message);
                    sockets.ForEach(s => s.Send(" client says: " + message));
                };
                */
            });

            var img = System.IO.File.ReadAllBytes("img.jpg");

            var input = Console.ReadLine();
            while (input != "exit")
            {
                sockets.ForEach(s => s.Send(img));
                input = Console.ReadLine();
            }
        }

    }
}