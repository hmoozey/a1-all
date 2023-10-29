// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-S22-20220729-20220974-20220731-A1-BONUS.cpp
// Last Modification Date:	9/10/2023
// Author1 and ID and Group:	20220729 /email : hmoozey200@gmail.com
// Author2 and ID and Group:	20220974 /email : Mohamad200a00@hotmail.com
// Author3 and ID and Group:	20220731 /email : ahmed.abdalluh@icloud.com
// Teaching Assistant:		xxxxx xxxxx
// Purpose:..........

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
void enlarge_image();
void enlarge();

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
    string fi;
    cin >> fi;
    if (fi == "1")
    {
        rotate();
    }
    else if (fi == "2")
    {
        merge();
    }
    else if (fi == "3")
    {
        flip();
    }
    else if (fi == "4")
    {
        black_and_white();
    }
    else if (fi == "5")
    {
        enlarge();
    }
}
//_________________________________________

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

void flip()
{
    cout << "1-sides " << endl;
    cout << "2-flip" << endl;
    int sf;
    cin >> sf;
    if (sf == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j <= 127; j++)
            {
                for (int k = 0; k < RGB; k++)
                    swap(image[i][j][k], image[i][255 - j][k]);
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
