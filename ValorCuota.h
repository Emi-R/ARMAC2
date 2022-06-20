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

void modificar_precio_cuota();

void modificarPrecio(float nuevoPrecio);

void listarPrecios();

void listar_historial_precios_cuota();