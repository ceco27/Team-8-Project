#pragma once
enum ComponentType
{
	Motherboard,
	CPU,
	GPU,
	RAM
};

enum Socket
{
	AM4,
	AM5,
	LGA1151,
	LGA1200
};

enum RamType
{
	DDR4,
	DDR5
};

void getComponentTypeText(ComponentType componentType);
void getSocketTypeText(Socket socket);
void getRamTypeText(RamType ramType);