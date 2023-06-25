#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* input = fopen(argv[1], "rb");
	FILE* output = fopen(argv[2], "wb");

	char irrelevant[2];
	int sirina = 0;
	int visina = 0;
	int irrelevanter = 0;
	fscanf(input, "%s%d%d%d", irrelevant, &sirina, &visina, &irrelevanter);
	fgetc(input);

	fprintf(output, "P5\n%d %d\n255\n", sirina, visina);
	for (int i = 0; i < visina * sirina; i++) {
		unsigned char pixel[3];
		fread(pixel, sizeof(unsigned char), 3, input);
		unsigned char gray = (30 * pixel[0] + 59 * pixel[1] + 11 * pixel[2]) / 100;
		fwrite(&gray, sizeof(unsigned char), 1, output);
	}
	
	fclose(input);
	fclose(output);
	return 0;
}