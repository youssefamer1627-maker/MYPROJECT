#define _CRT_SECURE_NO_WARNINGS
#include "image_Class.h"
#include <iostream>
using namespace std;
void rotateImage(Image& image) {
    int choice;
    cout << "Choose angle (90, 180, 270): ";
    cin >> choice;

    int times = choice / 90;
    for (int t = 0; t < times; ++t) {
        Image rotated(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    rotated.setPixel(j, image.width - 1 - i, k, image.getPixel(i, j, k));
                }
            }
        }
        image = rotated;
    }
}


int main() {
    Image image("test.jpg");

    rotateImage(image);


    image.saveImage("test_rotated.jpg");

    cout << "Done!" << endl;
    return 0;
}

