#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apple {
	int weight;
	char color[10];
} Apple;

int main(int argc, char *argv[]) {
	

	FILE *fp = fopen("apples.bin", "rb");
	Apple *tmpApl;
	tmpApl = (Apple *)malloc(2 * sizeof(Apple));
	if (tmpApl == NULL) {
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}
	
	fread(tmpApl, sizeof(Apple), 2, fp);

	for (int i = 0; i < 2; i++) {
		printf("Apple %d. has %s color and weights %d g.\n", i + 1, tmpApl[i].color, tmpApl[i].weight);
	}

	fclose(fp);
	return 0;
}