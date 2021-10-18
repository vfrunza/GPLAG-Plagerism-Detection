#include <stdio.h>

int main() {
	
	char tarik,bojan,mirza,novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if(tarik=='P' && bojan=='P' && mirza=='P') { //1
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	}
	
	else if(tarik=='P' && bojan=='P' && mirza=='H') { //2
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).");
	}
	
	else if(tarik=='P' && bojan=='P' && mirza=='C'){ //3
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	
	else if(tarik=='P' && bojan=='H' && mirza=='P') { //4
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	else if(tarik=='P' && bojan=='H' && mirza=='H') { //5
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	
	else if(tarik=='P' && bojan=='H' && mirza=='C') { //6
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
	}
	
	else if(tarik=='P' && bojan=='C' && mirza=='P') { //7
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	
	else if(tarik=='P' && bojan=='C' && mirza=='H') { //8
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
	}
	
	else if(tarik=='P' && bojan=='C' && mirza=='C') { //9
		printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	}
	
	else if(tarik=='H' && bojan=='P' && mirza=='P') { //10
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	
	else if(tarik=='H' && bojan=='P' && mirza=='H') { //11
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	
	else if(tarik=='H' && bojan=='P' && mirza=='C') { //12
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
	}
	
	else if(tarik=='H' && bojan=='H' && mirza=='P') { //13
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	
	else if(tarik=='H' && bojan=='H' && mirza=='H') { //14
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (8.91 KM).");
	}
	
	else if(tarik=='H' && bojan=='H' && mirza=='C') { //15
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	
	else if(tarik=='H' && bojan=='C' && mirza=='P') { //16
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
	}
	
	else if(tarik=='H' && bojan=='C' && mirza=='H') { //17
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	
	else if(tarik=='H' && bojan=='C' && mirza=='C') { //18
		printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	
	else if(tarik=='C' && bojan=='P' && mirza=='P') { //19
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	
	else if(tarik=='C' && bojan=='P' && mirza=='H') { //20
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
	}
	
	else if(tarik=='C' && bojan=='P' && mirza=='C') { //21
		printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	}
	
	else if(tarik=='C' && bojan=='H' && mirza=='P') { //22
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	
	else if(tarik=='C' && bojan=='H' && mirza=='H') { //23
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	
	else if(tarik=='C' && bojan=='H' && mirza=='C') { //24
		printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	
	else if(tarik=='C' && bojan=='C' && mirza=='P') { //25
		printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	}
	
	else if(tarik=='C' && bojan=='C' && mirza=='H') { //26
		printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	
	else {
		
		printf("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM)."); //27
	}
	
	
	return 0;
}