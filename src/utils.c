#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_junk(const char *file) {
	int bytes_to_corrupt;
	FILE *f = fopen(file, "r+b");

	if (!f) {
		perror("fopen");
		return;
	}

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	rewind(f);

	if (size >= 0 && size <= 100) {
		bytes_to_corrupt = 100;
	} else if (size >= 101 && size <= 1024) {
		bytes_to_corrupt = 1000;
	} else if (size >= 1025 && size <= 10240) {
		bytes_to_corrupt = 10000;
	} else if (size < 0) {
		fprintf(stderr, "File is already corrupted ! (file size below zero : %ld\n", size);
		fclose(f);
		return;
	} else {
		bytes_to_corrupt = 100000;
	}
		
	srand(time(NULL));
	for (int i = 0; i < bytes_to_corrupt; i++) {
		long pos = rand() % size;
		fseek(f, pos, SEEK_SET);
		char junk = (char)(rand() % 256);
		fwrite(&junk, 1, 1, f);
	}

	printf("File successfully corrupted\n");

	fclose(f);
}
