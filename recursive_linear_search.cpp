#include <iostream>
#include <cstdlib>

using namespace std;


int answer_search=0;

int recursive_linear_search(int array[], int i, int n, int data)
{
    
  
    if(i<n)
    {
            if(array[i]==data)
            {
                answer_search=1;
                cout<<"Item was found at position: "<<i+1<<endl;
               
                i=i+1;
                recursive_linear_search(array,i,n,data);
                
            }
            else
            {
                i=i+1;
                recursive_linear_search(array,i,n,data);
            }
    }
    
    else
    {
        if(answer_search==0)
        {
               
                return answer_search;
        }
       
    }
    return answer_search;
}
