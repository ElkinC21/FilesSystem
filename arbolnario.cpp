#include "arbolnario.h"

ArbolNario::ArbolNario() {
    this->root=new Directory("", QDateTime(), QDateTime(), true, "", QDateTime(),0);
}
void ArbolNario::InsertarHijo(OriginFile* padre, OriginFile* nuevoHijo) {

    Directory* dir = dynamic_cast<Directory*>(padre);
    if (dir != nullptr) {
        dir->hijos.push_back(nuevoHijo);
    }
}
