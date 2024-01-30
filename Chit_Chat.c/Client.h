#pragma once
#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define PACKET_SIZE 1024

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <thread> //thread
#include <cstdlib>