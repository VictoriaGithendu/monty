#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @s1: First string
 * @s2: Second string
 * Return: 0 if s1 and s2 are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;
	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}
/**
 * _sch - function that searches a char inside a string
 * @s: string to searches
 * @c: char to find
 * Return: 1 on success
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}
/**
 * _strtok - function that tokenizes a string
 * @s: string
 * @d: delimiter
 * Return: first partition
 */
char *_strtok(char *s, char *d)
{
	static char *ultimo;
	int x = 0, y = 0;

	if (!s)
		s = ultimo;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
