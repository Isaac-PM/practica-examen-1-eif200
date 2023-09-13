#include "Estadisticas.h"

Estadisticas::Estadisticas(
	float amistad,
	float dannoFisico,
	float dannoEspecial,
	float defensaFisica,
	float defensaEspecial
)
{
	this->amistad = amistad;
	this->dannoFisico = dannoFisico;
	this->dannoEspecial = dannoEspecial;
	this->defensaFisica = defensaFisica;
	this->defensaEspecial = defensaEspecial;
}

float Estadisticas::getAmistad() const
{
	return this->amistad;
}

void Estadisticas::setAmistad(float amistad)
{
	this->amistad = amistad;
}

float Estadisticas::getDannoFisico() const
{
	return this->dannoFisico;
}

void Estadisticas::setDannoFisico(float dannoFisico)
{
	this->dannoFisico = dannoFisico;
}

float Estadisticas::getDannoEspecial() const
{
	return this->dannoEspecial;
}

void Estadisticas::setDannoEspecial(float dannoEspecial)
{
	this->dannoEspecial = dannoEspecial;
}

float Estadisticas::getDefensaFisica() const
{
	return this->defensaFisica;
}

void Estadisticas::setDefensaFisica(float defensaFisica)
{
	this->defensaFisica = defensaFisica;
}

float Estadisticas::getDefensaEspecial() const
{
	return this->defensaEspecial;
}

void Estadisticas::setDefensaEspecial(float defensaEspecial)
{
	this->defensaEspecial = defensaEspecial;
}

void Estadisticas::aumentarEstadisticas(float porcentaje)
{
	dannoFisico = dannoFisico + (dannoFisico * porcentaje);
	dannoEspecial = dannoEspecial + (dannoEspecial * porcentaje);
	defensaFisica = defensaFisica + (defensaFisica * porcentaje);
	defensaEspecial = defensaEspecial + (defensaEspecial * porcentaje);
}

void Estadisticas::aumentarConAccesorio(Accesorio* accesorio)
{
	dannoFisico = dannoFisico + (dannoFisico * (accesorio->getBonusDannoFisico() / 100));
	dannoEspecial = dannoEspecial + (dannoEspecial * (accesorio->getBonusDannoEspecial() / 100));
}

string Estadisticas::toString()
{
	stringstream ss;
	ss << "[ESTADISTICAS] Amistad: " << amistad
		<< " Danno Fisico: " << dannoFisico
		<< " Danno Especial: " << dannoEspecial
		<< " Defensa Fisica: " << defensaFisica
		<< " Defensa Especial: " << defensaEspecial;
	return ss.str();
}
