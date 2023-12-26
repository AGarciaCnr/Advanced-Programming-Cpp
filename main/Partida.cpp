#include "Partida.hpp"

Partida::Partida(Jugador* jugador, Arma* armaJugador, Enemigo** enemigos, int tamEnemigos, Item** items, int tamItems) {
	this->jugador = jugador;
	this->armaJugador = armaJugador;
	this->enemigos = enemigos;
	this->tamEnemigos = tamEnemigos;
	this->items = items;
	this->tamItems = tamItems;
}

Personaje Partida::Combate() {
    int i = 0;
    asignarItemAJugador(armaJugador);
    asignarItemsAEnemigos();

    do {
        std::cout << "\n\n>>> COMIENZO DEL COMBATE ENTRE: " << jugador->GetNombre() << " y " << enemigos[i]->GetNombre() << " <<<" << std::endl;
        int turno = 0;

        while (true) {
            turno++;
            std::cout << "\nTurno " << turno << ":" << std::endl;

            std::cout << "\n" << jugador->GetNombre() << " con " << jugador->GetVidaActual() << " PS       VS       " << enemigos[i]->GetNombre() << " con " << enemigos[i]->GetVidaActual() << " PS\n" << std::endl;

            if (jugador->GetVelocidad() > enemigos[i]->GetVelocidad()) {
                std::cout << jugador->GetNombre() << " es mas rapido y ataca primero \n" << std::endl;
                ataqueJugador(i);

                if (enemigos[i]->EstaVivo()) {
                    enemigos[i]->Atacar(jugador);

                    if (!jugador->EstaVivo()) {
                        std::cout << "\n" << jugador->GetNombre() << " ha muerto." << std::endl;
                        break;
                    }
                }
                else {
                    std::cout << enemigos[i]->GetNombre() << " ha muerto." << std::endl;

                    // El enemigo dropea el item que lleva equipado
                    asignarItemAJugador(enemigos[i]->GetInventario()[0]);
                    std::cout << jugador->GetNombre() << " equipa " << enemigos[i]->GetInventario()[0]->GetNombre() << ", encontrado junto a " << enemigos[i]->GetNombre() << "." << std::endl;
                    i++;
                    break;
                }
            }
            else {
                std::cout << enemigos[i]->GetNombre() << " es mas rapido y ataca primero \n" << std::endl;
                enemigos[i]->Atacar(jugador);

                if (jugador->EstaVivo()) {
                    ataqueJugador(i);

                    if (!enemigos[i]->EstaVivo()) {
                        std::cout << enemigos[i]->GetNombre() << " ha muerto." << std::endl;

                        // El enemigo dropea el item que lleva equipado
                        asignarItemAJugador(enemigos[i]->GetInventario()[0]);
                        std::cout << jugador->GetNombre() << " equipa " << enemigos[i]->GetInventario()[0]->GetNombre() << ", encontrado junto a " << enemigos[i]->GetNombre() << "." << std::endl;
                        i++;
                        break;
                    }
                }
                else {
                    std::cout << jugador->GetNombre() << " ha muerto." << std::endl;
                    break;
                }
            }
        }
    } while (jugador->EstaVivo() && i <= tamEnemigos - 1);

    if (jugador->EstaVivo()) {
        return *jugador;
    }
    else {
        return *enemigos[i];
    }
}

void Partida::asignarItemAJugador(Item* item) {
	jugador->EquiparItem(item);
	item->AgregarObserver(jugador);
}

void Partida::asignarItemsAEnemigos() {
	for (int i = 0; i < tamEnemigos; i++) {
		int indice = generarNumeroAleatorio(0, tamItems - 1);
		enemigos[i]->EquiparItem(items[indice]);
	}
}

void Partida::ataqueJugador(int i) {
	std::cout << "Turno del jugador: " << std::endl;
	for (int j = 0; j < 5; j++) {
		if (jugador->GetInventario()[j] != nullptr)
			std::cout << j + 1 << ". " << jugador->GetInventario()[j]->GetNombre() << std::endl;
		else {
			std::cout << j + 1 << ". " << "Vacio" << std::endl;
		}
	}
	
	while (true) {
		int accion;
		std::cout << "Elige un objeto del inventario: ";
		std::cin >> accion;
		if (jugador->GetInventario()[accion - 1] != nullptr) {
			jugador->UsarItem(jugador->GetInventario()[accion - 1], enemigos[i]);
            std::cout << "\n";
			break;
		}
		else {
			std::cout << "Elige una accion valida: " << std::endl;
            std::cout << "\n";
		}
	}
}

int Partida::generarNumeroAleatorio(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}