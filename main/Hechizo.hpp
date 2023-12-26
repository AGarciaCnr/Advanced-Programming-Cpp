#pragma once
#include "Item.hpp"
#include "Personaje.hpp"
#include "Constants.hpp"

class Hechizo : public Item
{
protected:
	int statsAlterados[4];
public:
	Hechizo(std::string nombre, int statsAlterados[4]);
	int* GetStatsAlterados();
	void Usar(Personaje* pAlterado, Personaje* p2);
};

