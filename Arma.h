#pragma once
#include "Pais.h"

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

	bool leerDeDisco(int pos);

	int generarId();
	bool buscarArmaPorID(int id);

};

