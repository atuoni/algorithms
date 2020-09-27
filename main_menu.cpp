

/* 
 * File:   main.cpp
 * Author: amauri
 *
 * Created on 26 de Setembro de 2020, 17:40
 */

#include <cstdlib>
#include <iostream>

#include "linear_search.h"
#include "better_linear_search.h"
#include "sentinel_linear_search.h"
#include "recursive_linear_search.h"

void print_result (int,int);

using namespace std;


int search_item;
int data_array[] = {11,3,4,1,0,4,7,-89,5,88};
int answer;
int size_array;
int menu_item;

/*
 * 
 */
int main(void) 
{
    do
    {
        cout << " ********************** Search Algorithms ********************** " << endl;
    
        cout <<"1 - Linear search"<<endl;
        cout<<"2 - Better Linear search"<<endl;
        cout<<"3 - Sentinel Linear search"<<endl;
        cout<<"4 - Recursive Linear search"<<endl;
        cout<<"5 - Exit"<<endl<<endl;
    
        cout<<"Type the menu option: "<<endl;  //print on the screen message
        cin >> menu_item; // type menu option
        
        if(menu_item < 1 || menu_item > 5)
            cout << "\nOption incorrect. Try again!" << endl<<endl;
    
    }while(menu_item<1 || menu_item>5);
    
    size_array = sizeof(data_array)/sizeof(int);  // calculate the size of the array
    
  
    
    switch(menu_item)
    {
        case 1:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = linear_search(data_array ,size_array,search_item); //call function linear search
            break;
        case 2:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = better_linear_search(data_array,size_array,search_item);
            break;
        case 3:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = sentinel_linear_search(data_array,size_array,search_item);
            break;
        case 4:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = recursive_linear_search(data_array,0,size_array,search_item);
            break;
        case 5:
            cout<<"Quitting..."<<endl;
            exit(0);
            break;
        default:
            cout<<"Incorrect option... "<<endl;
            cout<<"Type again the menu option : "<<endl;
            break;
    }
    
    print_result(answer,menu_item);
    
}
    

void print_result(int data, int menu_item)
{
    if(data==0) //verify return of the function
    {
        cout<<"Search finished. Item not found !"<< endl; // print on the screen that search item was not found
    }
    if(data!=0 && menu_item != 1 && menu_item != 4)
    {
        cout<<"Item was found at position: "<< data <<endl;
    }
    
}