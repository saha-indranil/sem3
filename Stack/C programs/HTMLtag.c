// Write a C program to validate an html tag.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

char st[MAX][MAX];
int top = -1;

bool isValid(char str[]);
void push(char c[]);
char *pop(void);
bool isEmpty(void);

int main()
{
    char str[40];
    printf("Enter HTML tag:\n");
    gets(str);
    if (isValid(str))
        printf("Valid Tag");
    else
        printf("Invalid Tag");
    return 0;
}

bool isValid(char str[])
{
    int len = strlen(str);
    int i, t;
    char ch[5], *ch1;
    if (str[0] != '<' || str[len - 1] != '>')
        return false;

    for (i = 0; i < len; i++)
    {
        // Push Operation
        if (str[i] == '<' && str[i + 1] != '/')
        {
            i++;
            t = 0;
            while (str[i] != '>')
            {
                ch[t++] = str[i];
                i++;
            }
            ch[t] = '\0';
            push(ch);
        }

        // Pop Operation
        if (str[i] == '<' && str[i + 1] == '/')
        {
            i += 2;
            t = 0;
            ch1 = pop();
            while (str[i] != '>')
            {
                if (*(ch1 + t) != (char)str[i])
                    return false;
                t++;
                i++;
            }
        }
    }
    if (isEmpty)
        return true;
    return false;
}

void push(char c[])
{
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
    {
        top++;
        strcpy(st[top], c);
    }
}

char *pop()
{
    char *ch = (char *)malloc(sizeof(char) * MAX);
    if (top == -1)
    {
        printf("Stack Underflow!");
        ch = '\0';
    }
    else
    {
        int i = 0;
        while (st[top][i] != '\0')
        {
            *(ch + i) = st[top][i];
            i++;
        }
        top--;
    }
    return ch;
}

bool isEmpty()
{
    if (top >= 0)
        return false;
    return true;
}

// TEST CASES
// <h1> TEXT </h1> -> Valid
// <abc> <xy> TEXT </xy> </abc> -> Valid
// <h1> TEXT <h1> -> Invalid
// <abc> <xy> TEXT </abc> </xy> -> Invalid
// <a> TEXT </b> -> Invalid
