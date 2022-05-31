#pragma once
#include "Fecha.h"
#include "Arma.h"
#include "Socio.h"
#include <cstring>

class Solicitud
{
private:
	int _idSolicitud, _idAdministrador, _idSocio, _idArma;
	Fecha _FechaSolicitud;
	bool _estado;

public:

	//CONSTRUCTOR
	Solicitud(int idSolicitud = 0, int idAdmin = 0, int idSocio = 0, bool estado = 0, int idArma = 0);

	//SETTERS
	void setIdSolicitud(int idSolicitud);
	void setIdAdministrador(int idAdmin);
	void setIdSocio(int idSocio);
	void setIdArma(int idArma);
	void setFechaSolicitud(Fecha FechaSolicitud);
	void setEstado(bool estado);

	//GETTERS
	int getIdSolicitud();
	int getIdAdministrador();
	int getIdSocio();
	int getIdArma();
	Fecha getFechaSolicitud();
	bool getEstado();

	void cargarSolicitud();
	void mostrarSolicitud();

	bool grabarEnDisco();
};
