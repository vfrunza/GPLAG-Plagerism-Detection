#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int pomStotice, predzadnji, zadnji, novi;
	long int BROJ, kbr, br, GAMEOVER = 0, output = 0, stotice = 1;
	printf ("Unesite broj: ");
	scanf ("%li", &BROJ);
	kbr = BROJ;
	while (kbr != 0)
	{
		stotice *= 10;
		kbr/=10;
	}
	stotice/=10;
	pomStotice = stotice;
	br = abs(BROJ);
	while(br != 0)
	{
		zadnji = br % 10;
		br/=10;
		predzadnji = br % 10;
		if (br == 0) break;
		novi = abs(zadnji - predzadnji);
		output += (novi * stotice);
		stotice/=10;
	}
	output/=10;
	
	while (output != 0)
	{
		GAMEOVER += (output%10)*pomStotice;
		output/=10;
		pomStotice/=10;
	}
	
	GAMEOVER/=10;
	printf ("%li", GAMEOVER);
	return 0;
}
