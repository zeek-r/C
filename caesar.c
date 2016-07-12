#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// make main program accept command line arguement

int main(int argc, char * argv[])
{   
    // check whether the integer counter is 2 or not
    if (argc == 2 && argv[1] >= 0)
    {
        // change key to integer
        int key = atoi(argv[1]);
        char *message = malloc(100*sizeof(char));
        scanf ("%[^\n]%*c", message);;
        // Get input message and start a loop for encypting message.
        for (int i = 0; i < strlen(message); i++)
        {
            // Encryption for uppercase letters
            if (message[i] <= 'Z' && message[i] >= 'A')
            {
                int Message = message[i];
                Message = ((Message - 'A') + key) % 26 + 'A';
                printf("%c", Message);
            }
            // Encryption for lower case letters
            else if (message[i] <= 'z' && message[i] >= 'a')
            {
                int Message = message[i];
                Message = ((Message - 'a') + key) % 26 + 'a';
                printf("%c", Message);
            }
            // prints non-alphabetic character as it is
            else
                printf("%c", message[i]);
        }
        printf("\n");
        return 0;
    }
    // IF arguement counter is more than 2
    else
    {
        printf("Please type>> ./caesar (ur key)\n");
        return 1;
   }
}
