#ifndef DOUBLELINKED_H
#define DOUBLELINKED_H
#include "nodo.h"
#include "originfile.h"
class DoubleLinked
{
public:
    DoubleLinked(OriginFile* OF);
    DoubleLinked() { Head = nullptr; }
    Nodo* Head;

    OriginFile* controlarBusqueda(OriginFile* actual,OriginFile* seleccionado);
    void irAtras(OriginFile* &actual);
    void irAdelante(OriginFile* &actual);
};

#endif // DOUBLELINKED_H
