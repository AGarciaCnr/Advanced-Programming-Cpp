#include "Arma.hpp"

Arma::Arma(std::string nombre, int fuerza) : Item(nombre) {
	this->fuerza = fuerza;
}

int Arma::GetFuerza() {
	return this->fuerza;
}
 
void Arma::Usar(Personaje *atacante, Personaje *atacado) {
	/*int golpe = atacante->GetAtaque() + this->fuerza - atacado->GetDefensa();
	if (golpe < 0) {
		golpe = 0;
	}
	atacado->AlterarVida(-golpe);*/
	std::cout << "Funcion de arma: " << nombre << std::endl;
}