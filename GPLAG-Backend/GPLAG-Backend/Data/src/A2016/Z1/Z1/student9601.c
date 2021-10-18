#include <stdio.h>
#include <stdlib.h>
#define EPS 0.00001

int main() {
	float BP1,BP2,BP,BZ,BU,TP1,TP2,TP,TZ,TU,MP1,MP2,MP,MZ,MU,Bukupno,Tukupno,Mukupno;
	int x,y,z;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&TP1);
	if(TP1<0||TP1>20)
		printf("Neispravan broj bodova\n");
		else{
			printf("II parcijalni ispit: ");
			scanf("%f",&TP2);
			if(TP2<0||TP2>20)
				printf("Neispravan broj bodova\n");
				else{
				printf("Prisustvo: ");
				scanf("%f",&TP);
				if(TP<0||TP>10)
					printf("Neispravan broj bodova\n");
					else{
					printf("Zadace: ");
					scanf("%f",&TZ);
					if(TZ<0||TZ>10)
						printf("Neispravan broj bodova\n");
						else{
						printf("Zavrsni ispit: ");
						scanf("%f",&TU);
						if(TU<0||TU>40)
							printf("Neispravan broj bodova\n");
							else{
							printf("Unesite bodove za Bojana: \n");
							printf("I parcijalni ispit: ");
							scanf("%f",&BP1);
							if(BP1<0||BP1>20)
								printf("Neispravan broj bodova\n");
								else{
								printf("II parcijalni ispit: ");
								scanf("%f",&BP2);
								if(BP2<0||BP2>20)
									printf("Neispravan broj bodova\n");
									else{
									printf("Prisustvo: ");
									scanf("%f",&BP);
									if(BP<0||BP>10)
										printf("Neispravan broj bodova\n");
										else{
										printf("Zadace: ");
										scanf("%f",&BZ);
										if(BZ<0||BZ>10)
											printf("Neispravan broj bodova\n");
											else{
											printf("Zavrsni ispit: ");
											scanf("%f",&BU);
											if(BU<0||BU>40)
												printf("Neispravan broj bodova\n");
												else{
												printf("Unesite bodove za Mirzu: \n");
												printf("I parcijalni ispit: ");
												scanf("%f",&MP1);
												if(MP1<0||MP1>20)
													printf("Neispravan broj bodova\n");
													else{
													printf("II parcijalni ispit: ");
													scanf("%f",&MP2);
													if(MP2<0||MP2>20)
														printf("Neispravan broj bodova\n");
														else{
														printf("Prisustvo: ");
														scanf("%f",&MP);
														if(MP<0||MP>10)
															printf("Neispravan broj bodova\n");
															else{
															printf("Zadace: ");
															scanf("%f",&MZ);
															if(MZ<0||MZ>10)
																printf("Neispravan broj bodova\n");
																else{
																printf("Zavrsni ispit: ");
																scanf("%f",&MU);
																if(MU<0||MU>40)
																	printf("Neispravan broj bodova\n");
																	
	else{
		Bukupno=(BP1*100+BP2*100+BP*100+BZ*100+BU*100)/100;
		Mukupno=(MP1*100+MP2*100+MP*100+MZ*100+MU*100)/100;
		Tukupno=(TP1*100+TP2*100+TP*100+TZ*100+TU*100)/100;
		if(Bukupno>=55&&Bukupno<65)
			x=6;
			else if(Bukupno>=65&&Bukupno<75)
				x=7;
					else if(Bukupno>=75&&Bukupno<85)
						x=8;
							else if(Bukupno>=85&&Bukupno<92)
								x=9;
									else if(Bukupno>=92&&Bukupno<=100)
										x=10;
											else
												x=5;
		if(Mukupno>=55&&Mukupno<65)
			y=6;
			else if(Mukupno>=65&&Mukupno<75)
				y=7;
					else if(Mukupno>=75&&Mukupno<85)
						y=8;
							else if(Mukupno>=85&&Mukupno<92)
								y=9;
									else if(Mukupno>=92&&Mukupno<=100)
										y=10;
											else
												y=5;
		if(Tukupno>=55&&Tukupno<65)
			z=6;
			else if(Tukupno>=65&&Tukupno<75)
				z=7;
					else if(Tukupno>=75&&Tukupno<85)
						z=8;
							else if(Tukupno>=85&&Tukupno<92)
								z=9;
									else if(Tukupno>=92&&Tukupno<=100)
										z=10;
											else
												z=5;
		if(x==5&&y==5&&z==5)
			printf("Nijedan student nije polozio.\n");
				else if((x==5&&y==5&&z!=5)||(x!=5&&y==5&&z==5)||(x==5&&y!=5&&z==5))
					printf("Jedan student je polozio.\n");
						else if((x==5&&y!=5&&z!=5)||(x!=5&&y==5&&z!=5)||(x!=5&&y!=5&&z==5))
							printf("Dva studenta su polozila.\n");
								else if(x!=5&&y!=5&&z!=5){
									printf("Sva tri studenta su polozila.\n");
		if(x==y&&y==z)
			printf("Sva tri studenta imaju istu ocjenu.\n");
				else if((x!=y&&y==z)||(x!=z&&y==z)||(y!=z&&x==z))
					printf("Dva od tri studenta imaju istu ocjenu.\n");
						else if(x!=y&&y!=z)
							printf("Svaki student ima razlicitu ocjenu.\n");
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
