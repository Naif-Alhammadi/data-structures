#include<iostream>
#include <vector>


void diplay_vector(const std::vector<int> &array);

int main(void)
{
    // vector is like dynamic arrays

    // vector initialization
    std::vector<int> array;

    // add elements to the last of the vector
    std::cout<<"---- push elements ---- "<<std::endl;
    // Time: O(1) -> Amortized
    // Space: O(1) or O(n) for reallocation
    array.push_back(10);
    array.push_back(20);
    array.push_back(30);
    diplay_vector(array);

    // remove elements from the end of the vector
    std::cout<<"---- pop elements ---- "<<std::endl;
    // Time: O(1) -> remove from the end
    // Space: O(1)
    array.pop_back();
    diplay_vector(array);


    // return the size of the vector
    std::cout<<"---- size of the array ---- "<<std::endl;
    // Time: O(1) -> an attribute
    // Space: O(1)
    int list_size = array.size();
    std::cout<<list_size<<std::endl;

    // return the capacity of the vector (total space)
    std::cout<<"---- capacity of the array ---- "<<std::endl;
    // Time: O(1) -> an attribute
    // Space: O(1)
    int capacity = array.capacity();
    std::cout<<capacity<<std::endl;

    // reserve vector capacity
    std::cout<<"---- reserve changes the capacity ---- "<<std::endl;
    // Time: O(n) -> copy old array to new one
    // Space: O(n) -> add new array
    array.reserve(10);
    std::cout<<array.capacity()<<std::endl;

    // resize vector size and capacity if needed
    // Time: O(n) -> copy old array to new one
    // Space: O(n) -> add new array
    std::cout<<"---- resize capacity and size of the vector ---- "<<std::endl;
    array.resize(capacity * 2);
    diplay_vector(array);
    

    // at index
    std::cout<<"---- at 0 index ---- "<<std::endl;
    // Time: O(1)
    // Space: O(1)
    std::cout<<array.at(0)<<std::endl;


    // insertion
    std::cout<<"---- insert to the array ---- "<<std::endl;
    // Time: O(n) -> to shift the elements from that location
    // Space: O(1) or O(n) for reallocation
    array.insert(array.begin() + 2, 30);
    diplay_vector(array);


    // erase
    std::cout<<"---- erase from the array ---- "<<std::endl;
    // Time: O(n) -> to shift the elements from that location
    // Space: O(1)
    array.erase(array.begin() + 2);
    diplay_vector(array);
    
}

void diplay_vector(const std::vector<int> &array)
{
    // Time: O(n)
    // Space: O(1)
    
    // range based for loop
    for(int l : array)
    {
        std::cout<<l<<std::endl;
    }
}