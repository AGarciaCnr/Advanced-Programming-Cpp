#pragma once
#include "Personaje.hpp"

class Enemigo : public Personaje {
public:
	Enemigo(std::string nombre, int vM, int a, int d, int v);
};