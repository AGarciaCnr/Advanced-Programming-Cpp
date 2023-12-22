#include <iostream>
#include "Partida.hpp"

int main() {
	/*Jugador *j = new Jugador("Jugador", 100, 20, 5, 20);
	Enemigo es[] = {
		Enemigo("Enemigo 1", 10, 20, 5, 10),
		Enemigo("Enemigo 2", 10, 12, 3, 10),
		Enemigo("Enemigo 3", 10, 13, 6, 10)
	};
	int tam = sizeof(es) / sizeof(es[0]);

	Partida *p = new Partida(es, tam, j);
	std::cout << "El ganador es " << p->Combate().GetNombre() << std::endl;*/
	int stats[] = { 10, 20, 5, 10 };

	Jugador *j = new Jugador("Jugador", 100, 20, 5, 20);
	Arma *a = new Arma("Espada", 10);
	Hechizo *h = new Hechizo("Bola de fuego", stats);
	h->AgregarObserver(j);
	h->Usar(j);
	a->AgregarObserver(j);
	a->Usar(j, j);
	return 0;
}