#pragma once

class Array{
private:
    static const int SIZE = 5;
    int current_index = 0;
    int array [SIZE];

public:
    int index(int index);
    void traversing();
    void insert(int number);
    void remove(int number);
    int linear_search(int number);
};