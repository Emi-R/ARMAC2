#include "Solicitud.h"
#include "administrador.h"
#include "Fecha.h"
#include "Arma.h"

using namespace std;

Solicitud::Solicitud(int idSolicitud, int idAdmin, int idSocio, bool estado, int idArma) {
	_idSolicitud = idSolicitud;
	_idAdministrador = idAdmin;
	_idSocio = idSocio;
	Fecha _FechaSolicitud;
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
}

void Solicitud::mostrarSolicitud() {

	Arma arma;
	cout << endl;
	cout << "Id de la Solicitud: " << this->getIdSolicitud();
	cout << endl;
	cout << "Id del Socio: " << this->getIdSocio();
	cout << endl;
	cout << "Id del Administrador: " << this->getIdAdministrador();
	cout << endl;

	//Falta mostrar el Arma de la Solicitud

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