#include "Pocion.hpp"

Pocion::Pocion(std::string nombre, int curacion) : Item(nombre) {
	this->curacion = curacion;
}

int Pocion::GetCuracion() {
	return curacion;
}

void Pocion::Usar(Personaje* curado, Personaje* p2) {
	curado->AlterarVida(this->curacion);
	std::cout << curado->GetNombre() << " se ha curado " << this->curacion << " puntos de vida." << std::endl;
	NotificarObservers();
}