#include <stdio.h>

int main() {
	int ci=0,bi=0,si=0,vi=0,pi=0,br=0,max=0;
	char c='c',b='b',s='s',v='v',p='p',C='C',B='B',S='S',V='V',P='P',n,K='K',k='k';
	printf("Unesite vozila: ");
         	scanf("%c",&n);
	while(n!=K)
	{
		if(n==K || n==k){
			break;
		}
	
		if(n==c || n==b || n==s || n==v || n==p || n==C || n==B || n==S || n==V || n==P){
	    
	    if(n==c || n==C){
			ci++;
			br++;
			if(ci>max){
				max=ci;
				
			}
			
		}
		else if(n==b || n==B){
			bi++;
			br++;
			if(bi>max){
				max=bi;
		}
		}
		else if(n==s || n==S){
			si++;
			br++;
			if(si>max){
				max=si;
			}
		}
		else if(n==v || n==V){
			vi++;
			br++;
			if(vi>max){
				max=vi;
			}
		}
		else if(n==p || n==P){
			pi++;
			br++;
			if(pi>max){
				max=pi;
			}
		}
		}else{
			printf("Neispravan unos\n");
		
		}
			
		scanf("%c",&n);
	
		
			
    
	}
	
	printf("Ukupno evidentirano %d vozila.\n",br);
	
		if(br==0){
			printf("Najpopularnija boja je crna (%.2f%).",((float)00.00));
		}
	 	else if(max==ci){
			printf("Najpopularnija boja je crna (%.2f%).",((float)ci/br)*100);
		}
		else if(max==bi){
		printf("Najpopularnija boja je bijela (%.2f%).",((float)bi/br)*100);
		}
		else if(max==si){
		printf("Najpopularnija boja je siva (%.2f%).",((float)si/br)*100);
		}
		else if(max==vi){
		printf("Najpopularnija boja je crvena (%.2f%).",((float)vi/br)*100);
		}
		else if(max==pi){
		printf("Najpopularnija boja je plava (%.2f%).",((float)pi/br)*100);
		}
	
	return 0;
}
