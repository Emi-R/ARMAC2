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

	setlocale(LC_ALL, "Spanish");

	instalacionArchivos();

	menuPrincipal();

	//while (aux.leerDeDisco(pos++) && !aux.getEstado())
	//{
	//	aux.listar();
	//}
	//anykey();
	//

	///login();

	/// Cambiar espacios de nombre en excel a _



	return 0;
}