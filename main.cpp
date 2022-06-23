#include <iostream>
#include <iomanip>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "funciones.h"
#include "ValorCuota.h"
#include "Pago.h"
#include "PagoSolicitud.h"

using namespace std;
using namespace rlutil;

int main()
{
	setlocale(LC_ALL, "Spanish");

	bool flag = false;
	bool flag2 = false;

	instalacionArchivos();

	/*Pais aux;

	for (int i = 0; i < 10; i++)
	{
		aux.CargarPais();
		aux.grabarEnDisco();
	}*/

	do
	{
		flag = login();

		if (flag)
		{
			flag2 = menuPrincipal();
		}

	} while (flag && flag2);

	return 0;
}