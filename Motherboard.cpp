#include "Motherboard.h"

Motherboard::Motherboard(const char* manufacturer, const char* model, const double price, Socket socket, RamType ramType) : Component(manufacturer, model, price)
{
	this->componentType = ComponentType::MOTHERBOARD;
	this->socket = socket;
	this->ramType = ramType;
}

Socket Motherboard::getSocket() const
{
	return socket;
}

RamType Motherboard::getRamType() const
{
	return ramType;
}

void Motherboard::showComponentInfo() const
{
	std::cout << "Motherboard:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Socket: ";
	getSocketTypeText(socket);
	std::cout << std::endl;
	std::cout << "Ram Type: ";
	getRamTypeText(ramType);
	std::cout << std::endl;
}

ComponentType Motherboard::getComponentType() const
{
	return componentType;
}

void Motherboard::saveToFile(std::ofstream& file) const
{
}

Component* Motherboard::clone() const
{
	return new Motherboard(*this);
}
