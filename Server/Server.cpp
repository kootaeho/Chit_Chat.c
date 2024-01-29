#include "Server.h"

void recvData(SOCKET s, int num) {
	char buffer[PACKET_SIZE] = { 0 };
	recv(s, buffer , sizeof buffer , 0);
	Client[num].second

}

void ACCEPT(SOCKET &s) {
	int cnt = 0;
	while (TRUE) {
		Client.push_back(pii(CLIENT(), ""));
		Client[cnt].first.client = accept(s, (SOCKADDR*)&Client[cnt].first.clientaddr, &Client[cnt].first.clientsize);
		Client[cnt].first.number = cnt;
		std::thread(recvData, Client[cnt].first.client, cnt).detach();

		
		cnt += 1;

	}
}

int main() {
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = PORT;

	bind(server, (SOCKADDR*)&addr, sizeof addr);
	listen(server, SOMAXCONN);

	std::thread(ACCEPT, ref(server).detach();

	while (1);
}