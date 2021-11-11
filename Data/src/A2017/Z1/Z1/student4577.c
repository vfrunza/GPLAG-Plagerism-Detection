#include <stdio.h>

int main()
{
	char unos1,unos2,unos3,novi_red;
	float pizza1=6.80,hamburger1=3.30,cevapi1=5.00;
	float pizza2=8.00,hamburger2=3.00,cevapi2=3.90;
	float pizza3=5.30,hamburger3=5.00,cevapi3=6.00;
	int H,C,P;
	float MAX=0;
	if(pizza1>hamburger1 && pizza1>cevapi1) MAX=pizza1;
	else if(hamburger1>pizza1 && hamburger1>cevapi1) MAX=hamburger1;
	else if(cevapi1>pizza1 && cevapi1>hamburger1) MAX=cevapi1;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&unos1);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&unos2);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&unos3);
	scanf("%c",&novi_red);
	if((unos1=='P' && unos2=='H' && unos3=='C')||(unos1=='P' && unos2=='C' && unos3=='H')||(unos1=='H' && unos2=='C' && unos3=='P')||(unos1=='H' && unos2=='P' && unos3=='C')||(unos1=='C' && unos2=='P' && unos3=='H')||(unos1=='C' && unos2=='H' && unos3=='P')) {
		if(pizza1+hamburger1+cevapi1<pizza2+hamburger2+cevapi2 && pizza1+hamburger1+cevapi1<pizza3+hamburger3+cevapi3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",pizza1+hamburger1+cevapi1);
		else if(pizza2+hamburger2+cevapi2<pizza1+hamburger1+cevapi1 && pizza2+hamburger2+cevapi2<pizza3+hamburger3+cevapi3 && pizza2+hamburger2+cevapi2<pizza1+hamburger1+cevapi1-MAX/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",pizza2+hamburger2+cevapi2);
		else if(pizza2+hamburger2+cevapi2<pizza1+hamburger1+cevapi1 && pizza2+hamburger2+cevapi2<pizza3+hamburger3+cevapi3 && pizza2+hamburger2+cevapi2>pizza1+hamburger1+cevapi1-MAX/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",pizza2+hamburger2+cevapi2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",pizza1+hamburger1+cevapi1-MAX/10);
		} else if(pizza3+hamburger3+cevapi3<pizza1+hamburger1+cevapi1 && pizza3+hamburger3+cevapi3<pizza2+hamburger2+cevapi2 && pizza3+hamburger3+cevapi3<pizza1+hamburger1+cevapi1-MAX/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",pizza3+hamburger3+cevapi3);
		else if(pizza3+hamburger3+cevapi3<pizza1+hamburger1+cevapi1 && pizza3+hamburger3+cevapi3<pizza2+hamburger2+cevapi2 && pizza3+hamburger3+cevapi3>pizza1+hamburger1+cevapi1-MAX/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",pizza3+hamburger3+cevapi3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",pizza1+hamburger1+cevapi1-MAX/10);
		}
	} else if(unos1=='H' && unos2=='H' && unos3=='H') {
		if(3*hamburger1<3*hamburger2 && 3*hamburger1<3*hamburger3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",3*hamburger1);
		else if(3*hamburger2<3*hamburger1 && 3*hamburger2<3*hamburger3 && 3*hamburger2<3*hamburger1-3*hamburger1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",3*hamburger2);
		else if(3*hamburger2<3*hamburger1 && 3*hamburger2<3*hamburger3 && 3*hamburger2>3*hamburger1-3*hamburger1/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",3*hamburger2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*hamburger1-3*hamburger1/10);
		} else if(3*hamburger3<3*hamburger1 && 3*hamburger3<3*hamburger2 && 3*hamburger3<3*hamburger1-3*hamburger1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",3*hamburger3);
		else if(3*hamburger3<3*hamburger1 && 3*hamburger3<3*hamburger2 && 3*hamburger3>3*hamburger1-3*hamburger1/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",3*hamburger3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*hamburger1-3*hamburger1/10);
		}
	} else if(unos1=='P' && unos2=='P' && unos3=='P') {
		if(3*pizza1<3*pizza2 && 3*pizza1<3*pizza3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",3*pizza1);
		else if(3*pizza2<3*pizza1 && 3*pizza2<3*pizza3 && 3*pizza2<3*pizza1-3*pizza1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",3*pizza2);
		else if(3*pizza2<3*pizza1 && 3*pizza2<3*pizza3 && 3*pizza2<3*pizza1-3*pizza1/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",3*pizza2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*pizza1-3*pizza1/10);
		} else if(3*pizza3<3*pizza1 && 3*pizza3<3*pizza2 && 3*pizza3<3*pizza1-3*pizza1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",3*pizza3);
		else if(3*pizza3<3*pizza1 && 3*pizza3<3*pizza2 && 3*pizza3>3*pizza1-3*pizza1/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",3*pizza3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*pizza1-3*pizza1/10);
		}
	} else if(unos1=='C' && unos2=='C' && unos3=='C') {
		if(3*cevapi1<3*cevapi2 && 3*cevapi1<3*cevapi3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",3*cevapi1);
		else if(3*cevapi2<3*cevapi1 && 3*cevapi2<3*cevapi3 && 3*cevapi2<3*cevapi1-3*cevapi1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",3*cevapi2);
		else if(3*cevapi2<3*cevapi1 && 3*cevapi2<3*cevapi3 && 3*cevapi2>3*cevapi1-3*cevapi1/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",3*cevapi2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*cevapi1-3*cevapi1/10);
		} else if(3*cevapi3<3*cevapi1 && 3*cevapi3<3*cevapi2 && 3*cevapi3<3*cevapi1-3*cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",3*cevapi3);
		else if(3*cevapi3<3*cevapi1 && 3*cevapi3<3*cevapi2 && 3*cevapi3<3*cevapi1-3*cevapi1/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",3*cevapi3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*cevapi1-3*cevapi1/10);

		}
	} else if((unos1=='P'&&unos2=='P'&&unos3=='H')||(unos1=='P'&&unos2=='H'&&unos3=='P')||(unos1=='H'&&unos2=='P'&&unos3=='P')) {
		if(2*pizza1+hamburger1<2*pizza2+hamburger2 && 2*pizza1+hamburger1<2*pizza3+hamburger3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*pizza1+hamburger1);
		else if(2*pizza1/10>hamburger1/10) {
			if(2*pizza2+hamburger2<2*pizza1+hamburger1 && 2*pizza2+hamburger2<2*pizza3+hamburger3 && 2*pizza2+hamburger2<2*pizza1+hamburger1-2*pizza1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*pizza2+hamburger2);
			else if(2*pizza2+hamburger2<2*pizza1+hamburger1 && 2*pizza2+hamburger2<2*pizza3+hamburger3 && 2*pizza2+hamburger2>2*pizza1+hamburger1-2*pizza1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*pizza2+hamburger2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+hamburger1-2*pizza1/10);
			} else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3<2*pizza1+hamburger1-2*pizza1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*pizza3+hamburger3);
			else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3>2*pizza1+hamburger1-2*pizza1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*pizza3+hamburger3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+hamburger1-2*pizza1/10);
			}
		} else if(2*pizza1/10<hamburger1/10) {
			if(2*pizza2+hamburger2<2*pizza1+hamburger1 && 2*pizza2+hamburger2<2*pizza3+hamburger3 && 2*pizza2+hamburger2<2*pizza1+hamburger1-hamburger1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*pizza2+hamburger2);
			else if(2*pizza2+hamburger2<2*pizza1+hamburger1 && 2*pizza2+hamburger2<2*pizza3+hamburger3 && 2*pizza2+hamburger2>2*pizza1+hamburger1-hamburger1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*pizza2+hamburger2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+hamburger1-hamburger1/10);
			} else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3<2*pizza1+hamburger1-hamburger1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*pizza3+hamburger3);
			else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3>2*pizza1+hamburger1-hamburger1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*pizza3+hamburger3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+hamburger1-hamburger1/10);
			} else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3<2*pizza1+hamburger1-cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*pizza3+hamburger3);
			else if(2*pizza3+hamburger3<2*pizza1+hamburger1 && 2*pizza3+hamburger3<2*pizza2+hamburger2 && 2*pizza3+hamburger3>2*pizza1+hamburger1-cevapi1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*pizza3+hamburger3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+hamburger1-cevapi1/10);
			}

		}
	} else if((unos1=='P'&&unos2=='P'&&unos3=='C')||(unos1=='P'&&unos2=='C'&&unos3=='P')||(unos1=='C'&&unos2=='P'&&unos3=='P')) {
		if(2*pizza1+cevapi1<2*pizza2+cevapi2 && 2*pizza1+cevapi1<2*pizza3+cevapi3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*pizza1+cevapi1);

		else if(2*pizza1/10>cevapi1/10) {
			if(2*pizza2+cevapi2<2*pizza1+cevapi1 && 2*pizza2+cevapi2<2*pizza3+cevapi3 && 2*pizza2+cevapi2<2*pizza1+cevapi1-2*pizza1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*pizza2+cevapi2);
			else if(2*pizza2+cevapi2<2*pizza1+cevapi1 && 2*pizza2+cevapi2<2*pizza3+cevapi3 && 2*pizza2+cevapi2>2*pizza1+cevapi1-2*pizza1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*pizza2+cevapi2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+cevapi1-2*pizza1/10);
			} else if(2*pizza3+cevapi3<2*pizza1+cevapi1 && 2*pizza3+cevapi3<2*pizza2+cevapi2 && 2*pizza3+cevapi3<2*pizza1+cevapi1-2*pizza1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*pizza3+cevapi3);
			else if(2*pizza3+cevapi3<2*pizza1+cevapi1 && 2*pizza3+cevapi3<2*pizza2+cevapi2 && 2*pizza3+cevapi3>2*pizza1+cevapi1-2*pizza1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*pizza3+cevapi3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+cevapi1-2*pizza1/10);
			}
		} else if(2*pizza1/10<cevapi1/10) {
			if(2*pizza2+cevapi2<2*pizza1+cevapi1 && 2*pizza2+cevapi2<2*pizza3+cevapi3 && 2*pizza2+cevapi2<2*pizza1+cevapi1-cevapi1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*pizza2+cevapi2);
			else if(2*pizza2+cevapi2<2*pizza1+cevapi1 && 2*pizza2+cevapi2<2*pizza3+cevapi3 && 2*pizza2+cevapi2<2*pizza1+cevapi1-cevapi1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*pizza2+cevapi2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+cevapi1-cevapi1/10);

			} else if(2*pizza3+cevapi3<2*pizza1+cevapi1 && 2*pizza3+cevapi3<2*pizza2+cevapi2 && 2*pizza3+cevapi3<2*pizza1+cevapi1-cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*pizza3+cevapi3);
			else if(2*pizza3+cevapi3<2*pizza1+cevapi1 && 2*pizza3+cevapi3<2*pizza2+cevapi2 && 2*pizza3+cevapi3>2*pizza1+cevapi1-cevapi1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*pizza3+cevapi3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*pizza1+cevapi1-cevapi1/10);
			}
		}
	} else if((unos1=='H'&&unos2=='H'&&unos3=='P')||(unos1=='H'&&unos2=='P'&&unos3=='H')||(unos1=='P'&&unos2=='H'&&unos3=='H')) {
		if(2*hamburger1+pizza1<2*hamburger2+pizza2 && 2*hamburger1+pizza1<2*hamburger3+pizza3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*hamburger1+pizza1);
		else if(2*hamburger1/10>pizza1/10) {
			if(2*hamburger2+pizza2<2*hamburger1+pizza1 && 2*hamburger2+pizza2<2*hamburger3+pizza3 && 2*hamburger2+pizza2<2*hamburger1+pizza1-2*hamburger1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*hamburger2+pizza2);
			else if(2*hamburger2+pizza2<2*hamburger1+pizza1 && 2*hamburger2+pizza2<2*hamburger3+pizza3 && 2*hamburger2+pizza2>2*hamburger1+pizza1-2*hamburger1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*hamburger2+pizza2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+pizza1-2*hamburger1/10);
			} else if(2*hamburger3+pizza3<2*hamburger1+pizza1 && 2*hamburger3+pizza3<2*hamburger2+pizza2 && 2*hamburger3+pizza3<2*hamburger1+pizza1-2*hamburger1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*hamburger3+pizza3);
			else if(2*hamburger3+pizza3<2*hamburger1+pizza1 && 2*hamburger3+pizza3<2*hamburger2+pizza2 && 2*hamburger3+pizza3>2*hamburger1+pizza1-2*hamburger1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*hamburger3+pizza3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+pizza1-2*hamburger1/10);
			}
		} else if(2*hamburger1/10<pizza1/10) {
			if(2*hamburger2+pizza2<2*hamburger1+pizza1 && 2*hamburger2+pizza2<2*hamburger3+pizza3 && 2*hamburger2+pizza2<2*hamburger1+pizza1-pizza1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*hamburger2+pizza2);
			else if(2*hamburger2+pizza2<2*hamburger1+pizza1 && 2*hamburger2+pizza2<2*hamburger3+pizza3 && 2*hamburger2+pizza2>2*hamburger1+pizza1-pizza1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*hamburger2+pizza2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+pizza1-pizza1/10);
			} else if(2*hamburger3+pizza3<2*hamburger1+pizza1 && 2*hamburger3+pizza3<2*hamburger2+pizza2 && 2*hamburger3+pizza3<2*hamburger1+pizza1-pizza1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*hamburger3+pizza3);
			else if(2*hamburger3+pizza3<2*hamburger1+pizza1 && 2*hamburger3+pizza3<2*hamburger2+pizza2 && 2*hamburger3+pizza3>2*hamburger1+pizza1-pizza1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*hamburger3+pizza3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+pizza1-pizza1/10);
			}
		}
	} else if((unos1=='H'&&unos2=='H'&&unos3=='C')||(unos1=='H'&&unos2=='C'&&unos3=='H')||(unos1=='C'&&unos2=='H'&&unos3=='H')) {
		if(2*hamburger1+cevapi1<2*hamburger2+cevapi2 && 2*hamburger1+cevapi1<2*hamburger3+cevapi3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*hamburger1+cevapi1);
		else if(2*hamburger1/10>cevapi1/10) {
			if(2*hamburger2+cevapi2<2*hamburger1+cevapi1 && 2*hamburger2+cevapi2<2*hamburger3+cevapi3 && 2*hamburger2+cevapi2<2*hamburger1+cevapi1-2*hamburger1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*hamburger2+cevapi2);
			else if(2*hamburger2+cevapi2<2*hamburger1+cevapi1 && 2*hamburger2+cevapi2<2*hamburger3+cevapi3 && 2*hamburger2+cevapi2>2*hamburger1+cevapi1-2*hamburger1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*hamburger2+cevapi2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+cevapi1-2*hamburger1/10);
			} else if(2*hamburger3+cevapi3<2*hamburger1+cevapi1 && 2*hamburger3+cevapi3<2*hamburger2+cevapi2 && 2*hamburger3+cevapi3<2*hamburger1+cevapi1-2*hamburger1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*hamburger3+cevapi3);
			else if(2*hamburger3+cevapi3<2*hamburger1+cevapi1 && 2*hamburger3+cevapi3<2*hamburger2+cevapi2 && 2*hamburger3+cevapi3<2*hamburger1+cevapi1-2*hamburger1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*hamburger3+cevapi3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+cevapi1-2*hamburger1/10);
			}
		} else if(2*hamburger1/10<cevapi1/10) {
			if(2*hamburger2+cevapi2<2*hamburger1+cevapi1 && 2*hamburger2+cevapi2<2*hamburger3+cevapi3 && 2*hamburger2+cevapi2<2*hamburger1+cevapi1-cevapi1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*hamburger2+cevapi2);
			else if(2*hamburger2+cevapi2<2*hamburger1+cevapi1 && 2*hamburger2+cevapi2<2*hamburger3+cevapi3 && 2*hamburger2+cevapi2>2*hamburger1+cevapi1-2*cevapi1/10) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*hamburger2+cevapi2);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+cevapi1-cevapi1/10);
			} else if(2*hamburger3+cevapi3<2*hamburger1+cevapi1 && 2*hamburger3+cevapi3<2*hamburger2+cevapi2 && 2*hamburger3+cevapi3<2*hamburger1+cevapi1-cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*hamburger3+cevapi3);
			else if(2*hamburger3+cevapi3<2*hamburger1+cevapi1 && 2*hamburger3+cevapi3<2*hamburger2+cevapi2 && 2*hamburger3+cevapi3<2*hamburger1+cevapi1-cevapi1/10) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*hamburger3+cevapi3);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*hamburger1+cevapi1-cevapi1/10);
			}
		}
	} else if((unos1=='C'&&unos2=='C'&&unos3=='P')||(unos1=='C'&&unos2=='P'&&unos3=='C')||(unos1=='P'&&unos2=='C'&&unos3=='C')) {
		if(2*cevapi1+pizza1<2*cevapi2+pizza2 && 2*cevapi1+pizza1<2*cevapi3+pizza3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*cevapi1+pizza1);
		else if(2*cevapi1/10>pizza1/10) {
			if(2*cevapi2+pizza2<2*cevapi1+pizza1 && 2*cevapi2+pizza2<2*cevapi3+pizza3 && 2*cevapi2+pizza2<2*cevapi1+pizza1-2*cevapi1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*cevapi2+pizza2);
		   else if(2*cevapi2+pizza2<2*cevapi1+pizza1 && 2*cevapi2+pizza2<2*cevapi3+pizza3 && 2*cevapi2+pizza2>2*cevapi1+pizza1-2*cevapi1/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*cevapi2+pizza2);
			
		} else if(2*cevapi3+pizza3<2*cevapi1+pizza1 && 2*cevapi3+pizza3<2*cevapi2+pizza2 && 2*cevapi3+pizza3<2*cevapi1+pizza1-2*cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*cevapi3+pizza3);
		else if(2*cevapi3+pizza3<2*cevapi1+pizza1 && 2*cevapi3+pizza3<2*cevapi2+pizza2 && 2*cevapi3+pizza3>2*cevapi1+pizza1-2*cevapi1/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*cevapi3+pizza3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+pizza1-2*cevapi1/10);

		}
	}
	

	else if(2*cevapi1/10<pizza1/10) {
		if(2*cevapi2+pizza2<2*cevapi1+pizza1 && 2*cevapi2+pizza2<2*cevapi3+pizza3 && 2*cevapi2+pizza2<2*cevapi1+pizza1-pizza1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*cevapi2+pizza2);
		else if(2*cevapi2+pizza2<2*cevapi1+pizza1 && 2*cevapi2+pizza2<2*cevapi3+pizza3 && 2*cevapi2+pizza2>2*cevapi1+pizza1-pizza1/10) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*cevapi2+pizza2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+pizza1-pizza1/10);
		} else if(2*cevapi3+pizza3<2*cevapi1+pizza1 && 2*cevapi3+pizza3<2*cevapi2+pizza2 && 2*cevapi3+pizza3<2*cevapi1+pizza1-pizza1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*cevapi3+pizza3);
		else if(2*cevapi3+pizza3<2*cevapi1+pizza1 && 2*cevapi3+pizza3<2*cevapi2+pizza2 && 2*cevapi3+pizza3>2*cevapi1+pizza1-pizza1/10) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*cevapi3+pizza3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+pizza1-pizza1/10);
		}
	}
}
else if((unos1=='C'&&unos2=='C'&&unos3=='H')||(unos1=='C'&&unos2=='H'&&unos3=='C')||(unos1=='H'&&unos2=='C'&&unos3=='C')){
	if(2*cevapi1+hamburger1<2*cevapi2+hamburger2 && 2*cevapi1+hamburger1<2*cevapi3+hamburger3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM)",2*cevapi1+hamburger1);
	else if(2*cevapi1/10>hamburger1/10){
		if(2*cevapi2+hamburger2<2*cevapi1+hamburger1 && 2*cevapi2+hamburger2<2*cevapi3+hamburger3 && 2*cevapi2+hamburger2<2*cevapi1+hamburger1-2*cevapi1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*cevapi2+hamburger2);
		else if(2*cevapi2+hamburger2<2*cevapi1+hamburger1 && 2*cevapi2+hamburger2<2*cevapi3+hamburger3 && 2*cevapi2+hamburger2>2*cevapi1+hamburger1-2*cevapi1/10){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*cevapi2+hamburger2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+hamburger1-2*cevapi1/10);
		}
		else if(2*cevapi3+hamburger3<2*cevapi1+hamburger1 && 2*cevapi3+hamburger3<2*cevapi2+hamburger2 && 2*cevapi3+hamburger3<2*cevapi1+hamburger1-2*cevapi1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*cevapi3+hamburger3);
		else if(2*cevapi3+hamburger3<2*cevapi1+hamburger1 && 2*cevapi3+hamburger3<2*cevapi2+hamburger2 && 2*cevapi3+hamburger3>2*cevapi1+hamburger1-2*cevapi1/10){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*cevapi3+hamburger3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+hamburger1-2*cevapi1/10);
		}
	}
	else if(2*cevapi1/10<hamburger1/10){
		if(2*cevapi2+hamburger2<2*cevapi1+hamburger1 && 2*cevapi2+hamburger2<2*cevapi3+hamburger3 && 2*cevapi2+hamburger2<2*cevapi1+hamburger1-hamburger1/10) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*cevapi2+hamburger2);
		else if(2*cevapi2+hamburger2<2*cevapi1+hamburger1 && 2*cevapi2+hamburger2<2*cevapi3+hamburger3 && 2*cevapi2+hamburger2>2*cevapi1+hamburger1-hamburger1/10){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",2*cevapi2+hamburger2);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+hamburger1-hamburger1/10);
		}
		else if(2*cevapi3+hamburger3<2*cevapi1+hamburger1 && 2*cevapi3+hamburger3<2*cevapi2+hamburger2 && 2*cevapi3+hamburger3<2*cevapi1+hamburger1-hamburger1/10) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*cevapi3+hamburger3);
		else if(2*cevapi3+hamburger3<2*cevapi1+hamburger1 && 2*cevapi3+hamburger3<2*cevapi2+hamburger2 && 2*cevapi3+hamburger3>2*cevapi1+hamburger1-hamburger1/10){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",2*cevapi3+hamburger3);
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*cevapi1+hamburger1-hamburger1/10);
		}
	}
}



return 0;
}
