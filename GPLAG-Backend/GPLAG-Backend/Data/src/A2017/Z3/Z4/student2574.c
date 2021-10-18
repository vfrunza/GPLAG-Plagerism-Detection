/* Headers. */
#include <stdio.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Macros. */
#define MAX 100

/* Prototypes. */
int max(int matrix[MAX][MAX], unsigned height, unsigned width);
unsigned izbaci_kolone(int matrix[MAX][MAX], unsigned height, unsigned width, int n);

/* Main. */
int main(void)
{
    int matrix[MAX][MAX];
    unsigned i, j, e, width, height;
    
    /* Prompt for the user to enter the dimensions of the matrix and its elements. */
    printf("Unesite sirinu i visinu matrice: "); scanf("%d %d", &width, &height);
    for (i = 0; i < height; i++)
    {
        printf("Unesite elemente %d. reda: ", i + 1);
        for (j = 0; j < width; j++)
            scanf("%d", &matrix[i][j]);
    }
    
    /* Calls the izbaci_kolone() function until the matrix completely disappears. */
    for (i = 1; 1; i++)
    {
        /* The width of the matrix, due to losing one column after each iteration of the for-loop, changes. */
        width = izbaci_kolone(matrix, height, width, max(matrix, height, width));
        
        /* The matrix has been completely eradicated.         */
        /* Exits the loop and the program finally terminates. */
        if (width == 0)
        {
            printf("\nNakon %d. prolaza matrica je prazna!\n", i);
            break;
        }
        
        /* Prints out the state of the matrix (if there is one still left of course) after each call of izbaci_kolone(). */
        printf("\nNakon %d. prolaza matrica glasi: \n", i);
        for (j = 0; j < height; j++)
        {
            for (e = 0; e < width; e++)
                printf("%5.d", matrix[j][e]);
                
            printf("\n");
        }
    }
    
    return 0;
}

int max(int matrix[MAX][MAX], unsigned height, unsigned width)
{
    int histogram[MAX * MAX * 2] = {0};
    int (*p_matrix_row)[MAX];
    unsigned i, j, n_repeats, pos_return_value, pos_histogram = 0;
    _bool initialized = false;
    _bool new_element = true;
    
    /* Gets the number of times that the values of the matrix appear (i.e., histogram data). */
    for (p_matrix_row = matrix; p_matrix_row != matrix + height; p_matrix_row++)
    {
        for (i = 0; i < width; i++)
        {
            /* Initializes the histogram array by inserting the 1st element of the matrix into it. */
            /* This piece of code gets executed only in the first iteration of the for-loop.       */
            if (!initialized)
            {
                /* Let's say that the 1st value that's been inserted into histogram[] is 12, */
                /* so we now have: histogram[] = {12, 1, 0, 0, 0, 0, ..., 0}                 */
                histogram[pos_histogram] = (*p_matrix_row)[i];
                histogram[pos_histogram + 1]++;
                pos_histogram += 2;
                initialized = true;
            }
            else
            {
                /* Checks whether the matrix value that is currently being pointed to is already present in histogram[]. */
                /* If it is, then it just increments the tracker value.                                                  */
                for (j = 0; j < pos_histogram; j += 2)
                {
                    if (histogram[j] == (*p_matrix_row)[i])
                    {
                        histogram[j + 1]++;
                        new_element = false;
                        break;
                    }   
                }
                
                /* If the matrix value that is currently being pointed to isn't already present in histogram[], */
                /* then it gets inserted into histogram[].                                                      */
                if (new_element)
                {
                    histogram[pos_histogram] = (*p_matrix_row)[i];
                    histogram[pos_histogram + 1]++;
                    pos_histogram += 2;
                }
                
                new_element = true;
            }
        }
    }
    
    /* Initializes some values. */
    n_repeats = histogram[1];
    pos_return_value = 0;
    /* Goes through histogram[] and sees which value appears the most times in the matrix. */
    for (i = 3; i < pos_histogram; i += 2)
    {
        /* Gets the greatest number of apearances (n_repeats), and the position of the value */ 
        /* (associated with the greatest number of aparances) in the histogram[].            */
        if (histogram[i] > n_repeats)
        {
            n_repeats = histogram[i];
            pos_return_value = i - 1;
        }
        /* If it happens that two numbers have the same n_repeats (greatest number of repeats), */
        /* then the program gets the position of the smaller of the two numbers.                */
        else if (histogram[i] == n_repeats)
        {
            if (histogram[i - 1] < histogram[pos_return_value])
            {
                pos_return_value = i - 1;
            }
        }
    }
    
    return histogram[pos_return_value];
}

unsigned izbaci_kolone(int matrix[MAX][MAX], unsigned height, unsigned width, int n)
{
    unsigned actual_width = width;
    unsigned i, j;
    int (*p_matrix_row)[MAX], (*p_matrix_row_temp)[MAX];

    /* Goes through the columns of the matrix: if the value of n is present in a column, then */ 
    /* that column gets deleted from the matrix.                                              */
    for (p_matrix_row = matrix; p_matrix_row != matrix + height; p_matrix_row++)
    {
        for (i = 0; i < actual_width; i++)
        {
            if ((*p_matrix_row)[i] == n)
            {
                /* Checks whether the column that is being deleted is the last column. */
                if (i == actual_width - 1)
                {
                    /* Since it's the last column of the matrix, no values from the right need to be shifted left. */
                    /* Just lowering the width of the matrix is all that is needed to be done.                     */
                    ;
                }
                /* The column that is being removed is not the last column, so elements need to be shifted from the right to the left. */
                else
                {
                    for (p_matrix_row_temp = matrix; p_matrix_row_temp != matrix + height; p_matrix_row_temp++)
                    {                            
                        for (j = i; j < actual_width - 1; j++)
                        {
                            (*p_matrix_row_temp)[j] = (*p_matrix_row_temp)[j + 1];
                        }
                    }
                    
                    i--;
                }
                
                actual_width--;
            }
        }
    }
    
    /* Returns the new (or old, depends on the value of n and the matrix) width of the matrix. */
    return actual_width;
}