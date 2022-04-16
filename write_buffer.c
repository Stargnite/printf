#include "main.h"
#include <unistd.h>

/**
 * write_buffer - print out the buffer of all characters
 * @buffer: buffer with string to print
 * @buflen: pointer to the length of buffer
 * @bufpos: pointer to the position inside buffer
 */

void write_buffer(char buffer[], int *buflen, int *bufpos)
{
	write(1, buffer, *buflen - 1);
	*bufpos = 0;
	*buflen = 1;
}
