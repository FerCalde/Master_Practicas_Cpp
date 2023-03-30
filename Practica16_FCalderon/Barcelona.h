#pragma once
#include "Equipo.h"
class CFcBarcelona: public IEquipo
{
public:

	CFcBarcelona();
	~CFcBarcelona() ;

	virtual const char* GetTeamName() override;
	virtual const char* GetMisterName() override;
	virtual int GetPointLiga() override;
	virtual void GanarPartido() override;
	virtual void EmpatarPartido() override;

private:

};
