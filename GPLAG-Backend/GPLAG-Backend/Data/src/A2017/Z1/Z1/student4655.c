#include <stdio.h>
int main() {
	char t,b,m,chk;
	float uk1=0,uk2=0,uk3=0,ukp,t1;
	int PI=0,HA=0,CE=0,t2;
//input--------------------------------	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&chk);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&chk);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&chk);

//tarik------------hrana
	switch(t){
		case 'P': 
		PI++;
		break;
		case 'H':
		HA++;
		break;
		case 'C':
		CE++;
		break;
	}
//bojan------------hrana
	switch(b){
		case 'P':
		PI++;
		break;
		case 'H':
		HA++;
		break;
		case 'C':
		CE++;
		break;
	}
//mirza------------hrana
	switch(m){
		case 'P':
		PI++;
		break;
		case 'H':
		HA++;
		break;
		case 'C':
		CE++;
		break;
	}
  	//restoran 1
  	uk1=(PI*6.80+HA*3.30+CE*5.);
	if(PI>0){
		ukp=((PI*6.80)-(10*6.80)/100*PI)+HA*3.30+CE*5.;
	}
	else if(CE>0){
		ukp=((CE*5.)-(10*5.)/100*CE)+PI*6.80+HA*3.3;
	}
	else{
		ukp=((HA*3.30)-(10*3.3)/100*HA)+PI*6.80+CE*5.;
	}
  	//restoran 2
  	uk2=(PI*8.+HA*3.+CE*3.9);
  	//restoran 3
  	uk3=(PI*5.3+HA*5.+CE*6.);
//poredjenje cjena---------------------
	if(uk3<uk1&&uk3<uk2){
		t1=uk3;
		t2=1;
	}
	else if(uk2<uk1){
		t1=uk2;
		t2=2;
	}
	else{
		t1=uk1;
		t2=3;
	}
switch(t2){
	case 3:
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",uk1);
	break;
	case 2:
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",uk2);
	break;
	case 1:
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",uk3);
}
//poredjenje cjene sa popustom sa najmanjom
if(t1>ukp&&t1!=uk1){
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",ukp);
}
	return 0;
}