#include "Gpu.h"

Gpu::Gpu(const char* manufacturer, const char* model, const double price, size_t videoMemory) : Component(manufacturer, model, price)
{
	this->componentType = ComponentType::GPU;
	this->videoMemory = videoMemory;
}

size_t Gpu::getVideoMemory() const
{
	return videoMemory;
}

void Gpu::showComponentInfo() const
{
	std::cout << "Gpu:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Video Memory: " << videoMemory << " GB" << std::endl;
}

ComponentType Gpu::getComponentType() const
{
	return componentType;
}

void Gpu::saveToFile(std::ofstream&) const
{
}

Component* Gpu::clone() const
{
	return new Gpu(*this);
}
