#pragma once
#include "Component.h"
#include "Motherboard.h"
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
class PCStore
{
private:
	Component** components;
	size_t countComponents;
	size_t capacityComponents;
	double money;
public:
	PCStore();
	PCStore(const PCStore&);
	PCStore& operator=(const PCStore&);
	~PCStore();

	void printComponentInfos() const;

	void addMotherboard(Motherboard);
	void addCpu(Cpu);
	void addGpu(Gpu);
	void addRam(Ram);

	void writeToFile() const;

private:
	void copy(const PCStore&);
	void free();
	void resize();
};