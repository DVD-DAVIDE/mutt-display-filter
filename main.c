#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *get_stdin();

int main(int argc, char **argv) {
	char *input = get_stdin();
	printf("%s", input);
	exit(0);
}

char *get_stdin() {
	char *str = malloc(sizeof(str));
	if (str == NULL)
		exit(EXIT_FAILURE);

	size_t index = 0;
	size_t length = 1;

	while(1) {
		int tmp_c = getc(stdin);

		if(tmp_c == EOF) {
			str[index] = '\0';
			return str;
		}
		
		str[index] = (char)tmp_c;
		index++;
		length++;

		char *tmp_str = realloc(str, length * sizeof(char));
		if(tmp_str == NULL)
			exit(EXIT_FAILURE);

		str = tmp_str;
	}
}

