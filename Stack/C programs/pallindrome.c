// Write a C program to find the palindrome using appropriate ADT to implement a more
// powerful version of the is_palindrome() function. As a reminder, this function
// implements simple palindome verification. Here is the signature and documentation for
// the function:
// • bool is_palindrome(char *text)

// Return true if text is a palindrome, false otherwise. A palindrome is a string that is
// identical to itself when reversed. For example, "madam", "dad", and "abba" are
// palindromes. Note: the empty string is a palindrome, as is every string of length one.

// Your solution should ignore whitespace and punctuation, and all comparisons should be
// case-insensitive. Include some tests in your main function. Examples of valid
// palindromes:

// Example- "", "a", "aa", "aaa", "aba", "abba", "Taco cat", "Madam, I'm Adam", "A man, a plan,
// a canal: Panama", "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod."

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int top = -1;

void push(char ele);
char pop(void);
bool is_pallindrome(char *text);
void printOutput(bool);

int main()
{
    char str1[] = "";
    printOutput(is_pallindrome(str1));
    char str2[] = "A";
    printOutput(is_pallindrome(str2));
    char str3[] = "Bb";
    printOutput(is_pallindrome(str3));
    char str4[] = "Madam, I'm Adam";
    printOutput(is_pallindrome(str4));
    char str5[] = "A man, a plan, a canal: Panama";
    printOutput(is_pallindrome(str5));
    char str6[] = "Data & Structure";
    printOutput(is_pallindrome(str6));
    return 0;
}

void push(char ele)
{
    top++;
    *(stack + top) = ele;
}

char pop(void)
{
    char c = *(stack + top);
    top--;
    return c;
}

bool is_pallindrome(char *text)
{
    int len = 0, i = 0;
    char ele, temp[strlen(text)];

    while (*(text + i) != '\0')
    {
        if (isalpha(*(text + i)))
        {
            temp[len] = *(text + i);
            len++;
        }
        i++;
    }
    temp[len] = '\0';

    stack = (char *)malloc(len * sizeof(char));

    for (i = 0; i < len / 2; i++)
    {
        push(temp[i]);
    }

    if (len % 2 != 0)
    {
        i++;
    }

    while (*(temp + i) != '\0')
    {
        ele = tolower(pop());
        if (ele != tolower(temp[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

void printOutput(bool b)
{
    if (b)
        printf("\nTRUE");
    else
        printf("\nFALSE");
}

// OUTPUT
// TRUE
// TRUE
// TRUE
// TRUE
// TRUE
// FALSE