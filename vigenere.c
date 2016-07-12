/** Implementation of Vigenere Cipher using C **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    // Checks that only 2 arguements are passed.
    if (argc == 2 )
    {
        // checks whether each character of keyword is alphabet or not 
        for (int x = 0; x < strlen(argv[1]); x++)
        {
            if (isalpha(argv[1][x]))
            {
                continue;
            }
            else
            {
                printf("Wrong Usage!!\nKeywords must be alphabet only\n");
                return 1;
            }
        }
        // prompts user for input
        char *message = malloc(500*sizeof(char));
        scanf("%[^\n]%*c", message);
        // counter for keyword
        int j = 0; 
        for (int i = 0; i < strlen(message); i++)
        {
            // encrypts upper case and lower case alphabets
            if (message[i] <= 'Z' && message[i] >= 'A')
            {
                int inner_array = j % (strlen(argv[1]));
                char keyword = tolower(argv[1][inner_array]) - 'a';
                int Message = message[i];
                Message = ((Message - 'A') + keyword) % 26 + 'A';
                printf("%c", Message);
                j++;
            }
            else if (message[i] <= 'z' && message[i] >= 'a')
            {
                int inner_array = j % (strlen(argv[1]));
                char keyword = tolower(argv[1][inner_array]) - 'a';
                int Message = message[i];
                Message = ((Message - 'a') + keyword) % 26 + 'a';
                printf("%c", Message);
                j++;
            }
            // If the message contains character other than alphabet
            else
            {
                printf("%c", message[i]);
            }
        }
        printf("\n");        
        return 0;
    }
    // If more than two arguements are passed
    else
    {
        printf("Wrong Usage\n Correct: ./vigenere (keyword, alphabets only)\n");
        return 1;
    }
}
