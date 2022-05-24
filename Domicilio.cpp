#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include "Domicilio.h"

using std::setprecision;
using namespace std;

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