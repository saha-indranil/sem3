// https://www.interviewbit.com/problems/allocate-books/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int findPages(int pages[], int books, int students);
bool isFeasibble(int pages[], int books, int students, int currMin);

// Utility function to check if current minimum value is feasible or not.
bool isFeasibble(int pages[], int books, int students, int currMin)
{
    int studentsRequired = 1, currSum = 0, i;
    // iterate over all books
    for (int i = 0; i < books; i++)
    {
        // check if current number of pages are greater
        // than currMin that means we will get the result
        // after mid no. of pages
        if (pages[i] > currMin)
            return false;

        // count how many students are required
        // to distribute currMin pages
        if (currSum + pages[i] > currMin)
        {
            // increment student count
            studentsRequired++;

            // update currSum
            currSum = pages[i];

            // if students required becomes greater
            // than given no. of students,return false
            if (studentsRequired > students)
                return false;
        }
        // else update currSum
        else
            currSum += pages[i];
    }
    return true;
}

int findPages(int pages[], int books, int students)
{
    int sum = 0, max = pages[0];

    // return -1 if no. of books is less than no. of students
    if (books < students)
        return -1;

    // Count total number of pages
    for (int i = 0; i < books; i++)
    {
        sum += pages[i];
        if (max < pages[i])
            max = pages[i];
    }
    // initialize start as 0 pages and end as total pages
    int start = max, end = sum;
    int result = INT_MAX;

    // traverse until start <= end
    while (start <= end)
    {
        // check if it is possible to distribute
        // books by using mid as current minimum
        int mid = (start + end) >> 1;
        if (isFeasibble(pages, books, students, mid))
        {
            // update result to current distribution
            // as it's the best we have found till now.
            result = mid;

            // as we are finding minimum and books
            // are sorted so reduce end = mid -1
            // that means
            end = mid - 1;
        }

        else
            // if not possible means pages should be
            // increased so update start = mid + 1
            start = mid + 1;
    }

    // at-last return minimum no. of  pages
    return result;
}

// Drivers Code
int main()
{
    int pages[10], books, students, i;
    printf("Enter Number of Books: ");
    scanf("%d", &books);
    for (i = 0; i < books; i++)
    {
        printf("Enter total page no. of Book[%d]: ", i);
        scanf("%d", &pages[i]);
    }
    printf("Enter Number of Students: ");
    scanf("%d", &students);
    printf("Minimum no of pages = %d", findPages(pages, books, students));
    return 0;
}