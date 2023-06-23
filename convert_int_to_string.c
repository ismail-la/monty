#include <stdlib.h>

char *gets_integer(int number);

unsigned int get_absolute(int);

int gets_line_base_num(unsigned int number, unsigned int Base);

void get_buff_base_num(unsigned int number, unsigned int Base,
		       char *buff, int Size_buff);


/**
 * get_absolute - get an integer's absolute value.
 * @x: integer to get its absolute value
 *
 * Return: u abs rep of an unsigned integer of x
 */
unsigned int get_absolute(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}



/**
 * get_buff_base_num - fills the buffer with the correct numbers up to Base 36
 * @number: number to be converted to a string given Base
 * @Base: the Base of the number used in the conversion; only base 36
 * @buff:  buffer to be filled with the conversion's result
 * @Size_buff: number of bytes in the buffe.
 * Return: always nothing.
 */
void get_buff_base_num(unsigned int number, unsigned int base,
			char *buff, int Size_buff)
{
	int R;
	int x = Size_buff - 1;
	buff[Size_buff] = '\0';

	while (x >= 0)
	{
		R = number % base;
		if (R > 9) /* return lowercase ascii val representation */
			buff[x] = R + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[x] = R + '0';
		number /= base;
		x--;
	}
}

/**
 * gets_integer -  returns a pointer to a new string containing int
 * @number: number to be converted to a string.
 *
 * Return:  pointer of a character to a new string. If malloc fails, NULL.
 */
char *gets_integer(int number)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = get_absolute(number);
	length = gets_line_base_num(temp, 10);

	if (number < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	get_buff_base_num(temp, 10, ret, length);
	if (number < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * gets_line_base_num -  determines the length of the buffer required for
 * an unsigned int
 * @number: the number to get the required length needed for.
 * @Base:  buffer's base number representation.
 *
 * Return: an integer with the length of bufferrequired.
 */
int gets_line_base_num(unsigned int number, unsigned int Base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (number > Base - 1)
	{
		len++;
		number /= Base;
	}
	return (len);
}
