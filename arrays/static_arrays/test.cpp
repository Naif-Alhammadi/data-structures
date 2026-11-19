#include <iostream>
#include "array.hpp"
using namespace std;

int main(void)
{
    Array array;
    cout<<"==== insert and check index ===="<<endl;
    array.insert(1);
    cout << array.index(1) << endl;
    cout << array.index(-1) << endl;
    cout<<endl;

    cout<<"==== traversing array ===="<<endl;
    array.traversing();
    cout<<endl;

    cout<<"==== insert until array got full ===="<<endl;
    array.insert(2);
    array.insert(3);
    array.insert(4);
    array.insert(5);
    array.traversing();
    array.insert(6);
    cout<<endl;

    cout<<"==== array after removing elements ===="<<endl;
    array.remove(1);
    array.remove(2);
    array.remove(3);
    array.traversing();
    cout<<endl;

    cout<<"==== remove all elemnts ===="<<endl;
    array.remove(4);
    array.remove(5);
    array.traversing();
    array.remove(6);
}