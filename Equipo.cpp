#include "Equipo.h"

Equipo::Equipo(const int tamano, string nombreEntrenador)
{
	this->tamano = tamano;
	this->cantidad = 0;
	this->nombreEntrenador = nombreEntrenador;
	this->misPokemon = new Pokemon * [tamano];
	for (int i = 0; i < tamano; i++)
	{
		this->misPokemon[i] = nullptr;
	}
}

void Equipo::agregarPokemon(Pokemon* pokemon)
{
	if (cantidad < tamano)
	{
		misPokemon[cantidad] = pokemon;
		cantidad++;
	}
}

int Equipo::cantidadDeInfectados()
{
	int infectados = 0;
	for (int i = 0; i < cantidad; i++)
	{
		if (misPokemon[i]->estaInfectado())
		{
			infectados++;
		}
	}
	return infectados;
}

int Equipo::cantidadDeDerrotados()
{
	int derrotados = 0;
	for (int i = 0; i < cantidad; i++)
	{
		if (misPokemon[i]->estaDerrotado())
		{
			derrotados++;
		}
	}
	return derrotados;
}

Pokemon* Equipo::pokemonMejorDannoFisico()
{
	Pokemon* mejor = misPokemon[0];
	for (int i = 0; i < cantidad; i++)
	{
		if (
			misPokemon[i]->getEstadisticas()->getDannoFisico() >
			mejor->getEstadisticas()->getDannoFisico()
			)
		{
			mejor = misPokemon[i];
		}
	}
	return mejor;
}

Pokemon* Equipo::pokemonPeorDefensaEspecial()
{
	Pokemon* peor = misPokemon[0];
	for (int i = 0; i < cantidad; i++)
	{
		if (
			misPokemon[i]->getEstadisticas()->getDefensaEspecial() <
			peor->getEstadisticas()->getDefensaEspecial()
			)
		{
			peor = misPokemon[i];
		}
	}
	return peor;
}

Pokemon* Equipo::mejorContraOtro(Pokemon* pokemon)
{
	Pokemon* mejorPokemon = misPokemon[0];
	int mejorPuntuacion = 0;

	for (int i = 0; i < cantidad; i++) {
		int puntuacionActual = misPokemon[i]->soyBuenoContra(pokemon->getTipos()[0], pokemon->getTipos()[1]);
		if (puntuacionActual > mejorPuntuacion) {
			mejorPuntuacion = puntuacionActual;
			mejorPokemon = misPokemon[i];
		}
	}
	return mejorPokemon;
}

float Equipo::promedioDannoEspecial()
{
	float suma = 0;
	for (int i = 0; i < cantidad; i++)
	{
		suma += misPokemon[i]->getEstadisticas()->getDannoEspecial();
	}
	return suma / cantidad;
}

string Equipo::tipoMasComun()
{
	int agua = 0;
	int fuego = 0;
	int planta = 0;
	int volador = 0;
	int lucha = 0;
	int roca = 0;

	for (int i = 0; i < cantidad; i++)
	{
		for (int j = 0; j < misPokemon[i]->getCantidadMovimientos(); j++)
		{
			if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Agua") {
				agua++;
			}
			else if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Fuego") {
				fuego++;
			}
			else if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Planta") {
				planta++;
			}
			else if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Volador") {
				volador++;
			}
			else if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Lucha") {
				lucha++;
			}
			else if (misPokemon[i]->getMovimiento(j)->getTipo()->getNombre() == "Roca") {
				roca++;
			}
		}
	}

	stringstream ss;
	ss << "\nAgua: " << agua << endl;
	ss << "Fuego: " << fuego << endl;
	ss << "Planta: " << planta << endl;
	ss << "Volador: " << volador << endl;
	ss << "Lucha: " << lucha << endl;
	ss << "Roca: " << roca;
	return ss.str();
}

string Equipo::toString()
{
	stringstream ss;
	ss << "Entrenador: " << nombreEntrenador << endl;
	ss << "Cantidad de infectados: " << cantidadDeInfectados() << endl;
	ss << "Cantidad de derrotados: " << cantidadDeDerrotados() << endl;
	ss << "Pokemon con mejor danno fisico: " << pokemonMejorDannoFisico()->getNombre() << endl;
	ss << "Pokemon con peor defensa especial: " << pokemonPeorDefensaEspecial()->getNombre() << endl;
	ss << "Promedio de danno especial: " << promedioDannoEspecial() << endl;
	ss << "Tipo mas comun: " << tipoMasComun() << endl;
	ss << endl;
	for (int i = 0; i < cantidad; i++)
	{
		ss << misPokemon[i]->toString() << endl;
	}
	return ss.str();
}

Equipo::~Equipo()
{
	for (int i = 0; i < cantidad; i++)
	{
		delete misPokemon[i];
	}
	delete[] misPokemon;
}
