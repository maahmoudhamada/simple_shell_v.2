#include "shell.h"

/**
* _strcmp - Function compare two strings
*
* @s1: First string
* @s2: Second string
*
* Return: Zero (0) if there is match
*/

int _strcmp(const char *s1, const char *s2)
{
int n = 0, i = 0;

for (i = 0; s1[i] || s2[i]; i++)
{
n = s1[i] - s2[i];

if (n == 0)
continue;
else
break;
}

return (n);
}

/**
* _strlen - Function to get length of string
*
* @s: String to get its length
*
* Return: Length of a string
*/

int _strlen(const char *s)
{

int i = 0;

if (s == NULL)
return ('\0');

while (s[i])
i++;

return (i);
}

/**
* _strcpy - Function to copy a string (src) to another (dest)
*
* @src: Original string to copy
* @dest: copied string
*
* Return: Return the copied string
*/

char *_strcpy(char *dest, const char *src)
{

int i = 0;

if (dest == NULL || src == NULL)
return (NULL);

for (i = 0; src[i]; i++)
dest[i] = src[i];

dest[i] = '\0';

return (dest);
}

/**
* _strdup - Function to allocate and duplicate memory for a string
*
* @s: String to duplicate
*
* Return: Duplicated string
*/

char *_strdup(const char *s)
{
int len = 0;
char *new;

if (s == NULL)
return (NULL);

len = _strlen(s);

new = malloc((len + 1) * sizeof(char));
if (new == NULL)
return (NULL);

new = _strcpy(new, s);

return (new);
}

/**
* _strlen2d - Function to get 2d array length
*
* @grid: 2D array
*
* Return: Length of array
*/

int _strlen2d(char **grid)
{
int i = 0;

if (grid == NULL)
return ('\0');

while (grid[i])
i++;

return (i);
}
