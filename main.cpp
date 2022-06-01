#include <iostream>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "funciones.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "Spanish");

	instalacionArchivos();

	//login();

	mostrarMenu();

	/*--Prueba Admin: todo OK
	*/
	//Administrador admin;
	//admin.cargar();
	//admin.grabarEnDisco();
	//admin.mostrar();


	/*--Prueba Persona: todo OK
	*
	Persona Persona;
	Persona.CargarPersona();
	Persona.MostrarPersona();*/


	/*Prueba socio*: Esta OK pero no toma el primer caracter en algunas cadenas*/

	//Socio socio;

	//listadoSocios();
	//socio.cargar();
	//socio.grabarEnDisco();


	//Prueba Solicitud: probar primero socio

	//Solicitud solic;
	//solic.cargarSolicitud();


	return 0;
}