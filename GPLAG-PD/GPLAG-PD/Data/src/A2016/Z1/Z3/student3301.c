#include <stdio.h>

int main() {
    int brojac=0,crvena=0,crna=0,plava=0,bijela=0,siva=0,k=0;
    float cproc,pproc,bproc,sproc,vproc,dproc=0;
    char r=' ';
    printf("Unesite vozila: ");
    while(r!='K' && r!='k'){
        scanf("%c",&r);
        if(r!='c' && r!='C' && r!='b' && r!='B' && r!='s' && r!='S' && r!='v' && r!='V' && r!='p' && r!='P' && r!='k' && r!='K'){
            printf("Neispravan unos\n");
            brojac--;
        }
        brojac++;
        if(r=='c') crna++;
        if(r=='C') crna++;
        if(r=='b') bijela++;
        if(r=='B') bijela++;
        if(r=='s') siva++;
        if(r=='S') siva++;
        if(r=='v') crvena++;
        if(r=='V') crvena++;
        if(r=='p') plava++;
        if(r=='P') plava++;
       
    }
    brojac=brojac-1;
        cproc=((crna*1.)/brojac)*100;
        vproc=((crvena*1.)/brojac)*100;
        bproc=((bijela*1.)/brojac)*100;
        pproc=((plava*1.)/brojac)*100;
        sproc=((siva*1.)/brojac)*100;
       /* printf("crna %d\n",crna);
        printf("bijela %d\n",bijela);
        printf("plava %d\n",plava);
        printf("siva %d\n",siva);
        printf("crvena %d\n",crvena);*/
         if(crna>k) k=crna;
         if(bijela>k) k=bijela;
         if(siva>k) k=siva;
         if(crvena>k) k=crvena;
         if(plava>k) k=plava;
    printf("Ukupno evidentirano %d vozila.\n",brojac);
    if(k==0){
        printf("Najpopularnija boja je crna (%.2f%%).",dproc);
    }
    else if(k==crna){
        printf("Najpopularnija boja je crna (%.2f%%).",cproc);
    }else if(k==bijela){
        printf("Najpopularnija boja je bijela (%.2f%%).",bproc);
    }else if(k==siva){
         printf("Najpopularnija boja je siva (%.2f%%).",sproc);
    }else if(k==crvena){
        printf("Najpopularnija boja je crvena (%.2f%%).",vproc);
    }else if(k==plava){
        printf("Najpopularnija boja je plava (%.2f%%).",pproc);
    }
    
    
	return 0;
}
