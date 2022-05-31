#include "Socio.h"

Socio::Socio() {
	Persona();
	_idsocio = 0;
	_estado = false;
}
void Socio::setIdsocio(int idsocio) {
	_idsocio = idsocio;
}

void Socio::setEstado(bool estado) {
	_estado = estado;
}

int	 Socio::getIdsocio() {
	return _idsocio;
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

	Persona persona;

	bool flag = false;
	int aux;

	persona.CargarPersona();

	do {
		aux = 1 + rand() % 9999;

		if (buscarSocioPorID(aux))
		{
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setIdsocio(aux);

	_estado = true;

	this->mostrar();
}

void Socio::mostrar() {

	MostrarPersona();

	cout << "ID socio: " << _idsocio << endl;

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

	fclose(fReg);

	return 1;

}