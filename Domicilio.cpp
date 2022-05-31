#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include "Domicilio.h"
#include <string.h>

using std::setprecision;
using namespace std;

Domicilio::Domicilio() {

}

/// Setters
void Domicilio::setPais(const char* pais) {
	strcpy(_pais, pais);
}

void Domicilio::setProvincia(const char* provincia) {
	strcpy(_provincia, provincia);
}

void Domicilio::setLocalidad(const char* localidad) {
	strcpy(_localidad, localidad);
}

void Domicilio::setCalle(const char* calle) {
	strcpy(_calle, calle);
}

void Domicilio::setAltura(int altura) {
	_altura = altura;
}

void Domicilio::setDpto(const char* dpto) {
	strcpy(_dpto, dpto);
}

void Domicilio::setCP(int cp) {
	_cp = cp;
}

void Domicilio::setEstado(bool estado) {
	_estado = estado;
}

/// Getters
const char* Domicilio::getPais() {
	return _pais;
}

const char* Domicilio::getProvincia() {
	return _provincia;
}

const char* Domicilio::getLocalidad() {
	return _localidad;
}

const char* Domicilio::getCalle() {
	return _calle;
}

int Domicilio::getAltura() {
	return _altura;
}

const char* Domicilio::getDpto() {
	return _dpto;
}

int Domicilio::getCP() {
	return _cp;
}

bool Domicilio::getEstado() {
	return _estado;
}

// Cargar y Mostrar
void Domicilio::cargarDomicilio() {
	cout << "Ingrese el país: ";
	cin.getline(_pais, 49);

	cout << "Ingrese la provincia: ";
	cin.getline(_provincia, 49);

	cout << "Ingrese la localidad: ";
	cin.getline(_localidad, 49);

	cout << "Ingrese la calle: ";
	cin.getline(_calle, 49);
	do {
		cout << "Ingrese la altura: ";
		cin >> _altura;
		if (_altura <= 0) {
			cout << "La altura es incorrecta. Inserte nuevamente: ";
		}
	} while (_altura > 0);

	int longitud = 0;
	do {
		cout << "Ingrese el departamento: ";
		cin.getline(_dpto, 9);
		//longitud = strlen(_dpto);
		if (longitud < 0) {
			cout << "El depto ingresado es incorrecto. Inserte nuevamente: ";
		}
	} while (longitud < 0);

	do {
		cout << "Ingrese el Código Postal: ";
		cin >> _cp;
		if (_cp <= 0) {
			cout << "El código postal ingresado es incorrecto. Inserte nuevamente: ";
		}
	} while (_cp > 0);


	_estado = true;

}

void Domicilio::mostrarDomicilio() {
	if (_estado) {

		cout << "País: ";
		cout << _pais;

		cout << "Provincia: ";
		cout << _provincia;

		cout << "Localidad: ";
		cout << _localidad;

		cout << "Calle: ";
		cout << _calle;

		cout << "Altura: ";
		cout << _altura;

		cout << "Dpto: ";
		cout << _dpto;

		cout << "Código Postal: ";
		cout << _cp;

	}
}