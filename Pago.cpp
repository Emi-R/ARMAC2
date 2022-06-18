#include "Pago.h"

PagoCuota::PagoCuota(int idSocio, float valorCuota, int idCuota)
{
	Fecha fechaActual;

	_idSocio = idSocio;
	_importe = valorCuota;
	_fechaPago = fechaActual;
	_idCuota = idCuota;

}

void PagoCuota::setIdCuota(int id)
{
	_idCuota = id;
}

void PagoCuota::setIdSocio(int id)
{
	_idSocio = id;
}

void PagoCuota::setImporte(float imp)
{
	_importe = imp;
}

void PagoCuota::setFechaPago(Fecha fecha)
{
	_fechaPago = fecha;
}

int PagoCuota::getIdCuota()
{
	return _idCuota;
}

int PagoCuota::getIdSocio()
{
	return _idSocio;
}

float PagoCuota::getImporte()
{
	return _importe;
}

Fecha PagoCuota::getFechaPago()
{
	return _fechaPago;
}

bool PagoCuota::grabarEnDisco()
{
	FILE* fReg = fopen("pagoscuota.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(PagoCuota), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool PagoCuota::leerDeDisco(int pos)
{
	FILE* fReg = fopen("pagoscuota.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(PagoCuota), SEEK_SET);

	int escribio = fread(this, sizeof(PagoCuota), 1, fReg);

	fclose(fReg);

	return escribio;
}

int generarIDCuota()
{
	PagoCuota aux;
	int id = 0;
	int pos = 0;

	while (aux.leerDeDisco(pos++)) {
		id = aux.getIdCuota();
	};

	return id;
}

int checkArchivoPagosCuota()
{
	FILE* solicReg = fopen("pagoscuota.dat", "rb");

	if (solicReg == NULL)
	{
		solicReg = fopen("pagoscuota.dat", "wb");

		if (solicReg == NULL)
		{
			cout << "Error al crear o leer archivo de pagos de cuotas." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(solicReg);
			cout << "Archivo de pagos de cuotas creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Archivo de pagos de cuotas cargado correctamente" << endl;
	}

	fclose(solicReg);
	return 1;
}