#include <stdio.h>
int main(){
 int brojac_c=0,brojac_b=0,brojac_s=0,brojac_v=0,brojac_p=0,ukupno=0;
 double procenat_crne,procenat_bijele,procenat_sive,procenat_crvene,procenat_plave;
  char boja;
  printf("Unesite vozila: ");
  do{
     scanf("%c",&boja);
     if(boja!='C' && boja!='c' && boja!='B' && boja!='b' && boja!='S' && boja!='s' && boja!='V' && boja!='v' && boja!='P' && boja!='p' && boja!='K' && boja!='k'){
      printf("Neispravan unos\n");
     }
     if(boja=='C' || boja=='c'){
      brojac_c++;
     }
     if(boja=='B' || boja=='b'){
      brojac_b++;
     }
     if(boja=='S' || boja=='s'){
      brojac_s++;
     }
     if(boja=='V' || boja=='v'){
      brojac_v++;
     }
     if(boja=='P' || boja=='p'){
      brojac_p++;
     }
  }
  while(boja!='K' && boja!='k');
    ukupno=brojac_p+brojac_v+brojac_s+brojac_b+brojac_c;
    printf("Ukupno evidentirano %d vozila.\n",ukupno);

    procenat_crne=((double)(brojac_c*100)/(ukupno+0.0000001));
    procenat_bijele=((double)(brojac_b*100)/(ukupno+0.0000001));
    procenat_sive=((double)(brojac_s*100)/(ukupno+0.0000001));
    procenat_crvene=((double)(brojac_v*100)/(ukupno+0.0000001));
    procenat_plave=((double)(brojac_p*100)/(ukupno+0.0000001));

    if(brojac_c>=brojac_b && brojac_c>=brojac_v && brojac_c>=brojac_p && brojac_c>=brojac_s){
     printf("Najpopularnija boja je crna (%.2lf%%).",procenat_crne);
    }
    if(brojac_b>brojac_c && brojac_b>=brojac_v && brojac_b>=brojac_p && brojac_b>=brojac_s){
     printf("Najpopularnija boja je bijela (%.2lf%%).",procenat_bijele);
    }
    if(brojac_s>brojac_b &&  brojac_s>brojac_c && brojac_s>=brojac_v && brojac_s>=brojac_p){
     printf("Najpopularnija boja je siva (%.2lf%%).",procenat_sive);
    }
    if(brojac_v>brojac_c && brojac_v>brojac_b && brojac_v>brojac_s && brojac_v>=brojac_p){
     printf("Najpopularnija boja je crvena (%.2lf%%).",procenat_crvene);
    }
    if(brojac_p>brojac_c && brojac_p>brojac_b && brojac_p>brojac_s && brojac_p>brojac_v){
     printf("Najpopularnija boja je plava (%.2lf%%).",procenat_plave);
    }
 return 0;
}
