//#include <iostream>
//
//using namespace std;
//
//class CBaseVirtual
//{
//public:
//    CBaseVirtual() { }
//    virtual ~CBaseVirtual() { cout << "CBaseVirtual destructor" << endl; }// Destructor virtual en la clase base
//    virtual void bar() { cout << "CBaseVirtual virtual BAR" << endl; }// Función virtual fun11 en la clase base
//    virtual void qux() { cout << "CBaseVirtual virtual QUX" << endl; }// Función virtual fun11 en la clase base
//
//};
//
//
//class CDerivadaVirtual :public CBaseVirtual
//{
//    int iData;
//public:
//    CDerivadaVirtual() { iData = 0; }
//    virtual ~CDerivadaVirtual() { cout << "CDerivadaVirtual destructor" << endl; }// Destructor virtual en clases derivadas
//    virtual void bar() override { cout << "CDerivadaVirtual virtual BAR override" << endl; }// Override de bar en CBase
//    virtual void qux() override { cout << "CDerivadaVirtual virtual QUX override" << endl; }// Override de qux en CBase
//};
//
//
//class CNoVirtual
//{
//public:
//    CNoVirtual() {}
//    ~CNoVirtual() { cout << "CNoVirtual destructor" << endl; }
//    void foo() { cout << "CNoVirtual NO Virtual foo" << endl; }
//
//};
//
//
//int main()
//{
//    CBaseVirtual obj_CBaseVirtual;
//    CDerivadaVirtual obj_CDerivadaVirtual;;
//    CNoVirtual obj_NoVirtual;
//
//    cout << "obj_CBaseVirtual Size = " << sizeof(obj_CBaseVirtual) << endl;
//    cout << "CDerivadaVirtual Size = " << sizeof(obj_CDerivadaVirtual) << " He incluido var Int (+4bytes) para modificar y revisar los datos obtenidos" << endl;
//    cout << "obj_NoVirtual Size = " << sizeof(obj_NoVirtual) << endl << endl;
//
//
//    return 0;
//}