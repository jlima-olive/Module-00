#include <unistd.h>
#include <iostream>

void reference_func(int &numb)
{
    numb = 10;
}

int main(void)
{
    int number = 5;

    reference_func(number);
    std::cout << number << std::endl;
}