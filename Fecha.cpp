#include "Fecha.h"
#include <ctime>

/// Constructor
Fecha::Fecha() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	_dia = timeinfo->tm_mday;
	_mes = timeinfo->tm_mon + 1;
	_anio = timeinfo->tm_year + 1900;
}

/// Setters
void Fecha::setDia(int dia) { _dia = dia; }
void Fecha::setMes(int mes) { _mes = mes; }
void Fecha::setAnio(int anio) { _anio = anio; }

/// Getters
int  Fecha::getDia() { return _dia; }
int  Fecha::getMes() { return _mes; }
int  Fecha::getAnio() { return _anio; }

/// Desarrollo cargar
void Fecha::cargarFecha() {

	Fecha actual;
	int aux = 0;
	const int MayorEdad = actual.getAnio() - 18;

	do {
		cout << "Año: ";
		cin >> aux;

		if (aux <1900 || aux > MayorEdad) 
		{
			cout << " El año ingresado es incorrecto, intente nuevamente" << endl;
		}
	} while (aux<1900 || aux> MayorEdad);

	this->setAnio(aux);

	do {
		cout << "Mes: ";
		cin >> aux;

		if (aux <= 0 || aux > 12)
		{
			cout << " El mes ingresado es incorrecto, intente nuevamente" << endl;
		}

	} while (aux <= 0 || aux > 12);

	this->setMes(aux);

	do {
		cout << "Dia: ";
		cin >> aux;

		if (!validaDia(this->getMes(), aux, this->getAnio())) 
		{
			cout << " El dia ingresado es incorrecto, intente nuevamente" << endl;
		}
	} while (!validaDia(this->getMes(), aux, this->getAnio()));

	this->setDia(aux);

}

/// Desarrollo Mostrar

void Fecha::mostrarFecha() {
	cout << "   " << this->getDia() << "/" << this->getMes() << "/" << this->getAnio();

}

/////////////////////////////////////
// Funciones globales Fecha
/////////////////////////////////////

bool validaDia(int mes, int dia, int anio) {

	switch (mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (dia >= 1 && dia <= 31)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case 2:
		if (anio % 4 != 0 || (anio % 100 == 0 && anio % 400 != 0))
		{
			if (dia >= 1 && dia <= 28)
			{
				return true;
			}
		}
		else {

			if (dia >= 1 && dia <= 29)
			{

				return true;
			}
		}
		return false;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (dia >= 1 && dia <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	default:
		return false;
		break;
	}
}