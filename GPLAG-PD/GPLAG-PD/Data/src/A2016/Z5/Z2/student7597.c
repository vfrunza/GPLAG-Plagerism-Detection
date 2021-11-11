#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _word
{
    char text[15];
    int count;
    int len;
};

typedef struct _word word;

int _strlen(char *s)
{
	int len = 0;
	if (s[0] == '\0') return len;
	while(s[++len] != '\0');
	return len;
}

int _isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


word words[1010];

void swap(word *a, word *b)
{
    word temp = *b;
    *b = *a;
    *a = temp;
}

void kompresuj(char *in, char *out)
{
    int word_count = 0, i;
    FILE *fin = fopen(in, "r");
    FILE *fout = fopen(out, "w");
    char c;
    word current_word;
    current_word.len = 0;
    int swapped = 1;
    
    c = 5;
    
    while ((c = (char)fgetc(fin)) != EOF)
    {
        if (_isalpha(c) && current_word.len < 13)
        {
            current_word.text[current_word.len] = c;
            current_word.text[current_word.len + 1] = '\0';
            current_word.len++;
        }
        else if (!_isalpha(c))
        {
            if (current_word.len > 0 && current_word.len < 10)
            {
                int found = 0;
                for (i = 0; i < word_count; i++)
                {
                    if (strcmp(current_word.text, words[i].text) == 0)
                    {
                        found = 1;
                        words[i].count++;
                        break;
                    }
                }
                
                if (!found)
                {
                    for (i = 0; i <= current_word.len; i++)
                        words[word_count].text[i] = current_word.text[i];
                    words[word_count].len = current_word.len;
                    words[word_count].count = 1;
                    word_count++;
                }
            }
            current_word.len = 0;
        }
    }
    
    if (current_word.len > 0 && current_word.len < 10)
    {
        int found = 0;
        for (i = 0; i < word_count; i++)
        {
            if (strcmp(current_word.text, words[i].text) == 0)
            {
                found = 1;
                words[i].count++;
                break;
            }
        }
        
        if (!found)
        {
            for (i = 0; i <= current_word.len; i++)
                words[word_count].text[i] = current_word.text[i];
            words[word_count].len = current_word.len;
            words[word_count].count = 1;
            word_count++;
        }
    }
    
    while(swapped)
    {
        swapped = 0;
        for (i = 1; i < word_count; i++)
        {
            if (words[i - 1].count < words[i].count ||
                (words[i - 1].count == words[i].count && strcmp(words[i - 1].text, words[i].text) > 0))
            {
                swapped = 1;
                swap(&words[i - 1], &words[i]);
            }
        }
    }
    
    rewind(fin);
    
    c = 5;
    
    current_word.len = 0;
    
    for (i = 0; i < 10 && i < word_count; i++)
        fprintf(fout, "%s\n", words[i].text);
    
    if (i < 10)
        fprintf(fout, "\n");
    
    while ((c = (char)fgetc(fin)) != EOF)
    {
        if (_isalpha(c))
        {
            current_word.text[current_word.len] = c;
            current_word.text[current_word.len + 1] = '\0';
            current_word.len++;
            
            if (current_word.len > 10)
            {
                fprintf(fout, "%s", current_word.text);
                current_word.len = 0;
                while (_isalpha(c = (char)fgetc(fin)) && c)
                    fprintf(fout, "%c", c);
                if (!c)
                    break;
                fprintf(fout, "%c", c);
            }
        }
        else
        {
            if (current_word.len > 0)
            {
                char found = 0;
                for (i = 0; i < 10 && i < word_count; i++)
                {
                    if (strcmp(current_word.text, words[i].text) == 0)
                    {
                        found = 1;
                        fprintf(fout, "%c", (char)(20 + i));
                        break;
                    }
                }
                if (!found)
                    fprintf(fout, "%s", current_word.text);
            }
            
            current_word.len = 0;
            
            fprintf(fout, "%c", c);
        }
    }
    
    if (current_word.len > 0)
    {
        char found = 0;
        for (i = 0; i < 10 && i < word_count; i++)
        {
            if (strcmp(current_word.text, words[i].text) == 0)
            {
                found = 1;
                fprintf(fout, "%c", (char)(20 + i));
                break;
            }
        }
        if (!found)
            fprintf(fout, "%s", current_word.text);
    }
    
    printf("Datoteka kompresovana.\n");

    fclose(fin);
    fclose(fout);
}

void dekompresuj(char *in, char *out)
{
    int word_count = 0, i;
    FILE *fin  = fopen(in, "r");
    FILE *fout = fopen(out, "w");
    char c;
    word current_word;
    current_word.len = 0;
    int swapped = 1;
    char word[15];
    c = 5;

    for (i = 0; i < 10; i++)
    {
        fgets(words[i].text, 100, fin);
        if (words[i].text[0] == '\n')
            break;
        words[i].text[strlen(words[i].text) - 1] = '\0';
    }
    
    word_count = i;
    
    while ((c = (char)fgetc(fin)) != EOF)
    {
        if (20 <= c && c <= 29)
            fprintf(fout, "%s", words[c - 20].text);
        else
            fprintf(fout, "%c", c);
    }
    
    printf("Datoteka dekompresovana.\n");

    fclose(fin);
    fclose(fout);
}

int main()
{
    /* AT5: Test predugackih rijeci, nekih specijalnih karaktera i slicno (kompresija) */
int c;
FILE* ulaz = fopen("z5z2_test5.txt", "w");
fputs("Proba proba predugacka proba predugackarijec proba proba proba... auto-stop!!@@##$$%%^^&&**(())--__++==sdfgsdfg", ulaz);
fclose(ulaz);

kompresuj("z5z2_test5.txt", "z5z2_test5.zip");

/* Ispisujemo kompresovanu datoteku na ekran */
printf("KOMPRESOVANA:\n");
ulaz = fopen("z5z2_test5.zip", "r");
if (ulaz == NULL) {
    printf("Datoteka ne postoji!");
    return 0;
}
do {
    c=fgetc(ulaz);
    if (c >= 20 && c<=29) printf("[%d]", c);
    else if (c != EOF) printf("%c", c);
} while (c != EOF);
fclose(ulaz);

    return 0;
}

int _main()
{
    char in[50], out[50];
    int q;
    while (1 == 1)
    {
        printf ("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf ("%d", &q);
        if (!q)
            break;
        printf("Unesite ime ulazne datoteke: ");
        scanf("%s", in);
        printf("Unesite ime izlazne datoteke: ");
        scanf("%s", out);
        
        if (q == 1)
            kompresuj(in, out);
        else if (q == 2)
            dekompresuj(in, out);
    }
    
    return 0;
}