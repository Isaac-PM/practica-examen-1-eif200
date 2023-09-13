#pragma once
#include "Movimiento.h"
#include "Tipo.h"
#include "Estadisticas.h"
#include "Accesorio.h"

#define MAX_MOVIMIENTOS 4
#define MAX_TIPOS 2

class Pokemon
{
private:
	int codigo;
	string nombre;
	float salud;
	bool infectadoPokerus;
	int cantidadMovimientos;
	Movimiento** movimientos;
	int cantidadTipos;
	Tipo** tipos;
	Estadisticas* estadisticas;
	Accesorio* accesorio;
public:
	Pokemon(int = 0, string = "", float = 0.0);
	string getNombre() const;
	int getCantidadMovimientos() const;
	Movimiento* getMovimiento(int);
	Tipo** getTipos() const;
	Estadisticas* getEstadisticas() const;
	void setEstadisticas(Estadisticas*);
	void setAccesorio(Accesorio*);
	bool estaInfectado();
	bool estaDerrotado();
	bool agregarMovimiento(Movimiento*);
	bool agregarTipo(Tipo*);
	void infectarPokerus();
	void aumentarAmistad(int);
	string parseInfectadoPokerus();
	int soyBuenoContra(Tipo*, Tipo*);
	string toString();
	~Pokemon();
};

