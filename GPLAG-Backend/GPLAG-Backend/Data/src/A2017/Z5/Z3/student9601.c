#include <stdio.h>
#include <stdlib.h> 
struct Oblik
{
 char naziv[20];
 int br_stranica;
 double stranice[300];
};
struct Oblik o[500];
void dodaj_oblik(struct Oblik *o)
{
 FILE*fp;
 fp=fopen("oblici.dat","a+");
 if(fp==NULL)
 {
  printf("Greska.");
  exit(1);
 }
 fwrite(o,sizeof(struct Oblik),500,fp);
 fclose(fp);
}
void izmjena(struct Oblik *o)
{
	FILE *dat;
	int i;
	if ((dat = fopen("oblici.txt", "wb")) == NULL) {
		printf("Greska.");
		exit(1);
	}
	for (i=0; i<=500; i++)
		fprintf(dat, "%s\n", o[i].naziv);
	fclose(dat);
}
void izbaci_duple(struct Oblik *o)
{
 int i,j;
 FILE*fp;
 fp=fopen("oblici.dat","rb");
 if(fp==NULL)
 {
  printf("Greska.");
  exit(1);
 }
 fread(o,sizeof(struct Oblik),500,fp);
 for(i=0;i<500;i++)
 {
  for(j=i-1;j>=0;j--)
  {
   if(o[i].naziv==o[j].naziv) 
    izmjena(o);
  }
 }
 fclose(fp);
}

int main() {
	return 0;
}
