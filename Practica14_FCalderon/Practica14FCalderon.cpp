// Practica14FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class CBaseVirtual
{
public:
	CBaseVirtual() {
		//14.D
		qux();
		cout << "CBaseVirtual constructor\n\n" << endl;
	}
	virtual ~CBaseVirtual() { cout << "CBaseVirtual destructor" << endl; }// Destructor virtual en la clase base
	virtual void bar() { cout << "CBaseVirtual virtual BAR" << endl; }// Función virtual fun11 en la clase base
	virtual void qux() { cout << "CBaseVirtual virtual QUX" << endl; }// Función virtual fun11 en la clase base

};

class CDerivadaVirtual :public CBaseVirtual
{

public:
	int m_data;
	CDerivadaVirtual() { 
		//14.C
		m_data = 0;

		//14.D-
		bar();
		cout << "CDerivadaVirtual constructor\n\n" << endl;
	}
	virtual ~CDerivadaVirtual() { cout << "CDerivadaVirtual destructor" << endl; }// Destructor virtual en clases derivadas
	virtual void bar() override { cout << "CDerivadaVirtual virtual BAR override" << endl; }// Override de bar en CBase
	virtual void qux() override { cout << "CDerivadaVirtual virtual QUX override" << endl; }// Override de qux en CBase
};

class CNoVirtual
{
public:
	CNoVirtual() {}
	~CNoVirtual() { cout << "CNoVirtual destructor" << endl; }
	void foo() { cout << "CNoVirtual NO Virtual foo" << endl; }

};


void EjercicioB();
void EjercicioC();
void EjercicioE();

int main()
{
	cout << "-EJERCICIO B-\n\n\n";
	EjercicioB();


	cout << "\n\n\n\n-EJERCICIO C-\n\n\n";
	EjercicioC();


	cout << "\n\n\n\n-EJERCICIO C-\n\n\n";
	EjercicioE();

	return 0;
}


void EjercicioB()
{
	CDerivadaVirtual obj_CDerivadaVirtual;

	// Obtener el puntero de la tabla virtual 
	int* pAuxVTable = reinterpret_cast<int*>(&obj_CDerivadaVirtual);
	int** pVirtualTable = reinterpret_cast<int**>(&obj_CDerivadaVirtual);

	// cout << "CDerivadaVirtual Address = " << (int*)&obj_CDerivadaVirtual << endl; //Hacce un cast a int.
	cout << "CDerivadaVirtual Address = \n";
	cout << "\tCDerivadaVirtual Address a traves de  (&obj_CDerivadaVirtual)= " << &obj_CDerivadaVirtual << endl;
	cout << "\tCDerivadaVirtual Address a traves de (pAuxVTable)= " << pAuxVTable << endl;
	cout << "\tCDerivadaVirtual Address a traves de (pVirtualTable)= " << pVirtualTable << endl;
	cout << "\tCDerivadaVirtual Address a traves de (*&PVirtualTable)= " << *&pVirtualTable << endl << endl;


	cout << "vTable Address = \n";
	cout << "\tvTable Address a traves de  ((*pVirtualTable))=" << (*pVirtualTable) << endl;
	printf("\tvTable Address a traves de  (reinterpret_cast<int>(*pVirtualTable))=  %08X\n", reinterpret_cast<int>(*pVirtualTable));
	cout << "\tvTable Address a traves de  ((reinterpret_cast<int*>(*pAuxVTable) ))=" << (reinterpret_cast<int*>(*pAuxVTable)) << endl;
	cout << "\tvTable Address a traves de  (((int*)*(pAuxVTable) ))=" << ((int*)*(pAuxVTable)) << endl << endl; //Hacce un cast por dentro. Similar a linea anterior
}


void EjercicioC()
{
	CBaseVirtual obj_CBaseVirtual;
	CDerivadaVirtual obj_CDerivadaVirtual;;
	CNoVirtual obj_NoVirtual;

	cout << "obj_CBaseVirtual Size = " << sizeof(obj_CBaseVirtual) << endl;
	cout << "CDerivadaVirtual Size = " << sizeof(obj_CDerivadaVirtual) << " He incluido var Int (+4bytes) para modificar y revisar los datos obtenidos" << endl;
	cout << "obj_NoVirtual Size = " << sizeof(obj_NoVirtual) << endl << endl;
}

void EjercicioE()
{
	CBaseVirtual obj_CBaseVirtual;
	CDerivadaVirtual obj_CDerivadaVirtual;;
	CNoVirtual obj_NoVirtual;

	cout << "obj_CBaseVirtual llamar a funciones\n";
	obj_CBaseVirtual.qux();
	obj_CBaseVirtual.bar();
	
	obj_CBaseVirtual.~CBaseVirtual(); //lo destruyo (Aunque se haria solo antes de salir del scope de func EjercicioD


	cout << "\n\nobj_CDerivadaVirtual llamar a funciones\n";
	obj_CDerivadaVirtual.qux();
	obj_CDerivadaVirtual.bar();
	
	obj_CDerivadaVirtual.~CDerivadaVirtual();

	cout << "\n\nobj_NoVirtual llamar a funciones\n";
	obj_NoVirtual.foo();

	obj_NoVirtual.~CNoVirtual();

}

//RESPUESTAS: Las pruebas fueron REALIZADAS EN 32Bits (x86)

//14.A-
//(4Byte* Num Funciones) La tabla de funciones virtuales es una tabla que almacena la direccion de memoria de todas las funciones virtuales de una clase, por lo que ocupa un slot de 4 Byte por cada funcion virtual que almacena (4Byte* Num Funciones)
// Esta conclusion la he sacado de pensar que debe hacer aritmetica de punteros con el ptrVtable que incluye el compilador en la clase base. Tras hacer el ejercicio 4, he visto que el puntero ocupa 4Bytes (por los casteos a int..). Por lo tanto, la vTable debe multiplicar el numero de funciones que tiene por el tamaño de ptrVtable 
//
// 
//14.B-
// vTable se crea en tiempo de compilacion por el compilador, además el compilador crea un Puntero (por cada VTable y en cada clase, obtiene su logica con el apartado siguiente) que contiene la direccion de memoria de la vTable en cada clase.
// La vTable se crea en una zona estatica de memoria, lo que he deducido tras repetir varias pruebas con debugs y aparecer todo el rato la misma posicion de memoria para la vTable. (Solo cambia de direccion cuando hago una modificacion de la clase como añadir una variable o cambiar de una variable su tipo
// 
// 
//14.C-
// vTable tiene un puntero oculto (a.k.a. ptrVTable) que crea el compilador para apuntar a la tabla virtual. Este puntero tiene un tamaño de 4Bytes (Ha sido comprobado con una clase que tenia un metodo virtual y una clase con un metodo No virtual.  
//
// 
//14.D-
// Cuando se implementa una funcion virtual en los constructores, se ejecuta la mas actualizada. En el caso de la derivada, se ejecuta la funcion BAR overrideada mientras que QUX (solo llamada en constructor de CBase) reproduce el codigo de dicha clase.
// 
// 
// 14.E-
//Lo que hace el compilador por dentro es una aritmetica de punteros con la que recorre el vTable de cada clase. Por lo tanto, los pasos extras son los comentados anteriormente y ahora recopilados:
//     -Creacion de vTable para la clase
//     -Asignacion de vPtr a la instancia de una clase
//     -vPtr se incluye oculto por el compilador
//     -Artimetica de puntero en vTable para llamar a la funcion correcta
//	
// 
//
//


