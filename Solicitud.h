#pragma once

#include <cstring>
#include <iostream>
#include <iomanip>
#include "rlutil.h"
#include "Fecha.h"
#include "Arma.h"
#include "Socio.h"

class Solicitud
{
private:
	int _idSolicitud, _idAdministrador, _idSocio, _idArma;
	int _aprobado;
	Fecha _FechaSolicitud;
	bool _editable;
	bool _estado;


public:

	//CONSTRUCTOR
	Solicitud(int idSolicitud = 0, int idAdmin = 0, int idSocio = 0, bool estado = 0, int idArma = 0, int aprobado = 0);

	//SETTERS
	void setIdSolicitud(int idSolicitud);
	void setIdAdministrador(int idAdmin);
	void setIdSocio(int idSocio);
	void setIdArma(int idArma);
	void setFechaSolicitud(Fecha FechaSolicitud);
	void setAprobado(int a);
	void setEditable(bool e);
	void setEstado(bool estado);

	//GETTERS
	int getIdSolicitud();
	int getIdAdministrador();
	int getIdSocio();
	int getIdArma();
	Fecha getFechaSolicitud();
	int getAprobado();
	bool getEditable();
	bool getEstado();

	void cargarSolicitud();
	void mostrarSolicitud();

	bool grabarEnDisco();
	bool leerDeDisco(int pos);
	bool modificarEnDisco(int pos);

	void listarSolicitud();
};

int checkArchivoSolicitud();

void cargarNuevaSolicitud();
void modificar_solicitud();
void bajaSolicitud(Solicitud ,int );
void aprobarSolicitud(Solicitud, int);
void desaprobarSolicitud(Solicitud ,int);

int generarIdSolicitud();

void listadoSolicitudes();
void mostrarEstadoApSolicitud(int estadoAprobacion);

void listarSolicitudesPorIdDesc();
void ordernarVecSolicPorIdDesc(Solicitud* vSolicitudes, int tam);

int buscarCantidadSolicitudes();

void listarSolicitudPorFechaDesc();
void mostrarSolicitudes(Solicitud* vSolicitudes, int tam);

void ordernarVectorSolicPorFechaDesc(Solicitud *vec, int tam);

void consultaSolicitudesPorAnio();
void mostrarConsultasPorAnio(Solicitud* vecSolicitudes, int tam, int anioConsulta);

void consultaSolicitudesPorFecha();
void mostrarConsultasPorFecha(Solicitud* vecSolicitudes, int tam, Fecha fechaConsulta);

void consultaSolicitudesPorId();
int buscarSolicitudPorId(int id);
void copiarSolicitudes(Solicitud* vecSoli, int tam);
