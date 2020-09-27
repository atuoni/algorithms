#include <iostream>
#include <cstdlib>

using namespace std;

int sentinel_linear_search (int array[],int size,int item)
{
    int last_data;
    int element;
    int answer_search=0;
    
    last_data=array[size];
    
    array[size]=item;
   
    for(element=0;array[element]!=item;element++);
    array[size]=last_data;
    
    if(element<size || array[size]==item )
        return element+1;
    else
        return answer_search;
}

