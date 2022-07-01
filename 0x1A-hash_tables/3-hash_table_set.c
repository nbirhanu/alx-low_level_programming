#include "hash_tables.h"

/**
* create_add_node - create and inser a node to the hash table
* @ht: hash table
* @key: key; cannot be empty
* @value: value
* @idx: index to insert in hash table
* Return: 1 on success or 0on failure
*/
int create_add_node(hash_table_t *ht, const char *key, const char *value,
unsigned long int idx)
{
hash_node_t *new_node;
char *new_value, *new_key;
new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
return (0);
new_key = strdup(key);
if (!new_key)
{
free(new_node);
return (0);
}
new_value = strdup(value);
if (!new_value)
{
free(new_key);
free(new_node);
return (0);
}
new_node->key = new_key;
new_node->value = new_value;
if (ht->array[idx] == NULL)
{
new_node->next = NULL;
}
else
{
new_node->next = ht->array[idx];
}
ht->array[idx] = new_node;
return (1);
}
/**
* hash_table_set - add an element to the hash table
* @ht: hash table
* @key: key
* @value: value
* Return: 1 on success or 0 on failure
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *node;
unsigned long int index;
char *new_value;
if (!ht || !ht->array || !key || strlen(key) == 0 || !value)
return (0);
index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];
while (node && strcmp(node->key, key) != 0)
node = node->next;
if (node != NULL)
{
new_value = strdup(value);
if (!new_value)
return (0);
if (node->value)
free(node->value);
node->value = new_value;
return (1);
}
return (create_add_node(ht, key, value, index));
}
