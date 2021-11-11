#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, i, procenat=0;
	char auta[2000];
	float procc,procb,procs,procv,procp;
	printf("Unesite vozila: ");
	scanf("%s", &auta);
	for(i=0; auta[i]!='\0'; ++i)
	{
		if(auta[i]=='c' || auta[i]=='C')
		{
			crna++;	
		}
		if(auta[i]=='b' || auta[i]=='B')
		{
			bijela++;	
		}
		if(auta[i]=='s' || auta[i]=='S')
		{
			siva++;	
		}
		if(auta[i]=='v' || auta[i]=='V')
		{
			crvena++;	
		}
		if(auta[i]=='p' || auta[i]=='P')
		{
			plava++;	
		}
		if(auta[i]=='a' || auta[i]=='d' || auta[i]=='e' || auta[i]=='f' || auta[i]=='g' || auta[i]=='h' || auta[i]=='i' || auta[i]=='j' || auta[i]=='l' || auta[i]=='m' || auta[i]=='n' || auta[i]=='o' || auta[i]=='r' || auta[i]=='t' || auta[i]=='u' || auta[i]=='z' || auta[i]=='y' || auta[i]=='x' || auta[i]=='w' || auta[i]==' ' || auta[i]==',' || auta[i]=='1' || auta[i]=='2'  || auta[i]=='0' || auta[i]==' 3' || auta[i]=='4' || auta[i]=='5' || auta[i]=='6' || auta[i]=='7' || auta[i]=='8' || auta[i]=='9' || auta[i]=='/' || auta[i]=='*' || auta[i]=='-' || auta[i]=='.' || auta[i]=='-' || auta[i]=='<' || auta[i]=='>' || auta[i]=='A' || auta[i]=='D' || auta[i]=='E' || auta[i]=='F' || auta[i]=='G' || auta[i]=='H' || auta[i]=='I' || auta[i]=='J' || auta[i]=='L' || auta[i]=='M' || auta[i]=='N' || auta[i]=='O' || auta[i]=='R' || auta[i]=='T' || auta[i]=='U' || auta[i]=='Z' || auta[i]=='Y' || auta[i]=='W' || auta[i]=='X')
		{
			printf("Neispravan unos\n");	
		}
		if(auta[i]=='k' || auta[i]=='K')
		{
			break;	
		}
	}
	procenat=crna+bijela+siva+crvena+plava;
	procc=(crna/(float)procenat)*100;
	procb=(bijela/(float)procenat)*100;
	procs=(siva/(float)procenat)*100;
	procv=(crvena/(float)procenat)*100;
	procp=(plava/(float)procenat)*100;
	printf("Ukupno evidentirano %d vozila.\n",procenat);
	if(procc>=procb && procc>=procs && procc>=procv && procc>=procp)
	{
		printf("Najpopularnija boja je crna (%.2f%).", procc);
	}
	else if(procb>=procc && procb>=procs && procb>=procv && procb>=procp)
	{
		printf("Najpopularnija boja je bijela (%.2f%).", procb);
	}
	else if(procs>=procc && procs>=procb && procs>=procv && procs>=procp)
	{
		printf("Najpopularnija boja je siva (%.2f%).", procs);
	}
	else if(procv>=procc && procv>=procb && procv>=procv && procv>=procp)
	{
		printf("Najpopularnija boja je crvena (%.2f%).", procv);
	}
	else if(procp>=procc && procp>=procb && procp>=procs && procp>=procv)
	{
		printf("Najpopularnija boja je plava (%.2f%).", procp);
	}
	else if (procenat==0)
	{
		procc=0;
		printf("Najpopularnija boja je crna (%.2f%).", procc);	
	}
	return 0;
}
