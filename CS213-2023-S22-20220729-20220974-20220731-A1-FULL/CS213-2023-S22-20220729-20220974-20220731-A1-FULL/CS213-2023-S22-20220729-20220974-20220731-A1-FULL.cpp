// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-S22-20220729-20220974-20220731-A1-FULL.cpp
// Last Modification Date:	9/10/2023
// Author1 and ID and Group:	20220729 /email : hmoozey200@gmail.com
// Author2 and ID and Group:	20220974 /email : Mohamad200a00@hotmail.com
// Author3 and ID and Group:	20220731 /email : ahmed.abdalluh@icloud.com
// Teaching Assistant:		xxxxx xxxxx
// Purpose:..........

#include <iostream>
#include <vector>
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
void detect_image_edge();
void enlarge_image();
void shrink_image();
void mirror_image();
void shuffle_image();
void blur_image();
void crop_image();
void skew_image_right();
void skew_image_up();

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
    cout << "1-detect image edge" << endl;
    cout << "2-enlarge image" << endl;
    cout << "3-shrink image" << endl;
    cout << "4-mirror image" << endl;
    cout << "5-shuffle image" << endl;
    cout << "6-blur image" << endl;
    cout << "7-crop image" << endl;
    cout << "8-skew image_right" << endl;
    cout << "9-skew image_up" << endl;
    cout << "Choose filter : ";
    string filter;
    cin >> filter;
    if (filter == "1")
    {
        detect_image_edge();
    }
    else if (filter == "2")
    {
        enlarge_image();
    }
    else if (filter == "3")
    {
        shrink_image();
    }
    else if (filter == "4")
    {
        mirror_image();
    }
    else if (filter == "5")
    {
        shuffle_image();
    }
    else if (filter == "6")
    {
        blur_image();
    }
    else if (filter == "7")
    {
        crop_image();
    }
    else if (filter == "8")
    {
        skew_image_right();
    }
    else if (filter == "9")
    {
        skew_image_up();
    }
}

//this code detect the edges of the object in the image
void detect_image_edge()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((image[i][j] < image[i][j + 1] + 50 && image[i][j] > image[i][j + 1] - 50) || image[i][j] < 20 - (image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 3)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

//this code upscales the image
void enlarge_image()
{
    int q;
    cout << "1-first corner" << endl;
    cout << "2-second corner" << endl;
    cout << "3-third corner" << endl;
    cout << "4-fourth corner" << endl;
    cin >> q;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image1[i][j] = image[i][j];
        }
    }
    if (q == 1)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                image[2 * i][2 * j] = image1[i][j];
                image[2 * i + 1][2 * j] = image1[i][j];
                image[2 * i][2 * j + 1] = image1[i][j];
                image[2 * i + 1][2 * j + 1] = image1[i][j];
            }
        }
    }
    else if (q == 2)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 127; j < 255; j++)
            {
                image[2 * i][2 * (j - 127)] = image1[i][j];
                image[2 * i + 1][2 * (j - 127)] = image1[i][j];
                image[2 * i][2 * (j - 127) + 1] = image1[i][j];
                image[2 * i + 1][2 * (j - 127) + 1] = image1[i][j];
            }
        }
    }
    else if (q == 3)
    {
        for (int i = 127; i < 255; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                image[2 * (i - 127)][2 * j] = image1[i][j];
                image[2 * (i - 127) + 1][2 * j] = image1[i][j];
                image[2 * (i - 127)][2 * j + 1] = image1[i][j];
                image[2 * (i - 127) + 1][2 * j + 1] = image1[i][j];
            }
        }
    }
    else if (q == 4)
    {
        for (int i = 127; i < 255; i++)
        {
            for (int j = 127; j < 255; j++)
            {
                image[2 * (i - 127)][2 * (j - 127)] = image1[i][j];
                image[2 * (i - 127) + 1][2 * (j - 127)] = image1[i][j];
                image[2 * (i - 127)][2 * (j - 127) + 1] = image1[i][j];
                image[2 * (i - 127) + 1][2 * (j - 127) + 1] = image1[i][j];
            }
        }
    }
}

//this code downscale the image
void shrink_image()

{
    int q;
    cout << "1-1/2" << endl;
    cout << "2-1/3" << endl;
    cout << "3-1/4" << endl;
    cout << "choose :";
    cin >> q;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image1[i][j] = image[i][j];
        }
    }
    if (q == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i > 127 || j > 127)
                    image[i][j] = 255;
                else
                {
                    image[i][j] = image[2 * i][2 * j];
                }
            }
        }
    }
    else if (q == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i > 85 || j > 85)
                    image[i][j] = 255;
                else
                {
                    image[i][j] = image[3 * i][3 * j];
                }
            }
        }
    }
    else if (q == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i > 64 || j > 64)
                    image[i][j] = 255;
                else
                {
                    image[i][j] = image[4 * i][4 * j];
                }
            }
        }
    }
}

//this code mirrors the wanted side of the image
void mirror_image()
{
    int q;
    cout << "1-mirror lower" << endl;
    cout << "2-mirror right" << endl;
    cout << "3-mirror upper" << endl;
    cout << "4-mirror left" << endl;
    cout << "choose : ";
    cin >> q;
    if (q == 1)
    {
        for (int i = 0; i < 127; i++)
        {
            for (int j = 0; j < 255; j++)
            {

                image[i][j] = image[255 - i][j];
            }
        }
    }
    else if (q == 2)
    {
        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < 127; j++)
            {
                image[i][j] = image[i][255 - j];
            }
        }
    }
    else if (q == 3)
    {
        for (int i = 0; i < 127; i++)
        {
            for (int j = 0; j < 255; j++)
            {
                image[255 - i][j] = image[i][j];
            }
        }
    }
    else if (q == 4)
    {
        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < 127; j++)
            {

                image[i][255 - j] = image[i][j];
            }
        }
    }
}

//this code reorganize the image as you please
void shuffle_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image1[i][j] = image[i][j];
        }
    }
    int x = 0, y = 0;
    for (int k = 0; k < 4; k++)
    {
        int g;
        cin >> g;
        int w, l;

        if (k == 0 || k == 1)
        {
            x = 0;
        }
        else
        {
            x = 128;
        }

        if (g == 1)
        {
            w = 0;
            l = 0;
        }
        else if (g == 2)
        {
            w = 128;
            l = 0;
        }
        else if (g == 3)
        {
            w = 0;
            l = 128;
        }
        else if (g == 4)
        {
            w = 128;
            l = 128;
        }
        for (int i = 0 + l; i <= 128 + l; i++)
        {
            for (int j = 0 + w; j <= 128 + w; j++)
            {
                image[x - 1][y] = image1[i][j];
                y++;
            }
            if (k == 0 || k == 2)
            {
                y = 0;
            }
            else
            {
                y = 128;
            }
            x++;
        }
    }
}

//this code blur the image
void blur_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image1[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            image[i][j] = (image1[i - 1][j - 1] + image[i][j - 1] + image[i - 1][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j - 1] + image[i - 1][j + 1] + image[i + 1][j + 1]) / 8;
        }
    }
}

//this code cut the image 
void crop_image()
{
    int x, y, w, l;
    cout << "enter X: ";
    cin >> x;
    cout << "enter Y: ";
    cin >> y;
    cout << "enter W: ";
    cin >> w;
    cout << "enter L: ";
    cin >> l;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((x > i || y > j) || (i > x + w || j > y + l))
            {
                image[i][j] = 255;
            }
        }
    }
}

void skew_image_right(int degree)
{
}
void skew_image_up()
{
}