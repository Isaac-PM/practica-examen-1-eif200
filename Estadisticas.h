#pragma once
#include "Accesorio.h"

class Estadisticas
{
private:
	float amistad;
	float dannoFisico;
	float dannoEspecial;
	float defensaFisica;
	float defensaEspecial;
public:
	Estadisticas(
		float = 0.0f,
		float = 0.0f,
		float = 0.0f,
		float = 0.0f,
		float = 0.0f
	);
	float getAmistad() const;
	void setAmistad(float);
	float getDannoFisico() const;
	void setDannoFisico(float);
	float getDannoEspecial() const;
	void setDannoEspecial(float);
	float getDefensaFisica() const;
	void setDefensaFisica(float);
	float getDefensaEspecial() const;
	void setDefensaEspecial(float);
	void aumentarEstadisticas(float);
	void aumentarConAccesorio(Accesorio*);
	string toString();
	~Estadisticas() = default;
};

