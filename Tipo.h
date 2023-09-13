#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tipo
{
private:
	string nombre;
public:
	Tipo(string = "");
	string getNombre() const;
	void setNombre(string);
	string toString();
	~Tipo() = default;
};