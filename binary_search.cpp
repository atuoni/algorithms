//************************************************************************************
// File:   binary_search.cpp
// Author: Amauri Tuoni
// 
// Program to do a Binary Search of data. 
//
// Created on 14 de Outubro de 2020, 17:40
//************************************************************************************


#include<iostream>
#include<cstdlib>


using namespace std;

void bubble_sort(int[] ,int);  //prototype of the bubble sort function  

int binary_search(int *data, int size, int item )    
{
   
    int copy_array[size];   // create variable to save a copy of data_array
    for(int element=0;element<size;element++)     //loop to run the elements of the array
        copy_array[element] = data[element];    //copy data array
    bubble_sort(copy_array,size);  // call function to do a bubble sort of copy array
    int start = 0;           // set the start index of array
    int end = size-1;        // set the end index of array
    int mid;                 // variable to save the mid index 
    
    while (start<=end)     //loop until start index is less than the end index
    {
        mid = (start+end)/2;    //calculate the mid index
        
        if(copy_array[mid]== item)   //verify if the data is equal (found the item)
        {
        
            return mid+1;      // return his position on the array ordered
            
        }
        else        // if not found
        {
            if(copy_array[mid] > item)  // the item is on the left side of array
            {
                end = mid-1;        // calculate the new end index
            }
            if (copy_array[mid] < item)   //the item is on the right side of array
            {
                start=mid+1;   //calculate the new start index
            }
        }
    } 
return 0;   // return not found item
}


//*****************************************************************************
//Bubble Sort function to order the array before binary search
//******************************************************************************

void bubble_sort(int data[], int size)
{
    int temp;  //auxiliary varible
    for(int element=0;element<size;element++)   //loop until the end of array
    {
        cout<<"\nOrdering the data array..."<<element+1<<endl;  // print on the screen a message that the array is being ordered
        for(int element_next=element+1; element_next<size; element_next++) //loop the array that run an index after 
        {
            if(data[element_next] < data[element])  // verify if the next data is less than the current data 
            {
                temp=data[element];      //save the current data
                data[element]=data[element_next];  // swap data
                data[element_next]=temp;      // save the current data on the next index
            }
        }
    }
    cout<<"\nData_Array_Ordered = {";             //print on the screen the ordered array
    for(int element=0;element<size;element++)     // run loop to print the elements of array
       cout<<data[element]<<",";                  //print on the screen the data
    cout<<"}"<<endl;  
}  // end of function

