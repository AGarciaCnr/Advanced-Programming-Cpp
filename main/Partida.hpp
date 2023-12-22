#pragma once
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Jugador.hpp"
#include "Arma.hpp"
#include "Hechizo.hpp"
#include "Pocion.hpp"
#include <vector>

class Partida {
private:
	Enemigo *enemigos;
	Jugador *jugador;
	int tamEnemigos;
public:
	Partida(Enemigo *enemigos, int tamEnemigos, Jugador* jugador);
	Personaje Combate();
};