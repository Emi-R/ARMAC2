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
	void setEstado(bool estado);

	//GETTERS
	int getIdSolicitud();
	int getIdAdministrador();
	int getIdSocio();
	int getIdArma();
	Fecha getFechaSolicitud();
	int getAprobado();
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
int generarIdSolicitud();

void listadoSolicitudes();
void mostrarEstadoApSolicitud(int estadoAprobacion);

void listarSolicitudesPorIdDesc();
int buscarCantidadSolicitudes();

void consultaSolicitudesPorAnio();
void mostrarConsultasPorAnio(Solicitud* vecSolicitudes, int tam, int anioConsulta);

void consultaSolicitudesPorId();
int buscarSolicitudPorId(int id);
void copiarSolicitudes(Solicitud* vecSoli, int tam);