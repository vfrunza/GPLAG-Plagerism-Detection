#include <stdio.h>

int main() {
	int brojac=0,ib=0,is=0,iv=0,ip=0,ic=0,boja1=100,boja2=100,boja3=100,boja4=100,boja5=100;
	float pro=0;
	char voz='q';
	printf("Unesite vozila: ");
	while (voz!='K' && voz!='k'){
   	scanf("%c",&voz);
   	if(voz=='c'||voz=='C'){
   	    boja1=brojac;
   	ic++;}
   	else if(voz=='b'||voz=='B'){
   	 boja2=brojac;  
   	 ib++;}
   	else if(voz=='s'||voz=='S'){
   	 boja3=brojac;   
   	is++;}
   	else if(voz=='v'||voz=='V'){
   	    boja4=brojac;
   	 iv++;}
   	else if(voz=='p'||voz=='P'){
   	    boja5=brojac;
   	    ip++;}
   	else if(voz=='k' || voz=='K') break;
   	else {
   	    printf("Neispravan unos\n");
   	    brojac --;
   	}
   	brojac ++;
   }
   printf("Ukupno evidentirano %d vozila.\n",brojac);
   if(ic==0 && ib==0 && is==0 && iv==0 && ip==0){
     printf("Najpopularnija boja je crna (%.2f%%).",pro);}
   else if(ic>ib && ic>is && ic>iv && ic>ip){
   	pro=((float)ic/(brojac))*100;
   	printf("Najpopularnija boja je crna (%.2f%%).",pro);
   }
   else if(ib>ic && ib>is && ib>iv && ib>ip){
   	pro=(float)ib/(brojac)*100;
   	printf("Najpopularnija boja je bijela (%.2f%%).",pro);
   }
   else if(is>ic && is>ib && is>iv && is>ip){
   	pro=(float)is/(brojac)*100;
   	printf("Najpopularnija boja je siva (%.2f%%).",pro);
   }
   else if(iv>ic && iv>ib && iv>is && iv>ip){
   	pro=(float)iv/(brojac)*100;
   	printf("Najpopularnija boja je crvena (%.2f%%).",pro);
   }
   else if(ip>ic && ip>ib && ip>is && ip>iv){
   	pro=(float)ip/(brojac)*100;
   	printf("Najpopularnija boja je plava (%.2f%%).",pro);
   }
  else if(boja1<boja2 || boja1<boja3 || boja1<boja4 || boja1<boja5){
   	pro=((float)ic/(brojac))*100;
   	printf("Najpopularnija boja je crna (%.2f%%).",pro);
   }
  else if(boja2<boja1 || boja2<boja3 || boja2<boja4 || boja2<boja5){
   	pro=((float)ib/(brojac))*100;
   	printf("Najpopularnija boja je bijela (%.2f%%).",pro);
   }
   else if(boja3<boja1 || boja3<boja2 || boja3<boja4 || boja3<boja5){
   	pro=((float)is/(brojac))*100;
   	printf("Najpopularnija boja je siva (%.2f%%).",pro);
   }
   else if(boja4<boja1 || boja4<boja3 || boja4<boja2 || boja4<boja5){
   	pro=((float)iv/(brojac))*100;
   	printf("Najpopularnija boja je crvena (%.2f%%).",pro);
   }
   else if(boja5<boja1 || boja5<boja3 || boja5<boja4 || boja5<boja2){
   	pro=((float)ip/(brojac))*100;
   	printf("Najpopularnija boja je plava (%.2f%%).",pro);
   }
	return 0;
}
