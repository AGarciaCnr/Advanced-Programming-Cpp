#include <iostream>
#include "Partida.hpp"

int main() {
	Jugador* jugador = new Jugador("Jugador", 100, 20, 5, 20);
	Arma* armaJugador = new Arma("Espada dorada", 15);
	Enemigo* enemigos[] = {
		new Enemigo("Enemigo 1", 50, 20, 5, 10),
		new Enemigo("Enemigo 2", 50, 12, 3, 30),
		new Enemigo("Enemigo 3", 50, 13, 6, 10)
	};
	int tamEnemigos = sizeof(enemigos) / sizeof(enemigos[0]);
	Item* items[] = {
		new Arma("Espada", 10),
		new Hechizo("Mejora de armadura", new int[4]{ 20, 0, 5, -2 }),
		new Pocion("Pocion de vida", 25)
	};
	int tamItems = sizeof(items) / sizeof(items[0]);

	Partida* partida = new Partida(jugador, armaJugador, enemigos, tamEnemigos, items, tamItems);
	std::cout << "El ganador es " << partida->Combate().GetNombre() << std::endl;

	return 0;
}