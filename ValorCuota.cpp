#include "ValorCuota.h"

void ValorCuota::setValorCouta(int valor) {
	_valorCuota = valor;
}

void ValorCuota::setFechaActual(Fecha nuevaFecha) {
	_fechaActual = nuevaFecha;
}

int ValorCuota::getvalorCuota() {
	return _valorCuota;
}

Fecha ValorCuota::getFechaActual() {
	return _fechaActual;
}

//Funciones de disco
bool ValorCuota::grabarEnDisco() {
	FILE* fReg = fopen("precioscuota.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(ValorCuota), 1, fReg);

	fclose(fReg);

	return escribio;
}

int ValorCuota::leerEnDisco(int pos) {
	FILE* fReg = fopen("precioscuotas.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(ValorCuota), SEEK_SET);

	int escribio = fread(this, sizeof(ValorCuota), 1, fReg);

	fclose(fReg);

	return escribio;
}