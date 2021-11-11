#include <stdio.h>

int main() {
	int c=0,b=0,s=0,v=0,p=0,n=0;
	char a;
	float C,B,S,V,P;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&a);
			
	 if(a=='c' || a=='C'){
			c++;
			n++;
		}
			else if(a=='b'||a=='B'){
				b++;
				n++;
			}
				else if(a=='s'||a=='S'){
					s++;
					n++;
				}
					else if(a=='v'||a=='V'){
						v++;
						n++;
					}
						else if(a=='P'||a=='p'){
							p++;
							n++;
						}
							else if(a=='K'||a=='k')
								break;
									else
										printf("Neispravan unos\n");
	}while(a!='K'&& a!='k');
	printf("Ukupno evidentirano %d vozila.\n",n);
	C=((float) c/n)*100;
	P=((float) p/n)*100;
	S=((float) s/n)*100;
	V=((float) v/n)*100;
	B=((float) b/n)*100;
		if(n==0)
			printf("Najpopularnija boja je crna (0.00%%).");
				else if(c>=b&&c>=s&&c>=v&&c>=p)
					printf("Najpopularnija boja je crna (%.2f%%).",C);
	 			else if(b>=c&&b>=s&&b>=v&&b>=p)
						printf("Najpopularnija boja je bijela (%.2f%%).",B);
						else if(s>=c&&s>=b&&s>=v&&s>=p)
							printf("Najpopularnija boja je siva (%.2f%%).",S);
							else if(v>=p&&v>=c&&v>=s&&v>=b)
								printf("Najpopularnija boja je crvena (%.2f%%).",V);
								else if(p>=c&&p>=b&&p>=s&&p>=v)
					    			printf("Najpopularnija boja je plava (%.2f%%).",P);
												
	return 0;
}