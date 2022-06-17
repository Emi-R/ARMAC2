#include <iostream>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "funciones.h"


using namespace std;
using namespace rlutil;

int main()
{

	Fecha aux;
	Fecha aux2;
	setlocale(LC_ALL, "Spanish");

	instalacionArchivos();

	///login();

	/// Cambiar espacios de nombre en excel a _

	menuPrincipal();


	return 0;
}