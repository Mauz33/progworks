#include <iostream>
#include "libbmp.h"


int main()
{
	BmpImg image;
	image.read("pic3.bmp");
	
	int width = image.get_width();
	int height = image.get_height();
	char text[5000];
	char shift = 0;
	int position = 0;
	int counter = 0;
	int pixel;
	bool stop = false;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			pixel = image.red_at(x, y);
			shift = shift << 1;			// 00000000
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}

			pixel = image.green_at(x, y);
			shift = shift << 1;
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}

			pixel = image.blue_at(x, y);
			shift = shift << 1;	
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}
		}
		if (stop) break;
	}
	std::cout << text;

}