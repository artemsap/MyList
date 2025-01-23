#include <iostream>

#include "MyList.h"

int main()
{
    MyList<double> kek;

    for (size_t i = 0; i < 5; i++)
    {
        kek.push_back(i);
    }
    kek.PrintList();

    kek.pop_back();
    kek.PrintList();

    kek.push_front(10);
    kek.PrintList();

    kek.remove_at(3);
    kek.PrintList();

    kek.insert_at(5, 3);
    kek.PrintList();

    kek.pop_front();
    kek.PrintList();
}
