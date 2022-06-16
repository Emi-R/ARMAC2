#include "Solicitud.h"
#include "administrador.h"
#include "rlutil.h"
#include <iostream>
#include "Fecha.h"
#include "Arma.h"
#include "PagoSolicitud.h"

using namespace std;
using namespace rlutil;

Solicitud::Solicitud(int idSolicitud, int idAdmin, int idSocio, bool estado, int idArma, int a) {

	_idSolicitud = idSolicitud;
	_idAdministrador = idAdmin;
	_idSocio = idSocio;
	Fecha _FechaSolicitud;
	_idArma = idArma;
	_aprobado = a;
	_estado = estado;
};

void Solicitud::setIdSolicitud(int idSolicitud) {
	_idSolicitud = idSolicitud;
};

void Solicitud::setIdAdministrador(int idAdmin) {
	_idAdministrador = idAdmin;
};

void Solicitud::setIdSocio(int idSocio) {
	_idSocio = idSocio;
};

void Solicitud::setIdArma(int idArma) {
	_idArma = idArma;
};

void Solicitud::setFechaSolicitud(Fecha FechaSolicitud) {
	_FechaSolicitud = FechaSolicitud;
}

void Solicitud::setAprobado(int a)
{
	_aprobado = a;
};

void Solicitud::setEstado(bool estado) {
	_estado = estado;
};


int Solicitud::getIdSolicitud() { return _idSolicitud; }

int Solicitud::getIdAdministrador() { return _idAdministrador; }

int Solicitud::getIdSocio() { return _idSocio; }

int Solicitud::getIdArma() { return _idArma; }

Fecha Solicitud::getFechaSolicitud() { return _FechaSolicitud; }

int Solicitud::getAprobado() { return _aprobado;}

bool Solicitud::getEstado() { return _estado; }

void Solicitud::cargarSolicitud() {

	int aux;
	bool verifica;
	Arma armaRegistro;
	Fecha fechaSolicitud;

	do {
		cout << "Ingrese el ID del Socio: ";
		cin >> aux;

		verifica = buscarSocioPorID(aux);

		if (!verifica)
		{
			cout << "El ID de socio no esta registrado o es incorrecto. Ingrese de nuevo por favor." << endl;
		}
		else
		{
			verifica = true;
		}

	} while (verifica == false);

	this->setIdSocio(aux);

	armaRegistro.cargarArma();
	armaRegistro.grabarEnDisco();

	this->setIdArma(armaRegistro.getIdArma());

	do {
		cout << "Ingrese el Id del Administrador: ";
		cin >> aux;

		verifica = buscarAdministradorPorID(aux);

		if (!verifica)
		{
			cout << "El Id del Administrador es inválido. Por favor, ingrese un ID correcto.";
		}

	} while (verifica == false);

	this->setIdAdministrador(aux);

	this->setFechaSolicitud(fechaSolicitud);

	_estado = true;
	this->setIdSolicitud(generarIdSolicitud() + 1);
}

void Solicitud::mostrarSolicitud() {

	Arma arma;
	int posArma;

	cout << endl;
	cout << "SOLICITUD N° " << this->getIdSolicitud();
	cout << endl;
	cout << "Id de Solicitud: " << this->getIdSolicitud();
	cout << endl;
	cout << "Id del Socio: " << this->getIdSocio();
	cout << endl;
	cout << "Id del Administrador: " << this->getIdAdministrador();
	cout << endl;

	//Falta mostrar el Arma de la Solicitud
	posArma = buscarArmaPorId(this->getIdArma());
	if (posArma == -1) {
		cout << "Hubo un error. No se encontró el Arma de La Solicitud: " << this->getIdSolicitud();
		cout << endl;
	}
	else {
		arma.leerDeDisco(posArma);
		arma.mostrarArma();
	}

	cout << endl;
	cout << "Fecha en la que se Registró la Solicitud: ";
	this->_FechaSolicitud.mostrarFecha();
	cout << endl;

};

bool Solicitud::grabarEnDisco() {

	FILE* solicReg = fopen("solicitudes.dat", "ab");
	if (solicReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	bool escribio = fwrite(this, sizeof(Solicitud), 1, solicReg);
	fclose(solicReg);

	return escribio;
}

bool Solicitud::leerDeDisco(int pos) {
	FILE* solicReg = fopen("solicitudes.dat", "rb");
	if (solicReg == NULL) {
		cout << "No se puede abrir el archivo.";
		return false;
	}
	fseek(solicReg, pos * sizeof(Solicitud), SEEK_SET);
	bool leyo = fread(this, sizeof(Solicitud), 1, solicReg);
	fclose(solicReg);

	return leyo;
}

bool Solicitud::modificarEnDisco(int pos) {
	FILE* solicReg = fopen("solicitudes.dat", "rb+");
	if (solicReg == NULL) {
		cout << "No se puede abrir el archivo.";
		return false;
	}
	fseek(solicReg, pos * sizeof(Solicitud), SEEK_SET);
	bool leyo = fwrite(this, sizeof(Solicitud), 1, solicReg);
	fclose(solicReg);
	return leyo;
}

int checkArchivoSolicitud() {

	FILE* solicReg = fopen("solicitudes.dat", "rb");

	if (solicReg == NULL)
	{
		solicReg = fopen("solicitudes.dat", "wb");

		if (solicReg == NULL)
		{
			cout << "Error al crear o leer archivo de Solicitudes." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(solicReg);
			cout << "Archivo de Solicitudes creado correctamente" << endl;

			return 0;
		}
	}

	fclose(solicReg);
	return 1;
}


int generarIdSolicitud() {

	Solicitud soli;
	int id = 0;
	int pos = 0;

	while (soli.leerDeDisco(pos++)) {
		id = soli.getIdSolicitud();
	};

	return id;
}

void listadoSolicitudes() {

	Solicitud solic;
	int p = 0;
	cout << endl;

	cout << "LISTADO DE SOLICITUDES" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(15) << "ID SOLICITUD";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID SOCIO";
	cout << setw(15) << "ID ARMA";
	cout << setw(15) << "FECHA CREACION" << endl;

	while (solic.leerDeDisco(p++))
	{
		solic.listarSolicitud();
	}
}


void Solicitud::listarSolicitud() {

	cout << left;
	cout << setw(15) << this->getIdSolicitud();
	cout << setw(20) << this->getIdAdministrador();
	cout << setw(15) << this->getIdSocio();
	cout << setw(15) << this->getIdArma();
	/*cout << setw(15) <<*/
	this->getFechaSolicitud().mostrarFecha();

	cout << endl;
}

void cargarNuevaSolicitud() {

	Solicitud solicitud;

	solicitud.cargarSolicitud();
	if (solicitud.grabarEnDisco()) {
		cout << "La Solicitud " << solicitud.getIdSolicitud() << " fue Ingresada correctamente.";
		cout << endl;
	}
	else {
		cout << "Hubo un Error al crear la Solicitud." << endl;
	}

	anykey();
}