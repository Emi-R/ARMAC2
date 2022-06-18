#pragma once
#include "Fecha.h"

class PagoCuota {

private:
	int _idCuota;
	int _idSocio;
	float _importe;
	Fecha _fechaPago;

public:
	PagoCuota(int idSocio = 0, float valorCuota = 0, int idCuota = 0);

	/// Setters
	void setIdCuota(int );
	void setIdSocio(int);
	void setImporte(float);
	void setFechaPago(Fecha);

	/// Getters
	int getIdCuota();
	int getIdSocio();
	float getImporte();
	Fecha getFechaPago();

	bool grabarEnDisco();
	bool leerDeDisco(int);

};

int generarIDCuota();

int checkArchivoPagosCuota();