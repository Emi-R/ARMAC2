#pragma once
#include <iomanip>
#include "Persona.h"


class Socio :public Persona
{
protected:
	Fecha _fechaIngreso;
	int _idsocio;
	Fecha _UltimoPago;
	bool _deudor;
	bool _estado;

public:
	Socio();
	///Setters
	void setIdsocio(int idsocio);
	void setEstado(bool estado);
	void setFechaIngreso(Fecha fechaIng);
	void setDeudor(bool d);
	void setUltimoPago(Fecha pago);

	///Getters
	Fecha getFechaIngreso();
	int getIdsocio();
	bool getEstado();
	bool getDeudor();
	Fecha getUltimoPago();

	// METODOS DE DISCO
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
	bool modificarEnDisco(int pos);

	void cargar();
	void mostrar();
	void mostrarSimplificado();

	void listar();
};

/////////////////////////////////////
// Funciones globales Socio
/////////////////////////////////////

int generarIDSocio();

int buscarSocioPorID(int);

bool buscarSocioPorDNI(int dni);

int checkArchivoSocios();

void listadoGeneralSocios();

void cargar_nuevo_socio();

void ModificarDNISocio(Socio aux, int pos);

void ModificarNombreSocio(Socio aux, int pos);

void ModificarApellidoSocio(Socio aux, int pos);

void ModificarFechaNac(Socio aux, int pos);

void ModificarDomicilio(Socio aux, int pos);

void ModificarEmail(Socio aux, int pos);

void ModificarTelefono(Socio aux, int pos);

void bajaSocio();

void listarSocioAlfabeticamente();

void copiarSocios(Socio* vec, int tam);

void ordenarVector(Socio* vec, int tam);

void MostrarVector(Socio* vec, int tam);

int CantidadRegistrosSocio();
