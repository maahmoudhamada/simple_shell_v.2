#include "shell.h"

/**
* linenum_convert - Function to convert cmd line number to string
*
* @n: Line number
*
* Return: String contain line number
*/

char *linenum_convert(int n)
{
int digit, num, i, j, sz;
long int pow = 1;
char *ptr;

digit = sz = i = j = 0, pow = 1, num = n;

if (n <= 0)
return (NULL);

for (sz = 0; n >= 1; sz++, n /= 10)
;

ptr = malloc((sz + 1) * sizeof(char));
if (ptr == NULL)
return (NULL);

for (i = 1, pow = 1; i < sz; i++, pow *= 10)
;

for (j = 0; j < sz; pow /= 10, j++)
{
digit = num / pow;
ptr[j] = digit + '0';
num = num - (digit *pow);
}
ptr[j] = '\0';

return (ptr);
}

