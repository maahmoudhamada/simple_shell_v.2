#include "shell.h"

/**
* _strconcat - Function to concat two strings
*
* @s1: First string
* @s2: Second string
* @flag: Identify path's dir or env's var
*
* Return: Concat string
*/
char *_strconcat(char *s1, char *s2, int flag)
{
int len1, len2, i, j;
char *out;

if (s1 == NULL || s2 == NULL)
return (NULL);

len1 = _strlen(s1), len2 = _strlen(s2);
i = j = 0;

out = malloc((len1 + len2 + 2) * sizeof(char));
if (out == NULL)
return (NULL);

for (i = 0; i < len1; i++)
out[i] = s1[i];
if (flag)
out[i++] = '=';
else
out[i++] = '/';

for (j = 0; j < len2; j++, i++)
out[i] = s2[j];
out[i] = '\0';

return (out);
}

