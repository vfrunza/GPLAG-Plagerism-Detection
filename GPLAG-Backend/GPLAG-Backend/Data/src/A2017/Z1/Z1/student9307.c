#include <stdio.h>
#define PK 6.80
#define HK 3.30
#define CK 5.00
#define PT 8.00
#define HT 3.00
#define CT 3.90
#define PL 5.30
#define HL 5.00
#define CL 6.00
#define POP 0.1

int main()
{
	char a,b,c;
	printf ("Unesite jelo za Tarika: ");
	scanf (" %c", &a);
	printf ("Unesite jelo za Bojana: ");
	scanf (" %c", &b);
	printf ("Unesite jelo za Mirzu: ");
	scanf (" %c", &c);

	if (a == 'P' && b == 'P' && c == 'P') {
		if ((PK + PK + PK)<(PT + PT + PT) && (PK + PK + PK)<(PL + PL + PL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", PK + PK + PK);
			return 1;
		}

		else if ((PT + PT + PT)<(PK + PK + PK) && (PT + PT + PT)<(PL + PL + PL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", PT + PT +PT);

		else if ((PL + PL + PL)<(PK + PK + PK) && (PL + PL + PL)<(PT + PT + PT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", PL + PL + PL);

		if (((PK + PK + PK)*(1-POP))<(PL + PL + PL) && ((PK + PK + PK)*(1-POP))<(PT + PT + PT))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (PK + PK + PK)*(1-POP));
	}


	if (a == 'H' && b == 'H' && c == 'H') {
		if ((HK + HK + HK)<(HT + HT + HT) && (HK + HK + HK)<(HL + HL + HL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", HK + HK + HK);
			return 1;
		}

		else if ((HT + HT + HT)<(HK + HK + HK) && (HT + HT + HT)<(HL + HL + HL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", HT + HT +HT);

		else if ((HL + HL + HL)<(HK + HK + HK) && (HL + HL + HL)<(HT + HT + HT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", HL + HL + HL);

		if (((HK + HK + HK)*(1-POP))<(HL + HL + HL) && ((HK + HK + HK)*(1-POP))<(HT + HT + HT))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (HK + HK + HK)*(1-POP));
	}


	if (a == 'C' && b == 'C' && c == 'C') {
		if ((CK + CK + CK)<(CT + CT + CT) && (CK + CK + CK)<(CL + CL + CL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CK + CK + CK);
			return 1;
		}

		else if ((CT + CT + CT)<(CK + CK + CK) && (CT + CT + CT)<(CL + CL + CL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CT + CT +CT);

		else if ((CL + CL + CL)<(CK + CK + CK) && (CL + CL + CL)<(CT + CT + CT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", CL + CL + CL);

		if (((CK + CK + CK)*(1-POP))<(CL + CL + CL) && ((CK + CK + CK)*(1-POP))<(CT + CT + CT))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (CK + CK + CK)*(1-POP));
	}



	else if ((a == 'P' && b == 'P' && c == 'H') || (a == 'P' && b == 'H' && c == 'P') || (a == 'H' && b == 'P' && c == 'P')) {
		if ((PK + PK + HK)<(PT + PT + HT) && (PK + PK + HK)<(PL + PL + HL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", PK + PK + HK);
			return 1;
		}

		else if ((PT + PT + HT)<(PK + PK + HK) && (PT + PT + HT)<(PL +PL + HL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", PT + PT +HT);

		else if ((PL + PL + HL)<(PK + PK + HK) && (PL + PL + HL)<(PT + PT + HT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", PL + PL + HL);

		if ((PK + PK) > HK) {
			if (((PK + PK)*(1-POP)+HK)<(PL + PL + HL) && ((PK + PK)*(1-POP)+HK)<(PT + PT + HT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (PK + PK)*(1-POP)+HK);
		} else if ((PK + PK)<HK) {
			if ((HK*(1-POP)+PK+PK)<(PL + PL + HL) && (HK*(1-POP)+PK+PK)<(PT + PT + HT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (HK*(1-POP)+PK+PK));
		}
	}



	else if ((a == 'P' && b == 'P' && c == 'C') || (a == 'P' && b == 'C' && c=='P') || (a == 'C' && b == 'P' && c == 'P')) {
		if ((PK + PK + CK)<(PT + PT + CT) && (PK + PK + CK)<(PL + PL + CL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", PK + PK + CK);
			return 1;
		}

		else if ((PT + PT + CT)<(PK + PK + CK) && (PT + PT + CT)<(PL +PL + CL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", PT + PT +CT);

		else if ((PL + PL + CL)<(PK + PK + CK) && (PL + PL + CL)<(PT + PT + CT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", PL + PL + CL);

		if ((PK + PK) > CK) {
			if (((PK + PK)*(1-POP)+CK)<(PL + PL + CL) && ((PK + PK)*(1-POP)+CK)<(PT + PT + CT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (PK + PK)*(1-POP)+CK);
		} else if ((PK + PK)<CK) {
			if ((CK*(1-POP)+PK+PK)<(PL + PL + CL) && (CK*(1-POP)+PK+PK)<(PT + PT + CT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (CK*(1-POP)+PK+PK));
		}
	}



	else if ((a == 'P' && b == 'H' && c == 'H') || (a == 'H' && b == 'H' && c == 'P') || (a == 'H' && b == 'P' && c == 'H')) {
		if ((HK + HK + PK)<(HT + HT + PT) && (HK + HK + PK)<(HL + HL + PL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", HK + HK + PK);
			return 1;
		}

		else if ((HT + HT + PT)<(HK + HK + PK) && (HT + HT + PT)<(HL +HL + PL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", HT + HT +PT);

		else if ((HL + HL + PL)<(HK + HK + PK) && (HL + HL + PL)<(HT + HT + PT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", HL + HL + PL);

		if ((HK + HK) > PK) {
			if (((HK + HK)*(1-POP)+PK)<(HL + HL + PL) && ((HK + HK)*(1-POP)+PK)<(HT + HT + PT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (HK + HK)*(1-POP)+PK);
		} else if ((HK + HK)<PK) {
			if ((PK*(1-POP)+HK+HK)<(HL + HL + PL) && (PK*(1-POP)+HK+HK)<(HT + HT + PT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (PK*(1-POP)+HK+HK));
		}
	}



	else if ((a == 'P' && b == 'C' && c == 'C') || (a == 'C' && b == 'C' && c == 'P') || (a == 'C' && b == 'P' && c == 'C')) {
		if ((CK + CK + PK)<(CT + CT + PT) && (CK + CK + PK)<(CL + CL + PL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CK + CK + PK);
			return 1;
		}

		else if ((CT + CT + PT)<(CK + CK + PK) && (CT + CT + PT)<(CL +CL + PL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CT + CT +PT);

		else if ((CL + CL + PL)<(CK + CK + PK) && (CL + CL + PL)<(CT + CT + PT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", CL + CL + PL);

		if ((CK + CK) > PK) {
			if (((CK + CK)*(1-POP)+PK)<(CL + CL + PL) && ((CK + CK)*(1-POP)+PK)<(CT + CT + PT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (CK + CK)*(1-POP)+PK);
		} else if ((CK + CK)<PK) {
			if ((PK*(1-POP)+CK+CK)<(CL + CL + PL) && (PK*(1-POP)+CK+CK)<(CT + CT + PT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (PK*(1-POP)+CK+CK));
		}
	}



	else if ((a == 'H' && b == 'H' && c == 'C') || (a == 'H' && b == 'C' && c == 'H') || (a == 'C' && b == 'H' && c == 'H') ) {
		if ((HK + HK + CK)<(HT + HT + CT) && (HK + HK + CK)<(HL + HL + CL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", HK + HK + CK);
			return 1;
		}

		else if ((HT + HT + CT)<(HK + HK + CK) && (HT + HT + CT)<(HL +HL + CL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", HT + HT +CT);

		else if ((HL + HL + CL)<(HK + HK + CK) && (HL + HL + CL)<(HT + HT + CT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", HL + HL + CL);

		if ((HK + HK) > CK) {
			if (((HK + HK)*(1-POP)+CK)<(HL + HL + CL) && ((HK + HK)*(1-POP)+CK)<(HT + HT + CT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (HK + HK)*(1-POP)+CK);
		} else if ((HK + HK)<CK) {
			if ((CK*(1-POP)+HK+HK)<(HL + HL + CL) && (CK*(1-POP)+HK+HK)<(HT + HT + CT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (CK*(1-POP)+HK+HK));
		}
	}


	else if ((a == 'H' && b == 'C' && c == 'C') || (a == 'C' && b == 'C' && c == 'H') || (a == 'C' && b == 'H' && c == 'C')) {
		if ((CK + CK + HK)<(CT + CT + HT) && (CK + CK + HK)<(CL + CL + HL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CK + CK + HK);
			return 1;
		}

		else if ((CT + CT + HT)<(CK + CK + HK) && (CT + CT + HT)<(CL +CL + HL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CT + CT +HT);

		else if ((CL + CL + HL)<(CK + CK + HK) && (CL + CL + HL)<(CT + CT + HT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", CL + CL + HL);

		if ((CK + CK) > HK) {
			if (((CK + CK)*(1-POP)+HK)<(CL + CL + HL) && ((CK + CK)*(1-POP)+HK)<(CT + CT + HT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (CK + CK)*(1-POP)+HK);
		} else if ((CK + CK)<HK) {
			if ((HK*(1-POP)+CK+CK)<(CL + CL + HL) && (HK*(1-POP)+CK+CK)<(CT + CT + HT))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", (HK*(1-POP)+CK+CK));
		}
	}


	else if ((a == 'P' && b == 'H' && c == 'C') || (a == 'P' && b == 'C' && c == 'H') || (a == 'H' && b == 'P' && c == 'C') || (a == 'H' && b == 'C' && c == 'P') || (a == 'C' && b == 'P' && c == 'H') || (a == 'C' && b == 'H' && c == 'P')) {
		if ((PK + CK + HK)<(PT + CT + HT) && (PK + CK + HK)<(PL + CL + HL)) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", PK + CK + HK);
			return 1;
		}

		else if ((PT + CT + HT)<(PK + CK + HK) && (PT + CT + HT)<(PL +CL + HL))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", PT + CT +HT);

		else if ((PL + CL + HL)<(PK + CK + HK) && (PL + CL + HL)<(PT + CT + HT))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", PL + CL + HL);

		if (PK > HK && PK > CK) {
			if ((PK*(1-POP)+HK + CK)<(PT + HT + CT) && (PK*(1-POP)+HK + CK)<(PL + HL + CL))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", PK*(1-POP) + HK + CK);
		} else if (HK > PK && HK > CK) {
			if ((HK*(1-POP)+PK + CK)<(PT + HT + CT) && (HK*(1-POP)+PK + CK)<(PL + HL + CL))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", HK*(1-POP) + PK + CK);
		} else if (CK > PK && CK > HK) {
			if ((CK*(1-POP)+PK + HK)<(PT + HT + CT) && (CK*(1-POP)+PK + HK)<(PL + HL + CL))
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CK*(1-POP) + PK + HK);
		}
	}
	return 0;
}