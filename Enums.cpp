#include "Enums.h"
#include<iostream>
char* getComponentTypeText(ComponentType componentType)
{
	char* type = new char[20];
	switch (componentType)
	{
	case MOTHERBOARD: strcpy(type, "Motherboard"); break;
	case CPU: strcpy(type, "CPU"); break;
	case GPU: strcpy(type, "GPU"); break;
	case RAM: strcpy(type, "RAM"); break;
	}

	return type;
}

char* getSocketTypeText(Socket socket)
{
	char* type = new char[10];
	switch (socket)
	{
	case AM4: strcpy(type, "AM4"); break;
	case AM5: strcpy(type, "AM5"); break;
	case LGA1151: strcpy(type, "LGA1151"); break;
	case LGA1200: strcpy(type, "LGA1200"); break;
	}

	return type;
}

char* getRamTypeText(RamType ramType)
{
	char* type = new char[5];
	switch (ramType)
	{
	case DDR4: strcpy(type, "DDR4"); break;
	case DDR5: strcpy(type, "DDR5"); break;
	}
	return type;
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
