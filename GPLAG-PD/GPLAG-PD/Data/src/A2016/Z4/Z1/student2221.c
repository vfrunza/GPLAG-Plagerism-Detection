#include <stdio.h>

int jednakiSu(char* s1, char* s2)
{
    int t = 1; 
    int i = 0; 
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
        t = 0; 
        i++;
        if (!t) return t;
    }
    i = 0;
    while(s2[i] != '\0')
    {
    if (s1[i] != s2[i]) 
    t = 0;
    i++;
    if (!t) return t;
    }
    return t;
}

char* izbaci_najcescu(char*s)
{
    if (s[0] == '\0')
    return s;
    char temp[1000];
    int i1 = 0, i2 = 0;
    while (s[i1] != '\0')
    {
        while (s[i1] != '\0' && ((s[i1] >= 'a' && s[i1] <= 'z') || (s[i1] >= 'A' && s[i1] <= 'Z')))
        {
            temp [i2] = s[i1];
            if (s[i1] >= 'A' && s[i1] <= 'Z')
            temp[i2] += 'a'-'A';
            i1++; i2++;
            temp[i2] = ',';
        }
        if (temp[i2] == ',')
        {
            i2++;
            temp[i2] = '.';
        }
        if (s[i1] == '\0')
        break;
        i1++;
    }
    temp [i2] = '\0';
    
    char maxRijec[100];
    int max = 0;
    i2 = 0;
    while (temp[i2] != '\0')
    {
        char temp2[100];
        int i3 = 0;
        while (temp[i2] != ',')
        {
            temp2[i3] = temp [i2];
            i3++; i2++;
        }
        temp2[i3] = '\0';
        i2++;
        
        int max1 = 0;
        int i4 = 0;
        while (temp[i4] != '\0')
        {
            char temp3[100];
            int i5 = 0;
            
            while (temp[i4] != ',')
            {
                temp3[i5] = temp[i4];
                i5++;
                i4++;
            }
            temp3[i5] = '\0';
            if (jednakiSu(temp2, temp3)) max1++;
            i4++;
        }
        
        if (max1 > max)
        {
            int i5 = 0;
            while (temp2[i5] != '\0')
            {
            maxRijec[i5] = temp2[i5];
            i5++;
        }
        maxRijec[i5] = '\0';
        max = max1;
        }
    }
    i1 = 0; 
    int i3 = 0;
    while (s[i1] != '\0')
    {
        i2 = 0;
        i3 = i1;
        while (s[i1] != '\0' && (s[i1] >= 'a' && s[i1] <= 'z') || (s[i1] >= 'A' && s[i1] <= 'Z'))
        {
            temp[i2] = s[i1];
            if (s[i1] >= 'A' && s[i1] <= 'Z')
            temp[i2] += 'a' - 'A';
            i1++; i2++;
        }
        temp[i2] = '\0';
        if (jednakiSu(maxRijec,temp))
        {
            int i4 = i3, i5 = i1;
            while (s[i5] != '\0')
            {
                s[i4] = s[i5];
                i5++; i4++;
            }
            s[i4] = '\0';
            
        }
        i1 = i3;
        i1++;
    }
    return s;
}
    
int main()
{
    char t[]="12345 ./,4 !@#%^ ";
    printf("a");
    printf("'%s'", izbaci_najcescu(t));
    return 0;
}
