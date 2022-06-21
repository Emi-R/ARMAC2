#pragma once

#include <iomanip>
#include "Pais.h"
#include "rlutil.h"

class Arma
{
private:
	int _idArma;
	char _modelo[30];
	float _calibre;
	int _idPaisFabricacion;
	int _tipoArma;
	int _numSerie;
	bool _estado;

public:
	Arma(int idArma = 0, const char* modelo = "", float calibre = 0, int tipoArma = 0, int numSerie = 0, bool estado = 0, int _idPais = 0);

	void setIdArma(int idArma);
	void setModelo(const char* modelo);
	void setCalibre(float _calibre);
	void setidPaisFabricacion(int _idPaisFabricacion);
	void setTipoArma(int tipoArma);
	void setNumSerie(int numSerie);
	void setEstado(bool estado);

	int getIdArma();
	const char* getModelo();
	float getCalibre();
	int  getidPaisFabricacion();
	int getTipoArma();
	int getNumSerie();
	bool getEstado();

	void cargarArma();
	void mostrarArma();
	void listar();
	void listarPorNumSerie();
	void listarPorTipoArma();
	void listarPorTipoCalibre();
	void listarPorIdArma();

	bool leerDeDisco(int pos);
	bool grabarEnDisco();
	bool modificarEnDisco(int pos);
};

/////////////////////////////////////
// Funciones globales Armas
/////////////////////////////////////

int generarIdArma();

int checkArchivoArmas();

int buscarArmaPorId(int );

void crear_nueva_arma();
void eliminarArma(int idArma);
void modificar_arma();

void listadoGeneralArmas();

void listado_armas_por_pais();

int buscarArmaPorId(int idArma);

void listadoDeArmasPorNumDeSerie();
int buscarCantidadArmas();
void copiarArmas(Arma* vArma, int tam);
void ordernarVecPorNumSerie(Arma* vArma, int tam);
void mostrarListadoArmas(Arma* vArma, int tam);

void listados_Armas_Por_Tipo();
int CantidadRegistroArmas();
void ordenarVector(Arma* vec, int tam);
void MostrarVector(Arma* vec, int tam);

void consultaArmasPorNumSerie();
void mostrarConsultaArmasPorNumSerie(Arma* vecArma, int tamVec, int numSerie);

void consultaArmasPorIdArma();
void mostrarConsultaArmasPorId(Arma* vecArma, int tamVec, int numId);

void listados_Armas_Por_Calibre();
void ordenarVectorPorCalibre(Arma* vec, int tam);
void MostrarVectorPorCalibre(Arma* vec, int tam);

void ModificarModelo(Arma aux, int pos);

void ModificarCalibre(Arma aux,int pos);

void ModificarPais(Arma aux, int pos);

void ModificarNumSerie(Arma aux, int pos);

void porcentaje_armas_por_tipo();