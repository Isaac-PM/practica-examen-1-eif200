#include "Tipo.h"

Tipo::Tipo(string nombre)
{
	if (
		nombre != "Agua" &&
		nombre != "Fuego" &&
		nombre != "Planta" &&
		nombre != "Volador" &&
		nombre != "Lucha" &&
		nombre != "Roca"
		) {
		this->nombre = "Agua";
	}
	else {
		this->nombre = nombre;
	}
}

string Tipo::getNombre() const
{
	return this->nombre;
}

void Tipo::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Tipo::toString()
{
	stringstream ss;
	ss << "[TIPO] Nombre: " << nombre;
	return ss.str();
}
