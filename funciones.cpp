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
	checkArchivoCuotas();

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
		cout << "Contraseña: " << endl;
		cout << "--------------------------" << endl;

		locate(19, 3);
		cin >> aux;

		if (buscarAdministradorPorID(aux)==-1)
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
				cout << "\tContraseña incorrecta." << endl;
				flag = false;
				setColor(WHITE);
				locate(1, 1);
			}
			else
			{
				locate(1, 6);
				setBackgroundColor(GREEN);
				setColor(LIGHTGREEN);
				cout << "\tID y Contraseña correctos. Bienvenido!" << endl;
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
		cout << "1 - Menú Socios" << endl;
		cout << "2 - Menú Administradores" << endl;
		cout << "3 - Menú Armas" << endl;
		cout << "4 - Menú Solicitudes" << endl;
		cout << "5 - Menú Informes" << endl;
		cout << "6 - Menú Configuraciones" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Salir del programa" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Confirma salir? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			/// Pedir ID
			/// Mostrar Valor
			/// Modificar bool deudor
			/// Modificar fecha ultimo pago
			/// Grabar
			break;
		case 5:
			menuListadosSocios();
			break;
		case 6:
			menuConsultasSocios();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "3 - Listar socios por antigüedad" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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

			break;
		case 4:


			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
		case 4: menuListadosAdmin();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuConsultasAdmin()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\t Consultas administradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Consulta por ID administrador " << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			break;
		case 2:
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			cargarNuevaSolicitud();
			break;
		case 2:

			break;
		case 3:


			break;
		case 4:
			menuListadosSolicitudes();

			break;
		case 5:
			menuConsultasSolicitudes();

			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosSolicitudes() {
	int opcion;
	char opcion2;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Solicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todas las Solicitudes" << endl;
		cout << "2 - Listar solicitudes orden descendente" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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

			break;
		case 4:


			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "2 - Consulta por fecha" << endl;
		cout << "3 - Consulta por Año" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:

			break;
		case 2:
			anykey();
			break;
		case 3:
			consultaSolicitudesPorAnio();
			anykey();
			break;
		case 4:
			
			
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}
//Case 4 del menú ARMAS
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
		cout << "2 - Listar cantidad de armas por ID" << endl;
		cout << "3 - Listar por nombre de arma" << endl;
		cout << "4 - Listar por tipo de arma" << endl;
		cout << "5 - Listar armas por calibre" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoGeneralArmas();//Falta desarrollar

			break;
		case 2:
			//listadoCantidadArmasPorID();//Falta desarrollar

			anykey();
			break;
		case 3:
			//listadoPorNombreDeArma();//Falta desarrollar
			anykey();
			break;
		case 4:
			//();//Falta desarrollar

			anykey();
			break;
		case 5:
			//listadoPorCalibre(); //Falta desarrollar
			anykey();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

//Case 5 del menú ARMAS
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
		cout << "1 - Consultas de armas por número de serie" << endl;
		cout << "2 - Consultas por ID de armas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			//consultasPorNumeroSerie(); //Falta desarrollar
			anykey();
			break;
		case 2:
			//consultasPorIDArmas(); //Falta desarrollar
			anykey();
			break;

		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "1 - Recaudacion anual" << endl;
		cout << "2 - Modificar por socio" << endl;
		cout << "3 - Recaudacion por tipo de arma" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Volver al menu anterior? (S/N) ";
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
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}
