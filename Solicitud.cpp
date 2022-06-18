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

void Solicitud::setEditable(bool e)
{
	_editable = e;
}

void Solicitud::setEstado(bool estado) {
	_estado = estado;
};

int Solicitud::getIdSolicitud() { return _idSolicitud; }

int Solicitud::getIdAdministrador() { return _idAdministrador; }

int Solicitud::getIdSocio() { return _idSocio; }

int Solicitud::getIdArma() { return _idArma; }

Fecha Solicitud::getFechaSolicitud() { return _FechaSolicitud; }

int Solicitud::getAprobado() { return _aprobado; }

bool Solicitud::getEditable() {return _editable;}

bool Solicitud::getEstado() { return _estado; }

void Solicitud::cargarSolicitud() {

	int aux;
	int estadoPendiente = 0;
	Arma armaRegistro;
	Fecha fechaSolicitud;
	bool verifica = false;

	do {
		cout << "Ingrese el Id del Administrador: ";
		cin >> aux;

		if (buscarAdministradorPorID(aux) == -1)
		{
			cout << "El Id del Administrador es inválido. Por favor, ingrese un ID correcto." << endl;
			anykey();
			cls();
			verifica = false;
		}
		else
		{
			verifica = true;
		}

	} while (verifica == false);

	this->setIdAdministrador(aux);
	verifica = false;

	do {
		cout << "Ingrese el ID del Socio: ";
		cin >> aux;

		if (buscarSocioPorID(aux) == -1)
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

	this->setIdArma(armaRegistro.getIdArma());

	this->setFechaSolicitud(fechaSolicitud);

	_estado = true;
	this->setAprobado(estadoPendiente);
	this->setIdSolicitud(generarIdSolicitud() + 1);
	this->setEditable(true);

	armaRegistro.grabarEnDisco();
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
		cout << "DESAPROBADA";
		break;
	case 0:
		cout << "PENDIENTE";
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

	copiarSolicitudes(solicitudes, cantSolicitudes);
	ordernarVecSolicPorIdDesc(solicitudes, cantSolicitudes);
	mostrarSolicitudes(solicitudes, cantSolicitudes);

	delete solicitudes;
}

void ordernarVecSolicPorIdDesc(Solicitud *vSolicitudes, int tam) {
	Solicitud aux;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vSolicitudes[i].getIdSolicitud() < vSolicitudes[j].getIdSolicitud()) {
				aux = vSolicitudes[i];
				vSolicitudes[i] = vSolicitudes[j];
				vSolicitudes[j] = aux;
			}
		}
	}
}
void listarSolicitudPorFechaDesc() {
	int cantReg = buscarCantidadSolicitudes();

	if (cantReg == 0) {
		cout << "No hay Solicitudes registradas";
		anykey();
		return;
	}

	Solicitud* vSolicitudes;
	vSolicitudes = new Solicitud[cantReg];
	if (vSolicitudes == NULL) return;

	copiarSolicitudes(vSolicitudes, cantReg);
	ordernarVectorSolicPorFechaDesc(vSolicitudes, cantReg);
	mostrarSolicitudes(vSolicitudes, cantReg);

	delete vSolicitudes;

}

void ordernarVectorSolicPorFechaDesc(Solicitud* vec, int tam) {
	Solicitud aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vec[i].getFechaSolicitud() >  vec[j].getFechaSolicitud()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
void mostrarSolicitudes(Solicitud *vSolicitudes, int tam) {
	cout << "LISTADO DE SOLICITUDES" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(15) << "ID SOLICITUD";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID SOCIO";
	cout << setw(15) << "ID ARMA";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;

	for (int i = 0; i < tam; i++) {
		vSolicitudes[i].listarSolicitud();
	}
};

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
		if (solicitud.getIdSolicitud() == id && solicitud.getEstado()) {
			return pos;
		}
	}

	return -1;
}

void copiarSolicitudes(Solicitud* vecSoli, int tam) {

	for (int i = 0; i < tam; i++) { vecSoli[i].leerDeDisco(i); }
}

void consultaSolicitudesPorFecha() {

	int cantidadSolicitudes = buscarCantidadSolicitudes();
	if (cantidadSolicitudes <= 0) {
		cout << "No hay Solicitudes Registradas.";
		return;
	}

	Solicitud* vecSolicitudes;

	vecSolicitudes = new Solicitud[cantidadSolicitudes];

	if (vecSolicitudes == NULL) { return; }

	copiarSolicitudes(vecSolicitudes, cantidadSolicitudes);

	Fecha fechaConsulta;

	cout << " - Consulta de Solicitudes por Fecha de Creación- ";
	cout << endl;
	cout << "Ingrese la Fecha: ";
	cout << endl;

	fechaConsulta.cargarFechaConsultas();

	mostrarConsultasPorFecha(vecSolicitudes, cantidadSolicitudes, fechaConsulta);

	delete vecSolicitudes;
}

void mostrarConsultasPorFecha(Solicitud* vecSolicitudes, int tam, Fecha fechaConsulta) {

	Fecha fechaSoli;
	cout << left;
	cout << setw(15) << "ID SOLICITUD";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID SOCIO";
	cout << setw(15) << "ID ARMA";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;

	for (int i = 0; i < tam; i++) {
		fechaSoli = vecSolicitudes[i].getFechaSolicitud();
		if (fechaSoli == fechaConsulta) {
			vecSolicitudes[i].listarSolicitud();
		}
	}
}

void bajaSolicitud(Solicitud aux, int pos)
{
	int id;
	bool flag = false;
	char confirm;

	cout << "¿Desea dar de baja la solicitud  N°" << aux.getIdSolicitud() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		/// Elimina el arma en archivo armas
		eliminarArma(aux.getIdArma());
		aux.setEstado(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La solicitud ha sido eliminada -- " << endl;
		anykey();
	}
	cls();
}

void modificar_solicitud()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;
	bool flag = false;
	int idaux;
	int pos = 0;
	Solicitud aux;

	while (!salir) {

		do
		{
			cout << "Ingrese ID de solicitud a modificar (0 para volver al menu Solicitud): ";
			cin >> idaux;

			pos = buscarSolicitudPorId(idaux) - 1;

			if (pos <= -1 && idaux != 0)
			{
				cout << "La Solicitud no se encuentra. Reintente por favor." << endl << endl;
			}
			else if (idaux == 0)
			{
				return;
			}
			else
			{
				aux.leerDeDisco(pos);

				if (aux.getEditable())
				{
					flag = true;
				}
				else
				{
					cout << endl << " -- La solicitud ya ha sido aprobada o desaprobada. No se puede editar --" << endl;
					anykey();
					cls();
					flag = false;
				}
			}
		
		} while (!flag);

		cls();

		aux.mostrarSolicitud();
		cout << endl;

		cout << "\tSeleccione opción" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Aprobar solicitud " << endl;
		cout << "2 - Desaprobar solicitud " << endl;
		cout << "3 - Eliminar registro de solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú Solicitudes" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			aprobarSolicitud(aux,pos);
			break;
		case 2:
			desaprobarSolicitud(aux,pos);
			break;
		case 3:
			bajaSolicitud(aux, pos);
			break;
		case 7:
			//ModificarTelefono(aux, pos);
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void aprobarSolicitud(Solicitud aux,int pos)
{
	int id;
	bool flag = false;
	char confirm;

	cout << "¿Desea aprobar la solicitud  N°" << aux.getIdSolicitud() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		aux.setAprobado(1);
		aux.setEditable(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La solicitud ha sido aprobada -- " << endl;
		anykey();
	}
	cls();
}

void desaprobarSolicitud(Solicitud aux, int pos)
{
	int id;
	bool flag = false;
	char confirm;

	cout << "¿Desea desaprobar la solicitud  N°" << aux.getIdSolicitud() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		aux.setAprobado(-1);
		aux.setEditable(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La solicitud ha sido desaprobada -- " << endl;
		anykey();
	}
	cls();
}
