#include <stdio.h>

int main() {
	
	char x='o';
	int ukupno=0;
	int c=0, b=0, s=0, v=0, p=0;
	
	printf("Unesite vozila: ");
	
	do{ 
	scanf("%c", &x);
	
	if(x=='c' || x=='C' || x=='b' || x=='B' || x=='s' || x=='S' || x=='v' || x=='V' || x=='p' || x=='P' || x=='k' || x=='K')
	{
	if(x=='C' || x=='c') {c++; }
	else if(x=='B' || x=='b') {b++; }
	else if(x=='S' || x=='s') {s++; }
	else if(x=='V' || x=='v') {v++; }
	else if (x=='P' || x=='p') {p++; }
	
	else if(x=='k') break;
	else if(x=='K') break;
	}
	else if (x!='c' && x!='C' && x!='b' && x!='B' && x!='s' && x!='S' && x!='v' && x!='V' && x!='p' && x!='P' && x!='k' && x!='K'){
    printf("Neispravan unos\n"); continue;	}
		
	} while(x!='K' || x!='k'); 
	
	ukupno=c+b+s+v+p;
	 printf("Ukupno evidentirano %d vozila.\n", ukupno);
	
	float pr=0;
    
    if((c>b && c>v && c>s && c>p) || (c==b && c>v && c>s && c>p) || (c>b && c>v && c==s && c>p) || (c>b && c>v && c>s && c==p) || (c==b && c==s && c==v && c==p)){
    	if(ukupno==0) pr=0;
    	else
    	pr=((float) c/(float)ukupno)*100;
    	
    	printf("Najpopularnija boja je crna (%.2f%%).\n", pr);
    }
    
     if((b>c && b>v && b>s && b>p) || (b>c && b>v && b==s && b>p) || (b>c && b>v && b>s && b==p) || (b>c && b==v && b>s && b>p)){
    		pr=((float) b/(float)ukupno)*100;
    	printf("Najpopularnija boja je bijela (%.2f%%).\n", pr);
    }
    
    else if((c==b && b>v && b>s && b>p)){
    	pr=((float) c/(float)ukupno)*100;
    	printf("Najpopularnija boja je crna (%.2f%%).\n", pr);
    }
    
     if((s>b && s>v && s>c && s>p) || (s==v && s>p && s>c && c>b) || (s==p && s>v && s>b && s>c) || (s==p && s==v && s>c && s>b)){
    	pr=((float) s/(float)ukupno)*100;
    	printf("Najpopularnija boja je siva (%.2f%%).\n", pr);
    }
    else if (s==b && s==c && s>v && s>p){
    		pr=((float) c/(float)ukupno)*100;
    	printf("Najpopularnija boja je crna (%.2f%%).\n", pr);
    }
    else if (b>c && b>v && b==s && b>p){
    		pr=((float) b/(float)ukupno)*100;
    	printf("Najpopularnija boja je bijela (%.2f%%).\n", pr);
    }
    
     if((v>c && v>b && v>s && v>p) || (v==p && v>c && v>b && v>s)){
    	pr=((float) v/(float)ukupno)*100;
    	printf("Najpopularnija boja je crvena (%.2f%%).\n", pr);
    }
    else if((v==p && v==s && v==b && v>c) || (v==s && v==b && v>c && v>p)){
  	pr=((float) b/(float)ukupno)*100;
    	printf("Najpopularnija boja je bijela (%.2f%%).\n", pr);
    }
    
    else if ((v==s && v==b && v==c && v>p) || (v==c && v>b && v>s && v>p) || (v==c && v>b && v>s && v>p)){
    		pr=((float) c/(float)ukupno)*100;
    	printf("Najpopularnija boja je crna (%.2f%%).\n", pr);
    }
    
    if(p>v && p>s && p>b && p>c){
    			pr=((float) p/(float)ukupno)*100;
    	printf("Najpopularnija boja je plava (%.2f%%).\n", pr);
    }
    
    else if(p==v && p==s && p==b && p>c){
    		pr=((float) b/(float)ukupno)*100;
    	printf("Najpopularnija boja je bijela (%.2f%%).\n", pr);
    }
  
	return 0;
}
