/*
* Filename: f7.cpp
* Project: Focused Assignment 7
* By: Jongeon Lee
* Date: Mar 24, 2023
* Description: Write a program to give you practice at creating text and binary files.
*/

#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
    FILE *fpTxt = NULL;
    fpTxt = fopen("myTextFile.txt", "w");

    if (fpTxt == NULL)
    {
        printf("Error-fopen function: Can't open file for writing\n");
        return -1;
    }

    for (int i = 1; i < 3; i++)
    {
        if (fprintf(fpTxt, "This is line %d.\n", i) < 0)
        {
            printf("Error-fopen function: Can't write line to file\n");
            return -1;
        }
    }

    if (fclose(fpTxt) != 0)
    {
        printf("Error-fclose function:Can't close file opened for writing\n");
        return -1;
    }

    FILE *fpBinary = NULL;
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
    
    fpBinary = fopen("myBinaryFile.data", "wb");
    
    if (fpBinary == NULL)
    {
        printf("Error-fopen function: Can't open file for writing\n");
        return -1;
    }

    if (fwrite(kBinaryData, 1, sizeof(kBinaryData), fpBinary) < 11)
    {
        printf("Error-fwrite function: Can't write to file\n");
        return -1;
    }

    if (fclose(fpBinary) != 0)
    {
        printf("Error-fclose function:Can't close file opened for writing\n");
        return -1;
    }

	return 0;
}