#include "administrador.h"


using namespace std;

///Constructor
Administrador::Administrador(int id, int dni, const char* apellido, const char* nombre, const char* contrasenia, bool estado)
{
	_idAdministrador = id;
	_dni = dni;
	strcpy(_apellido, apellido);
	strcpy(_nombre, nombre);
	strcpy(_contrasenia, contrasenia);
	_estado = estado;
}

/// Setters
void Administrador::setIdAdmin(int idAdmin)
{
	_idAdministrador = idAdmin;
}

void Administrador::setDNI(int dni)
{
	_dni = dni;
}

void Administrador::setNombre(const char* nombre)
{
	strcpy(_nombre, nombre);
}

void Administrador::setApellido(const char* apellido)
{
	strcpy(_apellido, apellido);
}

void Administrador::setContrasenia(const char* contrasenia)
{
	strcpy(_contrasenia, contrasenia);
}

void Administrador::setEstado(bool estado)
{
	_estado = estado;
}

/// Getters
int Administrador::getIdAdmin()
{
	return _idAdministrador;
}

int Administrador::getDNI()
{
	return _dni;
}

const char* Administrador::getContrasenia()
{
	return _contrasenia;
}

const char* Administrador::getApellido()
{
	return _apellido;
}

const char* Administrador::getNombre()
{
	return _nombre;
}

bool Administrador::getEstado()
{
	return false;
}

void Administrador::cargar()
{
	int aux;
	char aux2[30];
	char aux3[30];
	bool flag = false;

	srand(time(NULL));

	do {
		cout << "Ingrese el DNI: ";
		cin >> aux;

		if (aux < 1)
		{
			cout << "DNI inv�lido. Por favor, reintente." << endl << endl;
		}
		else if (buscarAdministradorPorDni(aux))
		{
			cout << "El DNI ya ha sido registrado anteriormente." << endl << endl;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setDNI(aux);

	cout << "Ingrese apellido: ";
	cin.ignore();
	cin.getline(_apellido, 29);

	cout << "Ingrese nombre: ";
	cin >> aux2;

	cin.ignore();
	cin.getline(_nombre, 29);

	do {
		cout << "Ingrese contrase�a nueva (sin espacios, m�ximo 15 caracteres): ";
		cin >> aux2;

		if (strlen(aux2) > 15)
		{
			cout << "Contrase�a demasiado larga." << endl << endl;
			flag = false;
		}
		else
		{
			cout << "Repita la contrase�a ingresada: ";
			cin >> aux3;

			if (strcmp(aux2, aux3) != 0)
			{
				cout << "La contrase�a es diferente a la primera ingresada. Por favor, reintente." << endl << endl;
				flag = false;
			}
			else
			{
				flag = true;
			}
		}

	} while (!flag);

	this->setContrasenia(aux2);

	do {
		aux = 1 + rand() % 9999;

		if (buscarAdministradorPorID(aux))
		{
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	aux = aux + 0000;

	this->setIdAdmin(aux);

	cout << endl << " -- Administrador creado correctamente --" << endl << endl;
	cout << "Nombre: " << this->getNombre() << endl;
	cout << "Apellido: " << this->getApellido() << endl << endl;
	cout << " - Datos para iniciar sesi�n: " << endl << endl;
	cout << "ID: " << this->getIdAdmin() << endl;
	cout << "Contrase�a: " << this->getContrasenia() << endl;

}

void Administrador::mostrar()
{
	cout << endl << "-----------------------------" << endl;
	cout << "ID: " << this->getIdAdmin() << endl;
	cout << "Nombre: " << this->getNombre() << endl;
	cout << "Apellido: " << this->getApellido() << endl;

}

bool Administrador::grabarEnDisco()
{
	FILE* fReg = fopen("administradores.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Administrador), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Administrador::leerDeDisco(int pos)
{
	FILE* fReg = fopen("administradores.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(Administrador), SEEK_SET);

	int escribio = fread(this, sizeof(Administrador), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Administrador::modificarEnDisco(int pos)
{
	FILE* fReg = fopen("administradores.dat", "rb+");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(Administrador), SEEK_SET);

	int escribio = fwrite(this, sizeof(Administrador), 1, fReg);

	fclose(fReg);

	return escribio;
}


/////////////////////////////////////
// Funciones globales Administrador
/////////////////////////////////////


bool buscarAdministradorPorDni(int DNI)
{
	Administrador admin;
	int pos = 0;

	while (admin.leerDeDisco(pos++))
	{
		if (admin.getDNI() == DNI)
		{
			return true;
		}
	}

	return false;
}

bool buscarAdministradorPorID(int id)
{
	Administrador admin;
	int pos = 0;

	while (admin.leerDeDisco(pos++))
	{
		if (admin.getIdAdmin() == id)
		{
			return true;
		}
	}

	return false;
}

bool checkContrasenia(const char* pass)
{
	Administrador admin;
	int pos = 0;

	while (admin.leerDeDisco(pos++))
	{
		if (strcmp(admin.getContrasenia(), pass) == 0)
		{
			return true;
		}
	}

	return false;
}

int checkArchivoAdmins() {

	FILE* fReg = fopen("administradores.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("administradores.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de administradores." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(fReg);
			cout << "Archivo de administradores creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Archivo de administradores cargado correctamente" << endl;
	}

	fclose(fReg);

	return 1;

}

void crear_nuevo_admin()
{
	Administrador aux;

	aux.cargar();
	aux.grabarEnDisco();
	rlutil::anykey();
}