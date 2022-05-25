#include "Persona.h"
#include <iostream>
using namespace std;


Persona::Persona() {

}
//SETTER
void Persona::setDni(int dni) { _dni = dni; }
void Persona::setNombre(char* nombre) { strcpy(_nombre, nombre); }
void Persona::setApellido(char* apelldo) { strcpy(_apellido, apelldo); }
void Persona::setFechanacimiento(Fecha fecha_nacimiento) { _fecha_nacimiento = fecha_nacimiento; }
void Persona::setDomicilio(Domicilio domicilio) { _domicilio, domicilio; }
void Persona::setEmail(char* email) { strcpy(_email, email); }
void Persona::setTelefono(char* telefono) { strcpy(_telefono, telefono); }
void Persona::setEstado(bool estado) { _estado = estado; }
//GETTER
int  Persona::getDni() { return _dni; }
const char* Persona::getNombre() { return _nombre; }
const char* Persona::getApellido() { return _apellido; }
Fecha Persona::getFecha() { return _fecha_nacimiento; }
Domicilio Persona::getDomicilio() { return _domicilio; }
const char* Persona::getEmail() { return _email; }
const char* Persona::getTelefono() { return _telefono; }
bool Persona::getEstado() { return _estado; }

//	MOSTRAR Y CARGAR
void Persona::CargarPersona() {

	do {
		cout << "Ingrese el dni:" << endl;
		cin >> _dni;

		if (_dni < 1000000)
		{
			cout << " El dni ingresado es incorrecto, intente nuevamente" << endl;
		}
	} while (_dni < 1000000);

	cout << "Ingrese el nombre  : ";
	cin.ignore();
	cin.getline(_nombre, 29);
	cout << "Ingrese el apellido: ";
	cin.getline(_apellido, 29);
	cout << "Ingrese la fecha de nacimiento: ";
	_fecha_nacimiento.cargarFecha();
	cout << "Ingrese el domicilio: ";
	_domicilio.cargarDomicilio();
	cout << "Ingrese la casilla de email : ";
	cin.getline(_email, 30);
	cout << "Ingrese el telefono : ";
	cin.getline(_telefono, 14);
	_estado = true;
}

void Persona::MostrarPersona() {
	if (_estado) {
		cout << "Dni: " << _dni << endl;
		cout << "Nombre: " << _nombre << endl;
		cout << "Apellido: " << _apellido << endl;
		cout << "Fecha nacimiento: ";
		_fecha_nacimiento.mostrarFecha();
		cout << "Domicilio: ";
		_domicilio.mostrarDomicilio();
		cout << "Email : " << _email;
		cout << "Ingrese el telefono: " << _telefono << endl;
	}
}