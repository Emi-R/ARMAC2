#pragma once
#pragma once
#include "Fecha.h"
#include"Domicilio.h"
#include <cstring>
class Persona
{
private:
	int _dni;
	char _nombre[30];
	char _apellido[30];
	Fecha _fecha_nacimiento;
	Domicilio _domicilio;
	char _email[30];
	char _telefono[15];
	bool _estado;

public:
	Persona();
	void setDni(int dni);
	void setNombre(char* nombre);
	void setApellido(char* apelldo);
	void setFechanacimiento(Fecha fecha_nacimiento);
	void setDomicilio(Domicilio domicilio);
	void setEmail(char* email);
	void setTelefono(char* telefono);
	void setEstado(bool estado);
	int getDni();
	const char* getNombre();
	const char* getApellido();
	Fecha getFecha();
	Domicilio getDomicilio();
	const char* getEmail();
	const char* getTelefono();
	bool getEstado();

};

