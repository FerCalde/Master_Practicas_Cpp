#pragma once
#include "Equipo.h"

class AtMadrid : public IEquipo
{

public:
	AtMadrid();
	~AtMadrid();

	virtual const char* GetTeamName() override;
	virtual const char* GetMisterName() override;
	virtual int GetPointLiga() override;
	virtual void GanarPartido() override;
	virtual void EmpatarPartido() override;
};