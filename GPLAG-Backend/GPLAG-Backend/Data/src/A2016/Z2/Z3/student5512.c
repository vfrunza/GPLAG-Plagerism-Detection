#include <stdio.h>

int main() {
    int a[10]={0},b[10]={0},i,j,x=0,y;
    char pm[20][20];
    p1:
    printf ("Unesite broj tacaka: ");
    scanf ("%d", &x);
    if (x>10 || x<=0){
        printf ("Pogresan unos\n");
        goto p1;}
    for (i=0; i<20; i++){
        for (j=0; j<20; j++){
            pm[i][j]=' ';}}
    for (i=0; i<x; i++){
    p2:
        printf ("Unesite %d. tacku: ", i+1);
        scanf ("%d %d", &a[i], &b[i]);
        if ((a[i]>=20 || a[i]<0) || (b[i]>=20 || b[i]<0)){
             printf ("Pogresan unos\n");
            goto p2;}}
    for (y=0; y<x; y++){
        for (i=0; i<20; i++){
            for (j=0; j<20; j++){
                if (i==b[y] && j==a[y]){
                    pm[i][j]='*';}}}}
    for (i=0; i<20; i++){
        for (j=0; j<20; j++){
             printf ("%c", pm[i][j]);}
        printf ("\n");}                
            
         
        
	
	
	return 0;
}
