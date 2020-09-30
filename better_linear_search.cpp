
#include <iostream>
#include <cstdlib>

using namespace std;


int better_linear_search(int *data,int size, int item)
{
    int answer_search = 0;  // initial set answer_search as 0 (not found) 
    int element = 0;     // initial set of element
    //int temp=*size;
    for(;element<size && data[element]!=item;element++);  //run loop of data array and check if the search item is equal to a data_array element 
    answer_search = element+1;  //if equal save element
    if (element==size)  // if not found
    {
        answer_search = 0;   //set answer_search as not found
      
    }
    
    return answer_search;  //return the result

}