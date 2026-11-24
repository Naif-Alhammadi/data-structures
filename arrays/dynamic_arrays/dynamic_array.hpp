#pragma once

class Array
{
private:
    int *list = nullptr;
    int size = 5;
    int current = -1;


public:
    Array();
    void display();
    void insert(int element);
    void resize();
    ~Array();
};