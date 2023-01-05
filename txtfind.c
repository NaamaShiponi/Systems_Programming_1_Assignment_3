#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int main()
{
    char buffer_line[LINE] = {"\0"};
    char buffer_word[WORD] = {"\0"};
    char key_word[WORD] = {"\0"};
    char char_command[2] = {"\0"};
    int place_in_string = 0;

    // find the key word and the char command
    fgets(buffer_line,LINE, stdin);
    place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
    strcpy(key_word, buffer_word);
    place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
    strcpy(char_command, buffer_word);

    fgetc(stdin);

    if (char_command[0] == 'a')
    {
        // Performs the loop until the file being run from runs out
        while(fgets(buffer_line,LINE, stdin)!=NULL)
        {
            place_in_string = 0;
            // Performs the loop until the end of the line
            while(place_in_string<=strlen(buffer_line))
            {
                place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
                // Checks whether the key word is a sub-word of the tested word
                if(sub(key_word, buffer_word) == TRUE)
                {
                    *(buffer_line + strlen(buffer_line)-1) = '\0';
                    printf("%s\n", buffer_line);
                    break;
                }
            }
        } 
    }
    else if (char_command[0] == 'b')
    {
        // Performs the loop until the file being run from runs out
        while(fgets(buffer_line,LINE, stdin)!=NULL)
        {
            place_in_string = 0;
            while(place_in_string<=strlen(buffer_line))
            {
                place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
                // Checking whether the words are identical up to a difference of one letter
                if(is_similar(key_word, buffer_word) == TRUE)
                {
                    printf("%s\n", buffer_word);
                }
            }

        }       
    }
    
}

int get_word_string(char* line, char* word, int place_in_string)
{
    int i = place_in_string;
    int j = 0;
    char ch = 'a';
    memset(word, '\0', WORD);
    // What defines the end of a word?
    while ((ch!=' ')&&(ch!='\t')&&(ch!='\r')&&(ch!='\n')&&(i<=strlen(line)))
    {
        ch = *(line+i);
        *(word+j) = ch;  
        i++;
        j++;
    }
    // To define a word according to c, you need to put a '\0' at the end of the word 
    *(word + (j-1)) = '\0';
    return i;
}

int sub(char* source, char* word_under_test)
{
    int i=0;
    int j=0;

    while(*(word_under_test+j)!='\0')
    {
        // As soon as you reach the first letter that is similar, you need to check the rest of the letters in the key word
        if (*(source)==*(word_under_test+j))
        {
            while(i<strlen(source))
            {
                if (*(source+i)!=*(word_under_test+(j+i)))
                {
                    return FULSE;
                }
                i++;
            }
            return TRUE;
        }
        else if (*(source)!=*(word_under_test+j))
        {
            j++;
        }
    }
    return FULSE;    
}


int is_similar(char* source, char* word_under_test)
{
    int i=0;
    int j=0;
    int different_letters = 1;
    int count_different_letters = 0;

    while(*(word_under_test+j)!='\0')
    {
        // If the letters in this position are equal then the following letters should be checked
        if (*(source+i)==*(word_under_test+j))
        {
            i++;
            j++;
        }
        else if (*(source+i)!=*(word_under_test+j))
        {
            count_different_letters++;
            /*
            1.If the length of the tested word is less than the key word, then the words are necessarily different
            2.If we found different letters above the value of different_letter the words are too different
            3.If the length of the tested word is greater than the length of key word + different letter
            */
            if ((strlen(word_under_test)<strlen(source))||(count_different_letters>different_letters)||(strlen(word_under_test)>(strlen(source)+different_letters)))
            {
                return FULSE;
            }
            j++;
        }
    }
    // Cover the case that the length of the word is 0
    if(strlen(word_under_test) == 0)
    {
        return FULSE;
    }
    return TRUE;
}










