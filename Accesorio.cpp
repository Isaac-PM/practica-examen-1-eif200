#include "Accesorio.h"

Accesorio::Accesorio(
	string nombre,
	string descripcionMejora,
	float bonusSalud,
	float bonusDannoFisico,
	float bonusDannoEspecial
)
{
	this->nombre = nombre;
	this->descripcionMejora = descripcionMejora;
	this->bonusSalud = bonusSalud;
	this->bonusDannoFisico = bonusDannoFisico;
	this->bonusDannoEspecial = bonusDannoEspecial;
}

string Accesorio::getNombre() const
{
	return this->nombre;
}

void Accesorio::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Accesorio::getDescripcionMejora() const
{
	return this->descripcionMejora;
}

void Accesorio::setDescripcionMejora(string descripcionMejora)
{
	this->descripcionMejora = descripcionMejora;
}

float Accesorio::getBonusSalud() const
{
	return this->bonusSalud;
}

void Accesorio::setBonusSalud(float bonusSalud)
{
	this->bonusSalud = bonusSalud;
}

float Accesorio::getBonusDannoFisico() const
{
	return this->bonusDannoFisico;
}

void Accesorio::setBonusDannoFisico(float bonusDannoFisico)
{
	this->bonusDannoFisico = bonusDannoFisico;
}

float Accesorio::getBonusDannoEspecial() const
{
	return this->bonusDannoEspecial;
}

void Accesorio::setBonusDannoEspecial(float bonusDannoEspecial)
{
	this->bonusDannoEspecial = bonusDannoEspecial;
}

string Accesorio::toString()
{
	stringstream ss;
	ss << "[ACCESORIO] Nombre: " << nombre
		<< " Descripcion: " << descripcionMejora
		<< " Bonus Salud: " << bonusSalud
		<< " Bonus Danno Fisico: " << bonusDannoFisico
		<< " Bonus Danno Especial: " << bonusDannoEspecial;
	return ss.str();
}
