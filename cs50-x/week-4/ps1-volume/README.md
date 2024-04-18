# Volume

## Text extracted from CS50:

WAV files are a common file format for representing audio. WAV files store audio as a sequence of “samples”: numbers that represent the value of 
some audio signal at a particular point in time. WAV files begin with a 44-byte “header” that contains information about the file itself, including 
the size of the file, the number of samples per second, and the size of each sample. After the header, the WAV file contains a sequence of samples, 
each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.

[...]
  
In a file called ```volume.c``` in a folder called ```volume```, write a program to modify the volume of an audio file.

Complete info in this link:
[CS50/pset4/volume](https://cs50.harvard.edu/x/2024/psets/4/volume/)
