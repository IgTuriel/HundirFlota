
#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include "Usuario.h"

typedef struct {
	int x;
	int y;
} Coordenada;

class Jugador: public Usuario
{
private:
	char tablero [12][18];
	bool flotaColocada;

public:
	Jugador();
	Jugador(char* nomUsuario, char* contrasenya, bool flotaColocada);

	//void setNombreUsuario(char* nomUsuario);
	//void setContrasenya(char* contrasenya);
	void setCasilla(int x, int y, char dato);
	//char* getNombreUsuario() const;
	//char* getContrasenya() const;

	void colocarFlota();
	void colocarBarco1();
	void colocarBarco2();
	void colocarBarco3();
	Coordenada comprobarCoordenada();
	void generarTablero();
	void imprimirTablero() const;
};

#endif /* SRC_JUGADOR_H_ */
