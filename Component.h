#pragma once

class Component {
protected:
	enum TypeOfComponent
	{
		MOTHERBOARD,
		CPU,
		GPU
	} type;
	char* manufacturer;
	char* model;
	double price;
public:

	Component();
	Component(const char*, const char*, const double);
	Component(const Component&);
	Component& operator=(const Component&);
	virtual ~Component();

	double getPrice() const;
	void setPrice(const double);

	virtual void showComponentInfo() const = 0;
	virtual Component::TypeOfComponent getType() const;

	virtual Component* clone() const = 0;

private:
	void copy(const Component&);
	void free();
};