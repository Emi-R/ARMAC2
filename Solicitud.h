#pragma once
#include "Fecha.h"
#include "Arma.h"
#include <cstring>

class Solicitud
{
private:
	int _idSolicitud, _idAdministrador, _idSocio;
	Arma _ArmaRegistro;
	Fecha _FechaSolicitud;
	bool _estado;

public:


	//CONSTRUCTOR
	Solicitud(int idSolicitud = 0, int idAdmin = 0, int idSocio = 0, bool estado = 0);

	//SETTERS
	void setIdSolicitud(int idSolicitud);
	void setIdAdministrador(int idAdmin);
	void setIdSocio(int idSocio);
	void setArma(Arma ArmaRegistro);
	void setFechaSolicitud(Fecha FechaSolicitud);
	void setEstado(bool estado);

	//GETTERS
	int getIdSolicitud();
	int getIdAdministrador();
	int getIdSocio();
	Arma getArma();
	Fecha getFechaSolicitud();
	bool getEstado();

	void cargarSolicitud();
	void mostrarSolicitud();

};

	//FUNCIONES GLOBALES 
	bool verificarIdSocio(int id);
	bool verificarIdAdmin(int id);
