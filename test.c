#include "libftprintf.h"

int main()
{
	printf("int: %i\ndoble: %d\ncharacter: %c\nstring: %s\nhex: %x\nHEX: %X\nmemory: %p", 1, 1, '1', "1", 47, 47, (void *)1);
}