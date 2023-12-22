#pragma once
#include "Item.hpp"
#include "Personaje.hpp"

class Arma : public Item {
protected:
	int fuerza;
public:
	Arma(std::string nombre, int fuerza);
	int GetFuerza();
	void Usar(Personaje* atacante, Personaje* atacado);
};