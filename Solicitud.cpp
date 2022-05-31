#include "Solicitud.h"
#include "administrador.h"
#include <cstring>
#include <iostream>

using namespace std;

Solicitud::Solicitud(int idSolicitud, int idAdmin, int idSocio, bool estado, int idArma) {
	_idSolicitud = idSolicitud;
	_idAdministrador = idAdmin;
	_idSocio = idSocio;
	_FechaSolicitud;
	_idArma = idArma;
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
};

void Solicitud::setEstado(bool estado) {
	_estado = estado;
};


int Solicitud::getIdSolicitud() { return _idSolicitud; };

int Solicitud::getIdAdministrador() { return _idAdministrador; };

int Solicitud::getIdSocio() { return _idSocio; };

int Solicitud::getIdArma() { return _idArma; };

Fecha Solicitud::getFechaSolicitud() { return _FechaSolicitud; };

bool Solicitud::getEstado() { return _estado; }

void Solicitud::cargarSolicitud() {

	int aux;
	bool verifica;
	Arma armaRegistro;

	do {
		cout << "Ingrese el ID del Socio: ";
		cin >> aux;
		verifica = buscarSocioPorID(aux);

		if (!verifica)
		{
			cout << "El ID de socio no esta registrado o es incorrecto. Ingrese de nuevo por favor.";
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
		if (!verifica) {
			cout << "El Id del Administrador es inválido. Por favor, ingrese un ID correcto.";
		}
	} while (verifica == false);

	this->setIdAdministrador(aux);

	_FechaSolicitud;
	_estado = true;
}

void Solicitud::mostrarSolicitud() {

	Arma arma;

	cout << "Id de la Solicitud: " << this->getIdSolicitud();
	cout << endl;
	cout << "Id del Socio: " << this->getIdSocio();
	cout << endl;
	cout << "Id del Administrador: " << this->getIdAdministrador();
	cout << endl;
	arma.leerDeDisco(this->getIdArma());
	arma.mostrarArma();
	cout << endl;
	cout << "Fecha en la que se Registró la Solicitud: ";
	this->_FechaSolicitud.mostrarFecha();
	cout << endl;

};


bool Solicitud::grabarEnDisco() {

	FILE* soliReg = fopen("solicitudes.dat", "ab");

	if (soliReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Solicitud), 1, soliReg);

	fclose(soliReg);

	return escribio;

}