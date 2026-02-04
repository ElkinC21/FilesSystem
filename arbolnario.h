#ifndef ARBOLNARIO_H
#define ARBOLNARIO_H
#include "directory.h"
#include "originfile.h"
#include "nodo.h"
class ArbolNario
{
public:
    ArbolNario();
    OriginFile* root;
    void InsertarHijo(OriginFile* actual,OriginFile* nuevohijo);
};

#endif // ARBOLNARIO_H
