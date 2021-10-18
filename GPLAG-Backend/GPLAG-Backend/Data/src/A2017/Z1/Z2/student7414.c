#include <stdio.h>
#include <math.h>

#define epsilon 0.0001
int main() 
{	double PI = 4*atan(1); 
	double x1,x2,x3,y1,y2,y3,udaljenost1=0,udaljenost2=0,udaljenost3=0;
	double ugao1,ugao2,ugao3 ;
	double ugao1ukupno, ugao2ukupno, ugao3ukupno; 
	int ugao1sekunde,ugao1minute,ugao1stepeni;
	int ugao2sekunde,ugao2minute,ugao2stepeni;
	int ugao3sekunde,ugao3minute,ugao3stepeni;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1, &y1) ;
	printf("Unesite koordinate tacke t2: ") ;
	scanf("%lf %lf",&x2, &y2);
	printf("Unesite koordinate tacke t3: ") ;
	scanf("%lf %lf",&x3, &y3) ;
	
	udaljenost1=sqrt(pow((x2-x1), 2)+pow((y2-y1), 2));
	udaljenost2=sqrt(pow((x3-x2), 2)+pow((y3-y2), 2));
	udaljenost3=sqrt(pow((x1-x3), 2)+pow((y1-y3), 2));
	
	ugao1=acos((pow(udaljenost3,2) + pow(udaljenost2,2)- pow(udaljenost1,2))/(2*udaljenost2*udaljenost3));
	ugao2=acos((pow(udaljenost3,2) + pow(udaljenost1,2)- pow(udaljenost2,2))/(2*udaljenost3*udaljenost1));
	ugao3=acos((pow (udaljenost1,2) +pow(udaljenost2,2)-pow(udaljenost3,2))/(2*udaljenost1*udaljenost2));
	
    
    	ugao1ukupno=(ugao1*360*60*60)/(2*PI);
	    ugao1sekunde=(int)(ugao1ukupno)%60 ;
	    ugao1minute=((int)(ugao1ukupno)/60)%60;
	    ugao1stepeni=(int)(ugao1ukupno)/ (60*60);

		ugao2ukupno=(ugao2*360*60*60)/(2*PI);
	    ugao2sekunde=(int)(ugao2ukupno)%60 ;
	    ugao2minute=((int)(ugao2ukupno)/60)%60;
	    ugao2stepeni=(int)(ugao2ukupno)/ (60*60);
	    
	    ugao3ukupno=(ugao3*360*60*60)/(2*PI);
	    ugao3sekunde=(int)(ugao3ukupno)%60 ;
	    ugao3minute=((int)(ugao3ukupno)/60)%60;
	    ugao3stepeni=(int)(ugao3ukupno)/ (60*60);
	
	
	if (((ugao1stepeni==180)&&(ugao1minute==0)&&(ugao1sekunde==0)) || ((ugao2stepeni==180)&&(ugao2minute==0)&&(ugao2sekunde==0)) || ((ugao3stepeni==180)&&(ugao3minute==0)&&(ugao3sekunde==0))){
		printf("Linija \nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n"); 
	
    } else {
    
	
	if (((ugao1stepeni==90)&&(ugao1minute==0)&&(ugao1sekunde==0)) || ((ugao2stepeni==90)&&(ugao2minute==0)&&(ugao2sekunde==0)) || ((ugao3stepeni==90)&&(ugao3minute==0)&&(ugao3sekunde==0))){
	printf("Pravougli\n");}
	if(fabs(udaljenost1-udaljenost2)<epsilon && fabs(udaljenost1-udaljenost3)<epsilon && fabs(udaljenost2-udaljenost3)<epsilon){
	printf("Jednakostranicni\n");}
	if (fabs(udaljenost1-udaljenost2)<epsilon && fabs(udaljenost1-udaljenost3)>epsilon && fabs(udaljenost2-udaljenost3)>epsilon){
	printf("Jednakokraki\n");}
	else if (fabs(udaljenost1-udaljenost3)<epsilon && fabs(udaljenost2-udaljenost3)>epsilon && fabs(udaljenost1-udaljenost2)>epsilon){
	printf("Jednakokraki\n");}
	else if (fabs(udaljenost2-udaljenost3)<epsilon && fabs(udaljenost1-udaljenost2)>epsilon && fabs(udaljenost1-udaljenost3)>epsilon){
   	printf("Jednakokraki\n");}
   
	
	
	else if((fabs(udaljenost1-udaljenost2)>epsilon && fabs(udaljenost3-udaljenost2)>epsilon) && fabs(udaljenost1-udaljenost3)>epsilon){
	
	printf("Raznostranicni\n");}
    

			
		
		
	    if ((ugao1>ugao2) && (ugao1>ugao3)){
	    printf( "Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",ugao1stepeni,ugao1minute,ugao1sekunde);}
	    if ((ugao2>ugao1) && (ugao2>ugao3)){
	    printf( "Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",ugao2stepeni,ugao2minute,ugao2sekunde);}
	    if ((ugao3>ugao1) && (ugao3>ugao2)){
	    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",ugao3stepeni,ugao3minute,ugao3sekunde);}
}
	return 0 ;
}