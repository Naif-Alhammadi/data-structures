#include <iostream>
#include "dynamic_array.hpp"


Array::Array()
{
    // initialize array in the heap (dynamic)
    list = new int[size];
}


// display array
void Array::display()
{
    // Time: O(n)
    // Space: O(1)

    // check if array has not any elements yet
    if(current == -1)
    {
        std::cout<<"array is empty"<<std::endl;
        return;
    }

    // print each element inside the array
    for(int i = 0; i <= current; i++)
    {
        std::cout<<list[i] << " ";
    }
    std::cout<<std::endl;
}


// insert inside the array (from the end of the array)
void Array::insert(int element)
{
    // Time: O(1) -> Amortized
    // Space: O(1) -> Amortized

    while(true)
    {
        // if current size of the array is smaller than the size add it
        if(current + 1 < size)
        {
            list[current + 1] = element;
            current++;

            return;
        }
        
        // else if current size of the array is not smaller than the size resize it
        else
        {
            resize();
        }
    }
}


// make the array larger
void Array::resize()
{
    // Time: O(n)
    // Space: O(n)

    // add some extra space to the old array
    int new_size = 2 * size;

    // initialize the new array
    int *temp = new int[new_size];

    // copy the elements from the old array to the new one
    for(int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }

    // add extra size
    size += new_size;

    // free the old memory
    delete []list;

    // update list to point to the new array
    list = temp;
}


// deconstruct the instance (relase heap memory)
Array::~Array()
{
    delete []list;
}