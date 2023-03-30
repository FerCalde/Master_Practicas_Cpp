// Practica10FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileUtils.h"
#include "TList.h"

int main()
{
    std::cout << "Hello World!\n";
    FileUtils::TList* miLista = FileUtils::RetornarTListConCadenaDeFile();


    std::cout << "Hello World!\n";

    //myTList = FileUtils::RetornarTListConCadenaDeFile();
    std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
}
