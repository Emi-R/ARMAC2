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
bool Socio::grabarendisco() {
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
bool Socio::leerdedisco(int pos) {
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
bool Socio::modificarendisco(int pos) {
	FILE* fReg = fopen("socio.dat", "rb+");

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
void Socio::cargarsocio() {
	CargarPersona();
	cout << "Ingrese el ID de socio" << endl;
	cin >> _idsocio;
	_estado = true;
}
void Socio::mostrarsocio() {
	MostrarPersona();
	cout << "ID socio: " << _idsocio << endl;
	
}

bool buscarSocioPorID(int id)
{
	Socio socio;
	int pos = 0;

	while (socio.leerdedisco(pos++))
	{
		if (socio.getIdsocio() == id)
		{
			return true;
		}
	}

	return false;
}