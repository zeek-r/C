/**
 * recover.c
 *
 *
 * Recovers JPEGs from a forensic image.
 */
	#include<stdio.h>
	#include<stdlib.h>
	#include<stdint.h>
 typedef uint8_t  BYTE;

 

int main()
{
    BYTE hex[512];
    FILE *file = fopen("/Desktop/jpg", "r");
    if(file == NULL)
    {
        fclose(file);
        printf("OOPs!! The input file can't be opened\n");
        return 1;
    }

    int counter = 0;
    char filename[20];
    FILE *output = NULL ;

    while(1)
    {
        fread(hex, sizeof(hex), 1, file);
        if(feof(file))
        {
            fclose(output);
            break;
        }
        
        if(hex[0] == 255 && hex[1]== 216 && hex[2] == 255 && (hex[3] >= 224 || hex[3] <= 239))
        {
            if(output == NULL)
            {
                sprintf(filename, "%03d.jpg", counter);
                counter++;
                output = fopen(filename,"w");
                fwrite(hex, sizeof(hex), 1, output); 
            }
            else
            {
                fclose(output);
                sprintf(filename, "%03d.jpg", counter);
                counter++;
                output = fopen(filename,"w");
                fwrite(hex, sizeof(hex), 1, output);
            }
        }
        else
        {
            if(output != NULL)
            fwrite(hex, sizeof(hex), 1, output);
        }
    }
    fclose(file);
    return 0;
}
