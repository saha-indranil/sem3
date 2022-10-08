#include <stdio.h>

int ht[10], i, found = 0, key;

void insert_val();
void search_val();
void delete_val();
void display();

int main()
{
    int option;
    for (i = 0; i < 10; i++) // to initialize every element as ‘-1’
        ht[i] = -1;
    printf("*** MENU *** \n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit\n");
    do
    {
        printf("Enter Choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_val();
            break;
        case 2:
            search_val();
            break;
        case 3:
            delete_val();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice entry!!!\n");
            break;
        }
    } while (option != 5);
    return 0;
}

void insert_val()
{
    int val, f = 0;
    printf("Enter the element to be inserted : ");
    scanf("%d", &val);
    key = (val % 10) - 1;
    if (ht[key] == -1)
    {
        ht[key] = val;
    }
    else
    {
        if (key < 9)
        {
            for (i = key + 1; i < 10; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = val;
                    break;
                }
            }
        }
        for (i = 0; i < key; i++)
        {
            if (ht[i] == -1)
            {
                ht[i] = val;
                break;
            }
        }
    }
}

void display()
{
    for (i = 0; i < 10; i++)
        printf("%d\t", ht[i]);
    printf("\n");
}

void search_val()
{
    int val, flag = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &val);
    key = (val % 10) - 1;
    if (ht[key] == val)
        flag = 1;
    else
    {
        for (i = key + 1; i < 10; i++)
        {
            if (ht[i] == val)
            {
                flag = 1;
                key = i;
                break;
            }
        }
    }
    if (flag == 0)
    {
        for (i = 0; i < key; i++)
        {
            if (ht[i] == val)
            {
                flag = 1;
                key = i;
                break;
            }
        }
    }
    if (flag == 1)
    {
        found = 1;
        printf("The item searched was found at position %d!\n", key + 1);
    }
    else
    {
        key = -1;
        printf("The item searched was not found in the hash table\n");
    }
}

void delete_val()
{
    search_val();
    if (found == 1)
    {
        if (key != -1)
        {
            printf("The element deleted is %d \n", ht[key]);
            ht[key] = -1;
        }
    }
}

// OUTPUT
// *** MENU ***
// 1.Insert
// 2.Search
// 3.Delete
// 4.Display
// 5.Exit
// Enter Choice: 1
// Enter the element to be inserted : 45
// Enter Choice: 1
// Enter the element to be inserted : 73
// Enter Choice: 1
// Enter the element to be inserted : 81
// Enter Choice: 4
// 81      -1      73      -1      45      -1      -1      -1      -1      -1
// Enter Choice: 2
// Enter the element to be searched: 73
// The item searched was found at position 3!
// Enter Choice: 3
// Enter the element to be searched: 45
// The item searched was found at position 5!
// The element deleted is 45
// Enter Choice: 4
// 81      -1      73      -1      -1      -1      -1      -1      -1      -1
// Enter Choice: 5