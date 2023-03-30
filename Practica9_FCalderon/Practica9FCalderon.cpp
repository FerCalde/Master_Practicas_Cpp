#pragma once
#include "TList.h"


int main()
{

    TList* miLista = new TList();
    int auxPorDevolverInt = 0;
   // std::cout << "Lista creada!\n"<<"\tEsta lista tiene: "<< miLista->ElementsCounter() <<" Elementos (NUEVA)"<< "\n";
    
    //std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    auxPorDevolverInt=miLista->Push("Hola");
    auxPorDevolverInt= miLista->Push("mi");
    auxPorDevolverInt = miLista->Push("nombre");
    auxPorDevolverInt = miLista->Push("es");
    auxPorDevolverInt = miLista->Push("Fer");
    auxPorDevolverInt = miLista->Push(" ");

   // std::cout << "Lista creada!\n"<<"\tEsta lista tiene: "<< miLista->ElementsCounter() <<" Elementos"<< "\n";

    
    //std::cout << "\tEsta lista tiene: "<< miLista->ElementsCounter() <<" Elementos"<< "\n";
    
    std::cout << "\tEl primer elemento es ["<< miLista->FirstElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    
    std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";

    std::cout << "\n\tEl primer elemento es ["<< miLista->FirstElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";

    std::cout << "\nVoy a sacar el primer Elemento que es ["<< miLista->Pop() <<"]\n";

    std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
    std::cout << "\n\tEl primer elemento es ["<< miLista->FirstElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";
    std::cout << "\tEl Siguiente elemento es ["<< miLista->NextElement() <<"]"<< "\n";



    std::cout << "\nElimino todos los Elementos con Reset()\n";
    miLista->Reset();



    std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
    std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";

    
    
    
    std::cout << "\nMeto nuevos elementos a la lista\n";
    auxPorDevolverInt = miLista->Push("Adios");
    auxPorDevolverInt = miLista->Push("mi");
    auxPorDevolverInt = miLista->Push("nombre");
    auxPorDevolverInt = miLista->Push("Cambio");
    auxPorDevolverInt = miLista->Push("Marta");
    auxPorDevolverInt = miLista->Push(" ");


    std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
    std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
    std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";

    std::cout << "\nHello World!\n";



    //TList miLista;
    //int auxSuda = 0;
    ////std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << "Elementos (NUEVA)" << "\n";

   
    //std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << " Elementos" << "\n";


    //std::cout << "Hello World!\n";

    //miLista.Push("t");
    //miLista.Push("s");
    //std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << " Elementos" << "\n";



    return 0;
}
