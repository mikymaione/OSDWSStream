using Fleck;
using System;
using System.Collections.Generic;

namespace WSServer
{
    class Program
    {

        static void Main(string[] args)
        {
            var blob = System.IO.File.ReadAllBytes("video.mp4");

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

            var input = Console.ReadLine();
            while (input != "exit")
            {
                sockets.ForEach(s => s.Send(blob));
                input = Console.ReadLine();
            }
        }

    }
}