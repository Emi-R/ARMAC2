
#pragma once
#include "Fecha.h"



class PagoSolicitud
{
private:
	int _idSocio;
	int _idPagoSolicitud;
	float _importe;
	Fecha _fechaPago;

public:

	PagoSolicitud(int id = 0, int idPago = 0,float importe = 0);

	//seters
	void setIdSocio(int id);
	void setIdPagosolicitud(int idPago);
	void setImporte(int importe);
	void setFechaPago(Fecha fechaPago);


	//getters
	int getIdSocio();
	int getIdPago();
	float getImporte();
	Fecha getFechaPago();


	//Funciones de disco
	bool  grabarEnDisco();
	int   leerEnDisco(int pos);
	bool  modificarEnDisco(int pos);



};