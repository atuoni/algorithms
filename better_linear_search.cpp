
#include <iostream>
#include <cstdlib>

using namespace std;


int better_linear_search(int data[],int size, int item)
{
    int answer_search = 0;  // initial set as 0 (not found) 
    int element = 0;
    for(;element<size && data[element]!=item;element++);
    answer_search = element+1;
    if (element==size)
    {
        answer_search = 0;
        //cout<<element<<endl;
    }
    
    return answer_search;

}