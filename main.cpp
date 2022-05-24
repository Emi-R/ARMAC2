#include <iostream>
#include "Fecha.h"
#include "Administrador.h"

using namespace std;

int checkArchivo() {

	FILE* fReg = fopen("administradores.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("administradores.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de administradores.";
			system("PAUSE > null");
			system("cls");
			return -1;
		}
		else
		{
			fclose(fReg);
			cout << "Archivo de administradores creado correctamente";
			system("PAUSE > null");
			system("cls");
			return 0;
		}
	}

	fclose(fReg);

	return 1;

}

int main() 
{
	Administrador admin;

	setlocale(LC_ALL,"Spanish");

	checkArchivo();
	admin.cargar();

	return 0;
}