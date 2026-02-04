#ifndef NODO_H
#define NODO_H
#include <string>
#include "originfile.h"
using std::string;
class Nodo
{
public:
    Nodo(OriginFile* OF, Nodo* anterior);
    Nodo* next;
    Nodo* anterior;
    OriginFile* OF;
};

#endif // NODO_H
