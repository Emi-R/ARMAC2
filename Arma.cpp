#include "Arma.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace rlutil;


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

	int aux;
	bool flag = false;

	cout << "Ingrese el Modelo del Arma: ";
	cin.ignore();
	cin.getline(_modelo, 29);

	cout << "Ingrese el Calibre del Arma: ";
	cin >> _calibre;

	do {
		cout << "Ingrese el Pais de Fabricacion: ";
		cin >> aux;

		if (aux < 0)
		{
			cout << "ID de pais incorrecto." << endl;
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setidPaisFabricacion(aux);

	do {
		cout << "Ingrese el tipo de arma: ";
		cin >> aux;

		if (aux < 0)
		{
			cout << "Tipo de arma inválido." << endl;
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setTipoArma(aux);

	do {
		cout << "Ingrese número de serie: ";
		cin >> aux;

		if (aux < 0)
		{
			cout << "Número de serie inválido." << endl;
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setNumSerie(aux);

	this->setIdArma(generarIdArma() + 1);

	_estado = true;

	cout << endl << "-- Arma agregada con exito. --" << endl << endl;

	this->mostrarArma();

};

void Arma::mostrarArma() {

	cout << "Id del Arma: " << this->getIdArma();
	cout << endl;
	cout << "Modelo del Arma: " << this->getModelo();
	cout << endl;
	cout << "Calibre del Arma: " << this->getCalibre();
	cout << endl;
	cout << "Pais de Fabricacion: " << this->getidPaisFabricacion();
	cout << endl;
	cout << "Tipo de Arma: " << this->getTipoArma();
	cout << endl;
	cout << "Numero de Serie: " << this->getNumSerie();
	cout << endl;

};

void Arma::listar()
{
	cout << left;
	cout << setw(5) << this->getIdArma();
	cout << setw(18) << this->getModelo();
	cout << setw(10) << this->getCalibre();
	cout << setw(15) << this->getidPaisFabricacion();
	cout << setw(15) << this->getTipoArma();
	cout << setw(15) << this->getNumSerie();
	cout << endl;

}

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

/////////////////////////////////////
// Funciones globales Armas
/////////////////////////////////////

int generarIdArma() {

	Arma arma;
	int id = 0;
	int pos = 0;

	while (arma.leerDeDisco(pos++)) {
		id = arma.getIdArma();
	};

	return id;
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

//Funcion que busca el Arma por su ID y retorna su posición en el Archivo, si no encuentra el Arma con ese ID retorna -1 
int buscarArmaPorId(int id) {
	Arma arma;
	int pos = 0;
	while (arma.leerDeDisco(pos))
	{
		if (arma.getIdArma() == id)
		{
			return pos;
		}
		pos++;
	}

	return -1;

}

void crear_nueva_arma()
{
	Arma arma;

	arma.cargarArma();
	arma.grabarEnDisco();

}

void listadoGeneralArmas()
{
	Arma arma;
	int pos = 0;

	cout << left;
	cout << setw(5) << "ID";
	cout << setw(18) << "MODELO";
	cout << setw(10) << "CALIBRE";
	cout << setw(15) << "ID PAIS FABR.";
	cout << setw(15) << "TIPO DE ARMA";
	cout << setw(15) << "NÚMERO DE SERIE" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	while (arma.leerDeDisco(pos++))
	{
		arma.listar();
	}

	anykey();
}