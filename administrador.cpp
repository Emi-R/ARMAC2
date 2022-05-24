#include "administrador.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Administrador::setIdAdmin(int idAdmin)
{
	_idAdministrador = idAdmin;
}

void Administrador::setDNI(int dni)
{
	_dni = dni;
}

void Administrador::setNombre(const char* nom)
{
	strcpy(_nombre, nom);
}

void Administrador::setApellido(const char* ape)
{
	strcpy(_apellido, ape);
}

void Administrador::setContraseña(const char* pass)
{
	strcpy(_contrasenia, pass);
}

void Administrador::setEstado(bool estado)
{
	_estado = estado;
}

int Administrador::getIdAdmin()
{
	return _idAdministrador;
}

int Administrador::getDNI()
{
	return _dni;
}

const char* Administrador::getContraseña()
{
	return _contrasenia;
}

const char* Administrador::getApellido()
{
	return _apellido;
}

const char* Administrador::getNombre()
{
	return _nombre;
}

bool Administrador::getEstado()
{
	return false;
}

void Administrador::cargar()
{
	int aux;

	do {
		cout << "Ingrese el DNI: ";
		cin >> aux;

		
	} while ();
}

bool Administrador::grabarEnDisco()
{
	FILE* fReg = fopen("administradores.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Administrador), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Administrador::leerDeDisco(int pos)
{
	FILE* fReg = fopen("administradores.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(Administrador), SEEK_SET);

	int escribio = fread(this, sizeof(Administrador), 1, fReg);

	fclose(fReg);

	return escribio;
}