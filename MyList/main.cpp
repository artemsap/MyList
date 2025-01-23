#include <iostream>

#include "MyList.h"

int main()
{
    MyList<double> kek;

    for (size_t i = 0; i < 5; i++)
    {
        kek.push_back(i);
    }

    for (size_t i = 0; i < kek.get_size(); i++)
    {
        std::cout << kek[i] << ' ';
    }
    std::cout << std::endl;

    kek.pop_back();

    for (size_t i = 0; i < kek.get_size(); i++)
    {
        std::cout << kek[i] << ' ';
    }
    std::cout << std::endl;

    kek.push_front(10);

    for (size_t i = 0; i < kek.get_size(); i++)
    {
        std::cout << kek[i] << ' ';
    }
    std::cout << std::endl;

    kek.remove_at(3);

    for (size_t i = 0; i < kek.get_size(); i++)
    {
        std::cout << kek[i] << ' ';
    }
    std::cout << std::endl;

    kek.insert_at(5, 3);

    for (size_t i = 0; i < kek.get_size(); i++)
    {
        std::cout << kek[i] << ' ';
    }
    std::cout << std::endl;
}
