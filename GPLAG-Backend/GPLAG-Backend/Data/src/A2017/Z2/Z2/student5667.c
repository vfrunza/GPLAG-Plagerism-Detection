#include<stdio.h>
#include<string.h>
char a[10000];
int brojac(int x){
	int b=0,b1=1,i=x+1,j;if(a[i]==' ')i++;
	if(a[x]==a[i])while(a[x]==a[i]){b++;i++;if(a[i]==' ')i++;}
	return b1 + b;
}
int indeks(int x){
	int b=0,b1=1,i=x+1,j;if(a[i]==' ')i++;
	if(a[x]==a[i])while(a[x]==a[i]){b++;i++;if(a[i]==' ')i++;}
	return i;
}
int niz1[100];
int main(){
	int n,i,j;
	do{printf("Unesite velicinu niza: ");
		scanf("%d",&n);
		if(n<0)printf("Uneseni broj nije prirodan!\n");
		else if(n>100)printf("Neispravna velicina!\n");
	}while(n<0||n>100);printf("Unesite clanove niza: ");
	scanf(" %[^\n]s", a);
	printf("Finalni niz glasi:\n");
	for(i=0;i<strlen(a);i++){
	  if(a[i]!=' '){
		printf("%c %d ",a[i],brojac(i));
		i=indeks(i)-1;
	  }
	}
	return 0;
}