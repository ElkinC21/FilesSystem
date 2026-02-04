#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "nodo.h"
#include "originfile.h"
#include "directory.h"
#include "file.h"
#include "doublelinked.h"
#include "arbolnario.h"
class Controlador
{
public:
    Controlador();
    ArbolNario Arbolinho;
    DoubleLinked historial;

    OriginFile* actual;
    bool crearHijo(string nombreBase, bool isDir);
};

#endif // CONTROLADOR_H
