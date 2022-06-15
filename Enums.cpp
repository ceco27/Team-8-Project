#include "Enums.h"
#include<iostream>
void getComponentTypeText(ComponentType componentType)
{
	switch (componentType)
	{
	case MOTHERBOARD: std::cout << "Motherboard"; break;
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

ComponentType getComponentTypeFromString(const char* input)
{
	if(strcmp(input, "Motherboard"))
		return MOTHERBOARD;
	if(strcmp(input, "CPU"))
		return CPU;
	if(strcmp(input, "GPU"))
		return GPU;
	if(strcmp(input, "RAM"))
		return RAM;
}

Socket getSocketFromString(const char* input)
{
	if (strcmp(input, "AM4"))
		return AM4;
	if (strcmp(input, "AM5"))
		return AM5;
	if (strcmp(input, "LGA1151"))
		return LGA1151;
	if (strcmp(input, "LGA1200"))
		return LGA1200;
}

RamType getRamTypeFromString(const char* input)
{
	if (strcmp(input, "DDR4"))
		return DDR4;
	if (strcmp(input, "DDR5"))
		return DDR5;
}
