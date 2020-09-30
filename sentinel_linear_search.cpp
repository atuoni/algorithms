//************************************************************************************
// File:   sentinel_linear_search.cpp
// Author: Amauri Tuoni
// 
// Program to do a linear search using sentinel method.
//
// Created on 26 de Setembro de 2020, 17:40
//************************************************************************************



#include <iostream>
#include <cstdlib>

using namespace std;

int sentinel_linear_search (int *array,int size,int search)
{
    int last_data;  //last data of data array variable
    int element;  // index of the data array
    int answer_search=0;  // initial set as 0 (not found) 
   
    
    last_data=array[size];  //save the last data of the data array
    
    array[size]=search;  // save the search item at the last position of data array
   
    for(element=0;array[element]!=search;element++); // run the data array until find the first search item
    array[size]=last_data;  // recover the last data of the data array to the last position
    
    if(element<size || array[size]==search ) //check the data array gets on the end
        return element+1; // if not return the data element found
    else
        return answer_search;  //if so, return the not found result (0)
}

