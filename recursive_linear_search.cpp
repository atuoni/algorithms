//************************************************************************************
// File:   recursive_linear_search.cpp
// Author: Amauri Tuoni
// 
// Program to do a linear search using recursive method.
//
// Created on 26 de Setembro de 2020, 17:40
//************************************************************************************


#include <iostream>
#include <cstdlib>

using namespace std;


int answer_search=0;  // initial set as 0 (not found) 

int recursive_linear_search(int *array, int element, int size, int search)
{
    
    
    if(element<size)     // check if the element is less than the size data array
    {
            if(array[element]==search)  //if data is equal than the search item
            {
                answer_search=1;        //flag to set the first item found
                cout<<"Item was found at position: "<<element+1<<endl;  //print on the screen
               
                element=element+1;     // increment the element of data array
                recursive_linear_search(array,element,size,search);  // call the function again with the next element
                
            }
            else  //if data is not equal
            {
                element=element+1;  //increment the element;
                recursive_linear_search(array,element,size,search); // call the function again with the next element
            }
    }
    
    else   //if get on the end of data array
    {  
        if(answer_search==0)   //if search item was not found
        {
               
                return answer_search;    //return 0
        }
       
    }
    return answer_search;  // return the last element that was found 
}
