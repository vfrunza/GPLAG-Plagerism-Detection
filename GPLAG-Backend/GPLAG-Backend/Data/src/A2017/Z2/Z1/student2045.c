#include <stdio.h>

int main() {

int i,j,k,n;

do { 
	printf ("Unesite broj N:");
	scanf ("%d", &n);
	if (n<8 || n%4!=0)
	printf (" Neispravno N!\n");
}

while (n<8 || n%4!=0);
printf ("\n");
printf ("\\");

for (i=0; i<(n/2)-2;i++) {
	printf (" ");
}
printf ("/");
printf ("+");

for (i=0; i<(n/2)-2; i++ ){
	printf ("-");
}
printf ("+\n");

for (k=0; k<(n/4)-1; k++) {
	for (j=0; j<k+1; j++) {
		printf (" ");
	}
	printf ("\\");

for (i=0; i<(n/2)-4-2*k; i++) {
	printf (" ");
}
printf ("/");
for (i=0; i<k+1; i++) {
	printf (" ");
}
printf ("|");
for (i=0; i<(n/2)-2; i++) {
	printf (" ");
}
printf ("|");
printf ("\n");
}
for (k=0;k<(n/4)-1; k++) {
	for (i=0; i<(n/4)-1-k; i++) {
		printf (" ");
	}
	printf ("/");

for (i=0; i<2*k; i++) {
	printf (" ");
}
printf ("\\");

for (i=0; i<(n/4)-1-k; i++) {
	printf (" ");
}
printf ("|");

for (i=0; i<(n/2)-2; i++) {
	printf (" ");
}
printf ("|\n");
}
printf ("/");

for (i=0; i<(n/2)-2; i++) {
	printf (" ");
}
printf ("\\");
printf ("+");
for (i=0;i<(n/2)-2;i++){
	printf ("-");
}
printf ("+\n");

printf ("+");
for (i=0; i<(n/2)-2; i++) {
	printf ("-");
}
printf ("+");
for (i=0; i<(n/4)-1;i++) {
	printf (" ");
}
printf ("||");
for (i=0; i<(n/4)-1; i++) {
	printf (" ");
}
printf ("\n");

for (k=0; k<((n/2)-4)/2;k++){
	printf ("|");
for (i=0; i<(n/2)-2; i++) {
	printf (" ");
}
printf ("|");

for (i=0; i<(n/4)-1; i++) {
	printf (" ");
}
printf ("||");
for (i=0; i<(n/4)-1; i++) {
	printf (" ");
}
printf ("\n");
}

for (j=0; j<2; j++) {
	printf ("|");
	for (i=0;i<(n/2)-2; i++) {
		printf (" ");
	}
printf ("|");
for (i=0; i<(n/4)-1; i++) {
	printf ("-");
}
printf ("++");
for (i=0; i<(n/4)-1;i++) {
	printf ("-");
}
printf ("\n");
}
for (k=0; k<((n/2)-4)/2; k++) {
	printf ("|");
	for (i=0; i<(n/2)-2; i++) {
		printf (" ");
	}
printf ("|");

for (i=0; i<(n/4)-1; i++)
{
	printf (" ");
}
printf ("||");

for (i=0; i<(n/4)-1; i++)
{
	printf (" ");
}
printf ("\n");
}
printf ("+");
for (i=0; i<(n/2)-2;i++) {
	printf ("-");
}
printf ("+");
for (i=0; i<(n/4)-1; i++) {
	printf (" ");
}
printf ("||");
for (i=0; i<(n/4)-1; i++) {
	printf (" ");
}
printf ("\n");

return 0; 
}