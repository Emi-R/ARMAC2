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

int Solicitud::getAprobado() { return _aprobado; }

bool Solicitud::getEstado() { return _estado; }

void Solicitud::cargarSolicitud() {

	int aux;
	int estadoPendiente = -1;
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
	this->setAprobado(estadoPendiente);
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
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;

	while (solic.leerDeDisco(p++))
	{
		solic.listarSolicitud();
	}
}


void Solicitud::listarSolicitud() {

	if (this->getEstado()) {
		cout << left;
		cout << setw(15) << this->getIdSolicitud();
		cout << setw(20) << this->getIdAdministrador();
		cout << setw(15) << this->getIdSocio();
		cout << setw(15) << this->getIdArma();
		cout << setw(15);
		mostrarEstadoApSolicitud(this->getAprobado());
		this->getFechaSolicitud().mostrarFecha();

		cout << endl;
	}
}

void mostrarEstadoApSolicitud(int estadoAprobacion) {
	switch (estadoAprobacion)
	{
	case -1:
		cout << "PENDIENTE";
		break;
	case 0:
		cout << "DESAPROBADA";
		break;
	case 1:
		cout << "APROBADA";
		break;
	default:
		break;
	}
};

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

void listarSolicitudesPorIdDesc() {

	int cantSolicitudes = buscarCantidadSolicitudes();

	if (cantSolicitudes == 0) {
		cout << "No hay solicitudes registradas.";
		return;
	}

	Solicitud* solicitudes = new Solicitud[cantSolicitudes];

	if (solicitudes == NULL) { return; }

	Solicitud aux;

	cout << "LISTADO DE SOLICITUDES" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(15) << "ID SOLICITUD";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID SOCIO";
	cout << setw(15) << "ID ARMA";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;

	for (int i = 0; i < cantSolicitudes; i++) {
		solicitudes[i].leerDeDisco(i);
	}

	for (int i = 0; i < cantSolicitudes - 1; i++) {
		for (int j = i + 1; j < cantSolicitudes; j++) {
			if (solicitudes[i].getIdSolicitud() < solicitudes[j].getIdSolicitud()) {
				aux = solicitudes[i];
				solicitudes[i] = solicitudes[j];
				solicitudes[j] = aux;
			}
		}
	}

	for (int i = 0; i < cantSolicitudes; i++) {
		solicitudes[i].listarSolicitud();
	}

	delete solicitudes;
}

int buscarCantidadSolicitudes() {

	FILE* p = fopen("solicitudes.dat", "rb");

	if (p == NULL) {
		return 0;
	}

	fseek(p, 0, SEEK_END);

	size_t bytes = ftell(p);

	fclose(p);

	unsigned int cantidadSolic = bytes / sizeof Solicitud;

	return cantidadSolic;
}

void consultaSolicitudesPorAnio() {

	int cantidadSolicitudes = buscarCantidadSolicitudes();
	if (cantidadSolicitudes <= 0) {
		cout << "No hay Solicitudes Registradas.";
		return;
	}

	Solicitud* vecSolicitudes;

	vecSolicitudes = new Solicitud[cantidadSolicitudes];

	if (vecSolicitudes == NULL) { return; }

	for (int i = 0; i < cantidadSolicitudes; i++) {
		vecSolicitudes[i].leerDeDisco(i);
	}

	int anioConsulta;

	cout << " - Listado de Solicitudes por Año - ";
	cout << endl;
	cout << "Ingrese el Año: ";

	cin >> anioConsulta;

	mostrarConsultasPorAnio(vecSolicitudes, cantidadSolicitudes, anioConsulta);

	delete vecSolicitudes;
}

void mostrarConsultasPorAnio(Solicitud* vecSolicitudes, int tam, int anioConsulta) {

	cout << "CONSULTA DE SOLICITUDES" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(15) << "ID SOLICITUD";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID SOCIO";
	cout << setw(15) << "ID ARMA";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;

	for (int i = 0; i < tam; i++) {
		if (vecSolicitudes[i].getFechaSolicitud().getAnio() == anioConsulta) {
			vecSolicitudes[i].listarSolicitud();
		}
	}
}

void consultaSolicitudesPorId() {

	Solicitud solicitud;
	int idSolicitud;

	cout << " - Consulta de Solicitudes por Id - ";
	cout << endl;
	cout << "Ingrese el Id: ";

	cin >> idSolicitud;
	cls();

	int posReg = buscarSolicitudPorId(idSolicitud) - 1;
	if (posReg >= 0) {
		cout << "SOLICITUD #" << idSolicitud << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << left;
		cout << setw(15) << "ID SOLICITUD";
		cout << setw(20) << "ID ADMINISTRADOR";
		cout << setw(15) << "ID SOCIO";
		cout << setw(15) << "ID ARMA";
		cout << setw(15) << "ESTADO";
		cout << setw(15) << "FECHA CREACION" << endl;

		solicitud.leerDeDisco(posReg);
		solicitud.listarSolicitud();
	}
	else {
		cout << "No se encontró una Solicitud Registrada con ese Id.";
	}

}

int buscarSolicitudPorId(int id) {

	Solicitud solicitud;
	int pos = 0;

	while (solicitud.leerDeDisco(pos++)) {
		if (solicitud.getIdSolicitud() == id) {
			return pos;
		}
	}

	return -1;
}

void copiarSolicitudes(Solicitud* vecSoli, int tam) {

	for (int i = 0; i < tam; i++) { vecSoli[i].leerDeDisco(i); }
}
