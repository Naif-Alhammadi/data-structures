#include <iostream>
#include "array.hpp"
using namespace std;


// access array by its index
int Array::index(int index)
{
    // allow user to search from back of the array
    int reveresd_index = index + this->current_index;

    // if index is less than the size of array and it is not neagtive and in the scope of the current index
    if(index < this->current_index && index >= 0)
    {
        return *(array + index);
    }

    // if index is neagtive and reveresed variable is inside the scope of the current index  
    else if (index < 0 and (reveresd_index >= 0 and reveresd_index < this->current_index))
    {
        return *(array + reveresd_index);
    }
    
    // if index is not inside the range of the array
    cout<< "Array out of range ";
    return -1;
}

// display all the elements inside the array
void Array::traversing()
{
    // check if array is not empty
    if(current_index != 0)

        // pass through the array until it reaches the current index 
        for(int i = 0; i < this->current_index; i++)
        {
            cout<< array[i]<<endl;
        }

        // if current index is zero
    else
        cout<<"Array is empty"<<endl;
}

// add a new element into the static array
void Array::insert(int number)
{
    // check if array's current index is not out of the range
    if (this->current_index < SIZE)
    {
        // update that index
        array[current_index] = number;

        // update current index
        this->current_index++;
        return;
    }

    // if user already fills all the array
    cout<<"array is full"<< endl;
}


// linear search algorithm
int Array::linear_search(int number)
{
    // Time: O(n)
    // Space: O(1)

    // save the index of the number that found
    int index_of_number;

    // search through array until it reaches the current index
    for(int i = 0; i < current_index; i++)
    {

        // if the number of the array equals the number
        if(array[i] == number)
        {
            // save that index
            index_of_number = i;

            // return the index of the number
            return index_of_number;
        }
    }

    // if number was not found return -1
    return -1;
}


// remove a number from the array
void Array::remove(int number)
{
    // the index of the element if found in the array
    int index_of_number;

    // search for that element using linear search algorithm
    index_of_number = linear_search(number);

    // check if number found
    if(index_of_number != -1)
    {
        // change the value of the element
        array[index_of_number] = 0;

        // reduce the current index
        this->current_index--;

        // shift array elements
        for(int i = index_of_number; i < current_index; i++)
        {
            array[i] = array[i + 1];
        }
    }

    // if number was not found inside the linear seach algorithm
    else
        cout<<"number was not found"<<endl;
}