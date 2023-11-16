#include "monty.h"
/**
 * _calloc - function that concatenate two strings
 * @nmemb: elements no
 * @size: size
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int x;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < (nmemb * size); x++)
	{
		*((char *)(p) + x) = 0;
	}
	return (p);
}
/**
 * _realloc - function that changes the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int x;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (x = 0; x < old_size; x++)
			p[x] = *((char *)ptr + x);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (x = 0; x < new_size; x++)
			p[x] = *((char *)ptr + x);
		free(ptr);
	}
	return (p);
}
