#pragma once

#include "Persona.h"

class Socio :public Persona
{
protected:
	int _idsocio;
	bool _estado;
	Persona socio;

public:
	Socio();
	void setIdsocio(int idsocio);
	void setEstado(bool estado);
	int getIdsocio();
	bool getEstado();

	// METODOS DE DISCO
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
	bool modificarEnDisco(int pos);

	void cargar();
	void mostrar();
};

bool buscarSocioPorID(int id);

int checkArchivoSocios();