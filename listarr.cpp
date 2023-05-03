#include "listarr.h"
#include "nodo.h"
#include "nodoResumen.h"
#include <iostream>
#include <deque>
using namespace std;

ListArr::ListArr()
{
    this->head = new Nodo(nullptr);
    this->actualSize = 0;
    this->maxSize = 0;
    this->numActualNodos = 0;
}

ListArr::~ListArr()
{
    delete head;
    delete root;
}

int ListArr::sizeNodos()
{
    Nodo* actual = head;
    int numNodos = 0;
    while(actual != nullptr)
    {
        numNodos++;
        actual = actual->getNext();
    }
    numActualNodos = numNodos;
    return numNodos;
}

void ListArr::crearArbol()
{
    Nodo* actual = head;
    arbol.clear();
    while (actual != nullptr)
    {
        NodoResumen* ref = new NodoResumen(actual,actual->size(),actual->totalSize());
        arbol.push_back(ref);
        actual = actual->getNext();
    }
    if(head->getNext() == nullptr) arbol.push_back(nullptr);
    while(arbol.size()>1)
    {
        if(arbol.size()%2 != 0)
        {
            arbol.push_back(nullptr);
        }
        int maxNodosPerLevel = arbol.size()/2;
        for(int i=0; i<maxNodosPerLevel; i++)
        {
            NodoResumen* left = arbol.front();
            arbol.pop_front();
            NodoResumen* right = arbol.front();
            arbol.pop_front();
            if(right == nullptr)
            {
                NodoResumen* padre = new NodoResumen(left, right, left->getCapacity(), left->getMaxCapacity()*2);
                arbol.push_back(padre);
                continue;
            }
            NodoResumen* padre =new NodoResumen(left, right, left->getCapacity()+right->getCapacity(), left->getMaxCapacity()*2);
            arbol.push_back(padre);
        }
    }
    root = arbol.front();
    actualSize = arbol.front()->getCapacity();
    maxSize = arbol.front()->getMaxCapacity();

}

int ListArr::size()
{
    return actualSize;
}

void ListArr::insert(int index, int element)
{
    if(numActualNodos != sizeNodos())
    {
        crearArbol();
    }
    if(index>actualSize)
    {
        cout<<"Numero invalido"<<endl;
    }
    NodoResumen* actual = arbol.front();
    while(actual->getSon() == nullptr)
    {
        if(actual->getLeft()->getCapacity() >= index)
        {
            actual = actual->getLeft();
            continue;
        }else
        {
            index = index - actual->getLeft()->getCapacity();
            actual = actual->getRight();
            continue;
        }
    }
    
    actual->getSon()->add(index,element);
}

void ListArr::insert_left(int element)
{
    insert(0,element);
}

void ListArr::insert_right(int element)
{
    insert(actualSize-1, element);
}

void ListArr::print()
{
    Nodo* actual = head;
    while(actual != nullptr)
    {
        actual->print();
        actual = actual->getNext();
    }
}

bool ListArr::find(int element)
{
    Nodo* actual = head;
    while(actual != nullptr)
    {
        for(int i =0; i< actual->size(); i++)
        {
            if (actual->getValueAt(i) == element)
            {
                return true;
            }
        }
        actual = actual->getNext();
    }
    return false;
}
