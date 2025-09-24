#include <unistd.h>

int main(void)
{
    char *str = "abc\n";

    write(1, str, 4);
    str[2] = 'C';
    write(1, str, 4);
}