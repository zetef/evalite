#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 2) {
		//TODO add args
		printf("usage: %s \033[4mdir\033[0m [args]\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *dir_name = argv[1];
	printf("%s\n", dir_name);


	return EXIT_SUCCESS;
}
