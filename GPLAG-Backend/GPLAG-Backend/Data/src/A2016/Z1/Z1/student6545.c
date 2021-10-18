#include <stdio.h>

int main() {
	double tpp, tdp, tp, tz, tzi, bpp, bdp, bp, bz, bzi, mpp, mdp, mp, mz, mzi, tu, bu, mu, to=0, bo=0, mo=0;
	//printf("Zadaća 1, Zadatak 1");
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &tpp);
	if (tpp<0 || tpp>20)
		printf("Neispravan broj bodova");
	else {
		printf("II parcijalni ispit: ");
		scanf("%lf", &tdp);
		if (tdp<0 || tdp>20)
			printf("Neispravan broj bodova");
		else {
			printf("Prisustvo: ");
			scanf("%lf", &tp);
			if (tp<0 || tp>10)
				printf("Neispravan broj bodova");
			else {
				printf("Zadace: ");
				scanf("%lf", &tz);
				if (tz<0 || tz>10)
					printf("Neispravan broj bodova");
				else {
					printf("Zavrsni ispit: ");
					scanf("%lf", &tzi);
					if (tzi<0 || tzi>40)
						printf("Neispravan broj bodova");
					else {
						printf("Unesite bodove za Bojana: ");
						printf("\nI parcijalni ispit: ");
						scanf("%lf", &bpp);
						if (bpp<0 || bpp>20)
							printf("Neispravan broj bodova");
						else {
							printf("II parcijalni ispit: ");
							scanf("%lf", &bdp);
							if (bdp<0 || bdp>20)
								printf("Neispravan broj bodova");
							else {
								printf("Prisustvo: ");
								scanf("%lf", &bp);
								if (bp<0 || bp>10)
									printf("Neispravan broj bodova");
								else {
									printf("Zadace: ");
									scanf("%lf", &bz);
									if (bz<0 || bz>10)
										printf("Neispravan broj bodova");
									else {
										printf("Zavrsni ispit: ");
										scanf("%lf", &bzi);
										if (bzi<0 || bzi>40)
											printf("Neispravan broj bodova");
										else {
											printf("Unesite bodove za Mirzu: ");
											printf("\nI parcijalni ispit: ");
											scanf("%lf", &mpp);
											if (mpp<0 || mpp>20)
												printf("Neispravan broj bodova");
											else {
												printf("II parcijalni ispit: ");
												scanf("%lf", &mdp);
												if (mdp<0 || mdp>20)
													printf("Neispravan broj bodova");
												else {
													printf("Prisustvo: ");
													scanf("%lf", &mp);
													if (mp<0 || mp>10)
														printf("Neispravan broj bodova");
													else {
														printf("Zadace: ");
														scanf("%lf", &mz);
														if (mz<0 || mz>10)
															printf("Neispravan broj bodova");
														else {
															printf("Zavrsni ispit: ");
															scanf("%lf", &mzi);
															if (mzi<0 || mzi>40)
																printf("Neispravan broj bodova");
															else {
																tu=tpp+tdp+tp+tz+tzi;
																bu=bpp+bdp+bp+bz+bzi;
																mu=mpp+mdp+mp+mz+mzi;
																if (tu<55) to=5;
																if (tu>=55 && tu<65) to=6;
																if (tu>=65 && tu<75) to=7;
																if (tu>=75 && tu<85) to=8;
																if (tu>=85 && tu<92) to=9;
																if (tu>=92 && tu<=100) to=10;
																if (bu<55) bo=5;
																if (bu>=55 && bu<65) bo=6;
																if (bu>=65 && bu<75) bo=7;
																if (bu>=75 && bu<85) bo=8;
																if (bu>=85 && bu<92) bo=9;
																if (bu>=92 && bu<=100) bo=10;
																if (mu<55) mo=5;
																if (mu>=55 && mu<65) mo=6;
																if (mu>=65 && mu<75) mo=7;
																if (mu>=75 && mu<85) mo=8;
																if (mu>=85 && mu<92) mo=9;
																if (mu>=92 && mu<=100) mo=10;
																if (to==5 && bo==5 && mo==5) printf ("Nijedan student nije polozio.");
																else
																if (to!=5 && bo!=5 && mo!=5) printf ("Sva tri studenta su polozila.");
																else 
																	if ((to!=5 && bo==5 && mo==5) || (to==5 && bo!=5 && mo==5) || (to==5 && bo==5 && mo!=6)) printf ("Jedan student je polozio.");
																	else
																		if ((to!=5 && bo!=5 && mo==5) || (to!=5 && bo==5 && mo!=5) || (to==5 && bo!=5 && mo!=6)) printf ("Dva studenta su polozila.");
																if (to!=5 && bo!=5 && mo!=5) {
																if (to==bo && bo==mo) printf ("\nSva tri studenta imaju istu ocjenu.");
																if (to!=bo && bo!=mo && to!=mo) printf ("\nSvaki student ima razlicitu ocjenu.");
																if ((to==bo && to!=mo) || (to==mo && to!=bo) || (mo==bo && mo!=to) ) printf ("\nDva od tri studenta imaju istu ocjenu.");
																}
															}
														}
													}
												}
											}	
										}
									}
								}
							}
						}
					}	
				}	
			}		
		}
	}	
	return 0;
}
