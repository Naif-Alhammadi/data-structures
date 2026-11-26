#include <iostream>
using namespace std;

int main(void)
{

    // size of arrays
    const int ONE_DIMENSIONAL_SIZE = 5;
    const int TWO_DIMENSIONAL_SIZE = 5;
    const int THREE_DIMENSIONAL_SIZE = 5;

    // array declartions
    int one_dimensional_array[ONE_DIMENSIONAL_SIZE] = {0};

    // accessing elements
    cout<< one_dimensional_array[0]; // first element
    cout<< one_dimensional_array[ONE_DIMENSIONAL_SIZE - 1]; // last element

    // traversing array
    for (int number : one_dimensional_array)
    {
        cout << number << endl;
    }
    cout << endl;


    // multidimenstional arrays
    int two_dimensional_array[TWO_DIMENSIONAL_SIZE][TWO_DIMENSIONAL_SIZE] = {{0}};
    
    int three_dimensional_array[THREE_DIMENSIONAL_SIZE][THREE_DIMENSIONAL_SIZE][THREE_DIMENSIONAL_SIZE] = {{{0}}};

    cout << "-----One Dimensional Array-----" << endl;
    
    cout << "-----Two Dimensional Array-----" << endl;

    // two dimenstional array
    for (int i = 0; i < TWO_DIMENSIONAL_SIZE; i++)
    {
        for (int j = 0; j < TWO_DIMENSIONAL_SIZE; j++)
        {
            // access by indicator arrays
            cout << *(*(two_dimensional_array + i) + j) << "\t";
        }
        cout << endl;
    }

    // three dimensional array
    cout << endl;
    cout << "-----Three Dimensional Array-----" << endl;
    for (int i = 0; i < THREE_DIMENSIONAL_SIZE; i++)
    {
        for (int j = 0; j < THREE_DIMENSIONAL_SIZE; j++)
        {
            for (int c = 0; c < THREE_DIMENSIONAL_SIZE; c++)
            {
                // access by indicator arrays
                cout << *(*(*(three_dimensional_array + i) + j) + c) << "\t";
            }
            cout<<endl;
        }
    }
}