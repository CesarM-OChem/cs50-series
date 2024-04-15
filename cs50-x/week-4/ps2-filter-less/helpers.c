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

            average += image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            average /= 3;

            if(average >=255){
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 255;
                image[i][j].rgbtBlue = 255;
            }else{
                image[i][j].rgbtRed = (int) round(average);
                image[i][j].rgbtGreen = (int) round(average);
                image[i][j].rgbtBlue = (int) round(average);
            }
        }

    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float sepiaRed, sepiaGreen, sepiaBlue;

            sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

            if(sepiaRed > 255){
                sepiaRed = 255;
            }

            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }

            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
            float sum[3] = {0, 0, 0}; // Array of Red, Green and Blue sums, respectively
            sumRGB(sum, copy[i][j]);

            //Checks for row above, then for columns in the left and in the right
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

            //Checks for row below, then for columns in the left and in the right
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

            //Checks for left and right
            if(j > 0){
                sumRGB(sum, copy[i][j - 1]);
                counter++;
            }

            if(j < width - 1){
                sumRGB(sum, copy[i][j + 1]);
                counter++;
            }

            //Calculate average and caps the value to the maximum of 255
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

//Helper sum function
void sumRGB(float array[], RGBTRIPLE pixel){
    array[0] += pixel.rgbtRed;
    array[1] += pixel.rgbtGreen;
    array[2] += pixel.rgbtBlue;

    return;
}
