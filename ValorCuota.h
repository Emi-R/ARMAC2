#pragma once
#include "Fecha.h"

class ValorCuota
{
private:
	int _valorCuota;
	Fecha _fechaActual;

public:
	void setValorCouta(int valor);
	void setFechaActual(Fecha nuevaFecha);
	int getvalorCuota();
	Fecha getFechaActual();

	//Funciones de disco
	bool grabarEnDisco();
	int leerEnDisco(int pos);




};