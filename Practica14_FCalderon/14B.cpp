//#include <iostream>
//
//using namespace std;
//
//class CBaseVirtual
//{
//public:
//	CBaseVirtual() { }
//	virtual ~CBaseVirtual() { cout << "CBaseVirtual destructor" << endl; }// Destructor virtual en la clase base
//	virtual void bar() { cout << "CBaseVirtual virtual BAR" << endl; }// Función virtual fun11 en la clase base
//	virtual void qux() { cout << "CBaseVirtual virtual QUX" << endl; }// Función virtual fun11 en la clase base
//
//};
//
//class CDerivadaVirtual :public CBaseVirtual
//{
//public:
//	CDerivadaVirtual() {  }
//	virtual ~CDerivadaVirtual() { cout << "CDerivadaVirtual destructor" << endl; }// Destructor virtual en clases derivadas
//	virtual void bar() override { cout << "CDerivadaVirtual virtual BAR override" << endl; }// Override de bar en CBase
//	virtual void qux() override { cout << "CDerivadaVirtual virtual QUX override" << endl; }// Override de qux en CBase
//};
//
//class CNoVirtual
//{
//public:
//	CNoVirtual() {}
//	~CNoVirtual() { cout << "CNoVirtual destructor" << endl; }
//	void foo() { cout << "CNoVirtual NO Virtual foo" << endl; }
//
//};
//
//int main()
//{
//	CDerivadaVirtual obj_CDerivadaVirtual;;
//
//	// Obtener el puntero de la tabla virtual 
//	int* pAuxVTable = reinterpret_cast<int*>(&obj_CDerivadaVirtual);
//	int** pVirtualTable = reinterpret_cast<int**>(&obj_CDerivadaVirtual);
//
//	// cout << "CDerivadaVirtual Address = " << (int*)&obj_CDerivadaVirtual << endl; //Hacce un cast a int.
//	cout << "CDerivadaVirtual Address = \n";
//	cout << "\tCDerivadaVirtual Address a traves de  (&obj_CDerivadaVirtual)= " << &obj_CDerivadaVirtual << endl;
//	cout << "\tCDerivadaVirtual Address a traves de (pAuxVTable)= " << pAuxVTable << endl;
//	cout << "\tCDerivadaVirtual Address a traves de (pVirtualTable)= " << pVirtualTable << endl;
//	cout << "\tCDerivadaVirtual Address a traves de (*&PVirtualTable)= " << *&pVirtualTable << endl << endl;
//
//
//	cout << "vTable Address = \n";
//	cout << "\tvTable Address a traves de  ((*pVirtualTable))=" << (*pVirtualTable) << endl;
//	printf("\tvTable Address a traves de  (reinterpret_cast<int>(*pVirtualTable))=  %08X\n", reinterpret_cast<int>(*pVirtualTable));
//	cout << "\tvTable Address a traves de  ((reinterpret_cast<int*>(*pAuxVTable) ))=" << (reinterpret_cast<int*>(*pAuxVTable)) << endl;
//	cout << "\tvTable Address a traves de  (((int*)*(pAuxVTable) ))=" << ((int*)*(pAuxVTable)) << endl << endl; //Hacce un cast por dentro. Similar a linea anterior
//
//	return 0;
//}
