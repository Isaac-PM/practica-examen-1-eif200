#include "Equipo.h"

int main()
{

	Pokemon* pokemon1 = new Pokemon(0, "Squirtle", 100);
	pokemon1->agregarMovimiento(new Movimiento("Burbuja", 40, new Tipo("Agua")));
	pokemon1->agregarMovimiento(new Movimiento("Pistola Agua", 90, new Tipo("Agua")));
	pokemon1->agregarMovimiento(new Movimiento("Catarata", 80, new Tipo("Agua")));
	// pokemon1->agregarMovimiento(new Movimiento("Ataque Rapido", 40, new Tipo("Lucha")));
	pokemon1->agregarTipo(new Tipo("Agua"));
	pokemon1->agregarTipo(new Tipo("Agua"));

	Estadisticas* estadisticas1 = new Estadisticas(0, 55, 40, 50, 50);
	pokemon1->setEstadisticas(estadisticas1);

	Accesorio* accesorio1 = new Accesorio("Piedra Agua", "...", 4, 0, 0);
	pokemon1->setAccesorio(accesorio1);

	cout << pokemon1->toString() << endl;

	delete pokemon1;


	/*Pokemon* pokemon1 = new Pokemon(0, "Squirtle", 100);
	pokemon1->agregarMovimiento(new Movimiento("Burbuja", 40, new Tipo("Agua")));
	pokemon1->agregarMovimiento(new Movimiento("Pistola Agua", 90, new Tipo("Agua")));
	pokemon1->agregarMovimiento(new Movimiento("Catarata", 80, new Tipo("Agua")));
	pokemon1->agregarMovimiento(new Movimiento("Ataque Rapido", 40, new Tipo("Lucha")));
	pokemon1->agregarTipo(new Tipo("Agua"));
	pokemon1->agregarTipo(new Tipo("Agua"));

	Estadisticas* estadisticas1 = new Estadisticas(0, 55, 40, 50, 50);
	pokemon1->setEstadisticas(estadisticas1);

	Accesorio* accesorio1 = new Accesorio("Piedra Agua", "...", 4, 0, 0);
	pokemon1->setAccesorio(accesorio1);

	Pokemon* pokemon2 = new Pokemon(1, "Hawlucha", 145);
	pokemon2->agregarMovimiento(new Movimiento("Patada Salto Alta", 85, new Tipo("Lucha")));
	pokemon2->agregarMovimiento(new Movimiento("Vuelo", 90, new Tipo("Volador")));
	pokemon2->agregarMovimiento(new Movimiento("Ataque Rapido", 40, new Tipo("Lucha")));
	pokemon2->agregarMovimiento(new Movimiento("Tajo Aereo", 75, new Tipo("Volador")));
	pokemon2->agregarTipo(new Tipo("Lucha"));
	pokemon2->agregarTipo(new Tipo("Volador"));
	pokemon2->infectarPokerus();

	Estadisticas* estadisticas2 = new Estadisticas(0, 64, 40, 50, 50);
	pokemon2->setEstadisticas(estadisticas2);

	Accesorio* accesorio2 = new Accesorio("Lentes de Sol", "...", 0, 13, 0);
	pokemon2->setAccesorio(accesorio2);

	Equipo* equipo = new Equipo(6, "Rojo");
	equipo->agregarPokemon(pokemon1);
	equipo->agregarPokemon(pokemon2);

	cout << "\nMostrando el equipo: " << endl;
	cout << equipo->toString() << endl;

	/* ----------------------------------------------- */

	/*Pokemon* pokemon3 = new Pokemon(2, "Charizard", 345);
	pokemon3->agregarMovimiento(new Movimiento("Lanzallamas", 90, new Tipo("Fuego")));
	pokemon3->agregarMovimiento(new Movimiento("Giro Fuego", 60, new Tipo("Fuego")));
	pokemon3->agregarMovimiento(new Movimiento("Ataque Rapido", 40, new Tipo("Lucha")));
	pokemon3->agregarMovimiento(new Movimiento("Tajo Aereo", 75, new Tipo("Volador")));
	pokemon3->agregarTipo(new Tipo("Fuego"));
	pokemon3->agregarTipo(new Tipo("Volador"));

	Estadisticas* estadisticas3 = new Estadisticas(35, 78, 40, 50, 50);
	pokemon3->setEstadisticas(estadisticas3);

	Accesorio* accesorio3 = new Accesorio("Piedra Fuego", "...", 0, 0, 4);
	pokemon3->setAccesorio(accesorio3);

	cout << "\nMostrando el pokemon 3: " << endl;
	cout << pokemon3->toString() << endl;

	cout << "\nMostrando el mejor contra otro: " << endl;
	cout << equipo->mejorContraOtro(pokemon3)->toString() << endl;*/

	cout << endl;
	system("pause");
	return 0;
}