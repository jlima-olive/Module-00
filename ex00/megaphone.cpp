#include <iostream>
#include <unistd.h>
#include <string>

int main(int ac, char **av)
{
    std::string str;

    for (int i = 1; i < ac; i++)
    {
        str.append(av[i]);
        str.append(" ");
    }
    for (int i = 0; str.begin() + i != str.end(); i++)
        while (*(str.begin() + i) == ' ' && *(str.begin() + i + 1) == ' ')
            str.erase(str.begin() + i);
    if (*str.begin() == ' ')
        str.erase(str.begin());
    if (*(str.end() - 1) == ' ')
        str.erase(str.end() - 1);
    for (int i = 0; str.begin() + i != str.end(); i++)
        if (str.at(i) > 96 && str.at(i) < 123)
            str.at(i) -= 32;
    if (str.length() == 0)
    {std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return(0);}
    std::cout << str << std::endl;
    return (0);
}
