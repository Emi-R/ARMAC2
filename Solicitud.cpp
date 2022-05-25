#include "Solicitud.h"
#include "administrador.h"
#include <iostream>
#include <cstring>

using namespace std;

Solicitud::Solicitud(int idSolicitud, int idAdmin, int idSocio, bool estado) {
	_idSolicitud = idSolicitud;
	_idAdministrador = idAdmin;
	_idSocio = idSocio;
	_FechaSolicitud;
	_ArmaRegistro;
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

void Solicitud::setArma(Arma ArmaRegistro) {
	_ArmaRegistro = ArmaRegistro;
};

void Solicitud::setFechaSolicitud(Fecha FechaSolicitud) {
	_FechaSolicitud = FechaSolicitud;
};

void Solicitud::setEstado(bool estado) {
	_estado = estado;
};


int Solicitud::getIdSolicitud() { return _idSolicitud; };

int Solicitud::getIdAdministrador() { return _idAdministrador; };

int Solicitud::getIdSocio() { return _idSocio; };

Arma Solicitud::getArma() { return _ArmaRegistro; };

Fecha Solicitud::getFechaSolicitud() { return _FechaSolicitud; };

bool Solicitud::getEstado() { return _estado; }

void Solicitud::cargarSolicitud() {

	int aux;
	bool verifica;

	do {
		cout << "Ingrese el ID del Socio: ";
		cin >> aux;
		verifica = verificarIdSocio(aux);
	} while (verifica == false);

	this->setIdSocio(aux);

	cout << "Ingrese el Arma a Registrar: ";
	_ArmaRegistro.cargarArma();

	do {
		cout << "Ingrese el Id del Administrador: ";
		cin >> aux;
		verifica = verificarIdAdmin(aux);
	} while (verifica == false);

	this->setIdAdministrador(aux);

	_FechaSolicitud;
	_estado = true;
}

void Solicitud::mostrarSolicitud() {

	cout << "Id de la Solicitud: " << this->getIdSolicitud();
	cout << endl;
	cout << "Id del Socio: " << this->getIdSocio();
	cout << endl;
	cout << "Id del Administrador: " << this->getIdAdministrador();
	cout << endl;
	//cout << "Arma Registrada: ";
	//_Arma.mostrarArma();
	cout << endl;
	cout << "Fecha en la que se Registró la Solicitud: ";
	this->_FechaSolicitud.mostrarFecha();
	cout << endl;

};


bool Solicitud::verificarIdSocio(int id) {

	int opc;

	if (id < 0) {
		cout << "El Id del Socio es inválido. Por favor ingrese un ID mayor a 0.";
		return false;
	}
	//acá es donde debería la condición que busca al Socio en el Archivo de SociosRegistrados
	else if (1 == 0) {

		cout << "El Id del Socio ingresado no es válido";
		cout << endl;
		cout << "Por favor Ingrese:" << endl;
		cout << "1. Si desea Registrar a un nuevo Socio." << endl;
		cout << "2. Si desea volver a Ingresar el Id del Socio. " << endl;
		cout << "Opción: ";

		cin >> opc;

		switch (opc) {
			//case 1: registrarSocio();
		case 2: return false;
			break;
		default: return false;
			break;
		}

	}
	else {
		return true;
	}
}

bool Solicitud::verificarIdAdmin(int id) {

	Administrador admin;
	int pos = 0;

	if (id < 0) {
		cout << "El Id del Administrador es inválido. Por favor ingrese un ID mayor a 0.";
		return false;
	}
	else {
		while (admin.leerDeDisco(pos++)) {
			if (admin.getIdAdmin() == id)
			{
				return true;
			}
		}
		cout << "El Id del Administrador es inválido. Por favor ingrese un ID correcto.";
		return false;
	}
}