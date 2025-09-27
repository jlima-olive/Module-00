#include <iostream>
#include <unistd.h>
#include <string>

class MyMega
{
private:
    std::string str;
public:
    void join(char **av, int ac)
    {
        for (int i = 1; i < ac; i++)
        {
            str.append(av[i]);
            str.append(" ");
        }
    }
    void rm_xspace();
    void all_upper()
    {
        for (int i = 0; str.begin() + i != str.end(); i++)
            if (str.at(i) > 96 && str.at(i) < 123)
                str.at(i) = toupper(str.at(i));
    }
    void print()
    {
        if (str.length() == 0)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
            std::cout << str << std::endl;
    }
};

void MyMega::rm_xspace()
{
    for (int i = 0; str.begin() + i != str.end(); i++)
        while (*(str.begin() + i) == ' ' && *(str.begin() + i + 1) == ' ')
            str.erase(str.begin() + i);
    if (*str.begin() == ' ')
        str.erase(str.begin());
    if (*(str.end() - 1) == ' ')
        str.erase(str.end() - 1);
 }

int main(int ac, char **av)
{
    MyMega phone;

    phone.join(av, ac);
    phone.all_upper();
    phone.rm_xspace();
    phone.print();
    return (0);
}
