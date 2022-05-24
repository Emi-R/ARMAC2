#pragma once
#include <cstring>

class Administrador
{
private:
	int _idAdministrador;
	int _dni;
	char _apellido[30];
	char _nombre[30];
	char _contrasenia[30];
	bool _estado;
public:
	Administrador();

	//Setters
	void setIdAdmin(int);
	void setDNI(int);
	void setNombre(const char*);
	void setApellido(const char*);
	void setContraseña(const char*);
	void setEstado(bool);

	//Getters
	int getIdAdmin();
	int getDNI();
	const char * getContraseña();
	const char* getApellido();
	const char* getNombre();
	bool getEstado();

	void cargar();
	void mostrar();

	bool grabarEnDisco();
	bool leerDeDisco(int);
};

