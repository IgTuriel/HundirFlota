
#ifndef SRC_ADMINISTRADOR_H_
#define SRC_ADMINISTRADOR_H_

#include "Usuario.h"

class Administrador: public Usuario
{
private:

public:
	Administrador();
	Administrador(char* nomUsuario, char* contrasenya);

	void borrarUsuario();
};

#endif /* SRC_ADMINISTRADOR_H_ */
