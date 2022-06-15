#include "Enums.h"
#include<iostream>
void getComponentTypeText(ComponentType componentType)
{
	switch (componentType)
	{
	case Motherboard: std::cout << "Motherboard"; break;
	case CPU: std::cout << "CPU"; break;
	case GPU: std::cout << "GPU"; break;
	case RAM: std::cout << "RAM"; break;
	}
}

void getSocketTypeText(Socket socket)
{
	switch (socket)
	{
	case AM4: std::cout << "AM4"; break;
	case AM5: std::cout << "AM5"; break;
	case LGA1151: std::cout << "LGA1151"; break;
	case LGA1200: std::cout << "LGA1200"; break;
	}
}

void getRamTypeText(RamType ramType)
{
	switch (ramType)
	{
	case DDR4: std::cout << "DDR4"; break;
	case DDR5: std::cout << "DDR5"; break;
	}
}
