#include "Pokemon.h"

Pokemon::Pokemon(
	int codigo,
	string nombre,
	float salud
)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->salud = salud;
	this->infectadoPokerus = false;

	this->cantidadMovimientos = 0;
	this->movimientos = new Movimiento * [MAX_MOVIMIENTOS];
	for (int i = 0; i < MAX_MOVIMIENTOS; i++)
	{
		this->movimientos[i] = nullptr;
	}

	this->cantidadTipos = 0;
	this->tipos = new Tipo * [MAX_TIPOS];
	for (int i = 0; i < MAX_TIPOS; i++)
	{
		this->tipos[i] = nullptr;
	}

	this->estadisticas = nullptr;
	this->accesorio = nullptr;
}

string Pokemon::getNombre() const
{
	return this->nombre;
}

int Pokemon::getCantidadMovimientos() const
{
	return this->cantidadMovimientos;
}

Movimiento* Pokemon::getMovimiento(int indice)
{
	if (indice >= 0 && indice < cantidadMovimientos) {
		return movimientos[indice];
	}
	return nullptr;
}

Tipo** Pokemon::getTipos() const
{
	return this->tipos;
}

Estadisticas* Pokemon::getEstadisticas() const
{
	return this->estadisticas;
}

void Pokemon::setEstadisticas(Estadisticas* estadisticas)
{
	this->estadisticas = estadisticas;
	aumentarAmistad(estadisticas->getAmistad());
}

void Pokemon::setAccesorio(Accesorio* accesorio)
{
	this->accesorio = accesorio;
	estadisticas->aumentarConAccesorio(accesorio);
}

bool Pokemon::estaInfectado()
{
	return this->infectadoPokerus;
}

bool Pokemon::estaDerrotado()
{
	return salud <= 0;
}

bool Pokemon::agregarMovimiento(Movimiento* movimiento)
{
	if (cantidadMovimientos < MAX_MOVIMIENTOS) {
		movimientos[cantidadMovimientos++] = movimiento;
		return true;
	}
	return false;
}

bool Pokemon::agregarTipo(Tipo* tipo)
{
	if (cantidadTipos < MAX_TIPOS) {
		tipos[cantidadTipos++] = tipo;
		return true;
	}
	return false;
}

void Pokemon::infectarPokerus()
{
	this->infectadoPokerus = true;
	if (estadisticas != nullptr) {
		estadisticas->aumentarEstadisticas(0.003);
	}
}

void Pokemon::aumentarAmistad(int puntos)
{
	if (estadisticas != nullptr) {
		estadisticas->setAmistad(estadisticas->getAmistad() + puntos);
		salud += puntos * 0.005;
	}
}

string Pokemon::parseInfectadoPokerus()
{
	return infectadoPokerus ? "Si" : "No";
}

int Pokemon::soyBuenoContra(Tipo* tipo1, Tipo* tipo2)
{
	string nombreMiTipo1 = "";
	if (tipos[0]) {
		nombreMiTipo1 = tipos[0]->getNombre();
	}

	string nombreMiTipo2 = "";
	if (tipos[1]) {
		nombreMiTipo2 = tipos[1]->getNombre();
	}

	string nombreTipo1 = tipo1->getNombre();
	string nombreTipo2 = tipo2->getNombre();
	int puntuacion = 0;

	if (
		nombreMiTipo1 == "Agua" &&
		(nombreTipo1 == "Fuego" || nombreTipo2 == "Fuego")
		)
	{
		puntuacion += 1;
	}
	if (
		nombreMiTipo1 == "Fuego" &&
		(nombreTipo1 == "Planta" || nombreTipo2 == "Planta")
		)
	{
		puntuacion += 1;
	}
	if (
		nombreMiTipo1 == "Planta" &&
		(nombreTipo1 == "Agua" || nombreTipo2 == "Agua")
		)
	{
		puntuacion += 1;
	}

	if (
		nombreMiTipo2 == "Volador" &&
		(nombreTipo1 == "Lucha" || nombreTipo2 == "Lucha")
		)
	{
		puntuacion += 1;
	}
	if (
		nombreMiTipo2 == "Lucha" &&
		(nombreTipo1 == "Roca" || nombreTipo2 == "Roca")
		)
	{
		puntuacion += 1;
	}
	if (
		nombreMiTipo2 == "Roca" &&
		(nombreTipo1 == "Volador" || nombreTipo2 == "Volador")
		)
	{
		puntuacion += 1;
	}

	return puntuacion;
}

string Pokemon::toString()
{
	stringstream ss;
	ss << "[POKEMON] Codigo: " << codigo
		<< " Nombre: " << nombre
		<< " Salud: " << salud
		<< " Infectado: " << parseInfectadoPokerus() << endl;
	ss << "Movimientos: " << endl;
	for (int i = 0; i < cantidadMovimientos; i++)
	{
		ss << movimientos[i]->toString() << endl;
	}
	ss << "Tipos: " << endl;
	for (int i = 0; i < cantidadTipos; i++)
	{
		ss << tipos[i]->toString() << endl;
	}
	ss << "Estadisticas: " << endl;
	if (estadisticas != nullptr) {
		ss << estadisticas->toString() << endl;
	}
	return ss.str();
}

Pokemon::~Pokemon()
{
	for (int i = 0; i < cantidadMovimientos; i++)
	{
		delete movimientos[i];
	}
	delete[] movimientos;

	for (int i = 0; i < cantidadTipos; i++)
	{
		delete tipos[i];
	}
	delete[] tipos;

	delete estadisticas;
	delete accesorio;
}
