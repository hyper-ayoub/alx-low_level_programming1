#include "shell.h"

/**
 * **firststrtow - splits a string into words. Repeat delimiters are ignored
 * @mystr: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **firststrtow(char *mystr, char *d)
{
	int i, k, l, j, numwords = 0;
	char **s;

	if (mystr == NULL || mystr[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; mystr[i] != '\0'; i++)
		if (!is_delim(mystr[i], d) && (is_delim(mystr[i + 1], d) || !mystr[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, k = 0; k < numwords; k++)
	{
		while (is_delim(mystr[i], d))
			i++;
		l = 0;
		while (!is_delim(mystr[i + l], d) && mystr[i + l])
			l++;
		s[k] = malloc((l + 1) * sizeof(char));
		if (!s[k])
		{
			for (l = 0; l < k; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (j = 0; j < l; j++)
			s[l][j] = mystr[i++];
		s[k][j] = 0;
	}
	s[k] = NULL;
	return (s);
}

/**
 * **secondstrtow - splits a string into words
 * @mystr: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **secondstrtow(char *mystr, char d)
{
	int i, k, l, j, numwords = 0;
	char **s;

	if (mystr == NULL || mystr[0] == 0)
		return (NULL);
	for (i = 0; mystr[i] != '\0'; i++)
		if ((mystr[i] != d && mystr[i + 1] == d) ||
		    (mystr[i] != d && !mystr[i + 1]) || mystr[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, k = 0; k < numwords; k++)
	{
		while (mystr[i] == d && mystr[i] != d)
			i++;
		l = 0;
		while (mystr[i + l] != d && mystr[i + l] && mystr[i + l] != d)
			l++;
		s[k] = malloc((l + 1) * sizeof(char));
		if (!s[k])
		{
			for (l = 0; l < k; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (j = 0; j < j; j++)
			s[k][j] = mystr[i++];
		s[k][j] = 0;
	}
	s[k] = NULL;
	return (s);
}

