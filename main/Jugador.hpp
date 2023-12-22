#pragma once
#include "Personaje.hpp"

class Jugador : public Personaje {
public:
	Jugador(std::string nombre, int vM, int a, int d, int v);
};