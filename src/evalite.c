#include <stdlib.h>
#include <stdio.h>

#include "../libs/tinydir/tinydir.h"

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 2) {
		//TODO add args
		printf("usage: %s \033[4mdir\033[0m [args]\n", argv[0]);
		return EXIT_FAILURE;
	}

	tinydir_dir dir;
	char *dir_name = argv[1];
	printf("%s:\n", dir_name);
	tinydir_open(&dir, dir_name);
	
	while (dir.has_next) {
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		printf("%s", file.name);
		if (file.is_dir) {
			printf("/");
		}
		printf("\n");

		tinydir_next(&dir);
	}

	tinydir_close(&dir);

	return EXIT_SUCCESS;
}
