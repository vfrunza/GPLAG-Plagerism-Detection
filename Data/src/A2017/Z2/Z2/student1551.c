/* Dat je neki niz prirodnih brojeva (uključujući nulu), na primjer:
	233, 38, 17777, 7737, 152
Ovaj niz možemo posmatrati kao neprekinuti niz cifara, npr:
	23338177777737152
Potrebno je u drugi niz upisati: cifru i koliko puta uzastopno se ta cifra nalazi u ovom neprekinutom nizu. Dakle, 
za primjer iznad drugi niz bi trebao glasiti:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
(cifra 2 se pojavljuje 1 put uzastopno, cifra 3 se pojavljuje 3 puta uzastopno itd.)

Potrebno je napisati program koji radi na sljedeći način: najprije se unosi veličina polaznog niza (max. 100 elemenata),
a zatim i njegovi članovi (osigurati da se ponavlja unos ako korisnik proba unijeti neispravnu veličinu ili član koji nije
prirodan broj ili nula). Zatim se na ekranu ispisuju članovi drugog niza razdvojeni znakom razmaka.

Primjer ulaza i izlaza:
Unesite velicinu niza: 5
Unesite clanove niza: 233 38 17777 7737 152
Finalni niz glasi:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1

Napomena: U rješenju se obavezno treba koristiti jedan C niz za unos podataka i jedan za konačni rezultat. Pretpostavite 
da ovaj drugi niz neće imati više od 1000 elemenata.
*/

#include <stdio.h>
#include <math.h>

int main() {
	
int a[100],b[2000],c[2000],d[2000];

int i,j,k,z,n,p;
double s;

for (i=0; i<2000 ;i++) {
	b[i]=0;
	c[i]=0;
	d[i]=0;
}

printf("Unesite velicinu niza: ");
scanf("%d",&n);
printf("Unesite clanove niza: ");

for(i=0; i<n; i++){
do {
	scanf("%lf",&s);
} while (fabs(s-(float)((int)s))>0.00001 || s<0);
a[i]=(int)s;
}

j=0;
a[n]=-1;

for(i=0;i<n;i++)
{
	j=j+log10(a[i])+1;
	k=j-1;
	
	if (a[i]==0 && i<j)
	b[k]=0;
	
	while(a[i]!=0){
	
		b[k]=a[i]%10;
		a[i]=a[i]/10;
		k--;
	}
	
}

z=b[0];
n=0;
p=2;
d[0]=z;

for(i=0; i<j; i++){
	while(b[i]==z&&i<j){
		c[n]++;
		i++;
	}
	if(i<j){z=b[i];
		d[p]=z;
		p+=2;
	}
	
	n++;
	i--;

}
n=0;
for(i=1; i<p; i=i+2)
{
	d[i]=c[n++];
}

printf("Finalni niz glasi:\n%d", d[0]);

for(i=1; i<p ;i++){
	printf(" %d",d[i]);
}

return 0;
}
