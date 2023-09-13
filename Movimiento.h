#pragma once
#include "Tipo.h"

class Movimiento
{
private:
	string nombre;
	int dannoBase;
	Tipo* tipo;
public:
	Movimiento(string = "", int = 0, Tipo* = nullptr);
	string getNombre() const;
	void setNombre(string);
	int getDannoBase() const;
	void setDannoBase(int);
	Tipo* getTipo() const;
	void setTipo(Tipo*);
	string toString();
	~Movimiento();
};

