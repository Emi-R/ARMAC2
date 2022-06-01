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
		cout << "Contrase�a: " << endl;
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


void mostrarMenu() {

	int opcion;
	char confirmarSalida;

	while (true) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
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
			confirmarSalir();
			break;
		}
		cin.ignore();
		rlutil::anykey();
	}

}

void mostrarMenuSocios() {

	int opcion;
	char confirmarSalida;
	while (true) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\tSocios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Cargar nuevo socio" << endl;
		cout << "2 - Modificar socio" << endl;
		cout << "3 - Eliminar socio" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
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
			confirmarVolver();
			break;
		}
		cin.ignore();
		//rlutil::anykey();
	}


}

void mostrarMenuAdmins() {

	int opcion;
	char confirmarSalida;
	while (true) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\t Administradores" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nuevo administrador " << endl;
		cout << "2 - Modificar administrador " << endl;
		cout << "3 - Eliminar administrador " << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
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
			confirmarVolver();
			break;
		}
		cin.ignore();
		//rlutil::anykey();
	}


}

void mostrarMenuSolicitudes() {

	int opcion;
	char confirmarSalida;
	while (true) {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::DARKGREY);
		rlutil::cls();
		cout << "\tSolicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Crear nueva solicitud" << endl;
		cout << "2 - Modificar Solicitud" << endl;
		cout << "3 - Eliminar Solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
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
			confirmarVolver();
			break;
		}
		cin.ignore();
		//rlutil::anykey();
	}
}

char confirmarSalir() {

	char confirmarSalida;

	cout << "�Confirma salir? (S/N) ";
	cin >> confirmarSalida;
	if (tolower(confirmarSalida) == 's') {
		return 0;
	}

}

void confirmarVolver() {
	char confirmarVolver;
	cout << "�Volver al men� anterior ? (S/N) ";
	cin >> confirmarVolver;
	if (tolower(confirmarVolver) == 's') {
		mostrarMenu();
	}

}
