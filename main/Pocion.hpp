#pragma once
#include "Item.hpp"
#include "Personaje.hpp"

class Pocion : public Item
{
protected:
	int curacion;
public:
	Pocion(std::string nombre, int curacion);
	int GetCuracion();
	void Usar(Personaje* curado, Personaje* p2);
};

