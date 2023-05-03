#include <iostream>
#include "nodoResumen.h"

NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right,int capacity, int maxCapacity)
{
    this->son = nullptr;
    this->left = left;
    this->right = right;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(int capacity, int maxCapacity)
{
    this->son = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(Nodo *son, int capacity, int maxCapacity)
{
    this->son = son;
    this->left = nullptr;
    this->right = nullptr;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right)
{
    this->son = nullptr;
    this->left = left;
    this->right = right;
    this->capacity = 0;
    this->maxCapacity = 0;

}

void NodoResumen::setLeft(NodoResumen *left)
{
    this->left = left;
}

void NodoResumen::setRight(NodoResumen *right)
{
    this->right = right;
}

void NodoResumen::setSon(Nodo *son)
{
    this->son = son;
}

NodoResumen *NodoResumen::getLeft()
{
    return left;
}

NodoResumen *NodoResumen::getRight()
{
    return right;
}

Nodo *NodoResumen::getSon()
{
    return son;
}

void NodoResumen::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void NodoResumen::setMaxCapacity(int maxCapacity)
{
    this->maxCapacity = maxCapacity;
}

int NodoResumen::getCapacity()
{
    return capacity;
}

int NodoResumen::getMaxCapacity()
{
    return maxCapacity;
}
