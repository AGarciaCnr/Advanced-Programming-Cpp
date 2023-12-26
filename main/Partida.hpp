#pragma once
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Jugador.hpp"
#include "Arma.hpp"
#include "Hechizo.hpp"
#include "Pocion.hpp"
#include "Item.hpp"
#include <vector>
#include <random>

class Partida {
private:
	Jugador* jugador;
	Arma* armaJugador;
	Enemigo** enemigos;
	int tamEnemigos;
	Item** items;
	int tamItems;
public:
	Partida(Jugador* jugador, Arma* armaJugador, Enemigo** enemigos, int tamEnemigos, Item** items, int tamItems);
	Personaje Combate();
	void ataqueJugador(int i);
	void asignarItemAJugador(Item* arma);
	void asignarItemsAEnemigos();
	int generarNumeroAleatorio(int min, int max);
};