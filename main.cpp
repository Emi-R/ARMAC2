#include <iostream>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"

using namespace std;

void instalacion()
{
	checkArchivoSocios();

	checkArchivoAdmins();

	system("PAUSE > null");
	system("cls");
}

int main()
{

	setlocale(LC_ALL, "Spanish");

	instalacion();

	/*--Prueba Admin: todo OK
	*
	Administrador admin;
	admin.cargar();*/

	/*--Prueba Persona: todo OK
	*
	Persona Persona;
	Persona.CargarPersona();
	Persona.MostrarPersona();*/


	/*--Prueba Solicitud: probar primero socio
	* 
	Solicitud solic;
	solic.cargarSolicitud();
	solic.mostrarSolicitud();*/

	/*Prueba socio*/

	Socio socio;

	socio.cargar();
	socio.grabarEnDisco();

	return 0;
}