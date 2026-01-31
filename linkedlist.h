#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
using std::cout;
class LinkedList
{
public:
    Node* Head;
    LinkedList();

    void Print(){
        if(Head==nullptr){
            cout<<"The list is empty";
        }
        Node* actual=Head;
        while(actual!=nullptr){
            cout<<"Valor: "<<actual->next<<"--> ";
            actual=actual->next;
        }
    }
    void Insert(int valor){
        if(Head==nullptr){
            Head=new Node(valor);
        }
        Node* actual=Head;
        while (actual->next!=nullptr) {
            actual=actual->next;
        }
        actual->next=new Node(valor);
    }
};

#endif // LINKEDLIST_H
