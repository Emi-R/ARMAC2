#include "Arma.h"
#include <iostream>
#include <cstring>

using namespace std;

Arma::Arma(int idArma, const char* modelo, float calibre, int tipoArma, int numSerie, bool estado, int _idPais) {
	_idArma = idArma;
	strcpy(_modelo, modelo);
	_calibre = calibre;
	_idPaisFabricacion = _idPais;
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

void Arma::setidPaisFabricacion(int idPaisFabricacion) {
	_idPaisFabricacion = idPaisFabricacion;
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

int Arma::getidPaisFabricacion() {
	return _idPaisFabricacion;
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


//Metodos de disco

bool Arma::grabarEnDisco() {
	FILE* fReg = fopen("armas.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Arma), 1, fReg);

	fclose(fReg);

	return escribio;
}
bool Arma::leerDeDisco(int pos) {
	FILE* fReg = fopen("armas.dat", "rb");
	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	fseek(fReg, pos * sizeof(Arma), SEEK_SET);

	int escribio = fread(this, sizeof(Arma), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Arma::modificarEnDisco(int pos) {
	FILE* armaReg = fopen("armas.dat", "rb+");

	if (armaReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	fseek(armaReg, pos * sizeof(Arma), SEEK_SET);
	int escribio = fwrite(this, sizeof(Arma), 1, armaReg);
	fclose(armaReg);

	return escribio;
}

int checkArchivoArmas() {

	FILE* solicReg = fopen("armas.dat", "rb");

	if (solicReg == NULL)
	{
		solicReg = fopen("armas.dat", "wb");

		if (solicReg == NULL)
		{
			cout << "Error al crear o leer archivo de armas." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(solicReg);
			cout << "Archivo de armas creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Archivo de armas cargado correctamente" << endl;
	}

	fclose(solicReg);
	return 1;
}

bool buscarArmaPorId(int id) {
	Arma arma;
	int pos = 0;

	while (arma.leerDeDisco(pos++))
	{
		if (arma.getIdArma() == id)
		{
			return true;
		}
	}

	return false;
}
