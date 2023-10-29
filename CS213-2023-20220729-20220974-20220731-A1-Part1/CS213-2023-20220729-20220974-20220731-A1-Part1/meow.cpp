
// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				meow.cpp
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
using namespace std;

// declare images...
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char imageR[SIZE][SIZE];

// declare filter functions...
void black_and_white();
void invert();
void merge();
void flip();
void rotate();
void darken_or_lighten();

// declare the program functions...
void loadImage();
void saveImage();
void doSomethingForImage();

// The body of the program
int main()
{
    loadImage();
    doSomethingForImage();
    saveImage();
    return 0;
}

// loadimage function to load the image from the file...
void loadImage()
{
    char imageFileName[100];

    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
// saveImage to return the result of the procces...
void saveImage()
{
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
// doSomethingForImage is used to choose which filter would you like to use...
void doSomethingForImage()
{
    cout << "1-Black and White" << endl;
    cout << "2-Invert " << endl;
    cout << "3-Merge" << endl;
    cout << "4-Flip" << endl;
    cout << "5-Rotate" << endl;
    cout << "6-Darken or Lighten" << endl;
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
        rotate();
    }
    else if (filter == "6")
    {
        darken_or_lighten();
    }
    
}
// The Black and White filter it changes each pixel to black or white...
void black_and_white()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > 127)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
}
// The Invert filter changes each pixel to it's opposet thing...
void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}
// The Merge filter merges two images into one...
void merge()
{
    char imageFileName1[100];
    cout << "Enter the source of the second image file name: ";
    cin >> imageFileName1;
    strcat(imageFileName1, ".bmp");
    readGSBMP(imageFileName1, image1);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (image1[i][j] + image[i][j]) / 2;
        }
    }
}
// The Flip filter flips the image upside down or sides...
void flip()
{
    cout << "1-sides " << endl
         << "2-flip" << endl;
    int sf;
    cin >> sf;
    if (sf == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j <= 127; j++)
            {
                swap(image[i][j], image[i][255 - j]);
            }
        }
    }
}
// The Rotate filter rotate 90, 180 ,270 degree as you chooses...
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
            imageR[i][j] = image[i][j];
        }
    }
    if (Angle == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                swap(image[255 - j][i], imageR[i][j]);
            }
        }
    }
    else if (Angle == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                swap(image[255 - i][255 - j], imageR[i][j]);
            }
        }
    }
    else if (Angle == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                swap(image[j][255 - i], imageR[i][j]);
            }
        }
    }
}
// The darken/Lighten filter darken or lighten the image as you chooses...
void darken_or_lighten()
{
    cout << "choose lighten or darken" << endl;
    cout << "1-lighten" << endl;
    cout << "2-darken" << endl;
    cout << "Choose filter : ";
    int ld;
    cin >> ld;
    if (ld == 1)
    {
        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if ((image[i][j] + 80) > 255)
                    image[i][j] = 255;
                else
                    image[i][j] = image[i][j] + 80;
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (image[i][j] - 80 < 0)
                    image[i][j] = 0;
                else
                    image[i][j] = image[i][j] - 80;
            }
        }
    }
}