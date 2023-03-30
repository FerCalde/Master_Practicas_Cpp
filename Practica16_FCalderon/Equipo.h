#pragma once
#include<iostream>

class IEquipo
{
protected:
    const char* m_ptrTeamName;
    const char* m_ptrMisterName;
    int m_iPuntosLiga;
public:
    /*IEquipo();
    virtual ~IEquipo();*/

    virtual const char* GetTeamName() = 0;
    virtual const char* GetMisterName() = 0;
    virtual int GetPointLiga() = 0;
    virtual void GanarPartido() = 0;
    virtual void EmpatarPartido() = 0;
};
//
//IEquipo::IEquipo()
//{
//  /*  m_ptrTeamName = "Default Team";
//    m_ptrMisterName = "Default Mister";
//    m_iPuntosLiga = 0;*/
//}
//
//IEquipo::~IEquipo()
//{
//    /*std::cout << "Destruido Equipo Default";
//    delete m_ptrTeamName;
//    m_ptrTeamName = nullptr;
//    delete m_ptrMisterName;
//    m_ptrMisterName = nullptr;
//    delete m_iPuntosLiga;
//    m_iPuntosLiga = nullptr;*/
//}
//
////void IEquipo::GanarPartido()
////{
////    m_iPuntosLiga += 3;
////}
////void IEquipo::EmpatarPartido()
////{
////    m_iPuntosLiga += 3;
////}
////const char* IEquipo::GetTeamName()
////{
////    return m_ptrTeamName;
////}
////
////const char* IEquipo::GetMisterName()
////{
////    return m_ptrMisterName;
////}
////
////int IEquipo::GetPointLiga()
////{
////    return *m_iPuntosLiga;
////}