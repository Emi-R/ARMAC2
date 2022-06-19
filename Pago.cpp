#include "Pago.h"
#include "PagoSolicitud.h"

using namespace rlutil;

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

void cobrar_cuota()
{
	int idaux;
	int pos = 0;
	bool flag = false;
	bool flag2 = false;

	Socio socio;
	Fecha fechaActual;

	do {

		do {
			cout << "Ingrese el ID de socio a cobrar (0 para volver al menu anterior): ";
			cin >> idaux;

			if (idaux == 0)
			{
				return;
			}

			pos = buscarSocioPorID(idaux) - 1;

			if (idaux < 1 || pos < 0)
			{
				cout << "ID inválido. Por favor, reintente." << endl << endl;
				flag = false;
			}
			else
			{
				socio.leerDeDisco(pos);

				if (!socio.getDeudor())
				{
					cout << "Ya se ha registrado un pago del socio para el mes actual";
					anykey();
					cls();
					flag = false;
				}
				else
				{
					flag = true;
				}
			}
		} while (!flag);

		cls();

		char confirm;

		socio.leerDeDisco(pos);
		socio.mostrar(); 
		int cantMesesAdeudados = 0;

		if (socio.getUltimoPago().getAnio() == fechaActual.getAnio())
		{
			cantMesesAdeudados = fechaActual.getMes() - socio.getUltimoPago().getMes();
		}
		else
		{
			cantMesesAdeudados = (12 - socio.getUltimoPago().getMes()) + fechaActual.getMes();
		}

		float valorCuota = getUltimoPrecioCuota();
		int idCuota = generarIDCuota() + 1;

		cout << endl << "Valor de la cuota: $" << valorCuota << endl;
		cout << "Cantidad de meses adeudados: " << cantMesesAdeudados << endl << endl;

		float totalAPagar = valorCuota * cantMesesAdeudados;

		cout << " -- Total a pagar: $" << totalAPagar << " --" << endl;

		cout << "Desea cobrar cuota al socio n° " << socio.getIdsocio() << "? (S/N)" << endl << endl;
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			PagoCuota pago(socio.getIdsocio(), totalAPagar, idCuota);
			Fecha fechaActual;
			socio.setDeudor(false);
			socio.setUltimoPago(fechaActual);
			socio.modificarEnDisco(pos);
			flag2 = true;
			cout << " -- Pago registrado correctamente --" << endl;
			anykey();

		}
		else
		{
			cls();
			flag2 = false;
		}

	} while (!flag2);

}

void actualizarEstadoCuotasSocios()
{
	int cantReg = CantidadRegistrosSocio();
	if (cantReg == 0)
	{
		cout << "No hay socios cargados." << endl;
		anykey();
		return;
	}

	Socio* vec = new Socio[cantReg];

	if (vec == NULL)
	{
		cout << "No hay memoria disponible." << endl;
		anykey();
		return;
	}

	copiarSocios(vec, cantReg);
	actualizarCarteraSocios(vec, cantReg);

	cout << "Estado de socios actualizado correctamente" << endl;
	anykey();

	delete vec;
}

void actualizarCarteraSocios(Socio* vec, int cantReg) {

	Fecha fechaActual;

	for (int i = 0; i < cantReg; i++)
	{
		if (vec[i].getEstado())
		{
			if (vec[i].getUltimoPago().getMes() != fechaActual.getMes() && vec[i].getUltimoPago().getDia() >= fechaActual.getDia())
			{
				vec[i].setDeudor(true);
				vec[i].modificarEnDisco(i);
			}
		}
	}
}

void recaudacionPorSocio() {

	int cantReg = CantidadRegistrosSocio();

	if (cantReg == 0) {
		cout << "No hay socios registrados";
		anykey();
		return;
	}

	float* vecRecaudacionSocio = new float[cantReg];
	if (vecRecaudacionSocio == NULL) return;

	ponerCeroVectorRecaudacion(vecRecaudacionSocio, cantReg);
	buscarRecaudacionesPorSocio(vecRecaudacionSocio, cantReg);
	listarRecaudacionesPorSocio(vecRecaudacionSocio, cantReg);

	delete vecRecaudacionSocio;
}
void ponerCeroVectorRecaudacion(float* vecRecaudacion, int tam) {

	for (int i = 0; i < tam; i++) {
		vecRecaudacion[i] = 0;
	}
}
void buscarRecaudacionesPorSocio(float* vecRecaudacion, int tam) {

	int pos = 0;
	PagoCuota cuotas;

	while (cuotas.leerDeDisco(pos++)) {
		int idSocio = cuotas.getIdSocio();
		float recaudacion = cuotas.getImporte();
		vecRecaudacion[idSocio-1] += recaudacion;
	}

	pos = 0;

	PagoSolicitud solicitudesCobros;

	while (solicitudesCobros.leerEnDisco(pos++)) {
		int idSocio = solicitudesCobros.getIdSocio();
		float recaudacion = solicitudesCobros.getImporte();
		vecRecaudacion[idSocio] += recaudacion;
	}

}
void listarRecaudacionesPorSocio(float* vecRecaudacion, int tam) {

	cout << endl << "-----------------------------------";
	cout << endl << "   -- Recaudación Por Socio --                " << endl;
	cout << "-----------------------------------" << endl;

	cout << left;
	cout << setw(11) << "ID SOCIO";
	cout << setw(1) << " ";
	cout << setw(15) << "RECAUDACION" << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < tam; i++) {

		cout << setw(12) << i + 1;
		cout << setw(1) << "$";
		cout << setw(15) << vecRecaudacion[i] << endl;
	}

	cout << "-----------------------------------" << endl;

	anykey();
}

void Informe_Recaudacion_Anual() {

	int Anio = 0;
	const int Meses = 12;
	float* vDinamicoCuota;
	vDinamicoCuota = new float[Meses];
	if (vDinamicoCuota == NULL) return;

	float* vDinamicoSolicitudes;
	vDinamicoSolicitudes = new float[Meses];
	if (vDinamicoSolicitudes == NULL) return;

	PonerEnCeroVector(vDinamicoCuota, Meses);
	PonerEnCeroVector(vDinamicoSolicitudes, Meses);
	cout << "Ingrese el año para  consultar su recaudacion:" << endl;
	cin >> Anio;

	RecaudacionAnualCuota(Anio, vDinamicoCuota, Meses);
	RecaudacionAnualSolictudes(Anio, vDinamicoSolicitudes, Meses);
	MostrarDetalleRecaudacionAnual(vDinamicoCuota, vDinamicoSolicitudes, Meses);

}
void RecaudacionAnualCuota(int anio, float* vec, int tam) {
	PagoCuota aux;
	for (int i = 0; i < tam; i++) {
		if (aux.getFechaPago().getAnio() == anio) {
			aux.leerDeDisco(i);
			vec[aux.getFechaPago().getMes() - 1] += aux.getImporte();
		}
	}
}
void RecaudacionAnualSolictudes(int anio, float* vec, int tam) {
	PagoSolicitud aux;
	int pos = 0;

	while (aux.leerEnDisco(pos)) {
		if (aux.getFechaPago().getAnio() == anio) {
			vec[aux.getFechaPago().getMes() - 1] += aux.getImporte();
		}
	}
}
void PonerEnCeroVector(float* vec, int tam) {
	for (int i = 0; i < tam; i++) 
	{
		vec[i] = 0;
	}
}
void MostrarDetalleRecaudacionAnual(float* vec, float* vec2, int tam) {
	string meses[12] = { "Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
	int totalAnio = 0;
	int totalAnio2 = 0;

	cout << "------------------------------------------------";
	cout << endl<<"\t  -- Recaudación Anual --                " << endl;
	cout << "------------------------------------------------" << endl << endl;
	cout << left;
	cout << setw(11) << "MES";
	cout << setw(1) << " ";
	cout << setw(15) << "REC POR CUOTAS";
	cout << setw(1) << " ";
	cout << setw(10) << "REC POR SOLICITUD" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {

		cout << setw(12) << meses[i];
		cout << setw(1) << "$";
		cout << setw(15) << vec[i];
		cout << setw(1) << "$";
		cout << setw(10) << vec2[i] << endl;
		totalAnio += vec[i];
		totalAnio2 += vec2[i];
		
	}

	cout << "-------------------------------------------------" << endl;
	cout << setw(12) << "Total año";
	cout << setw(1) << "$";
	cout << setw(15) << totalAnio;
	cout << setw(1) << "$";
	cout << setw(5) << totalAnio2 << endl;
	cout << "-------------------------------------------------" << endl;


}