#include <stdio.h>

int main() {
 char u;
 int i=0;
 int q=0;
 int w=0;
 int e=0;
 int r=0;
 int t=0;
 float g,h,d,z,y;
 printf("Unesite vozila: ");
 while(1)
 {
 	scanf("%c", &u);
 	if(u=='k' || u=='K' ) break;
 	else if(u=='c' || u=='C'){
 		i++;
 		q++;
 	}
 	else if(u=='b'|| u=='B'){
 		i++;
 		w++;
 	}
 	else if(u=='s'|| u=='S'){
 		 i++;
 		 e++;
 	}
 	else if(u=='v'|| u=='V'){
 		i++;
 		r++;
 	}
 	else if(u=='p' || u=='P'){
 		i++;
 		t++;
 	}
 	else if(u!='c' && u!='C' && u!='b' && u!='B' && u!='s' && u!='S' && u!='v' && u!='V' && u!='p' && u!='P')
 	printf("Neispravan unos\n");
 	continue;
 }
    printf("Ukupno evidentirano %d vozila.", i);
    
  if(q==0 && w==0 && e==0 && r==0 && t==0 && i==0) {
     printf("\nNajpopularnija boja je crna (0.00%%).");
  } 
  else if((q>w || q==w) && (q>e || q==e) && (q>r || q==r) && (q>t || q==t)){
    g=(q*100.00)/i;
    printf("\nNajpopularnija boja je crna (%.2f%%).", g );
}

else  if((w>q) && (w>e || w==e) && (w>r || w==r) && (w>t || w==t)){
    h=(w*100.00)/i;
    printf("\nNajpopularnija boja je bijela (%.2f%%).", h);
 }   
 
else  if((e>q) && (e>w) && (e>r || e==r) && (e>t || e==t)) {
  d=(e*100.00)/i;
    printf("\nNajpopularnija boja je siva (%.2f%%).", d);
 }
 else if((r>q) && (r>w) && (r>e) && (r>t || r==t)) {
  z=(r*100.00)/i;
    printf("\nNajpopularnija boja je crvena (%.2f%%).", z);
 }
else if((t>q) && (t>w) && (t>e) && (t>r)) {
  y=(t*100.00)/i;
    printf("\nNajpopularnija boja je plava (%.2f%%).", y); 
  
 }
	return 0;
}
