#include "Arma.hpp"

Arma::Arma(std::string nombre, int fuerza) : Item(nombre) {
	this->fuerza = fuerza;
}

int Arma::GetFuerza() {
	return this->fuerza;
}
 
void Arma::Usar(Personaje* atacante, Personaje* atacado) {
	int golpe = atacante->GetAtaque() + this->fuerza - atacado->GetDefensa();
	if (golpe < 0) {
		golpe = 0;
	}
	atacado->AlterarVida(-golpe);
	std::cout << atacante->GetNombre() << " ha infringido " << golpe << " de da�o a " << atacado->GetNombre() << std::endl;
}