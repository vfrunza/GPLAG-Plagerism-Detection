#include <stdio.h>

int main() {
	char x;
	int i,c=0,b=0,s=0,v=0,p=0,total=0;
	float proc,popular;
	printf("Unesite vozila: ");
	
	for(i=1;i>0;i++){
		scanf("%c",&x);
		if((x=='c')||(x=='C')){
			c++;
			total++;
		}
		else if((x=='b')||(x=='B')){
			b++;
			total++;
		}
		else if((x=='s')||(x=='S')){
			s++;
			total++;
		
	}
	else if((x=='v')||(x=='V')){
			v++;
			total++;
	}
	
	else if((x=='p')||(x=='P')){
			p++;
			total++;
	}
	else if((x=='k')||(x=='K')){
			break;
			
	}
		else if((x!='k')&&(x!='b')&&(x!='c')&&(x!='s')&&(x!='v')&&(x!='p')&&(x!='K')&&(x!='B')&&(x!='C')&&(x!='S')&&(x!='V')&&(x!='P')){
			printf("Neispravan unos\n");
		}
	}
	if(c>=v && c>=b && c>=s && c>=p && c!=0){
		popular=c;
	}
	if(v>=c && v>=b && v>=s && v>=p && v!=0){
		popular=v;
	}
	if(b>=c && b>=v && b>=s && b>=p && b!=0){
		popular=b;
	}
	if(s>=c && s>=b && s>=v && s>=p && s!=0){
		popular=s;
	}
	if(p>=c && p>=b && p>=s && p>=v && p!=0){
		popular=p;
	}
	
	proc=(popular/total)*100;
	printf("Ukupno evidentirano %d vozila.\n",total);
	
	if(total==0){
		printf("Najpopularnija boja je crna (0.00%).\n");
		return 0;
	}
	if(popular==c){
		printf("Najpopularnija boja je crna (%.2f%).\n",proc);
		return 0;
	}
	else if(popular==b){
	printf("Najpopularnija boja je bijela (%.2f%).\n",proc);
	return 0;
	}
	else if(popular==s){
		printf("Najpopularnija boja je siva (%.2f%).\n",proc);
		return 0;
	}
	else if(popular==v){
		printf("Najpopularnija boja je crvena (%.2f%).\n",proc);
		return 0;
	}
	else if(popular==p){
		printf("Najpopularnija boja je plava (%.2f%).\n",proc);
		return 0;
	}
	return 0;
}
