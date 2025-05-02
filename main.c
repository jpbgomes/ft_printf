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
    // printf(" NULL %s NULL ", NULL);
    ft_printf(" NULL %s NULL ", NULL);

    ft_printf("\n\n");
	// ft_printf("%p %p \n", INT_MIN, INT_MAX);
	// ft_printf("%p %p \n", LONG_MIN, LONG_MAX);
	// ft_printf("%p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf("%p %p \n", 0, 0);
	ft_printf("%p %p \n", 0, 0);

    // ft_printf("\n\n");
    // ft_printf("%u \n", LONG_MAX);
    // ft_printf("%u \n", LONG_MIN);
    // ft_printf("%u \n", ULONG_MAX);
    // ft_printf("%u \n", 9223372036854775807LL);
    // ft_printf("%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    return (0);
}

/*
    va_list: A type that holds information about the variable arguments.
    va_start: A macro to initialize the va_list variable to point to the first variable argument.
    va_arg: A macro to retrieve the next argument from the list.
    va_end: A macro to clean up after accessing all the arguments.
*/