#include <stdio.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00


int main() {
	char t,b,m,novi_red;
	float nr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c", &novi_red);
		printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c", &novi_red);
		printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c", &novi_red);
	if(t=='h' && b=='h' && m=='h') {
		nr=3*h2;
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2fKM)",nr );
	}
	else  if(t=='p' && b=='p' && m=='p') {
		nr=3*p3;
		printf("Najjeftiniji je bistro ""Lorelei"" (%.2fKM)",nr );
		
	}
   else  if(t=='c' && b=='c' && m=='c') {
		nr=3*c2;
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2fKM)",nr );
	return 0;
}
