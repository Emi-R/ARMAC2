#pragma once

#include <iostream>
using namespace std;

class Fecha
{
private:
	int _dia, _mes, _anio;

public:
	//Constructor
	Fecha();

	// Setters
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	//Getters
	int getDia();
	int getMes();
	int getAnio() ;

	//CARGAR Y MOSTRAR

	void cargarFecha();
	void mostrarFecha();
};

bool validaDia(int mes, int dia, int anio);