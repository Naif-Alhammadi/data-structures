#include<iostream>
#include "dynamic_array.hpp"
using namespace std;

int main(void)
{
    int list [] = {1,2,3,4,5};
    Array array;
    cout<<"----- display an empty array -----"<<endl;
    array.display();
    array.insert(1);
    array.insert(2);
    array.insert(3);
    array.insert(4);
    array.insert(5);
    cout<<"----- display array after filling the size -----"<<endl;
    array.display();
    array.insert(6);
    array.insert(7);
    array.insert(8);
    array.insert(9);
    array.insert(10);
    cout<<"----- display array after filling the size -----"<<endl;
    array.display();
}