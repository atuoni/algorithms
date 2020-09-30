//************************************************************************************
// File:   linear_search.cpp
// Author: Amauri Tuoni
// 
// Program to do a linear search of data. 
//
// Created on 26 de Setembro de 2020, 17:40
//************************************************************************************



#include<iostream>
#include<cstdlib>

using namespace std;


int linear_search(int *data, int size, int item)
{
    int element;   // index of the data array
    
    int answer_search = 0;  // initial set as 0 (not found) 
    for(element=0; element < size; element++)  //run loop until the end of data array
    {
        if(data[element]==item)         //check if the search item is equal to data element
        {
            answer_search = element+1;    // save the data that is equal
            cout <<" The search item is at position: "<< answer_search << endl;  //print on the screen the position of the data element found
        }    
    }    
    return answer_search;  // return the result ( 0 not found)
    
}
