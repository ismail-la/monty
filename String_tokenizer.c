#include <stdlib.h>

char **_strtow(char *str, char *Delim);
int Delim_check(char ch, char *Delim);
int get_Len_word(char *str, char *Delim);
int get_num_word(char *str, char *Delim);
char *get_word_next(char *str, char *Delim);



/**
 * Delim_check - checks to see if the stream has a char delimiter.
 * @ch: the character in stream.
 * @Delim: Pointer to a delimitor array with a null terminator.
 *
 * Return: 1 on success or - 0 on failur
 */

int Delim_check(char ch, char *Delim)
{
	int x = 0;

	while (Delim[x])
	{
		if (Delim[x] == ch)
			return (1);
		x++;
	}
	return (0);
}


/**
 * get_num_word -gets the word count of a string.
 *
 * @str: the string to obtain the number of words from.
 * @Delim: words that can be used as delimiters.
 * Return:  the string's word count.
 *
 */

int get_num_word(char *str, char *Delim)
{
	int susp = 1, wn = 0, x = 0;

	while (*(str + x))
	{
		if (Delim_check(str[x], Delim))
			susp = 1;
		else if (susp)
		{
			susp = 0;
			wn++;
		}
		x++;
	}
	return (wn);
}

/**
 * get_word_next -  retrieves the next word in a string.
 * @str: string to get next word from.
 * @Delim: string to obtain the following word from.
 * Return: delimiters that can be used to separate words.
 *
 */

char *get_word_next(char *str, char *Delim)
{
	int x = 0;
	int susp = 0;

	while (*(str + x))
	{
		if (Delim_check(str[x], Delim))
			susp = 1;
		else if (susp)
			break;
		x++;
	}
	return (str + x);
}

/**
 * _strtow - separates words from strings
 *
 * @str: string to divide words int
 * @Delim:  words that can be used as delimiters
 *
 * Return:  Pointers to each word in a two-dimensional 2D array
 */

char **_strtow(char *str, char *Delim)
{
	int n, x = 0, wn, Len_word;
	char **_Words = NULL;

	if (str == NULL || !*str)
		return (NULL);
	wn = get_num_word(str, Delim);

	if (wn == 0)
		return (NULL);
	_Words = malloc((wn + 1) * sizeof(char *));
	if (_Words == NULL)
		return (NULL);
	while (x < wn)
	{
		Len_word = get_Len_word(str, Delim);
		if (Delim_check(*str, Delim))
		{
			str = get_word_next(str, Delim);
		}
		_Words[x] = malloc((Len_word + 1) * sizeof(char));
		if (_Words[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(_Words[x]);
			}
			free(_Words);
			return (NULL);
		}
		n = 0;
		while (n < Len_word)
		{
			_Words[x][n] = *(str + n);
			n++;
		}
		_Words[x][n] = '\0'; /* set end of str */
		str = get_word_next(str, Delim);
		x++;
	}
	_Words[x] = NULL; /* last element is null for iteration */
	return (_Words);
}

/**
 * get_Len_word - obtains the length of the cur word in str
 * @str:  string to determine the length of the currently used word.
 * @Delim:  words that can be used as delimiters
 *
 * Return: word length of current word
 */

int get_Len_word(char *str, char *Delim)
{
	int wLen = 0, susp = 1, x = 0;

	while (*(str + x))
	{
		if (Delim_check(str[x], Delim))
			susp = 1;
		else if (susp)
		{
			wLen++;
		}
		if (wLen > 0 && Delim_check(str[x], Delim))
			break;
		x++;
	}
	return (wLen);
}

