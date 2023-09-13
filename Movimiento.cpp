#include "Movimiento.h"

Movimiento::Movimiento(string nombre, int dannoBase, Tipo* tipo)
{
	this->nombre = nombre;
	this->dannoBase = dannoBase;
	this->tipo = tipo;
}

string Movimiento::getNombre() const
{
	return this->nombre;
}

void Movimiento::setNombre(string nombre)
{
	this->nombre = nombre;
}

int Movimiento::getDannoBase() const
{
	return this->dannoBase;
}

void Movimiento::setDannoBase(int dannoBase)
{
	this->dannoBase = dannoBase;
}

Tipo* Movimiento::getTipo() const
{
	return this->tipo;
}

void Movimiento::setTipo(Tipo* tipo)
{
	this->tipo = tipo;
}

string Movimiento::toString()
{
	stringstream ss;
	ss << "[MOVIMIENTO] Nombre: " << nombre
		<< " Danno Base: " << dannoBase
		<< " Tipo: " << tipo->getNombre();
	return ss.str();
}

Movimiento::~Movimiento()
{
	delete tipo;
}
