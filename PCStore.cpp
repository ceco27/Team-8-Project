#include "PCStore.h"
#include <iostream>
PCStore::PCStore()
{
	components = new Component*[8];
	countComponents = 0;
	capacityComponents = 8;
	money = 0.0;
}

PCStore::PCStore(const PCStore& other)
{
	copy(other);
}

PCStore& PCStore::operator=(const PCStore& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

PCStore::~PCStore()
{
	free();
}

void PCStore::printComponentInfos() const
{
	for (size_t i = 0; i < countComponents; i++)
	{
		std::cout << "Component " << i + 1 << ": ";
		components[i]->showComponentInfo();
	}
}

void PCStore::addMotherboard(Motherboard motherboard)
{
	if (countComponents == capacityComponents)
		resize();

	components[countComponents++] = new Motherboard(motherboard);
}

void PCStore::addCpu(Cpu cpu)
{
	if (countComponents == capacityComponents)
		resize();

	components[countComponents++] = new Cpu(cpu);
}

void PCStore::addGpu(Gpu gpu)
{
	if (countComponents == capacityComponents)
		resize();

	components[countComponents++] = new Gpu(gpu);
}

void PCStore::addRam(Ram ram)
{
	if (countComponents == capacityComponents)
		resize();

	components[countComponents++] = new Ram(ram);
}

void PCStore::writeToFile() const
{
	//TODO
}

void PCStore::copy(const PCStore& other)
{
	components = new Component * [other.capacityComponents];

	countComponents = other.countComponents;
	capacityComponents = other.capacityComponents;

	for (size_t i = 0; i < countComponents; i++)
		components[i] = other.components[i]->clone();
}

void PCStore::free()
{
	for (size_t i = 0; i < countComponents; i++)
		delete components[i];

	delete[] components;
}

void PCStore::resize()
{
	capacityComponents *= 2;
	Component** newComponents = new Component * [capacityComponents];

	for (size_t i = 0; i < countComponents; i++)
		newComponents[i] = components[i]->clone();

	for (size_t i = 0; i < countComponents; i++)
		delete components[i];

	delete[] components;

	components = newComponents;
}
