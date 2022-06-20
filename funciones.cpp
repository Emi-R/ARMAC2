#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include <thread>
#include "funciones.h"
#include "rlutil.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "Pago.h"
#include "Arma.h"
#include "ValorCuota.h"

using namespace std;
using namespace rlutil;

void instalacionArchivos()
{
	setColor(WHITE);
	setBackgroundColor(DARKGREY);

	checkArchivoSocios();
	checkArchivoAdmins();
	checkArchivoSolicitud();
	checkArchivoArmas();
	checkArchivoPagosCuota();

	checkArchivoPrecioCuota();
	actualizarEstadoCuotasSocios();

	//checkArchivoPrecioSolicitud();

	system("PAUSE > null");
	system("cls");
}

void login() {

	int aux;
	char aux2[30];

	bool flag = false;



	do {

		cout << "\tBienvenido a Sistema ARMAC" << endl;
		cout << "--------------------------" << endl;
		cout << "ID Administrador: " << endl;
		cout << "Contrase�a: " << endl;
		cout << "--------------------------" << endl;

		locate(19, 3);
		cin >> aux;

		if (buscarAdministradorPorID(aux) == -1)
		{
			cls();
			locate(1, 6);
			setBackgroundColor(LIGHTRED);
			setColor(RED);
			cout << "\tID incorrecto." << endl;
			flag = false;
			setColor(WHITE);
			setBackgroundColor(DARKGREY);
			locate(1, 1);
		}
		else
		{
			locate(13, 4);
			cin >> aux2;


			if (!checkContrasenia(aux2))
			{
				cls();
				locate(1, 6);
				setColor(RED);
				cout << "\tContrase�a incorrecta." << endl;
				flag = false;
				setColor(WHITE);
				locate(1, 1);
			}
			else
			{
				locate(1, 6);
				setBackgroundColor(GREEN);
				setColor(LIGHTGREEN);
				cout << "\tID y Contrase�a correctos. Bienvenido!" << endl;
				cout << "\t";
				setColor(WHITE);
				setBackgroundColor(DARKGREY);
				system("PAUSE");
				cls();
				flag = true;
			}
		}
	} while (!flag);
}

void menuPrincipal() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		cls();
		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cout << "\tSistema ARMAC" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Men� Socios" << endl;
		cout << "2 - Men� Administradores" << endl;
		cout << "3 - Men� Armas" << endl;
		cout << "4 - Men� Solicitudes" << endl;
		cout << "5 - Men� Informes" << endl;
		cout << "6 - Men� Configuraciones" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Salir del programa" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			menuSocios();
			break;
		case 2:
			menuAdmins();
			break;
		case 3:
			menuArmas();
			break;
		case 4:
			menuSolicitudes();
			break;
		case 5:
			menuInformes();
			break;
		case 6:
			menuConfiguracion();
			break;
		case 0:
			cout << "�Confirma salir? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}


////////////////////////////
/// Menu Socios y submenus
////////////////////////////
void menuSocios() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tSocios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Cargar nuevo socio" << endl;
		cout << "2 - Modificar socio" << endl;
		cout << "3 - Eliminar socio" << endl;
		cout << "4 - Cobrar cuota" << endl;
		cout << "--------------------------" << endl;
		cout << "5 - Listados" << endl;
		cout << "6 - Consultas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		int i = 0;
		switch (opcion) {
		case 1:
			cargar_nuevo_socio();
			break;
		case 2:
			modificar_socio();
			break;
		case 3:
			bajaSocio();
			break;
		case 4:
			cobrar_cuota();
			break;
		case 5:
			menuListadosSocios();
			break;
		case 6:
			menuConsultasSocios();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuListadosSocios() {
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Socios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todos los socios" << endl;
		cout << "2 - Listar socios ordenados alfabeticamente" << endl;
		cout << "3 - Listar socios por antig�edad" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoGeneralSocios();
			anykey();
			break;
		case 2:
			listarSocioAlfabeticamente();
			anykey();
			break;
		case 3:
			listarSocioPorFecha();
			anykey();
			break;
		case 4:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuConsultasSocios() {
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tConsultas Socios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Consulta por DNI" << endl;
		cout << "2 - Consulta por ID" << endl;
		cout << "3 - Consulta por Apellido" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaPorDni();
			anykey();
			break;
		case 2:
			consulta_Por_Id();
			anykey();
			break;
		case 3:
			consulta_Por_Apellido();
			anykey();
			break;
		case 4:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}



////////////////////////////
/// Menu Administradores y submenus
////////////////////////////

void menuAdmins() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tAdministradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nuevo administrador " << endl;
		cout << "2 - Modificar administrador " << endl;
		cout << "3 - Eliminar administrador " << endl;
		cout << "--------------------------" << endl;
		cout << "4 - Listados de Administradores" << endl;
		cout << "5 - Buscar administrador por ID" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			crear_nuevo_admin();
			break;
		case 2:
			modificar_admin();
			break;
		case 3:
			baja_admin();
			break;
		case 4: 
			menuListadosAdmin();
			break;
		case 5:
			consulta_admin_Por_ID();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosAdmin() {
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\t Listados administradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listados general de administradores" << endl;
		cout << "2 - Listados por recaudacion" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listado_general_admin();
			anykey();
			break;
		case 2:
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

////////////////////////////
///Menu Solicitudes y submenus
////////////////////////////
void menuSolicitudes() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tSolicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nueva solicitud" << endl;
		cout << "2 - Modificar Solicitud" << endl;
		cout << "3 - Eliminar Solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "4 - Listados" << endl;
		cout << "5 - Consultas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			cargarNuevaSolicitud();
			break;
		case 2:
			modificar_solicitud();
			break;
		case 3:
			anykey();
			break;
		case 4:
			menuListadosSolicitudes();

			break;
		case 5:
			menuConsultasSolicitudes();

			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosSolicitudes() {
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Solicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todas las Solicitudes" << endl;
		cout << "2 - Listar Solicitudes orden descendente" << endl;
		cout << "3 - Listar Solicitudes por Fecha Descendente" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoSolicitudes();
			anykey();
			break;
		case 2:
			listarSolicitudesPorIdDesc();
			anykey();
			break;
		case 3:
			listarSolicitudPorFechaDesc();
			anykey();
			break;
		case 4:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuConsultasSolicitudes()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tConsultas Solicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Consulta por ID de solicitud" << endl;
		cout << "2 - Consulta por Fecha" << endl;
		cout << "3 - Consulta por A�o" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaSolicitudesPorId();
			anykey();
			break;
		case 2:
			consultaSolicitudesPorFecha();
			anykey();
			break;
		case 3:
			consultaSolicitudesPorAnio();
			anykey();
			break;
		case 4:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}


////////////////////////////
///Menu Armas y submenus
////////////////////////////

void menuArmas() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();

		cout << "\tArmas" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nueva arma " << endl;
		cout << "2 - Modificar arma " << endl;
		cout << "3 - Eliminar arma " << endl;
		cout << "--------------------------" << endl;
		cout << "4 - Listados" << endl;
		cout << "5 - Consultas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			crear_nueva_arma();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			menuListadosArmas();//Falta desarrollar
			break;
		case 5:
			menuConsultasArmas();//Falta desarrollar
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}
//Case 4 del men� ARMAS
void menuListadosArmas() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Armas" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todas los armas" << endl;
		cout << "2 - Listado por N� de serie" << endl;
		cout << "3 - Listar por tipo de arma" << endl;
		cout << "4 - Listar armas por calibre" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoGeneralArmas();
			anykey();
			break;
		case 2:
			listadoDeArmasPorNumDeSerie();
			anykey();
			break;
		case 3:
			listados_Armas_Por_Tipo();
			anykey();
			break;
		case 4:
			listados_Armas_Por_Calibre();
			anykey();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

//Case 5 del men� ARMAS
void menuConsultasArmas() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tConsultas Armas" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Consultas de armas por n�mero de serie" << endl;
		cout << "2 - Consultas por ID de armas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaArmasPorNumSerie();
			anykey();
			break;
		case 2:
			consultaArmasPorIdArma();
			anykey();
			break;

		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

////////////////////////////
///Menu Informes
////////////////////////////
void menuInformes() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tInformes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Recaudaci�n anual" << endl;
		cout << "2 - Recaudaci�n por socio" << endl;
		cout << "3 - Recaudaci�n por tipo de arma" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			Informe_Recaudacion_Anual();
			anykey();
			break;
		case 2:
			recaudacionPorSocio();
			break;
		case 3:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

////////////////////////////
///Menu Configuracion
////////////////////////////
void menuConfiguracion() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tConfiguraciones" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Realizar copia de seguridad" << endl;
		cout << "2 - Restaurar copia de seguridad" << endl;
		cout << "3 - Exportar archivo CSV" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:

			break;
		case 2:

			break;
		case 3:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void todoAMayus(char* apellido)
{

	int len = strlen(apellido);

	for (int i = 0; i < len; i++)
	{
		apellido[i] = toupper(apellido[i]);
	}
}