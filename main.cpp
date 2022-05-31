#include <iostream>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"

using namespace std;


int main()
{

	setlocale(LC_ALL, "Spanish");

	checkArchivoSocios();

	/*--Prueba Admin: todo OK

	Administrador admin;
	admin.cargar();*/

	/*--Prueba Persona: todo OK

	Persona Persona;
	Persona.CargarPersona();
	Persona.MostrarPersona();*/


	/*--Prueba Solicitud
	Solicitud solic;
	solic.cargarSolicitud();
	solic.mostrarSolicitud();*/



	return 0;
}