/*
C ECHO client example using sockets
*/
#include <iostream>
#include<stdio.h> //printf
#include<string.h>    //strlen
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#include<sys/socket.h>    //socket
//#include<arpa/inet.h> //inet_addr
#include <WinSock2.h>
#include <string>
#include <windows.h> // added

using namespace std;

const int SERVER_REPLY_BUFFER_LENGTH = 2000;

int main(int argc, char *argv[])
{
	ShellExecute(NULL, "open", "C:\\Users\\adrianjohnston\\Documents\\Visual Studio 2015\\Projects\\tcpserverimplemented\\Release\\tcpserverimplemented.exe", NULL, NULL, SW_SHOWDEFAULT); //added
	WSADATA wsa;
	int sock, bytesReceived;
	struct sockaddr_in server;
	char message[1000], server_reply[SERVER_REPLY_BUFFER_LENGTH];
	string input;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	//Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == -1)
	{
		//printf("Could not create socket \n");

		wprintf(L"socket function failed with error = %d\n", WSAGetLastError());
		exit(-1);
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	//Connect to remote server
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}

	puts("Connected\n");

	//keep communicating with server
	while (1)
	{
		printf("Enter message : ");
		//scanf("%s", message);
		getline(cin, input);

		//Send some data
		if (send(sock, input.c_str(), input.length(), 0) < 0)
		{
			puts("Send failed");
			return 1;
		}

		memset(server_reply, '\0', SERVER_REPLY_BUFFER_LENGTH); 
		

		//Receive a reply from the server

		if (bytesReceived = recv(sock, server_reply, SERVER_REPLY_BUFFER_LENGTH - 1, 0) < 0)
		{
			puts("recv failed");
			break;
		}
		puts("Server reply :");
		//puts(server_reply);
		cout << input << " " << endl;
	//	if (bytesReceived == 0) //testing
	//		break;
		/*memset(server_reply, '\0', SERVER_REPLY_BUFFER_LENGTH);
		if (bytesReceived = recv(sock, server_reply, SERVER_REPLY_BUFFER_LENGTH - 1, 0) < 0)
		{
		puts("recv failed");
		break;
		}
		puts("Server reply :");
		puts(server_reply);*/
	}

	closesocket(sock);
	WSACleanup();

	return 0;
}
