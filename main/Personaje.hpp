#pragma once
#include <iostream>
#include <vector>
#include "Observer.hpp"
#include "Item.hpp"
#include "Constants.hpp"
#define INVENTARIO_SIZE 5

class Personaje : public Observer{
protected:
	int vidaActual;
	std::string nombre;
	int stats[4];
	std::vector<Item*> inventario = std::vector<Item*>(INVENTARIO_SIZE);
	Item *usado = nullptr;
	void SetVidaInicial();
public:
	Personaje(int vM, int a, int d, int v);
	int GetVidaActual();
	bool EstaVivo();
	std::string GetNombre();
	int GetVidaMaxima();
	int GetAtaque();
	int GetDefensa();
	int GetVelocidad();
	std::vector<Item*> GetInventario();
	void AlterarVida(int v);
	void Atacar(Personaje* p);
	void AlterarVidaMaxima(int vM);
	void AlterarAtaque(int a);
	void AlterarDefensa(int d);
	void AlterarVelocidad(int v);
	void Actualizar() override;
	void EquiparItem(Item* i);
	void DesequiparItem(Item* i);
	void UsarItem(Item* i, Personaje* enemigo);
};