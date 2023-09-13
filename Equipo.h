#pragma once
#include "Pokemon.h"

class Equipo
{
private:
	int tamano;
	int cantidad;
	Pokemon** misPokemon;
	string nombreEntrenador;
public:
	Equipo(const int = 6, string = "");
	void agregarPokemon(Pokemon*);
	int cantidadDeInfectados();
	int cantidadDeDerrotados();
	Pokemon* pokemonMejorDannoFisico();
	Pokemon* pokemonPeorDefensaEspecial();
	Pokemon* mejorContraOtro(Pokemon*);
	float promedioDannoEspecial();
	string tipoMasComun();
	string toString();
	~Equipo();
};

