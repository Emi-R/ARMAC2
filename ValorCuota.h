#pragma once
#include "Fecha.h"
#include <iomanip>

class ValorCuota
{
private:
	int _valorCuota;
	Fecha _fechaActualizacion;

public:
	void setValorCuota(int valor);
	void setFechaActualizacion(Fecha nuevaFecha);
	int getvalorCuota();
	Fecha getFechaActualizacion();

	//Funciones de disco
	bool grabarEnDisco();
	int leerEnDisco(int pos);

	void mostrar();
	void mostrarSimplificado();

};

int cantidadRegistrosPreciosCuota();

float getUltimoPrecioCuota();

int checkArchivoPrecioCuota();

void modificarPrecioCuota(float nuevoPrecio);

void listarPrecios();