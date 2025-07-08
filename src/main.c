#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Provide a file name\n");
		return 1;
	}
	
	char choice[10];
	printf("Are you sure you want to corrupt '%s' ? [Y/N]\n", argv[1]);
	
	printf(">");
	fgets(choice, 10, stdin);
	choice[strcspn(choice, "\n")] = 0;

	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
		create_junk(argv[1]);
	} else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0) {
		printf("File corruption aborted\n");
	} else {
		printf("Unknown choice : %s\n", choice);
		printf("Aborting file corruption\n");
	}

	return 0;
}
