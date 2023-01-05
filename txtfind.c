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
    
    fgets(buffer_line,LINE, stdin);
    place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
    strcpy(key_word, buffer_word);
    place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
    strcpy(char_command, buffer_word);

    fgetc(stdin);

    if (char_command[0] == 'a')
    {
        while(fgets(buffer_line,LINE, stdin)!=NULL)
        {
            place_in_string = 0;
            while(place_in_string<=strlen(buffer_line))
            {
                place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
                if(sub(key_word, buffer_word) == TRUE)
                {
                    *(buffer_line + strlen(buffer_line)-1) = '\0';
                    printf("%s\n", buffer_line);
                    break;
                }
            }
        }printf("\n"); 
    }
    else if (char_command[0] == 'b')
    {
        while(fgets(buffer_line,LINE, stdin)!=NULL)
        {
            place_in_string = 0;
            while(place_in_string<=strlen(buffer_line))
            {
                place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
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

    while ((ch!=' ')&&(ch!='\t')&&(ch!='\r')&&(ch!='\n')&&(i<=strlen(line)))
    {
        ch = *(line+i);
        *(word+j) = ch;  
        i++;
        j++;
    }
    *(word + (j-1)) = '\0';
    // printf("%s, %ld\n", word, strlen(word));
    return i;
}

int sub(char* source, char* word_under_test)
{
    int i=0;
    int j=0;

    while(*(word_under_test+j)!='\0')
    {
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
        if (*(source+i)==*(word_under_test+j))
        {
            i++;
            j++;
        }
        else if (*(source+i)!=*(word_under_test+j))
        {
            count_different_letters++;
            if ((strlen(word_under_test)<strlen(source))||(count_different_letters>different_letters)||(strlen(word_under_test)>(strlen(source)+different_letters)))
            {
                return FULSE;
            }
            j++;
        }
    }
    if(strlen(word_under_test) == 0)
    {
        return FULSE;
    }
    return TRUE;
}










