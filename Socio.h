#pragma once
#include <iomanip>
#include "Persona.h"


class Socio :public Persona
{
protected:
	Fecha _fechaIngreso;
	int _idsocio;
	bool _estado;

public:
	Socio();
	///Setters
	void setIdsocio(int idsocio);
	void setEstado(bool estado);
	void setFechaIngreso(Fecha fechaIng);

	///Getters
	Fecha getFechaIngreso();
	int getIdsocio();
	bool getEstado();

	// METODOS DE DISCO
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
	bool modificarEnDisco(int pos);

	void cargar();
	void mostrar();

	void listar();
};

int generarIDSocio();

bool buscarSocioPorID(int id);

bool buscarSocioPorDNI(int dni);

int checkArchivoSocios();

void listadoGeneralSocios();

void cargar_nuevo_socio();