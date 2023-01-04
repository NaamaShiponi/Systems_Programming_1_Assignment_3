#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE 256

int main()
{
    char buffer_line[LINE];
    char buffer_word[WORD];
    char key_word[WORD];
    char char_command[2];
    int place_in_string = 0;
    int different_letters = 0;
    char ch = 'a';

    //    fgets(text,LINE,stdin);


    get_line_file(buffer_line);
    place_in_string = get_word_string(buffer_line, key_word, place_in_string);
    get_word_string(buffer_line, char_command, place_in_string);

    // printf("key word = %s\nchar command = %s\n", key_word, char_command);

    ch = fgetc(stdin);

    if (char_command[0] == 'a')
    {
        different_letters = 0;
        while(ch!=EOF)
        {
            ch = get_line_file(buffer_line);
            // printf("buffer = %s\n", buffer_line);
            place_in_string = 0;
            while(place_in_string<=strlen(buffer_line))
            {
                place_in_string = get_word_string(buffer_line, buffer_word, place_in_string);
                if(sub(key_word, buffer_word) == TRUE)
                {
                    printf("%s\n", buffer_line);
                    break;
                }
            }

        } 

    }
    else if (char_command[0] == 'b')
    {
        char ch = 'a';
        different_letters = 1;
        while(ch!=EOF)
        {
            ch = get_word_file(fp, buffer_word);
            if(is_similar(key_word, buffer_word, different_letters))
            {
                printf("%s\n", buffer_word);
            }
        }        
    }
    fclose(fp);
}



char get_line_file(char* buffer_line)
{
    int i = 0;
    char ch = fgetc(stdin);
    while((ch!='\n')&&(ch!='\r')&&(ch != EOF))
    {
        *(buffer_line + i) = ch;
        i++;
        ch = fgetc(stdin);
    }
    if(ch=='\r')
    {
        ch = fgetc(stdin);
    }
    *(buffer_line + i) = '\0';
    return ch;
}

int get_word_string(char* buffer_line, char* buffer_word, int place_in_string)
{
    int i = place_in_string;
    int j = 0;
    char ch = 'a';
    memset(buffer_word, '\0', WORD);

    while ((ch!=' ')&&(ch!='\t')&&(i<=strlen(buffer_line)))
    {
        ch = *(buffer_line+i);
        *(buffer_word+j) = ch;  
        i++;
        j++;
    }
    *(buffer_word + (j-1)) = '\0';
    // printf("%s, len = %ld, j = %d\n", buffer_word, strlen(buffer_word), j);
    
    return i;
}

char get_word_file(char* buffer_word)
{
    int i = 0;
    memset(buffer_word, '\0', WORD);
    char ch = fgetc(stdin);

    while ((ch!=' ')&&(ch!='\t')&&(ch!='\r')&&(ch!='\n')&&(ch!=EOF))
    {
          
        *(buffer_word+i) = ch;  
        i++;
        ch = fgetc(stdin);
    }    
    return ch;
}


int sub(char* source, char* word_under_test)
{
    int i=0;
    int j=0;

    while(*(word_under_test+j)!='\0')
    {
        // printf("in while\n");
        if (*(source)==*(word_under_test+j))
        {
            // printf("qw\n");
            while(i<strlen(source))
            {
                if (*(source+i)!=*(word_under_test+(j+i)))
                {
                    // printf("FULSE IN WHILE\n");
                    return FULSE;
                }
                i++;
            }
            // printf("TRUE\n");
            return TRUE;
        }
        else if (*(source)!=*(word_under_test+j))
        {
            j++;
        }
    }
    // printf("FULSE OUT WHILE\n");
    return FULSE;    
}


int is_similar(char* source, char* word_under_test, int different_letters)
{
    int i=0;
    int j=0;
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










