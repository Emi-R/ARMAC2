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
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::DARKGREY);

	checkArchivoSocios();
	checkArchivoAdmins();
	checkArchivoSolicitud();
	checkArchivoArmas();

	system("PAUSE > null");
	system("cls");
}

void login()
{
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

void mostrarMenu() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
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

		rlutil::cls();

		switch (opcion) {
		case 1:
			mostrarMenuSocios();
			break;
		case 2:
			mostrarMenuAdmins();
			break;
		case 3:
			mostrarMenuSolicitudes();
			break;
		case 4:

			break;
		case 0:
			cout << "¿Confirma salir? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			
			break;
		}

	}

}

void mostrarMenuSocios() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\tSocios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Cargar nuevo socio" << endl;
		cout << "2 - Modificar socio" << endl;
		cout << "3 - Eliminar socio" << endl;
		cout << "--------------------------" << endl;
		cout << "4 - Listados" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		rlutil::cls();

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
			MenuListadosSocios();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}


}

void MenuListadosSocios()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!false) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\tListados Socios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todos los socios" << endl;
		cout << "2 - Listar socios por ID" << endl;
		cout << "3 - Listar socios por antigüedad" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		rlutil::cls();

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

void mostrarMenuAdmins() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\t Administradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nuevo administrador " << endl;
		cout << "2 - Modificar administrador " << endl;
		cout << "3 - Eliminar administrador " << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		rlutil::cls();

		switch (opcion) {
		case 1:
			crear_nuevo_admin();
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

void mostrarMenuSolicitudes() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\tSolicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nueva solicitud" << endl;
		cout << "2 - Modificar Solicitud" << endl;
		cout << "3 - Eliminar Solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		rlutil::cls();

		switch (opcion) {
		case 1:
			system("pause");
			break;
		case 2:

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
