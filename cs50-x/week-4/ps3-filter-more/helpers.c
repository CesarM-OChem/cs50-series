#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float average = 0;
            average += image[i][j].rgbtRed;
            average += image[i][j].rgbtGreen;
            average += image[i][j].rgbtBlue;
            average = round(average / 3);

            if(average > 255){
                average = 255;
            }

            image[i][j].rgbtRed = (int)average;
            image[i][j].rgbtGreen = (int)average;
            image[i][j].rgbtBlue = (int)average;
        }
        
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
