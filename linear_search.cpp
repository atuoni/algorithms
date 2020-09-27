#include<iostream>
#include<cstdlib>

using namespace std;


int linear_search(int data[] , int size, int item)
{
    int element;
    int answer_search = 0;  // initial set as 0 (not found) 
    for(element=0; element < size; element++)
    {
        if(data[element]==item)
        {
            answer_search = element+1;
            cout <<" The search item is in the position: "<< answer_search << endl;
        }    
    }    
    return answer_search;
    
}
