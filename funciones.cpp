#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include "funciones.h"
#include "rlutil.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"

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

		if (!buscarAdministradorPorID(aux))
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

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
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
			system("pause");
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
			cargar_nuevo_socio();
			break;
		case 2:
			anykey();
			break;
		case 3:

			break;
		case 4:
			menuListadosSocios();
			break;
		case 5:
			menuConsultasSocios();
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
		cout << "2 - Listar socios por ID" << endl;
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

			anykey();
			break;
		case 2:
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
		cout << "4- Listados de Administradores" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			crear_nuevo_admin();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4: menuListadoAdmin();

		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}
void menuListadoAdmin() {
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\t Listados administradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listados por ID administrador " << endl;
		cout << "2 - Listados por recaudacion " << endl;
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
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Solicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todas las Solicitudes" << endl;
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
			menuListadosArmas();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

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
		cout << "2 - Listar armas por ID" << endl;
		cout << "3 - Listar por número de serie" << endl;
		cout << "4 - Listar por tipo de arma" << endl;
		cout << "5 - Listar armas por calibre" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoGeneralArmas();
			anykey();
			break;
		case 2:
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
