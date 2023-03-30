// Practica16FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TList.h"
#include "Equipo.h"
#include "Barcelona.h"
#include "Madrid.h"
#include "Atletico.h"

int main()
{
	std::cout << "ESTE EJERCICIO TRATA A TODOS LOS REFERENCIADOS DE UNA MANERA SIMILAR, UTILIZANDO EL HUMOR PARA TODOS. NO TOMAR EN SERIO LOS NOMBRES :)\n\n\n";

	TList* listaEquipos = new TList();

	CFcBarcelona* obj_FCBarcelona = new CFcBarcelona();
	RealMadrid* obj_RM = new RealMadrid();
	AtMadrid* obj_AtleticoMadrid = new AtMadrid();

	listaEquipos->Push(obj_FCBarcelona);
	listaEquipos->Push(obj_RM);
	listaEquipos->Push(obj_AtleticoMadrid);

	//Se muestran datos de obj_FCBarcelona
	listaEquipos->FirstElement();
	std::cout << listaEquipos->GetElement()->GetTeamName() << " tiene de entrenador a " << listaEquipos->GetElement()->GetMisterName()<<"\n";
	std::cout << "Puntos previo partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n";
	listaEquipos->GetElement()->GanarPartido();
	std::cout << "Puntos actualizado partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n\n\n";

	//Se muestran datos de obj_RM
	listaEquipos->NextElement();
	std::cout << listaEquipos->GetElement()->GetTeamName() << " tiene de entrenador a " << listaEquipos->GetElement()->GetMisterName()<<"\n";
	std::cout << "Puntos previo partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n";
	listaEquipos->GetElement()->GanarPartido();
	std::cout << "Puntos actualizado partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n\n\n";
	


	//Se muestran datos de obj_FCBarcelona
	listaEquipos->FirstElement();
	std::cout << listaEquipos->GetElement()->GetTeamName() << " tiene de entrenador a " << listaEquipos->GetElement()->GetMisterName() << "\n";
	std::cout << "Puntos previo partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n";
	listaEquipos->GetElement()->GanarPartido();
	std::cout << "Puntos actualizado partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n\n\n";

	listaEquipos->NextElement();
	listaEquipos->NextElement();
	//Se muestran datos deobj_AtleticoMadrid
	std::cout << listaEquipos->GetElement()->GetTeamName() << " tiene de entrenador a " << listaEquipos->GetElement()->GetMisterName() << "\n";
	std::cout << "Puntos previo partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n";
	listaEquipos->GetElement()->GanarPartido();
	std::cout << "Puntos actualizado partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n\n\n";
	
	
	//Se muestran datos de obj_FCBarcelona

	listaEquipos->NextElement();
	std::cout << listaEquipos->GetElement()->GetTeamName() << " tiene de entrenador a " << listaEquipos->GetElement()->GetMisterName() << "\n";
	std::cout << "Puntos previo partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n";
	listaEquipos->GetElement()->EmpatarPartido();
	std::cout << "Puntos actualizado partido: " << listaEquipos->GetElement()->GetPointLiga() << "\n\n\n";
	

	std::cout << "\nHello World!\n";
	return 0;
}
