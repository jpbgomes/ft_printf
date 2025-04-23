#include "ft_printf.h"

int main()
{
    ft_printf("%s\n", "Hello, world!");
    ft_printf("%p\n", "Hello, world!");
    ft_printf("%d\n", -1234);
    ft_printf("%i\n", -1234);
    ft_printf("%u\n", -1234);
    ft_printf("%x\n", -1234);
    ft_printf("%X\n", -1234);
    ft_printf("%cbcd%%\n", 'a');
    return (0);
}


/*
    va_list: A type that holds information about the variable arguments.
    va_start: A macro to initialize the va_list variable to point to the first variable argument.
    va_arg: A macro to retrieve the next argument from the list.
    va_end: A macro to clean up after accessing all the arguments.
*/