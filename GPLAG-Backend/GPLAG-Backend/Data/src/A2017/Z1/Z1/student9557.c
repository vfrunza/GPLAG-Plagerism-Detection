#include <stdio.h>

int main() {
	char tarik,bojan,mirza,novi_red;
	double K,T,R,NK,temp1,temp2,temp3;
	int a=1;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c",&novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c",&mirza);
	scanf ("%c", &novi_red);
	
	if ('H'==tarik && 'H'==bojan && 'H'==mirza){
		K=3.3*3;
		T=3*3;
		R=5*3;
		temp1=temp2=temp3=(3.3-((3.3/100)*10))*3;
	}
	
	else if ('P'==tarik && 'P'==bojan && 'P'==mirza){
		K=6.8*3;
		T=8*3;
		R=5.3*3;
		temp1=temp2=temp3=(6.8-((6.8/100)*10))*3;
	}
	
	else if ('C'==tarik && 'C'==bojan && 'C'==mirza){
		K=5*3;
		T=3.9*3;
		R=6*3;
		temp1=temp2=temp3=(5-((5/100)*10))*3;
	}	
	
	else if ('P'==tarik && 'H'==bojan && 'C'==mirza){
		K=6.80+3.3+5;
		T=8+3+3.9;
		R=5+5.3+6;
		temp1=(6.8-((6.8/100)*10))+3.3+5;
		temp2=(3.3-((3.3/100)*10))+6.8+5;
		temp3=(5-((5/100)*10))+6.8+3.3;
		
	}
	
	else if ('C'==tarik && 'H'==bojan && 'P'==mirza){
		K=6.80+3.3+5;
		T=8+3+3.9;
		R=5+5.3+6;
		temp1=(6.8-((6.8/100)*10))+3.3+5;
		temp2=(3.3-((3.3/100)*10))+6.8+5;
		temp3=(5-((5/100)*10))+6.8+3.3;
		
	}
	
	else if ('P'==tarik && 'P'==bojan && 'H'==mirza){
		K=6.8*2+3.3;
		T=8*2+3;
		R=5*2+5.3;
		temp1=temp2=(6.8-((6.8/100)*10))*2+3.3;
		temp3=(3.3-((3.3/100)*10))+6.8*2;
	}
	
	else if ('P'==tarik && 'P'==bojan && 'C'==mirza) {
		K=6.8*2+5;
		T=8*2+3.9;
		R=5.3*2+6;
		temp1=temp2=(6.8-((6.8/100)*10))*2+5;
		temp3=(5-((5/100)*10))+6.8*2;
	}
	
	else if ('H'==tarik && 'H'==bojan && 'P'==mirza){
		K=3.3*2+6.8;
		T=3*2+8;
		R=5*2+5.3;
		temp1=temp2=(3.3-((3.3/100)*10))*2+6.8;
		temp3=(6.8-((6.8/100)*10))+3.3*2;
	}
	
	else if ('H'==tarik && 'H'==bojan && 'C'==mirza){
		K=3.3*2+5;
		T=3*2+6;
		R=5*2+6;
		temp1=temp2=(3.3-((3.3/100)*10))*2+5;
		temp3=(5-((5/100)*10))+3.3*2;
	}
	
	else if ('C'==tarik && 'H'==bojan && 'H'==mirza){
		K=3.3*2+5;
		T=3*2+3.9;
		R=5*2+6;
		temp1=temp2=(3.3-((3.3/100)*10))*2+5;
		temp3=(5-((5/100)*10))+3.3*2;
	}
	else if ('C'==tarik && 'C'==bojan && 'P'==mirza){
		K=5*2+6.8;
		T=3.9*2+8;
		R=6*2+5.3;
		temp1=temp2=(5-((5/100)*10))*2+6.8;
		temp3=(6.8-((6.8/100)*10))+5*2;
	}
	
	else if ('C'==tarik && 'C'==bojan && 'P'==mirza){
		K=5*2+6.8;
		T=3.9*2+8;
		R=6*2+5.3;
		temp1=temp2=(5-((5/100)*10))*2+6.8;
		temp3=(6.8-((6.8/100)*10))+5*2;
	}
	else if ('C'==tarik && 'P'==bojan && 'C'==mirza){
		K=5*2+6.8;
		T=3.9*2+8;
		R=6*2+5.3;
		temp1=temp2=(5-((5/100)*10))*2+6.8;
		temp3=(6.8-((6.8/100)*10))+5*2;
	}
	
	else if ('H'==tarik && 'C'==bojan && 'C'==mirza){
		K=5*2+3.3;
		T=3.9*2+3;
		R=6*2+5;
		temp1=temp2=(5-((5/100)*10))*2+3.3;
		temp3=(3.3-((3.3/100)*10))+5*2;
	}
	
	else if ('H'==tarik && 'P'==bojan && 'P'==mirza){
		K=3.3+6.8*2;
		T=3+8*2;
		R=5+5.3*2;
		temp1=temp2=(6.8-((6.8/100)*10))*2+3.3;
		temp3=(3.3-((3.3/100)*10))+6.8*2;
	}

	if (temp1==temp2 && temp1==temp3) NK=temp1;
	else if (temp1<=temp2 && temp1<=temp3) NK=temp1;
	else if(temp2<=temp1 && temp2<=temp3) NK=temp2;
	else if (temp3<=temp1 && temp3<=temp2) NK=temp3;

	if (K<T && K<R){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM). ",K);
		a=0;
	}
	else if (T<K && T<R)
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM)." ,T);
	else if (R<K && R<T)
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R);
	
	if ((T>K || R>K) && a==1){
		if (NK<T && NK<R){
			printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NK);
		}
	}
	
	return 0;
	
}