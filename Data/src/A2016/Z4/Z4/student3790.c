#include <stdio.h>
#define epsilon 0.0001

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* obuhvat(char *s,float x1, float y1, float x2, float y2){
	return s;
}
int main() {
	char recenica[100];
	unesi(&recenica[0],100);
	char *pok;
	float x1,x2,y1,y2;
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	pok=obuhvat(&recenica[0],x1,y2,x2,y2);
	return 0;
}
