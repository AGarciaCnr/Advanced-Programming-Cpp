#include "Item.hpp"

Item::Item(std::string nombre) {
	this->nombre = nombre;
}

std::string Item::GetNombre() {
	return nombre;
}

void Item::AgregarObserver(Observer* observador) {
	observadores.push_back(observador);
}

void Item::NotificarObservers() {
	for (int i = 0; i < observadores.size(); i++) {
		observadores[i]->Actualizar();
	}
}