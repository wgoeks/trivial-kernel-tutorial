/*
 *  kernel.c
 */
void kmain(void) 
{
 	const char *str = "My first kernel!";
	char *vidptr = (char*)0xb8000; // Video memory begins here
	unsigned int i = 0;
	unsigned int j = 0;
	
	/* This loop clears the screen
	 * There are 25 lines x 80 cols and each element takes 2 bytes */
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		/* attribute-byte  - green on black background */
		vidptr[j + 1] = 0x02;
		j += 2;
	}

	j = 0;

	/* This loop writes the string to video memory */
	while(str[j] != '\0') {
		/* The character's ASCII value */
		vidptr[i] = str[j];
		/* Attribute-byte: give the char black background & green body */
		vidptr[i + 1] = 0x02;
		++j;
		i += 2;
	}
	return;
}
