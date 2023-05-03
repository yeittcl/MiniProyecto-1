#pragma once
#include "nodo.h"
#include "nodoResumen.h"
#include <iostream>
#include <deque>
using namespace std;

class ListArr
{
    private:
        int actualSize;
        int maxSize;
        int numActualNodos;
        NodoResumen* root;
        Nodo* head;
        deque<NodoResumen*> arbol;
    public:
        ListArr();
        ~ListArr();
        int sizeNodos();
        void crearArbol();
        int size();
        void insert(int index, int element);
        void insert_left(int element);
        void insert_right(int element);
        void print();
        bool find(int element);
};