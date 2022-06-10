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

	menuPrincipal();

	return 0;
}