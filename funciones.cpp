#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include <conio.h>
#include "funciones.h"
#include "rlutil.h"
#include "Administrador.h"
#include "Persona.h"
#include "Solicitud.h"
#include "Pago.h"
#include "Arma.h"
#include "ValorCuota.h"
#include "ValorSolicitud.h"
#include "RecaudacionesPorAdmin.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace rlutil;

void instalacionArchivos()
{
	setColor(WHITE);
	setBackgroundColor(BLUE);

	checkArchivoSocios();
	checkArchivoAdmins();
	checkArchivoSolicitud();
	checkArchivoArmas();

	checkArchivoPagosCuota();
	checkArchivoPagosSolicitud();

	checkArchivoPrecioCuota();
	checkArchivoPrecioSolicitud();

	actualizarEstadoCuotasSocios();

	cout << endl << "\t-- Presione enter para continuar --";
	system("PAUSE > null");
	system("cls");
}

bool login() {

	int aux;
	bool flag = false;
	bool flag2 = false;
	int pos = 0;
	string aux2;
	string password;
	char caracter;
	int cont = 0;

	Administrador admin;

	do {

		cout << "\tBienvenido a Sistema ARMAC" << endl;
		cout << "--------------------------" << endl;
		cout << "ID Administrador: " << endl;
		cout << "Contraseña: " << endl;
		cout << "--------------------------" << endl;

		locate(19, 3);
		cin >> aux;

		pos = buscarAdministradorPorID(aux);

		if (pos == -1)
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
			admin.leerDeDisco(pos);
			password = admin.getContrasenia();

			aux2 = pedirContrasenia();

			if (aux2 != password)
			{
				cls();
				locate(1, 6);
				setColor(RED);
				cout << "\tContraseña incorrecta." << endl;
				flag = false;
				setColor(WHITE);
				locate(1, 1);
				cont++;
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
				return true;

			}
		}

		if (cont == 3)
		{
			cls();
			setBackgroundColor(RED);
			setColor(YELLOW);
			cout << endl << "\t-- Ha superado el límite de intentos. Contacte a Ángel Simón. --" << endl;
			anykey();
			setColor(WHITE);
			return false;
		}

	} while (!flag);

	return true;
}

bool menuPrincipal() {

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		cls();
		setColor(WHITE);
		setBackgroundColor(BLUE);
		cout << "\tSistema ARMAC" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Menú Socios" << endl;
		cout << "2 - Menú Administradores" << endl;
		cout << "3 - Menú Armas" << endl;
		cout << "4 - Menú Solicitudes" << endl;
		cout << "5 - Menú Informes" << endl;
		cout << "6 - Menú Configuraciones" << endl;
		cout << "--------------------------" << endl;
		cout << "9 - Cerrar sesion" << endl;
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
		case 9:
			cout << "¿Desea cerrar la sesion? (S/N) ";
			cin >> confirmarSalida;

			if (tolower(confirmarSalida) == 's')
			{
				cls();
				return true;
			}
			else
			{
				salir = false;
			}
			break;
		case 0:
			cout << "¿Confirma salir? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			return false;
		}
	}
	return true;
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
		setBackgroundColor(LIGHTBLUE);
		cls();
		cout << "\tSocios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Cargar nuevo Socio" << endl;
		cout << "2 - Modificar Socio" << endl;
		cout << "3 - Eliminar Socio" << endl;
		cout << "4 - Cobrar Cuota" << endl;
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
			baja_socio();
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
		setBackgroundColor(CYAN);
		cls();
		cout << "\tListados Socios" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todos los Socios" << endl;
		cout << "2 - Listar socios ordenados alfabeticamente" << endl;
		cout << "3 - Listar socios por antigüedad" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listado_general_socios();
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
			break;
		case 2:
			consulta_Por_Id();
			break;
		case 3:
			consulta_Por_Apellido();
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
		cout << "1 - Crear nuevo Administrador " << endl;
		cout << "2 - Modificar Administrador " << endl;
		cout << "3 - Eliminar Administrador " << endl;
		cout << "--------------------------" << endl;
		cout << "4 - Listados de administradores" << endl;
		cout << "5 - Buscar Administrador por ID" << endl;
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
		case 4:
			menuListadosAdmin();
			break;
		case 5:
			consulta_admin_Por_ID();
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
		cout << "1 - Crear nueva Solicitud" << endl;
		cout << "2 - Modificar Solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "3 - Listados" << endl;
		cout << "4 - Consultas" << endl;
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
			modificar_solicitud();
			break;
		case 3:
			menuListadosSolicitudes();
			break;
		case 4:
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
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setColor(WHITE);
		setBackgroundColor(DARKGREY);
		cls();
		cout << "\tListados Solicitudes" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Listar todas las Solicitudes" << endl;
		cout << "2 - Listar Solicitudes por orden descendente" << endl;
		cout << "3 - Listar Solicitudes por fecha Descendente" << endl;
		cout << "4 - Listar Solicitudes aprobadas" << endl;
		cout << "5 - Listar Solicitudes pendientes" << endl;
		cout << "6 - Listar Solicitudes desaprobadas" << endl;
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
			listarSolicitudPorFechaDesc();
			anykey();
			break;
		case 4:
			listadoSolicitudesAprobadas();
			anykey();
			break;
		case 5:
			listadoSolicitudesPendientes();
			anykey();
			break;
		case 6:
			listadoSolicitudesDesaprobadas();
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
		cout << "1 - Consulta por ID de Solicitud" << endl;
		cout << "2 - Consulta por Fecha" << endl;
		cout << "3 - Consulta por Año" << endl;
		cout << "3 - Consulta Solicitudes pendientes por Socio" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
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
			listadoSolicitudesPendientesPorSocio();
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
		cout << "1 - Modificar arma " << endl;
		cout << "--------------------------" << endl;
		cout << "2 - Listados" << endl;
		cout << "3 - Consultas" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			modificar_arma();
			break;
		case 2:
			menuListadosArmas();
			break;
		case 3:
			menuConsultasArmas();
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
		cout << "2 - Listado por N° de serie" << endl;
		cout << "3 - Listar por tipo de arma" << endl;
		cout << "4 - Listar armas por calibre" << endl;
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
			consultaArmasPorNumSerie();
			anykey();
			break;
		case 2:
			consultaArmasPorIdArma();
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
		cout << "1 - Recaudación anual" << endl;
		cout << "2 - Recaudación por socio" << endl;
		cout << "3 - Recaudación por administrador" << endl;
		cout << "4 - Recaudación por tipo de arma" << endl;
		cout << "5 - Cantidad de solicitudes desaprobadas por año" << endl;
		cout << "--------------------------" << endl;
		cout << "6 - Listar historial de precios de cuota" << endl;
		cout << "7 - Listar historial de precios de solicitud" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			Informe_Recaudacion_Anual();
			break;
		case 2:
			recaudacionPorSocio();
			break;
		case 3:
			recaudacionPorAdmin();
			break;
		case 5:
			cantidad_solicitudes_desap_por_anio();
			break;
		case 6:
			listar_historial_precios_cuota();
			break;
		case 7:
			listar_historial_precios_solicitud();
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
		cout << "----------------------------------" << endl;
		cout << "-------  Estado de cuotas  -------" << endl;
		cout << "1 - Actualizar deudores en archivo" << endl;
		cout << "------------  Precios  -----------" << endl;
		cout << "2 - Modificar precio de cuota" << endl;
		cout << "3 - Modificar precio de solicitud" << endl;
		/*cout << "----------------------------------" << endl;*/
		cout << "------------  Archivos  ----------" << endl;
		cout << "4 - Hacer copia de seguridad" << endl;
		cout << "5 - Exportar archivo CSV" << endl;
		cout << "----------------------------------" << endl;
		cout << "0 - Volver al menú principal" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			actualizarEstadoCuotasSocios();
			anykey();
			break;
		case 2:
			modificar_precio_cuota();
			break;
		case 3:
			modificar_precio_solicitud();
			break;
		case 4:
			backup_socios();
			anykey();
			break;
		case 5:
			exportarCSVSocios();
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
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

bool exportarCSVSocios() {

	ofstream myFile;
	myFile.open("listadoSocios.csv");

	FILE* p = fopen("socios.dat", "rb");
	Socio reg;

	if (p == NULL) {
		cout << "No se pudo abrir el archivo";
		return false;
	}

	int pos = 0;

	myFile << "ID SOCIO" << ';' << "DNI" << ';' << "APELLIDO" << ';' << "NOMBRE" << ';' << "ULTIMO PAGO" << ';' << "FECHA INGRESO" << endl;

	string fecha1;
	string fecha2;

	while (reg.leerDeDisco(pos++)) {
		fecha1 = reg.getUltimoPago().toString();
		fecha2 = reg.getFechaIngreso().toString();

		myFile << reg.getIdsocio() << ';' << reg.getDni() << ';' << reg.getApellido() << ';' << reg.getNombre() << ';' << fecha1 << ';' << fecha2 << endl;
	}

	cout << "Listado 'listadoSocios.csv' exportado correctamente" << endl;
	system("pause");
	system("cls");

	return true;


}