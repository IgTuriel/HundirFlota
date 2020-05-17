
#ifndef SRC_USUARIO_H_
#define SRC_USUARIO_H_

class Usuario
{
private:
	char* nomUsuario;
	char* contrasenya;

public:
	Usuario();
	Usuario(char* nomUsuario, char* contrasenya);

	void setNomUsuario(char* nomUsuario);
	void setContrasenya(char* contrasenya);
	char* getNomUsuario();
	char* getContrasenya();
};

#endif /* SRC_USUARIO_H_ */
