
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "array_generator.h"

//#define RAND_MAX 10

using namespace std;

void array_generator(int data[],int size)
{
    int number;
    unsigned int seed;
    
    seed = time(0);
    srand(seed);
    for(int element=0;element<size;element++)
    {
        number = rand()%10;
        //cout<<number<<endl;
        data[element]=number;
        cout<<"Generating array with "<<element+1<<" elements ..."<< endl;
    }
    //for(int element=0;element<size;element++)
    //    cout<<data[element]<<endl;
   
    cout<<"Done."<<endl<<endl;
}