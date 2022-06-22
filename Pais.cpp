#include "Pais.h"

using std::setprecision;
using namespace std;

///Setters

void Pais::setId(int idpais) {
	_IdPais = idpais;
}

void Pais::setNombre(const char* nombre) {
	strcpy(_Nombre, nombre);
}
void Pais::setEstado(bool estado) {
	_Estado = estado;
}


///Getters
const char* Pais::getNombre() {
	return _Nombre;
}

bool Pais::getEstado() {
	return _Estado;
}
int Pais::getIdPais() {
	return _IdPais;
}