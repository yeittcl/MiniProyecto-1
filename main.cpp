#include <iostream>
#include <deque>
#include <math.h>
#include "nodo.h"
#include "nodoResumen.h"
#include "listarr.h"
using namespace std;

int main()
{
    ListArr* lr = new ListArr();
    lr->insert_left(0);
    lr->insert_left(1);
    lr->insert_left(2);
    lr->insert_left(3);
    lr->insert_left(4);
    lr->insert(1,9);
    lr->insert_right(-1);
    lr->print();
    cout<<lr->find(1)<<endl;

    return 0;
}