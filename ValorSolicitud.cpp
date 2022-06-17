#include "ValorSolicitud.h"

void ValorSolicitud::setValorSolicitud(int valor) {
	_valorSolicitud = valor;
}

void  ValorSolicitud::setFechaActual(Fecha nuevaFecha) {
	_fechaActual = nuevaFecha;
}

int   ValorSolicitud::getValorSolicitud() {
	return _valorSolicitud;
}

Fecha ValorSolicitud::getFechaActual() {
	return _fechaActual;
}

//Funciones de disco
bool ValorSolicitud::grabarEnDisco() {

	FILE* fReg = fopen("preciossolicitud.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(ValorSolicitud), 1, fReg);

	fclose(fReg);

	return escribio;
}

int   ValorSolicitud::leerEnDisco(int pos) {

	FILE* fReg = fopen("preciossolicitud.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(ValorSolicitud), SEEK_SET);

	int escribio = fread(this, sizeof(ValorSolicitud), 1, fReg);

	fclose(fReg);

	return escribio;
}