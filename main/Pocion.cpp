#include "Pocion.hpp"

Pocion::Pocion(std::string nombre, int curacion) : Item(nombre) {
	this->curacion = curacion;
}

int Pocion::GetCuracion() {
	return curacion;
}

void Pocion::Usar(Personaje* curado) {
	curado->AlterarVida(this->curacion);
	NotificarObservers();
}