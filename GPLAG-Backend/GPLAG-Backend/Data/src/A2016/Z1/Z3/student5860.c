#include <stdio.h>

int main() {

	char vozila;
	int brojac=0, cx=0, bx=0, sx=0, vx=0, px=0;
    float pc, pb, ps, pv, pp;
    
printf("Unesite vozila: ");
	for(;;) {
    scanf("%c", &vozila);
    
     if(vozila=='C' || vozila=='c') 
          cx++; 
      else if(vozila=='B' || vozila=='b') 
        bx++; 
        else if(vozila=='S' || vozila=='s') 
        sx++;
      else if(vozila=='V' || vozila=='v') 
      vx++; 
        else if(vozila=='P' || vozila=='p') 
       px++; 
    
	 else if(vozila=='K' || vozila=='k')
           break;
    else  printf("Neispravan unos\n");


}
 brojac=cx+bx+sx+vx+px;



printf("Ukupno evidentirano %d vozila.\n", brojac);
if (brojac==0) brojac=1;
if(cx>=bx && cx>=sx && cx>=vx && cx>=px){
    pc=((float)cx/(float)brojac)*100;
    printf("Najpopularnija boja je crna (%.2f%%).", pc);
}
else if(bx>=cx && bx>=sx && bx>=vx && bx>=px){
    pb=((float)bx/(float)brojac)*100;
    printf("Najpopularnija boja je bijela (%.2f%%).", pb);
}
else if(sx>=cx && sx>=bx && sx>=vx && sx>=px){
    ps=((float)sx/(float)brojac)*100;
    printf("Najpopularnija boja je siva (%.2f%%).", ps);
}
else if(vx>=cx && vx>=bx && vx>=sx && vx>=px){
    pv=((float)vx/(float)brojac)*100;
    printf("Najpopularnija boja je crvena (%.2f%%).", pv);
}
else if(px>=cx && px>=bx && px>=sx && px>=vx){
    pp=((float)px/(float)brojac)*100;
    printf("Najpopularnija boja je plava (%.2f%%).", pp);
}

	return 0;


}







