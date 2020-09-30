

//************************************************************************************
// File:   main.cpp
// Author: Amauri Tuoni    Version 2.1
// 
// Program to test search algorithms. User can choose the size of the array that will be
// tested.
//
// Created on 26 de Setembro de 2020, 17:40
//************************************************************************************

#include <cstdlib>  //general library
#include <iostream>   //prototype for the cout function
#include <new>        
#include <limits>

#include "linear_search.h"   //header linear search
#include "better_linear_search.h"   //header better linear search
#include "sentinel_linear_search.h"  //header sentinel linear search
#include "recursive_linear_search.h"  //header recursive linear search
#include "array_generator.h"   //header of the array generator

#define RAND_MAX 10       // define the random number range  

void print_result (int,int);   //prototype of the print result function
int data_array_size(void);     //prototype of the data array size function
void show_data_array(int*,int);     //prototype of the show data array funtion
int get_search_item(void); //prototype of the get search data function

using namespace std;


//************************************************************************************
// * Main function (Show menu screen)
//**********************************************************************************


int main(void) 
{
    int menu_item, answer, search_item;
    int size_array;
    int *data_array;                         // pointer to the data array
    cout << " ********************** Search Algorithms ********************** " << endl;  // print on the screen the name of the program
    size_array=data_array_size();            // call the function to get the size of the data array 
    try
    {
        data_array=new int [size_array];         // create a dynamic memory allocation of the data array
   
    }
    catch (bad_alloc &memoryAllocationException) //treat exception bad allocation of memory
    {
        cerr << "Exception occurred: "<< memoryAllocationException.what() << endl;  //print on the screen a message 
    }
    array_generator(data_array,size_array);  //call funtion to generate the array elements
    
    
    do  //print the menu on the screen
    {
       
        cout<<"\nChoose the algorithm: "<<endl;
        cout <<"1 - Linear search"<<endl;
        cout<<"2 - Better Linear search"<<endl;
        cout<<"3 - Sentinel Linear search"<<endl;
        cout<<"4 - Recursive Linear search"<<endl;
        cout<<"5 - Show array generated"<<endl;
        cout<<"6 - Modify array generated"<<endl;
        cout<<"7 - Exit"<<endl<<endl;
    
        cout<<"Type the menu option: "<<endl;        //print on the screen message
        cin.clear(ios::goodbit);
        
        cin >> menu_item;                            //get the menu option
            
        
        while (!cin.good())
        {
            cout<<"Incorrect menu data! Type a number..."<<endl;
            cin.clear(ios::goodbit);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
            cin>> menu_item;   //get the menu item option from the user
        }
            
       
        switch(menu_item)  //test menu option chosen by user
        {
            case 1:
                search_item = get_search_item();          //call function to get the search data
                answer = linear_search(data_array,size_array,search_item);   //call function to do a linear search
                print_result(answer,menu_item);               //call function to print the result on the screen
                break;
            case 2:
                search_item = get_search_item();       //call function to get the search data
                answer = better_linear_search(data_array,size_array,search_item); //call funtion to do a better linear search
                print_result(answer,menu_item);     //call function to print the result on the screen
                break;
            case 3:
                search_item = get_search_item();     // call function to get the search data
                answer = sentinel_linear_search(data_array,size_array,search_item);      //call funtion to do a sentinel linear search
                print_result(answer,menu_item);              //call funtion to print the result on the screen
                break;
            case 4:
                search_item = get_search_item();    //call function to get the search data
                answer = recursive_linear_search(data_array,0,size_array,search_item); //call function to do a recursive linear search
                print_result(answer,menu_item);               // call funtion to print the result on the screen
                break;
            case 5:
                show_data_array(data_array,size_array);             //call funtion to show the array generated
                break;
            case 6:
                size_array=data_array_size();                  // call the function to get the new size of the data array 
                delete [] data_array;                          // delete the old data array that was allocated (free space)
                try
                {
                    data_array= new int[size_array];                // create a new memory dynamic allocation of the data array
                }
                catch (bad_alloc &memoryAllocationException)             //treat exception bad allocation of memory
                {
                    cerr << "Exception occurred: "<< memoryAllocationException.what()<< endl;       //print on the screen a message 
                }
                array_generator(data_array,size_array);            //call funtion to generate the new array elements
                break;
            case 7:
                cout<<"Ending..."<<endl;                          //print on screen a exit message
                delete [] data_array;                            //delete the old data array that was allocated before exit
                exit(0);  //terminate program and go to the system
                break;
        
            default:
                cout<<"Incorrect menu option...Try again! "<<endl;                   //print on the screen a message about the wrong option
                cout<<endl;
                break;
        
        }
    
    }while(1);  //loop to show the menu always  

}   //end of main function


//************************************************************************************************************************************************************
//Function to print the result of the search selected
//************************************************************************************************************************************************************

void print_result(int data, int menu_item)
{
    if(data==0) // if data is 0 (not found)
    {
        cout<<"Search finished. Item not found !"<< endl<<endl; // print on the screen a message that was not found
    }
    if(data!=0 && menu_item != 1 && menu_item != 4)   // if data was found and it was selected menu item not equal 1 and 4      
    {
        cout<<"Item was found at position: "<< data <<endl;  //print a message with the position of the element
    }
    
} // end of the function

//*******************************************************************************************************************************************************
// Function to get the size of the data array
//*******************************************************************************************************************************************************

int data_array_size(void)
{
    cout<<"Type the size of the data array :"<<endl;  //print on the screen the message
    int size;                                      // create the variable
    cin.clear(ios::goodbit);
    cin >> size;                                   // get the array size 
    
    while (!cin.good())
    {
        cout<<"Incorrect size data! Type a number..."<<endl;   //print on the screen a message of error
        cin.clear(ios::failbit);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>size;   
    }
    cout<<"Data Array Interval 0 - "<<RAND_MAX<<" with "<<size<<" elements"<< endl;  //print on the screen the number elements and the range of the array that will be generated
    return size;                                                                       //return the size value
} //end of the function


//********************************************************************************************************************************************************
// Function to show the data array generated
//********************************************************************************************************************************************************

void show_data_array(int *data, int size)
{
    cout<<"data_array = {";             //print on the screen
    for(int element=0;element<size;element++)     //loop to run the elements of the array
       cout<<data[element]<<",";                  //print on the screen the element
    cout<<"}"<<endl;                     //print on the screen 

} //end of the function

//************************************************************************************************************
// Function to get the search data from the user
//************************************************************************************************************
int get_search_item(void)
{
    int search;                                        //variable to save the search data
    cout<<"Type the search item: "<<endl;               //print on the screen
    cin.clear(ios::goodbit);
    cin >> search;                  //get the number to search in the array
    
    while (!cin.good())
    {
        cout<<"Incorrect search data! Type a number..."<<endl; //print on the screen a message of error
        cin.clear(ios::goodbit);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>search;    // get the search data from the user
    }
    return search;            //return the search data
}//end of the function