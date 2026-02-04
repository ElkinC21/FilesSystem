#include "nodo.h"

Nodo::Nodo(OriginFile* OF,Nodo* anterior) {
    this->OF=OF;
    this->next=nullptr;
    this->anterior=anterior;
}
