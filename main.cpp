#include <iostream>
#include <chrono>
#include "nodo.h"
#include "nodoResumen.h"
#include "listarr.h"
using namespace std;
typedef chrono::milliseconds MSEC;
typedef chrono::high_resolution_clock HRC;

int main()
{
    int num_datos = 10000;
    ListArr* lr = new ListArr();
    auto start = HRC::now();

    for(int i = 0; i<num_datos; i++){
        lr->insert_left(i);
    }

    auto end = HRC::now();
    auto exect_time = chrono::duration_cast<MSEC>(end-start);
    cout<<"tiempo de ejecucion = "<<exect_time.count()<<" ms"<<endl;

    return 0;
}