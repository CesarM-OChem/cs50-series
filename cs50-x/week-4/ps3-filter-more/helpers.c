#include "helpers.h"
#include <math.h>

// Helper function prototype
void sumRGB(float array[], RGBTRIPLE pixel);

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
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
        
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int counter = 1;
            float sum[3] = {0, 0, 0}; // Array of RGB sum values

            sumRGB(sum, copy[i][j]);

            // Checks for upper row and top left and right pixels
            if(i > 0){
                sumRGB(sum, copy[i - 1][j]);
                counter++;

                if(j > 0){
                    sumRGB(sum, copy[i - 1][j - 1]);
                    counter++;
                }

                if(j < width - 1){
                    sumRGB(sum, copy[i - 1][j + 1]);
                    counter++;
                }
            }

            // Checks for lower row and bottom left and right pixels
            if(i < height - 1){
                sumRGB(sum, copy[i + 1][j]);
                counter++;

                if(j > 0){
                    sumRGB(sum, copy[i + 1][j - 1]);
                    counter++;
                }

                if(j < width - 1){
                    sumRGB(sum, copy[i + 1][j + 1]);
                    counter++;
                }
            }

            // Checks for left pixel
            if(j > 0){
                sumRGB(sum, copy[i][j - 1]);
                counter++;
            }

            // Checks for right pixel
            if(j < width - 1){
                sumRGB(sum, copy[i][j + 1]);
                counter++;
            }

            sum[0] = round(sum[0] / counter);
            sum[1] = round(sum[1] / counter);
            sum[2] = round(sum[2] / counter);

            if(sum[0] > 255){
                sum[0] = 255;
            }

            if(sum[1] > 255){
                sum[1] = 255;
            }

            if(sum[2] > 255){
                sum[2] = 255;
            }

            image[i][j].rgbtRed = (int)sum[0];
            image[i][j].rgbtGreen = (int)sum[1];
            image[i][j].rgbtBlue = (int)sum[2];
        }
    }
    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Sums the RGB values to the sum array
void sumRGB(float array[], RGBTRIPLE pixel){
    array[0] += pixel.rgbtRed;
    array[1] += pixel.rgbtGreen;
    array[2] += pixel.rgbtBlue;
    
    return;
}