#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf(" %% \n");
    printf(" %%%% \n");
    printf(" %% %% %% \n");
    printf(" %%  %%  %% \n");
    printf(" %%   %%   %% \n");
    printf("%%\n");
    printf("%% %%\n\n");

    ft_printf(" %% \n");
    ft_printf(" %%%% \n");
    ft_printf(" %% %% %% \n");
    ft_printf(" %%  %%  %% \n");
    ft_printf(" %%   %%   %% \n");
    ft_printf("%%\n");
    ft_printf("%% %%\n");

    ft_printf("\n\n");
    ft_printf(" NULL %s NULL ", NULL);

    ft_printf("\n\n");
	ft_printf("%p %p \n", INT_MIN, INT_MAX);
	ft_printf("%p %p \n", LONG_MIN, LONG_MAX);
	ft_printf("%p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf("%p %p \n", 0, 0);

    ft_printf("\n\n");
    printf("%x \n", 0);
    ft_printf("%x \n\n", 0);
    printf("%x \n", -1);
    ft_printf("%x \n", -1);
    // ft_printf(" %x \n", -9);
    // ft_printf(" %x \n", -10);
    // ft_printf(" %x \n", -11);
    // ft_printf(" %x \n", -14);
    // ft_printf(" %x \n", -15);
    // ft_printf(" %x \n", -16);
    // ft_printf(" %x \n", -99);
    // ft_printf(" %x \n", -100);
    // ft_printf(" %x \n", -101);
    // ft_printf(" %x \n", INT_MIN);
    // ft_printf(" %x \n", LONG_MAX);
    // ft_printf(" %x \n", UINT_MAX);
    // ft_printf(" %x \n", ULONG_MAX);
    // ft_printf(" %x \n", 9223372036854775807LL);
    // ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    // ft_printf(" %x \n", -42);

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