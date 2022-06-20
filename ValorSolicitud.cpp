#include "ValorSolicitud.h"
#include <iomanip>

void ValorSolicitud::setValorSolicitud(int valor) {
	_valorSolicitud = valor;
}

void  ValorSolicitud::setFechaActualizacion(Fecha nuevaFecha) {
	_fechaActualizacion = nuevaFecha;
}

int   ValorSolicitud::getValorSolicitud() {
	return _valorSolicitud;
}

Fecha ValorSolicitud::getFechaActualizacion() {
	return _fechaActualizacion;
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
void ValorSolicitud::mostrar()
{
	cout << left;
	cout << setw(10) << this->getValorSolicitud ();
	this->getFechaActualizacion().mostrarFecha();
	cout << endl;

}
void ValorSolicitud::mostrarSimplificado()
{
	Fecha fechaActualizacion = this->getFechaActualizacion();

	cout << this->getValorSolicitud();
	fechaActualizacion.mostrarFecha();
}
int cantidadRegistrosPreciosSolicitud() {
	FILE* p = fopen("preciossolicitud.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(ValorSolicitud);
	return cant_reg;
}
float getUltimoPrecioSolicitud()
{
	ValorSolicitud aux;

	int pos = cantidadRegistrosPreciosSolicitud() - 1;

	aux.leerEnDisco(pos);

	return aux.grabarEnDisco ();

}
int checkArchivoPrecioSolicitud()
{
	FILE* fReg = fopen("preciossolicitud.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("preciossolicitud.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de precio de solicitud." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			float aux;
			cout << "Ingrese precio de la solicitud: ";
			cin >> aux;

			modificarPrecioSolicitud(aux);

			cout << "Archivo de valor de solicitudes creado correctamente con precio inicial: " << aux << endl;

			fclose(fReg);
			return 0;
		}
	}
	else
	{
		cout << "Archivo de precio de cuotas cargado correctamente" << endl;
	}

	fclose(fReg);

	return 1;

}
void modificarPrecioSolicitud(float nuevoPrecio) {
	ValorSolicitud aux;
	Fecha fechaActual;

	aux.setValorSolicitud (nuevoPrecio);
	aux.setFechaActualizacion(fechaActual);

	aux.grabarEnDisco();
}
void listarPreciosSolicitud()
{
	ValorSolicitud aux;
	int pos = 0;

	cout << left;
	cout << setw(10) << "IMPORTE";
	cout << setw(10) << "FECHA ACTUALIZADA" << endl;
	cout << "-------------------------------" << endl;

	while (aux.leerEnDisco(pos++))
	{
		aux.mostrar();

	}
}