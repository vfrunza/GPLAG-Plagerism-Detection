#include <stdio.h>
#define ch character
int main() 
{
    int ch, brojAutomobila=0, c=0, b=0, s=0, v=0, p=0, max=-1;
    //boje imaju brojeve koji su njihovi redni brojevi u tekstu zadatka char ch;// ch skraceno od character
    printf("Unesite vozila: ");
    do{
        scanf("%c", &ch);
        if((ch=="c")||(ch=="C")){c++; brojAutomobila++;
        if((c>=b)&&(c>=s)&&(c>=v)&&(c>=p))max=1;}
        
        else if((ch=="b")|| (ch=="B")){b++; brojAutomobila++;
        if((b>c)&& (b>=s)&& (b>=v)&&(b>=p))max=2;}
        
        else if ((ch=="s")||(ch=="S")){s++; brojAutomobila++;
        if((s>c)&&(s>b)&&(s>=v)&&(s>=p))max=3;}
        
        else if ((ch=="v")||(ch=="V")){v++; brojAutomobila++;
        if((v>c)&&(v>b)&&(v>s)&&(v>=p))max=4;}
        
        else if ((ch=="p")||ch=="P"){p++; brojAutomobila++;
        if((p>c)&&(p>b)&&(p>s)&&(p>v))max=5;}
        
        else if((ch!="K")&&(ch!="k"))
        printf("Neispravan unos\n");
       }
       
       
       while ( (ch!="K") && (ch!="k"));
        printf("Ukupno evidentirano %d vozila.\n", brojAutomobila);
        printf("Najpopularnija boja je ");
       
        switch (max){
            case 1:
            printf("crna(%2lf%%)",((double)c/brojAutomobila)*100);
            break;
            
            case 2:
            printf("bijela(%2lf%%)",((double)b/brojAutomobila)*100);
            break;
            
            case 3:
            printf("siva(%2lf%%)", ((double)s/brojAutomobila)*100);
            break;
            
            case 4:
            printf("crvena(%2lf%%)",((double)c/brojAutomobila)*100);
            break;
            
            case 5:
            printf("plava(%2lf%%)", ((double)p/brojAutomobila)*100);
            break;
            
            default:
            printf("Niste unijeli nijedan automobil");
            break;}
        
    
	return 0;
}