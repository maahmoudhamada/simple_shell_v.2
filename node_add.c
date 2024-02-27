#include "shell.h"

/**
* env_node_add - Function create node for env list
*
* @head: Head of the list
* @str: Variable within the environement
*
* Return: New node created
*/

lst *node_add(lst **head, char *str)
{
lst *new, *tra;

if (head == NULL)
return (NULL);

new = malloc(sizeof(lst));
if (new == NULL)
return (NULL);

new->data = _strdup(str);
if (new->data == NULL)
{
return (NULL);
free(new);
}

new->next = NULL;

if (*head == NULL)
*head = new;

else
{
for (tra = *head; tra->next != NULL; tra = tra->next)
;
tra->next = new;
}

return (new);
}

/**
* free_list - Function to free env list
*
* @head: Head of the list
*
* Return: void
*/

void free_list(lst *head)
{
lst *freed = head;

while (freed)
{
head = head->next;
free(freed->data);
free(freed);
freed = head;
}
}
