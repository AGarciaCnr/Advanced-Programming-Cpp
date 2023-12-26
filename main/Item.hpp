#pragma once
#include <iostream>
#include <vector>
#include "Observer.hpp"
#include "Constants.hpp"

class Personaje;

class Item {
protected:
	std::string nombre;
	std::vector<Observer*> observadores;
public:
	Item(std::string nombre);
	std::string GetNombre();
	void AgregarObserver(Observer* observador);
	void NotificarObservers();
	virtual void Usar(Personaje* p1, Personaje* p2);
};