// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

void black_and_white();
void invert();
void merge();
void flip();
void rotate();
void darken_or_lighten();
//void skew_image_right();
void skew_image_up();

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
unsigned char imageR[SIZE][SIZE][RGB];

void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    doSomethingForImage();
    saveImage();
    return 0;
}

//_________________________________________
void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

//_________________________________________
void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

//_________________________________________
void doSomethingForImage()
{
    cout << "1-Black and White" << endl;
    cout << "2-Invert " << endl;
    cout << "3-Merge" << endl;
    cout << "4-Flip" << endl;
    cout << "5-Rotate" << endl;
    cout << "6-Darken or Lighten" << endl;
    cout << "7-detect image edge" << endl;
    cout << "8-enlarge image" << endl;
    cout << "9-shrink image" << endl;
    cout << "10-mirror image" << endl;
    cout << "11-shuffle image" << endl;
    cout << "12-blur image" << endl;
    cout << "13-crop image" << endl;
    cout << "14-skew image_right" << endl;
    cout << "15-skew image_up" << endl;
    cout << "Choose filter : ";
    string filter;
    cin >> filter;
    if (filter == "1")
    {
        black_and_white();
    }
    else if (filter == "2")
    {
        invert();
    }
    else if (filter == "3")
    {
        merge();
    }
    else if (filter == "4")
    {
        flip();
    }
    else if (filter == "5")
    {
        //finish
        rotate();
    }
    else if (filter == "6")
    {
        darken_or_lighten();
    }
    /*
    else if (filter == "7")
    {
        detect_image_edge();
    }
    else if (filter == "8")
    {
        enlarge_image();
    }
    else if (filter == "9")
    {
        shrink_image();
    }
    else if (filter == "10")
    {
        mirror_image();
    }
    else if (filter == "11")
    {
        shuffle_image();
    }
    else if (filter == "12")
    {
        blur_image();
    }
    else if (filter == "13")
    {
        crop_image();
    }
    else if (filter == "14")
    {
       //skew_image_right();
    }
    else if (filter == "15")
    {
        skew_image_up();
    }
    */
}


// The Merge filter merges two images into one...
void merge()
{
    char imageFileName1[100];
    cout << "Enter the source of the second image file name: ";
    cin >> imageFileName1;
    strcat(imageFileName1, ".bmp");
    readRGBBMP(imageFileName1, image1);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
            image[i][j][k] = (image1[i][j][k] + image[i][j][k]) / 2;
            }
        }
    }
}

void rotate()
{
    cout << "Choose the Angle: " << endl;
    cout << "1-90 degree" << endl;
    cout << "2-180 degree" << endl;
    cout << "3-270 degree" << endl;
    int Angle;
    cin >> Angle;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                imageR[i][j][k] = image[i][j][k];
            }
        }
    }
    if (Angle == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
            {
                swap(image[255 - j][i][k], imageR[i][j][k]);
            }
            }
        }
    }
    else if (Angle == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
            {
                swap(image[255 - i][255 - j][k], imageR[i][j][k]);
            }
            }
        }
    }
    else if (Angle == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
            {
                swap(image[j][255 - i][k], imageR[i][j][k]);
            }
            }
        }
    }
}
