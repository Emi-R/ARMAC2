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

	login();

	menuPrincipal();

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


	//Prueba Solicitud: probar primero socio-creo que está bien, falta chequear el set para Pais de fabricacion del Arma

	//Solicitud solic;
	//solic.cargarSolicitud();
	//listadoSolicitudes();

	return 0;
}