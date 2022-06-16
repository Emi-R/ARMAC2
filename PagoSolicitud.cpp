#include "PagoSolicitud.h"

using namespace std;

PagoSolicitud::PagoSolicitud(int id = 0, int idPago = 0, float importe = 0) {

	_idSocio = id;
	_idPagoSolicitud = idPago;
	_importe = importe;
}

void  PagoSolicitud::setIdSocio(int id) {
	_idSocio = id;
}
void  PagoSolicitud::setIdPagosolicitud(int idPago) {
	_idPagoSolicitud = idPago;
}
void  PagoSolicitud::setImporte(int importe) {
	_importe = importe;
}
void  PagoSolicitud::setFechaPago(Fecha fechaPago) {
	_fechaPago = fechaPago;
}
int   PagoSolicitud::getIdSocio() {
	return _idSocio;
}
int   PagoSolicitud::getIdPago() {
	return _idPagoSolicitud;
}
float PagoSolicitud::getImporte() {
	return _importe;
}
Fecha PagoSolicitud::getFechaPago() {
	return _fechaPago;
}


bool  PagoSolicitud::grabarEnDisco() {
	FILE* fReg = fopen("pagosolicitudes.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(PagoSolicitud), 1, fReg);

	fclose(fReg);

	return escribio;
}
int  PagoSolicitud::leerEnDisco(int pos) {
	FILE* fReg = fopen("pagosolicitudes.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(PagoSolicitud), SEEK_SET);

	int escribio = fread(this, sizeof(PagoSolicitud), 1, fReg);

	fclose(fReg);

	return escribio;
}
bool  PagoSolicitud::modificarEnDisco(int pos) {
	FILE* fReg = fopen("pagosolicitudes.dat", "rb+");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(PagoSolicitud), SEEK_SET);

	bool escribio = fwrite(this, sizeof(PagoSolicitud), 1, fReg);

	fclose(fReg);

	return escribio;
}