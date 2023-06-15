#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("bytes ft: %d\n", ft_printf("output ft: bagulho%"));
    printf("bytes og: %d\n", printf("output og: bagulho%"));

    return (0);
}
