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


// Selection Sort Algorithm
void Array::selection_sort()
{
    // Selection Sort Algorithm sort the array by selecting the minimum number found in each iteration

    // Time: O(n^2)
    // Space: O(1)


    for(int i = 0; i < this->current_index; i++)
    {
        // initial min variable
        int min = i;
        for(int j = i + 1; j < this->current_index; j++)
        {
            // check the minimum number
            if(array[min] > array[j])
            {
                // update min variable
                min = j;
            }
        }

        // sort array 
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// Bubble Sort Algorithm
void Array::bubble_sort()
{
    // Bubble Sort Algorithm bubbles the biggest number to the end and the smallest to the begging of the array

    // Time: O(n^2), Best Case: O(n)
    // Space: O(1)

    // if reaching the end of the outter loop
    int stop = 0;
    
    while (stop != this->current_index)
    {
        // check if array is already sorted. Time O(n)
        bool swap = false;

        // reset iteration to start from the begging of the array
        int left = 0;

        for(int right = left + 1; right < this->current_index - stop; right++)
        {
            // check if left value is greater than the right value
            // that means we sawp them to perform bubbling
            if(array[left] > array[right])
            {
                // swapping
                int small = array[right];
                array[right] = array[left];
                array[left] = small;
                swap = true;
            }
            // increase left which also will increase right by the inner loop
            left += 1;
        }

        // update stop
        stop += 1;

        // if there was not any sawps that means the array is sorted
        if(!swap)
            break;
    }
}

// Binary Search Algorithm
int Array::binary_search(int number)
{
    // Array must be sorted in ascending order
    // Time: O(log n)
    // Sapce: O(1)
    
    // save the index of the number that found
    int index_of_number = -1;

    // store the index of the left side of the array
    int left = 0;

    // store the index of the right side of the array
    int right = this->current_index - 1;

    // store the index of the middle side of the array
    // count the distance between the begging and the end of the array
    // divide by 2
    // move from the begging of the array (left) to the middle
    int middle = left + (right - left) / 2;

    // while left and right are inside the boundaries
    while (left < this->current_index && right > 0)
    {

        // update middle
        middle = left + (right - left) / 2;

        // if number is smaller than the number inside the middle array
        if(array[middle] > number)
        {
            // ignore bigger numbers
            right = middle - 1;
        }

        // if number is greater than the number inside the middle array
        else if(array[middle] < number)
        {
            // ignore smaller numbers
            left = middle + 1;
        }

        // if number equals the number inside the middle array
        else
        {
            // store it
            index_of_number = middle;

            // exit the while loop
            break;
        }
}

// if numder was not found (did not update its value)
if (index_of_number == -1)
    // print a message to the user
    cout<< "number was not found"<<endl;

// else return that index
return index_of_number;
}