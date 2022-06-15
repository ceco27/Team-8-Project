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

void PCStore::setMoney(double money)
{
	this->money = money;
}

bool PCStore::checkBalance(double price)
{
	return money > price;
}

void PCStore::subtractFunds(double price)
{
	money -= price;
}

void PCStore::addFunds(double price)
{
	money += price * 1.1;
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

void PCStore::sellComponent(size_t index)
{
	money += components[index]->getPrice();
	removeFromIndex(index);
	std::cout << "Component sold!" << std::endl;
}

void PCStore::removeFromIndex(size_t index)
{
	if (index >= countComponents)
	{
		std::cout << "No such index!" << std::endl;
		return;
	}

	delete[] components[index];

	for (size_t j = index; j < countComponents - 1; j++)
		components[j] = components[j + 1]->clone();

	if (index != countComponents - 1)
		delete[] components[countComponents - 1];
	countComponents--;
}

void PCStore::writeToFile() const
{
	std::ofstream file;

	file.open("components.txt");

	file << "money " << money << std::endl;

	for (size_t i = 0; i < countComponents; i++)
		components[i]->saveToFile(file);

	file << "End" << std::endl;

	file.close();
}

void PCStore::copy(const PCStore& other)
{
	components = new Component * [other.capacityComponents];

	countComponents = other.countComponents;
	capacityComponents = other.capacityComponents;

	money = other.money;

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
