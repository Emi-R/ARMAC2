#pragma once
#include "Fecha.h"

class ValorSolicitud
{
private:
	int _valorSolicitud;
	Fecha _fechaActual;

public:
	void setValorSolicitud(int valor);
	void setFechaActual(Fecha nuevaFecha);
	int getValorSolicitud();
	Fecha getFechaActual();

	//Funciones de disco
	bool grabarEnDisco();
	int leerEnDisco(int pos);

};