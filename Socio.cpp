#include "Socio.h"

Socio::Socio() {

	Persona();
	Fecha _fechaIngreso;
	_idsocio = 0;
	_estado = false;
}
void Socio::setIdsocio(int idsocio) {
	_idsocio = idsocio;
}

void Socio::setEstado(bool estado) {
	_estado = estado;
}

void Socio::setFechaIngreso(Fecha fechaIng)
{
	_fechaIngreso = fechaIng;
}

int	 Socio::getIdsocio() {
	return _idsocio;
}

Fecha Socio::getFechaIngreso()
{
	return _fechaIngreso;
}

bool Socio::getEstado() {
	return _estado;
}


//METODOS DE DISCO
bool Socio::grabarEnDisco() {
	FILE* fReg = fopen("socios.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Socio), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Socio::leerDeDisco(int pos) {
	FILE* fReg = fopen("socios.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(Socio), SEEK_SET);

	int escribio = fread(this, sizeof(Socio), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Socio::modificarEnDisco(int pos) {
	FILE* fReg = fopen("socios.dat", "rb+");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(Socio), SEEK_SET);

	int escribio = fwrite(this, sizeof(Socio), 1, fReg);

	fclose(fReg);

	return escribio;
}

//Cargar y Mostrar
void Socio::cargar() {

	bool flag = false;
	int aux;
	Fecha fechaActual;

	srand(time(NULL));

	CargarPersona();

	this->setFechaIngreso(fechaActual);

	this->setIdsocio(generarIDSocio() + 1);

	_estado = true;

	cout << endl << " -- Socio creado correctamente --" << endl << endl;

	this->mostrar();
}

void Socio::mostrar() {

	cout << "ID de socio: " << this->getIdsocio() << endl;
	cout << "Fecha de ingreso: ";
	_fechaIngreso.mostrarFecha();

	MostrarPersona();

}

int generarIDSocio()
{
	Socio socio;
	int id = 0;
	int pos = 0;

	while (socio.leerDeDisco(pos++)) {
		id = socio.getIdsocio();
	};

	return id;
}

bool buscarSocioPorID(int id)
{
	Socio socio;
	int pos = 0;

	while (socio.leerDeDisco(pos++))
	{
		if (socio.getIdsocio() == id)
		{
			return true;
		}
	}

	return false;
}

bool buscarSocioPorDNI(int dni)
{
	Socio socio;
	int pos = 0;

	while (socio.leerDeDisco(pos++))
	{
		if (socio.getDni() == dni)
		{
			return true;
		}
	}

	return false;
}

int checkArchivoSocios() {

	FILE* fReg = fopen("socios.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("socios.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de socios." << endl;
			system("PAUSE > null");
			system("cls");
			return -1;
		}
		else
		{
			fclose(fReg);
			cout << "Archivo de socios creado correctamente" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Archivo de socios cargado correctamente" << endl;
	}

	fclose(fReg);

	return 1;

}

void listadoSocios()
{
	Socio socio;
	int pos = 0;

	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(30) << "NOMBRE";
	cout << setw(30) << "APELLIDO";
	cout << setw(15) << "FECHA INGRESO" << endl;

	while (socio.leerDeDisco(pos++))
	{
		socio.listar();
	}

}

void Socio::listar() {

	cout << left;
	cout << setw(5) << this->getIdsocio();
	cout << setw(15) << this->getDni();
	cout << setw(30) << this->getNombre();
	cout << setw(30) << this->getApellido();
	//setw(15);
	this->getFechaIngreso().mostrarFecha();
	cout << endl;
}

void cargar_nuevo_socio()
{
	Socio aux;

	aux.cargar();
	aux.grabarEnDisco();
}