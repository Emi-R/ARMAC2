#include "Arma.h"
#include <iostream>
#include <cstring>

using namespace std;

Arma::Arma(int idArma, const char* modelo, float calibre, int tipoArma, int numSerie, bool estado) {
	_idArma = idArma;
	strcpy(_modelo, modelo);
	_calibre = calibre;
	_PaisFabricacion;
	_tipoArma = tipoArma;
	_numSerie = numSerie;
	_estado = estado;
};

void Arma::setIdArma(int idArma) {
	_idArma = idArma;
};

void Arma::setModelo(const char* modelo) {
	strcpy(_modelo, modelo);
};

void Arma::setCalibre(float calibre) {
	_calibre = calibre;
};

void Arma::setPaisFabricacion(Pais _PaisFabricacion) {

};
void Arma::setTipoArma(int tipoArma) {
	_tipoArma = tipoArma;
};

void Arma::setNumSerie(int numSerie) {
	_numSerie = numSerie;
};

void Arma::setEstado(bool estado) {
	_estado = estado;
};

int Arma::getIdArma() {
	return _idArma;
};

const char* Arma::getModelo() {
	return _modelo;
};

float Arma::getCalibre() {
	return _calibre;
};

Pais Arma::getPaisFabricacion() {
	return _PaisFabricacion;
};

int Arma::getTipoArma() {
	return _tipoArma;
};

int Arma::getNumSerie() {
	return _numSerie;
};

bool Arma::getEstado() {
	return _estado;
};

void Arma::cargarArma() {

	cout << "Ingrese el Modelo del Arma: ";
	cin >> _modelo;

	cout << "Ingrese el Tipo de Arma: ";
	cin >> _tipoArma;

	cout << "Ingrese el Numero de Serie: ";
	cin >> _numSerie;

	_idArma = generarId() + 1;
	_estado = true;

};

void Arma::mostrarArma() {

	cout << "Id del Arma: " << this->getIdArma();
	cout << endl;
	cout << "Modelo del Arma: " << this->getModelo();
	cout << endl;
	cout << "Calibre del Arma: " << this->getCalibre();
	cout << endl;
	cout << "Tipo de Arma: " << this->getTipoArma();
	cout << endl;
	cout << "Numero de Serie: " << this->getNumSerie();
	cout << endl;
	cout << "Estado: " << this->getEstado();

};

int generarId() {

	Arma arma;
	int id = 0;
	int pos = 0;

	while (arma.leerDeDisco(pos++)) {
		id = arma.getIdArma();
	};

	return id;
}
