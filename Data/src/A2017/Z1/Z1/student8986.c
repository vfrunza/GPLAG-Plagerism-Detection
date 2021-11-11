#include <stdio.h>


int main() {

int a,b,c;
float restoran, fastfood, bistro, c1,c2,c3,c4,c5,c6,c7,c8,c9;
char tarik, bojan, mirza,novi_red;


printf("Unesite jelo za Tarika: ");
scanf("%c",&tarik);
scanf("%c",&novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&bojan);
scanf("%c",&novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&mirza);
scanf("%c",&novi_red);

a=tarik;
b=bojan;
c=mirza;


if(a==72) { 
c1=3.3;c2=3;c3=5;    
} else if(a==67){  
c1=5;c2=3.9;c3=6;  
} else if(a==80) { 
c1=6.8;c2=8;c3=5.3;
}


if(b==72){ 
c4=3.3;c5=3;c6=5;   
} else if(b==67){  
c4=5;c5=3.9;c6=6;  
} else if(b==80) { 
c4=6.8;c5=8;c6=5.3;
}

if(c==72){ 
c7=3.3;c8=3;c9=5;   
} else if(c==67){ 
c7=5;c8=3.9;c9=6;  
} else if(c==80) { 
c7=6.8;c8=8;c9=5.3;
}


restoran = c1+c4+c7;
fastfood = c2+c5+c8;
bistro = c3+c6+c9;

if(restoran < fastfood && restoran < bistro)printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
else if(fastfood < restoran && fastfood < bistro){
   printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fastfood);
   
    if(c1==c4 && c1==c7)restoran=3*0.9*c1;
    else if(c1>c4 && c1>c7)restoran=0.9*c1+c4+c7;
    else if(c4>c1 && c4>c7)restoran=c1+ 0.9*c4+c7;
    else if(c7>c1 && c7>c4)restoran=c1+c4 + 0.9*c7;
    else if(c4==c7 && c4>c1)restoran=2*0.9*c4+c1;
    else if(c1==c7 && c1>c4)restoran=2*0.9*c1+c4;
    else if(c1==c4 && c1>c7)restoran=2*0.9*c1+c7;
    
    if(restoran < fastfood)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran);
}


else if(bistro < restoran && bistro < fastfood){
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistro);
    
     if(c1==c4 && c1==c7)restoran=3*0.9*c1;
    else if(c1>c4 && c1>c7)restoran=0.9*c1+c4+c7;
    else if(c4>c1 && c4>c7)restoran=c1+ 0.9*c4+c7;
    else if(c7>c1 && c7>c4)restoran=c1+c4+ 0.9*c7;
    else if(c4==c7 && c4>c1)restoran=2*0.9*c4+c1;
    else if(c1==c7 && c1>c4)restoran=2*0.9*c1+c4;
    else if(c1==c4 && c1>c7)restoran=2*0.9*c1+c7;
    
    if(restoran < bistro)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran);
}


	return 0;
}
