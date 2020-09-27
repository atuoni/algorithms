

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
#include "array_generator.h"

#define RAND_MAX 10

void print_result (int,int);
int data_array_size(void);
void show_array(int[],int);

using namespace std;


int search_item;
//int size_array;
//int answer;
//int menu_item;
//int data_array[size_array];

/*
 * 
 */
int main(void) 
{
    int menu_item, answer;
    int size_array;
    cout << " ********************** Search Algorithms ********************** " << endl;
    size_array=data_array_size();
    int data_array[size_array];
    array_generator(data_array,size_array);
    //int new_size;
    
    do
    {
       
        cout<<"\nChoose the algorithm: "<<endl;
        cout <<"1 - Linear search"<<endl;
        cout<<"2 - Better Linear search"<<endl;
        cout<<"3 - Sentinel Linear search"<<endl;
        cout<<"4 - Recursive Linear search"<<endl;
        cout<<"5 - Show array generated"<<endl;
        cout<<"6 - Modify array generated"<<endl;
        cout<<"7 - Exit"<<endl<<endl;
    
        cout<<"Type the menu option: "<<endl;  //print on the screen message
        cin >> menu_item; // type menu option
        
       
    
   // }while(menu_item<1 || menu_item>5);
    
    //int data_array[size_array];
    switch(menu_item)
    {
        case 1:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = linear_search(data_array,size_array,search_item); //call function linear search
            print_result(answer,menu_item);
            break;
        case 2:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = better_linear_search(data_array,size_array,search_item);
            print_result(answer,menu_item);
            break;
        case 3:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
            answer = sentinel_linear_search(data_array,size_array,search_item);
            print_result(answer,menu_item);
            break;
        case 4:
            cout<<"Type search item: "<<endl;
            cin >> search_item;
                   
            answer = recursive_linear_search(data_array,0,size_array,search_item);
            print_result(answer,menu_item);
            break;
        case 5:
            show_array(data_array,size_array);
            break;
        case 6:
            size_array=data_array_size();
            array_generator(data_array,size_array);
            break;
        case 7:
            cout<<"Ending..."<<endl;
            exit(0);
            break;
        
        default:
            cout<<"Incorrect option... "<<endl;
            cout<<"Try again!"<<endl;
            break;
    }
    
    //print_result(answer,menu_item);
    }while(1);
}
    

void print_result(int data, int menu_item)
{
    if(data==0) //verify return of the function
    {
        cout<<"Search finished. Item not found !"<< endl<<endl; // print on the screen that search item was not found
    }
    if(data!=0 && menu_item != 1 && menu_item != 4)
    {
        cout<<"Item was found at position: "<< data <<endl;
    }
    
}

int data_array_size(void)
{
    cout<<"Type the size of the data array :"<<endl;
    int size;
    cin >> size;
    cout<<"Data Array Interval 0 - "<<RAND_MAX<<" with "<<size<<" elements"<< endl;
    return size;
}

void show_array(int data[], int size)
{
  
    cout<<"data_array = {";
    for(int element=0;element<size;element++)
   
       
        
       cout<<data[element]<<",";
  
    cout<<"}"<<endl;
}