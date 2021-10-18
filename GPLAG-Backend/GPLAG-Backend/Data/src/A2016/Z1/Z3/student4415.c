#include <stdio.h>

int main(){
  int z,C,B,S,V,P;
  
  double posto,suma,m1=0;
  
  C=0;
  B=0;
  S=0;
  V=0;
  P=0;
  printf("Unesite vozila: ");
  z = getchar();
  
  while(z!='k' && z!='K'){
  
  if(z=='c' || z=='C')
  C++;
  else if(z=='b' || z=='B')
  B++;
  else if(z=='s' || z=='S')
  S++;
  else if(z=='v' || z=='V')
  V++;
  else if(z=='p' || z=='P')
  P++;
  else if(z=='\n')
  continue;
  else printf("Neispravan unos\n");
  z = getchar();
  }
  
  
  suma=C+B+S+V+P;

  
  if(C>=B && C>=S && C>=V && C>=P)
  m1=C;
  else if(B>=C && B>=S && B>=V && B>=P)
  m1=B;
  else if(S>=B && S>=C && S>=V && S>=P)
  m1=S;
  else if(V>=B && V>=S && V>=C && V>=P)
  m1=V;
  else if(P>=B && P>=S && P>=V && P>=C)
  m1=P;
  if ((int)suma!=0)
  posto=m1/suma*100;
  else posto=0;
  
  printf("Ukupno evidentirano %.0f vozila.\n",suma);
  if((int)m1==C)
  printf("Najpopularnija boja je crna (%.2f%%).",posto);
  else if((int)m1==B)
  printf("Najpopularnija boja je bijela (%.2f%%).",posto);
  else if((int)m1==S)
  printf("Najpopularnija boja je siva (%.2f%%).",posto);
  else if((int)m1==V)
  printf("Najpopularnija boja je crvena (%.2f%%).",posto);
  else if((int)m1==P)
  printf("Najpopularnija boja je plava (%.2f%%).",posto);
  
  
  
  
return 0;
}