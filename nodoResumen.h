#pragma once
#include <iostream>
#include "nodo.h"

class NodoResumen
{
    private:
        NodoResumen* left;
        NodoResumen* right;
        Nodo* son;
        int capacity;
        int maxCapacity;
    public:
        NodoResumen(NodoResumen* left, NodoResumen* right, int capacity, int maxCapacity);
        NodoResumen(NodoResumen* left, NodoResumen* right);
        NodoResumen(int capacity, int maxCapacity);
        NodoResumen(Nodo* son, int capacity, int maxCapacity);
        void setLeft(NodoResumen* left);
        void setRight(NodoResumen* right);
        void setSon(Nodo* son);
        NodoResumen* getLeft();
        NodoResumen* getRight();
        Nodo* getSon();
        void setCapacity(int capacity);
        void setMaxCapacity(int maxCapacity);
        int getCapacity();
        int getMaxCapacity();

};