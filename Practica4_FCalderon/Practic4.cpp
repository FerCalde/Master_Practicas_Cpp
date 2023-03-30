// practica4.cpp
//
#include <stdio.h>
#include "consola.h" //asi pa los archivos que metemos nosotros


struct TEntity;
typedef void (*FUNC_ENTITY)(TEntity*);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
    int m_ix;
    int m_iy;
    FUNC_ENTITY* m_funcs;

    TEntity(FUNC_ENTITY* funcs, int x, int y)
    {
        m_ix = x;
        m_iy = y;
        m_funcs = funcs;

        //Pintar

        //Tiempo delay

        //Mover

    }
};


void CheckLimits(TEntity* _pEntity) {
    if (_pEntity->m_ix >= 30)
    {
        _pEntity->m_ix = 0;
    }
}


void DrawA(TEntity* _pEntity) {
    gotoxy(_pEntity->m_ix, _pEntity->m_iy);
    printf("A");
}
void DrawB(TEntity* _pEntity) {
    gotoxy(_pEntity->m_ix, _pEntity->m_iy);
    printf("B");
}

void MoveRight(TEntity* _pEntity)
{
    _pEntity->m_ix++;
}
void MoveLeft(TEntity* _pEntity)
{
    _pEntity->m_ix--;
}
void MoveDown(TEntity* _pEntity)
{
    _pEntity->m_iy--;
}
void MoveUp(TEntity* _pEntity)
{
    _pEntity->m_iy++;
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main()
{
    //Alocada en Stack
    FUNC_ENTITY oFunc01[2] =
    { &DrawA, &MoveRight };

    //Alocada en Heap
    FUNC_ENTITY* pFunc02 = new FUNC_ENTITY[2];
    pFunc02[0] = &DrawB;
    pFunc02[1] = &MoveLeft;




    TEntity aEntities[] =
    {
        TEntity(oFunc01, 15, 12),
        TEntity(pFunc02, 16, 3)
    };

    unsigned int const uNumEntities = sizeof(aEntities) / sizeof(TEntity);
    while (true)
    {
        /*for (unsigned int uIndex = 0; uIndex < )
        {

        }*/



        for (TEntity& rEntity : aEntities) //Esta crea copias, se debe poner el & para que se muevan
        {
            //Move
            (*rEntity.m_funcs[1])(&rEntity);
            //(*(rEntity.m_funcs+1))(&rEntity);
           
            //CheckLimits(&rEntity);

            //Draw
            (*rEntity.m_funcs[0])(&rEntity);

        }


        hidecursor();
        Sleep(500);
        clear();
    }

   // TEntity oEntity01(oFunc01, 15, 12);
    //TEntity oEntity02(pFunc02, 16, 3);


    //SIEMPRE QUE HAGO NEW TENGO QUE HACER DELETE!
    delete[] pFunc02;
}

