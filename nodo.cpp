#include "nodo.h"
#include <iostream>
using namespace std;

Nodo::Nodo(Nodo *next)
{
    this->next = next;
    this->maxSize = 2;
    this->data = new int[maxSize-1];
    this->actualSize = 0;
}

void Nodo::setNext(Nodo *next)
{
    this->next = next;
}

Nodo *Nodo::getNext()
{
    return next;
}

void Nodo::add(int index, int element)
{
    bool reciencreado;
    if (isFull())
    {
        if (next == nullptr)
        {
            next = new Nodo(nullptr);
            next->add(0, data[actualSize-1]);
            reciencreado = true;
        }
        if (next->isFull())
        {
            Nodo* nodoIntermedio = new Nodo(next);
            setNext(nodoIntermedio);
            next->add(0,data[actualSize-1]);
        }else
        {
            if(reciencreado == false){
            next->add(0,data[actualSize-1]);
            }
        }

    }
    reciencreado = false;
    
    for(int i = actualSize; i>index; i--)
    {
        data[i] = data[i-1];
    }
    data[index] = element;
    

    if(!isFull()){
      actualSize++; 
    } 
}

int Nodo::getValueAt(int index)
{
    return data[index];
}

bool Nodo::isFull()
{
    if(actualSize == maxSize){
        return true;
    } 
    return false;
}

int Nodo::size()
{
    return actualSize;
}

int Nodo::totalSize()
{
    return maxSize;
}

void Nodo::print()
{
    for(int i=0; i<actualSize; i++)
    {
        cout<<data[i]<<" ";
    }
}
