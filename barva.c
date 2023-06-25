#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	FILE* image = fopen(argv[1], "rb");
	int vrstica = atoi(argv[2]);
	int stolpec = atoi(argv[3]);
	
	char irrelevant[2];
	int sirina = 0;
	int visina = 0;
	int irrelevanter = 0;
	fscanf(image, "%s%d%d%d", irrelevant, &sirina, &visina, &irrelevanter);
	fgetc(image);

	unsigned char red = 0;
	unsigned char green = 0;
	unsigned char blue = 0;
	int pixel = vrstica * sirina + stolpec;
	for (int i = 0; i <= pixel; i++) {
		unsigned char dot[3];
		fread(dot, sizeof(unsigned char), 3, image);
		if (pixel == i) {
			red = dot[0];
			green = dot[1];
			blue = dot[2];
		}
	}

	printf("%d %d %d\n", red, green, blue);
	fclose(image);
	return 0;
}