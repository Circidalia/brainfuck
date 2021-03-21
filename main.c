#include <unistd.h>
#include <stdlib.h>

#define OPERATIONS 2048

char	*loopForward(register char *args) {
	register short others = 0;
	
	args++;
	while (*args != ']' || others) {
		switch (*args) {
			case '[':
				others++;
				break;
			case ']':
				others--;
				break;
			default:
				break;
		}
		args++;
	}
	return (args);
}

char	*loopBackward(register char *args) {
	register short others = 0;
	
	args--;
	while (*args != '[' || others) {
		switch (*args) {
			case ']':
				others++;
				break;
			case '[':
				others--;
				break;
			default:
				break;
		}
		args--;
	}
	return (args);
}

void	brainfuck(register char *args) {
	register unsigned char *ptr = (unsigned char *)malloc(sizeof(unsigned char) * OPERATIONS);
	register unsigned char *t = ptr;
	register short i = 0;
	
	while (i < OPERATIONS) {
		ptr[i] = 0;
		++i;
	}
	while (*args) {
		switch (*args) {
			case '>':
				ptr++;
				break;
			case '<':
				ptr--;
				break;
			case '+':
				(*ptr)++;
				break;
			case '-':
				(*ptr)--;
				break;
			case '.':
				write(1, ptr, 1);
				break;
			case '[':
				if (!(*ptr)) args = loopForward(args);
				break;
			case ']':
				if (*ptr) args = loopBackward(args);
				break;
			default:
				break;
		}
		args++;
	}
	free(t);
}

int		main(int argc, char **argv) {
	if (argc == 2) brainfuck(argv[1]);
	return (0);
}
