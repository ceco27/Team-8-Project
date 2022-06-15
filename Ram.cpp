#include "Ram.h"

Ram::Ram(const char* manufacturer, const char* model, const double price, RamType ramType, size_t memoryCapacity) : Component(manufacturer, model, price)
{
	this->componentType = ComponentType::RAM;
	this->ramType = ramType;
	this->memoryCapacity = memoryCapacity;
}

RamType Ram::getRamType()
{
	return ramType;
}

size_t Ram::getMemoryCapacity() const
{
	return memoryCapacity;
}

void Ram::showComponentInfo() const
{
	std::cout << "Cpu:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Ram Type: ";
	getRamTypeText(ramType);
	std::cout << std::endl;
	std::cout << "Memory Capacity: " << memoryCapacity << std::endl;
}

ComponentType Ram::getComponentType() const
{
	return componentType;
}

void Ram::saveToFile(std::ofstream&) const
{
}

Component* Ram::clone() const
{
	return new Ram(*this);
}