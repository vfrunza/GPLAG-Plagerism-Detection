/* Headers. */
#include <stdio.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Macros. */
#define MAX 100

/* Prototypes. */
unsigned dva_od_tri(int *firstArray, unsigned firstSize, int *secondArray, unsigned secondSize, int* thirdArray, unsigned thirdSize);

/* Main. */
int main(void)
{
    /* ... */
    
    return 0;
}

/* Function implementation. */
unsigned dva_od_tri(int *firstArray, unsigned firstSize, int *secondArray, unsigned secondSize, int* thirdArray, unsigned thirdSize)
{
    int pairs1[MAX] = {0};
    int pairs2[MAX] = {0};
    int pairs3[MAX] = {0};
    int pairs[MAX] = {0};
    int histogram[MAX] = {0};
    int *p1, *p2;
    unsigned i, n_pairs, n_pairs1, n_pairs2, n_pairs3, pos_histogram, return_value;
    n_pairs = n_pairs1 = n_pairs2 = n_pairs3 = return_value = pos_histogram = 0;
    _bool initialized;
    _bool duplicate;

    /* For the sake of convenience, I'll be refering to the first array as A, the second as B, and the third as C (think of them as mathematical sets). */
    /* How the program works in principle:                                                                                                              */
    /*                                                                                                                                                  */
    /* 1. Find the intersections (pairs) between A&B, B&C, and A&C.                                                                                     */
    /* Ex: A = {1, 2, 3}, B = {2, 3, 4}, C = {3, 4, 5} ==> A&B = {2, 3}, B&C = {3, 4}, A&C = {3}.                                                       */
    /*                                                                                                                                                  */
    /* 2. Merge the intersections into one 1-D array -- pairs[].                                                                                        */
    /* Using the above example, it follows that pairs[] = {2, 3, 3, 4, 3}.                                                                              */
    /*                                                                                                                                                  */
    /* 3. Count the number of times that each number appears in pairs[], i.e. create a histogram of sorts.                                                */
    /* So for pairs[] = {2, 3, 3, 4, 3} ==> histogram[] = {2, 1, 3, 3, 4, 1}.                                                                           */
    /*                                                                                                                                                  */
    /* 4. Counts the number of times (return_value) that a number appears exactly once in histogram[].                                                  */
    /* So for histogram[] = {2, 1, 3, 3, 4, 1} ==> return_value = 2, because of (2, 1) and (4, 1).                                                      */
    /*                                                                                                                                                  */
    /* 5. Return the return_value.                                                                                                                      */
    
    /* Finds the intersection between A and B, and stores it in pairs1[]. */
    for (p1 = firstArray, initialized = false, duplicate = false; p1 < firstArray + firstSize; p1++)
    {
        for (p2 = secondArray; p2 < secondArray + secondSize; p2++)
        {
            if (*p1 == *p2)
            {
                if (!initialized)
                {
                    pairs1[n_pairs1++] = *p1;
                    initialized = true;
                }
                else
                {
                    for (i = 0; i < n_pairs1; i++)
                    {
                        if (pairs1[i] == *p1)
                        {
                            duplicate = true;
                            break;
                        }
                    }
                    
                    if (!duplicate)
                    {
                        pairs1[n_pairs1++] = *p1;
                    }
                    
                    duplicate = false;
                }
            }
        }
    }
    
    /* Finds the intersection between B and C, and stores it in pairs2[]. */
    for (p1 = secondArray, initialized = false, duplicate = false; p1 < secondArray + secondSize; p1++)
    {
        for (p2 = thirdArray; p2 < thirdArray + thirdSize; p2++)
        {
            if (*p1 == *p2)
            {
                if (!initialized)
                {
                    pairs2[n_pairs2++] = *p1;
                    initialized = true;
                }
                else
                {
                    for (i = 0; i < n_pairs2; i++)
                    {
                        if (pairs2[i] == *p1)
                        {
                            duplicate = true;
                            break;
                        }
                    }
                    
                    if (!duplicate)
                    {
                        pairs2[n_pairs2++] = *p1;
                    }
                    
                    duplicate = false;
                }
            }
        }
    }
    
    /* Finds the intersection between A and C, and stores it in pairs3[]. */
    for (p1 = firstArray, initialized = false, duplicate = false; p1 < firstArray + firstSize; p1++)
    {
        for (p2 = thirdArray; p2 < thirdArray + thirdSize; p2++)
        {
            if (*p1 == *p2)
            {
                if (!initialized)
                {
                    pairs3[n_pairs3++] = *p1;
                    initialized = true;
                }
                else
                {
                    for (i = 0; i < n_pairs3; i++)
                    {
                        if (pairs3[i] == *p1)
                        {
                            duplicate = true;
                            break;
                        }
                    }
                    
                    if (!duplicate)
                    {
                        pairs3[n_pairs3++] = *p1;
                    }
                    
                    duplicate = false;
                }
            }
        }
    }
    
    /* Merges pairs1[], pairs2[] and pairs3[] into one set -- pairs[]. */
    for (p1 = pairs1; p1 < pairs1 + n_pairs1; p1++)
    {
        pairs[n_pairs++]  = *p1;
    }
    for (p1 = pairs2; p1 < pairs2 + n_pairs2; p1++)
    {
        pairs[n_pairs++]  = *p1;
    }
    for (p1 = pairs3; p1 < pairs3 + n_pairs3; p1++)
    {
        pairs[n_pairs++]  = *p1;
    }
    
    /* Finds the number (or numbers? English is confusing...) of appearances of all the numbers in pairs[] (i.e., histogram data). */
    /* Ex: pairs[] = {1, 1, 2, 0, 3, 3, 1, 17} ==> histogram[] = {1, 3, 2, 1, 0, 1, 3, 2, 17, 1}.                                  */
    for (p1 = pairs, initialized = false, duplicate = false; p1 < pairs + n_pairs; p1++)
    {
        /* Since histogram[] is empty in the first iteration of the for-loop, stick in the first number from pairs[] into it. */
        if (!initialized)
        {
            histogram[pos_histogram] = *p1;
            histogram[pos_histogram + 1]++;
            pos_histogram += 2;
            initialized = true;
        }
        /* Since histogram[] is not empty now, all elements from pairs[] that come after the first element from pairs[], */
        /* need to be checked for they could be duplicates.                                                              */
        else
        {
            for (i = 0; i < pos_histogram; i += 2)
            {
                /* If the number currently being checked is already in histogram[], then the only thing that needs */
                /* to be done is to the increment the tracker value next to it, i.e. histogram[i + 1].             */
                if (histogram[i] == *p1)
                {
                    duplicate = true;
                    histogram[i + 1]++;
                    break;
                }
            }
            
            /* If the number currently being checked is indeed not a duplicate, then it gets stored in histogram[]. */
            if (!duplicate)
            {
                histogram[pos_histogram] = *p1;
                histogram[pos_histogram + 1]++;
                pos_histogram += 2;
            }
            
            duplicate = false;
        }
    }
    
    /* Goes through histogram[], and increments return_value (the number of pairs) by one  */
    /* each time it finds a number that appears exactly once in histogram[].               */
    for (p1 = histogram + 1; p1 < histogram + pos_histogram; p1 += 2)
    {
        if (*p1 == 1)
        {
            return_value++;
        }
    }
    
    /* Returns the number of pairs. */
    return return_value;
}