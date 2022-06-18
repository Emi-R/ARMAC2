#pragma once
#include "Fecha.h"

class ValorSolicitud
{
private:
	int _valorSolicitud;
	Fecha _fechaActualizacion;

public:
	void setValorSolicitud(int valor);
	void setFechaActualizacion(Fecha nuevaFecha);
	int getValorSolicitud();
	Fecha getFechaActualizacion();

	//Funciones de disco
	bool grabarEnDisco();
	int leerEnDisco(int pos);

	void mostrar();
	void mostrarSimplificado();
};

int cantidadRegistrosPreciosSolicitud();
float getUltimoPrecioSolicitud();

int checkArchivoPrecioSolicitud();

void modificarPrecioSolicitud(float nuevoPrecio);

void listarPreciosSolicitud();