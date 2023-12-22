#include "Enemigo.hpp"

Enemigo::Enemigo(std::string nombre, int vM, int a, int d, int v) : Personaje(vM, a, d, v) {
	this->nombre = nombre;
}
