#pragma once
#include <iostream>

class Nodo
{
    private:
        Nodo* next;
        int* data;
        int actualSize;
        int maxSize;
    public:
        Nodo(Nodo* next);
        void setNext(Nodo* next);
        Nodo* getNext();
        void add(int index, int element);
        int getValueAt(int index);
        bool isFull();
        int size();
        int totalSize();
        void print();
};