#pragma once

#include <cstring>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"

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
	/// Constructor
	Administrador(int id = 0, int dni = 0, const char* apellido = "-", const char* nombre = "-", const char* contrasenia = "-", bool estado = false);

	/// Setters
	void setIdAdmin(int);
	void setDNI(int);
	void setNombre(const char*);
	void setApellido(const char*);
	void setContrasenia(const char*);
	void setEstado(bool);

	/// Getters
	int getIdAdmin();
	int getDNI();
	const char* getContrasenia();
	const char* getApellido();
	const char* getNombre();
	bool getEstado();

	void cargar();
	void mostrar();

	bool grabarEnDisco();
	bool leerDeDisco(int);
	bool modificarEnDisco(int pos);
};

/////////////////////////////////////
// Funciones globales Administrador
/////////////////////////////////////

void crear_nuevo_admin();

void modificar_admin();

int buscarAdministradorPorDni(int);

int buscarAdministradorPorID(int);

bool checkContrasenia(const char*);

int checkArchivoAdmins();

void ModificarDNIAdmin(Administrador aux, int pos);

void ModificarNombreAdmin(Administrador aux, int pos);

void ModificarApellidoAdmin(Administrador aux, int pos);

void ModificarContrasenia(Administrador aux, int pos);