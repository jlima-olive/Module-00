#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;

    if (ac == 1)
    {std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return(0);}
    for (int i = 1; i < ac; i++)
    {
        str.append(av[i]);
        
        str.append(" ");
    }
    // for (int i = 1; i < ac; i++)
    std::cout << str << std::endl;
    return (0);
}