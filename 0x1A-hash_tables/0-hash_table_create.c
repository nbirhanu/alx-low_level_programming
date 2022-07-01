#include "hash_tables.h"

/**
* hash_table_create - create a hash table
* @size: size of the array
* Return: pointer to newly created hash table or NULL if it failes
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_table;
unsigned int i;
if (size == 0)
return (NULL);
new_table = malloc(sizeof(hash_table_t));
if (new_table == NULL)
return (NULL);
new_table->array = malloc(size * sizeof(hash_node_t *));
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}
for (i = 0; i < size; i++)
new_table->array[i] = NULL;
new_table->size = size;
return (new_table);
}
