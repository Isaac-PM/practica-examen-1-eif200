#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Accesorio
{
private:
	string nombre;
	string descripcionMejora;
	float bonusSalud;
	float bonusDannoFisico;
	float bonusDannoEspecial;
public:
	Accesorio(string = "", string = "", float = 0.0f, float = 0.0f, float = 0.0f);
	string getNombre() const;
	void setNombre(string);
	string getDescripcionMejora() const;
	void setDescripcionMejora(string);
	float getBonusSalud() const;
	void setBonusSalud(float);
	float getBonusDannoFisico() const;
	void setBonusDannoFisico(float);
	float getBonusDannoEspecial() const;
	void setBonusDannoEspecial(float);
	string toString();
	~Accesorio() = default;
};

