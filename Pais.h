#pragma once
class Pais
{
private:
	int _IdPais;
	char  _Nombre[50];
	bool  _Estado;
public:
	Pais();

	/// Setters
	void setNombre(const char* nombre);
	void setEstado(bool estado);
	void setId(int idpais);

	/// Getters
	int getIdPais();
	const char* getNombre();
	bool getEstado();

	//Cargar y Mostrar
	void CargarPais();
	void MostrarPais();

};