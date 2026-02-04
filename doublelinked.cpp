#include "doublelinked.h"

DoubleLinked::DoubleLinked(OriginFile* OF) {
    this->Head=new Nodo(OF, nullptr);
}

OriginFile* DoubleLinked::controlarBusqueda(OriginFile* actual, OriginFile* seleccionado) {
   //ubicar el iterador en el *actual
    Nodo* it = Head;
    while (it != nullptr && it->OF != actual) {
        it = it->next;
    }


    if (it == nullptr) {
        return actual;
    }

//si la siguiente busqueda es igual a la que seguia en la DLL
    if (it->next != nullptr && it->next->OF == seleccionado) {
        return it->next->OF;
    }

//Eliminar resto
    Nodo* resto = it->next;
    it->next = nullptr;

    while (resto != nullptr) {
        Nodo* tmp = resto;
        resto = resto->next;
        delete tmp;
    }


    it->next = new Nodo(seleccionado, it);


    return it->next->OF;
}
void DoubleLinked::irAtras(OriginFile* &actual) {
    Nodo* it = Head;
  //Buscar actual
    while (it != nullptr && it->OF != actual) {
        it = it->next;
    }
    if (it != nullptr && it->anterior != nullptr) {
        actual = it->anterior->OF;
    }

}
void DoubleLinked::irAdelante(OriginFile* &actual) {
    Nodo* it = Head;


    while (it != nullptr && it->OF != actual) {
        it = it->next;
    }

    if (it != nullptr && it->next != nullptr) {
        actual = it->next->OF;
    }
}
