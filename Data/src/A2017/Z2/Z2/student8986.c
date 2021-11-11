#include <stdio.h>

int main() {


int s,hasan,clanovi,o=1,done[1000],hajde,molim,brale=0,pomoc[1000],brojka,bezze,flash,prev,count,poc=0,k=0,l,i,j,BR1=0,BR2=0,n,suma=0,ulaz[100],izlaz[100],cifra,obrada[100],x,BR3=0,zavrsni[1000],modul,ponavljanje=0;




printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    
     do{
   	if(n<100 && n>0)break;
   	printf("Neispravna velicina niza!\n");
   	printf("Unesite velicinu niza: ");
   	scanf("%d",&n);
     }while(n<=0 || n>100);
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&ulaz[i]);
		while(ulaz[i]<0){
		    printf("Neispravna velicina clana niza!\n");
		    printf("Unesite clanove niza: ");
		    scanf("%d",&ulaz[i]);
		    
		}
	}
	
	

for(i=0;i<n;i++){
		if(ulaz[i]==0)o++;
	}


for(i=0;i<n;i++){

x=ulaz[i];
if(x==0)BR3++;
while(x>0){
	x=x/10;
	BR3++;
}



if(ulaz[i]==0){
	ulaz[i]++;
	modul=1;
}
else if(ulaz[i]>0)modul=10;

while(ulaz[i]>0){
	cifra=ulaz[i]%modul;
	BR1++;
	suma=suma+BR1;
	BR2=suma-BR1;
	
	for(j=BR2;j<suma;j++){
		obrada[j]=cifra;
	}BR1=0;
	ulaz[i]=ulaz[i]/10;
}

for (l = BR3-1; k < BR3; k++, l--){
      izlaz[l] = obrada[k];}poc=poc+k;

}
izlaz[BR3]=-1;

for(i=0;i<=100;i++){
    zavrsni[i]=-1;
}

for(i=0;i<=100;i++){
    pomoc[i]=-1;
}

prev = izlaz[0];
count = 1;
for (s=1;s<=BR3; s++)
{
  
  if (izlaz[s] == prev) {count++;}
  
  else
  {
  
  zavrsni[s-1]=prev;
  pomoc[s-1]=count;

    
    prev = izlaz[s];
   
    count = 1;
    
  }
}


pomoc[BR3]=count;


flash=BR3;
bezze=BR3;
brojka=BR3;


if(izlaz[bezze-1]!=0){
    for (i=0; i<bezze; i++) {
if (zavrsni[i]==-1) {
for (j=i; j<bezze; j++) {
zavrsni[j] = zavrsni[j+1];
}
bezze--;
i--;

}zavrsni[j]=-1;
}

for (i=0; i<brojka; i++) {
if (zavrsni[i]==0 && o<1) {
for (j=i; j<brojka; j++) {
zavrsni[j] = zavrsni[j+1];
}
brojka--;
i--;

}zavrsni[brojka]=-1;
}
    
    
    
}else{

for (i=0; i<=bezze+100; i++) {
if (zavrsni[i]==-1) {
for (j=i; j<=bezze-1; j++) {
zavrsni[j] = zavrsni[j+1];
}
bezze--;
i--;
}
}zavrsni[j]=-1;

}

for (i=0; i<BR3; i++) {
if (pomoc[i]==-1) {
for (j=i; j<=BR3; j++) {
pomoc[j] = pomoc[j+1];
}
BR3--;
i--;

}pomoc[flash+1]=-1;brale++;
}

if(brale>n){
   pomoc[flash]=-1;
}

for (i=0; i<flash; i++) {
if (pomoc[i]==0)pomoc[i]=-1;

}

for (i=0; i<flash; i++) {
if(pomoc[i+1]==1 && pomoc[i+2]==-1 && BR3==1)pomoc[i+1]=pomoc[i+2];
}



for (i=0;i<=BR3;i++){
    if(zavrsni[i]==-1)break;
    
    hajde=i;
}



for (i=0;i<=BR3+1;i++){
    if(pomoc[i]==-1)break;
   
    molim=i;
    
}
clanovi=hajde+molim;



j=0;
  for(i=1;i<clanovi+3;i++){
      
      done[i-1]=zavrsni[j];
      done[i]=zavrsni[j];
      i++;
      j++;
      
  }
     
j=0;
  for(i=2;i<clanovi+4;i++){
      
      done[i-1]=pomoc[j];
      i++;
      j++;
      
  }



for (i=0;i<=clanovi+1;i++){
    if(done[i]==-1)break;
    
}



if(done[clanovi]==0 && BR3!=1 && hajde!=molim)done[clanovi-1]--;


printf("Finalni niz glasi: \n");

for (i=0;i<=clanovi+1;i++){
    if(done[i]==-1)break;
    printf("%d ",done[i]);
}


	return 0;
}
