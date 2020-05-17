#include <iostream>
using namespace std;

#include "Usuario.h"

Usuario::Usuario() {
	this->nomUsuario = NULL;
	this->contrasenya = NULL;
}

Usuario::Usuario(char* nomUsuario, char* contrasenya) {
	this->nomUsuario = nomUsuario;
	this->contrasenya = contrasenya;
}

char* Usuario::getNomUsuario() {
	return this->nomUsuario;
}

char* Usuario::getContrasenya() {
	return this->contrasenya;
}

void Usuario::setNomUsuario(char* nomUsuario) {
	this->nomUsuario = nomUsuario;
}

void Usuario::setContrasenya(char* contrasenya) {
	this->contrasenya = contrasenya;
}
