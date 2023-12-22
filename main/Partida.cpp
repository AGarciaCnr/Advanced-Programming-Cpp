#include "Partida.hpp"

Partida::Partida(Enemigo *enemigos, int tamEnemigos, Jugador* jugador) {
	this->enemigos = enemigos;
	this->jugador = jugador;
	this->tamEnemigos = tamEnemigos;
}

Personaje Partida::Combate() {
	/*int i = 0;
	do {
		jugador->Atacar(&enemigos[i]);
		std::cout << "El enemigo " << (this->enemigos + i)->GetNombre() << " ha sido atacado por " << jugador->GetNombre() << " y ha recibido " << jugador->GetAtaque() << " puntos de daño.\n";
		std::cout << "Le quedan " << (this->enemigos + i)->GetVidaActual() << " puntos de vida.\n";
		if ((this->enemigos + i)->GetVidaActual() <= 0) {
			std::cout << "El enemigo " << (this->enemigos + i)->GetNombre() << " ha muerto.\n";
			if (i == tamEnemigos - 1) {
				std::cout << "No quedan enemigos.\n";
				break;
			}
			i++;
			std::cout << "El enemigo " << (this->enemigos + i)->GetNombre() << " ha entrado en combate.\n";
		}
		enemigos[i].Atacar(jugador);
		std::cout << "El jugador " << jugador->GetNombre() << " ha sido atacado por " << enemigos[i].GetNombre() << " y ha recibido " << (this->enemigos + i)->GetAtaque() << " puntos de daño.\n";
		std::cout << "Le quedan " << jugador->GetVidaActual() << " puntos de vida.\n";
	} while (jugador->GetVidaActual() > 0 && i <= tamEnemigos - 1);

	if (jugador->GetVidaActual() > 0) {
		return *jugador;
	}
	else {
		return enemigos[i];
	}*/
	return *jugador;
}