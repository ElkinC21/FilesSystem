#include "controlador.h"
#include "arbolnario.h"
using std::to_string;
Controlador::Controlador() {
    this->actual=this->Arbolinho.root;
    this->historial=DoubleLinked(this->actual);

}
bool Controlador::crearHijo(string name, bool isDir) {
    //Validar si es Dir
    if (this->actual == nullptr || !this->actual->getIsDir()) {
        return false;
    }

   //Contar nombre repetido
    Directory* dirActual = dynamic_cast<Directory*>(this->actual);

    string nameFinal = name;
    int contador = 1;
    bool nombreRepetido = true;


    while (nombreRepetido) {
        nombreRepetido = false;


        for (OriginFile* hijo : dirActual->hijos) {
            if (hijo->getName() == nameFinal) {
                nombreRepetido = true;
                break;
            }
        }

        if (nombreRepetido) {
            nameFinal = name + " (" + std::to_string(contador) + ")";
            contador++;
        }
    }

    //Datos
    QDateTime ahora = QDateTime::currentDateTime();
    string nuevoPath = this->actual->getpath() + "/" + nameFinal;
    int sizeInicial = 0;


    OriginFile* nuevo = nullptr;
    if (isDir) {
        nuevo = new Directory(nameFinal, ahora, ahora, true, nuevoPath, QDateTime(), sizeInicial);
    } else {
        nuevo = new File(nameFinal, ahora, ahora, false, nuevoPath, QDateTime(), sizeInicial);
    }

    //Llamada a arbol
    ArbolNario a;
    a.InsertarHijo(this->actual, nuevo);

    return true;
}
