#pragma once
#include "Persona.h"
class Socio :public Persona
{
protected:
	int _idsocio;
	bool _estado;
public:
	Socio();
	void setIdsocio(int idsocio);
	void setEstado(bool estado);
	int getIdsocio();
	bool getEstado();

	// METODOS DE DISCO
	bool grabarendisco();
	bool leerdedisco(int pos);
	bool modificarendisco(int pos);

	void cargarsocio();
	void mostrarsocio();
};

bool buscarSocioPorID(int id);