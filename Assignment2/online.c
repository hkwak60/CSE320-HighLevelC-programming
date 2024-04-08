#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apple {
	int weight;
	char color[10];
} Apple;

int main(int argc, char *argv[]) {
	
	Apple *ap = (Apple *)malloc(2*sizeof(Apple));
	if (ap == NULL) {
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}
	for (int i = 0; i < 2; i++) {
		printf("Apple %d. Color: ", i + 1);
		scanf("%s", ap[i].color);
		printf("Apple %d. Weight: ", i + 1);
		scanf("%d", &ap[i].weight);
	}

	for (int i = 0; i < 2; i++) {
		printf("Apple %d. has %s color and weights %d g.\n", i + 1, ap[i].color, ap[i].weight);
	}

	FILE *fp = fopen("apples.bin", "wb+");
	if (fp == NULL) {
		fprintf(stderr, "Error could not open a file.\n");
		exit(1);
	}

	fwrite(ap, sizeof(Apple), 2, fp);
	rewind(fp);

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
	free(ap);
	return 0;
}