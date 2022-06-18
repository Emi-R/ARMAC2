#include <iostream>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "funciones.h"
#include "ValorCuota.h"
#include "Pago.h"

using namespace std;
using namespace rlutil;

int main()
{

	setlocale(LC_ALL, "Spanish");

	instalacionArchivos();

	menuPrincipal();

	PagoCuota aux;

	int pos = 0;

	while (aux.leerDeDisco(pos++))
	{
		cout << aux.getIdSocio() << endl;
		cout << aux.getImporte() << endl;
		aux.getFechaPago().mostrarFecha();
		cout << endl << aux.getIdCuota() << endl << endl;

	}

	anykey();

	///login();

	/// Cambiar espacios de nombre en excel a _



	return 0;
}