#include "Hechizo.hpp"

Hechizo::Hechizo(std::string nombre, int statsAlterados[4]) : Item(nombre) {
	for (int i = 0; i < 4; i++) {
		this->statsAlterados[i] = statsAlterados[i];
	}
}

int* Hechizo::GetStatsAlterados() {
	return statsAlterados;
}

void Hechizo::Usar(Personaje* pAlterado, Personaje* p2) {
	pAlterado->AlterarVidaMaxima(this->statsAlterados[atrib::vidaMaxima]);
	pAlterado->AlterarAtaque(this->statsAlterados[atrib::ataque]);
	pAlterado->AlterarDefensa(this->statsAlterados[atrib::defensa]);
	pAlterado->AlterarVelocidad(this->statsAlterados[atrib::velocidad]);
	std::cout << "El hechizo " << this->nombre << " ha modificado los stats del personaje " << pAlterado->GetNombre() << std::endl;
	NotificarObservers();
}