#include "Personaje.hpp"

Personaje::Personaje(int vM, int a, int d, int v) {
	stats[atrib::vidaMaxima] = vM;
	stats[atrib::ataque] = a;
	stats[atrib::defensa] = d;
	stats[atrib::velocidad] = v;
	Personaje::SetVidaInicial();
}

void Personaje::SetVidaInicial() {
	vidaActual = stats[atrib::vidaMaxima];
}

int Personaje::GetVidaActual() {
	return vidaActual;
}

std::string Personaje::GetNombre() {
	return nombre;
}

int Personaje::GetVidaMaxima() {
	return stats[atrib::vidaMaxima];
}

int Personaje::GetAtaque() {
	return stats[atrib::ataque];
}

int Personaje::GetDefensa() {
	return stats[atrib::defensa];
}

int Personaje::GetVelocidad() {
	return stats[atrib::velocidad];
}

std::vector<Item *> Personaje::GetInventario() {
	return inventario;
}

void Personaje::AlterarVida(int v) {
	vidaActual += v;
	if (vidaActual > stats[atrib::vidaMaxima]) {
		vidaActual = stats[atrib::vidaMaxima];
	}
	else if (vidaActual < 0) {
		vidaActual = 0;
	}
}

bool Personaje::EstaVivo() {
	return vidaActual > 0 ? true : false;
}

void Personaje::Atacar(Personaje* p) {
	int golpe = GetAtaque() - p->GetDefensa();
	if (golpe < 0) {
		golpe = 0;
	}
	p->AlterarVida(-golpe);
	std::cout << GetNombre() << " ha infringido " << golpe << " de daño a " << p->GetNombre() << std::endl;
}

void Personaje::AlterarVidaMaxima(int vM) {
	stats[atrib::vidaMaxima] += vM;
	if (stats[atrib::vidaMaxima] < 1) {
		stats[atrib::vidaMaxima] = 1;
	}
}

void Personaje::AlterarAtaque(int a) {
	stats[atrib::ataque] += a;
	if (stats[atrib::ataque] < 1) {
		stats[atrib::ataque] = 1;
	}
}

void Personaje::AlterarDefensa(int d) {
	stats[atrib::defensa] += d;
	if (stats[atrib::defensa] < 1) {
		stats[atrib::defensa] = 1;
	}
}

void Personaje::AlterarVelocidad(int v) {
	stats[atrib::velocidad] += v;
	if (stats[atrib::velocidad] < 1) {
		stats[atrib::velocidad] = 1;
	}
}

void Personaje::Actualizar() {
	DesequiparItem(usado);
	std::cout << "El item " << usado->GetNombre() << " se ha gastado" << std::endl;
	usado = nullptr;
}

void Personaje::EquiparItem(Item* item) {
	int i = 0;
	for (i = 0; i < inventario.size(); i++) {
		if (inventario[i] == nullptr) {
			inventario[i] = item;
			break;
		}
	}
	if (i == inventario.size()) {
		std::cout << "Inventario lleno." << std::endl;
	}
}

void Personaje::DesequiparItem(Item* i) {
	for (int j = 0; j < inventario.size(); j++) {
		if (inventario[j] == i) {
			inventario[j] = nullptr;
		}
	}
}

void Personaje::UsarItem(Item* i, Personaje* enemigo) {
	usado = i;
	std::cout << "El item " << i->GetNombre() << " ha sido usado." << std::endl;
	i->Usar(this, enemigo);
}