#include "Client.h"

int main() {
	char IP[PACKET_SIZE] = { 0 }; 
	char name[PACKET_SIZE] = { 0 };

	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> name;

	std::cout << "IP�� �Է��ϼ��� : ";
	std::cin >> IP;


	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = PORT;


	while (connect(server, (SOCKADDR*)&addr, sizeof addr));
	send(server, name, sizeof name, 0);
}