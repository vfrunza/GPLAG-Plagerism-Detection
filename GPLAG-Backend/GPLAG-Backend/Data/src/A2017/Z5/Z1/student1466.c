#include <stdio.h>
#include <math.h>
#define eps 0.00000000000000000000000000000000000000000000001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

										/* Funkcija genijalci prima niz studenata, velicinu niza i realan broj prosjek */

int genijalci(struct Student studenti[], int vel, float prosjek)	{
		int i,j,k,suma,brojac,max1,max2,p=0,s=0;
		float prosjek_studenta,prosjek_studenta1;

	
										/* Izbacivanje studenata koji imaju manji prosjek od zadanog */

		for (i = 0 ; i < vel ; i++)	{
		
			suma = 0;
			brojac = 0;
		
		
		for ( j = 0 ; j < studenti[i].br_ocjena ; j++)	{
		
		
										/* Ako student ima samo jednu evidentiranu ocjenu prosjek mu je automatski 5.0 */
			if ( studenti[i].ocjene[j] == 5)	{
				suma = 5;
				brojac = 1;
				break;
			}
		
				suma+=studenti[i].ocjene[j];
				brojac++;
		}
										/* Ako student nema evidentirani ocjena prosjek mu je također 5.0 */
				if ( suma == 0)	{
			
				suma = 5;
				brojac = 1;
			}
		
		
		prosjek_studenta = (float)suma/brojac;
		
			if ( prosjek_studenta < prosjek)	{
			
				for ( k = i ; k < vel-1 ; k++)	{
				
					studenti[k] = studenti[k+1];
				}
			
		
			i--;
			vel--;
	
		}
	
			
	}
	
	
	
	
											/* Ispisivanje imena i prezimena studenta sa najvecim prosjekom */
				i = 0;
				suma = 0;
		
			for ( j = 0 ; j < studenti[i].br_ocjena ; j++)		suma+=studenti[i].ocjene[j];
		
				prosjek_studenta = (float)suma/studenti[i].br_ocjena;
		
			
					for ( k = i+1 ; k < vel ; k++ )	{
						suma = 0;
		
						for ( j = 0 ; j < studenti[k].br_ocjena ; j++)		suma+=studenti[k].ocjene[j];
			
							prosjek_studenta1 = (float)suma/studenti[k].br_ocjena;
		
		
		
											/* Ukoliko dva studenta imaju isti prosjek ispisuje se ime onog studenta čije je prezime ispred po leksikografskom redoslijedu */
			
					while (fabs(prosjek_studenta - prosjek_studenta1)<eps)	{
				
						p = 0;
						s = 0;
					
							while ( studenti[i].prezime[p] == studenti[k].prezime[s] && studenti[i].prezime[p] != '\0' && studenti[k].prezime[s] != '\0') {
								p++;
								s++;
							}
							
						
				
							if ( studenti[i].prezime[p] == '\0' && studenti[k].prezime[s] == '\0')	{
				
								p = 0;
								s = 0;
				
											/* Ako im je isto prezime onda im se gleda ime */ 
											
							while ( studenti[i].ime[p] == studenti[k].ime[s] && studenti[i].ime[p] != '\0' && studenti[k].ime[s] != '\0') {
								p++;
								s++;
							}
				
							if ( studenti[i].ime[p] > studenti[k].ime[s] )	{
							
								prosjek_studenta = prosjek_studenta1;
								i = k;
								break;
						}
						
					}	
				
						if ( studenti[i].prezime[p] > studenti[k].prezime[s] )	{
						
							prosjek_studenta = prosjek_studenta1;
							i = k;
							break;
						}
				
							break;
				}
				
						if ( prosjek_studenta < prosjek_studenta1)	{
				
							prosjek_studenta = prosjek_studenta1;
							i = k;
				
						}
				
			
			}
			
			
						max1 = i;
						if ( i < vel)
						printf("%s %s\n", studenti[i].prezime,studenti[i].ime);

			
												/* Ispis studenta sa drugim najvecim prosjekom */
			
			i = 0;
			suma = 0;
			
			if ( i == max1) i++;
			if ( i < vel)	{
				
					for ( j = 0 ; j < studenti[i].br_ocjena ; j++)	suma+=studenti[i].ocjene[j];
			
					prosjek_studenta = (float)suma/studenti[i].br_ocjena;
		
			
						for ( k = i+1 ; k < vel ; k++ )	{
							suma = 0;
							if ( k == max1) k++;
							if ( k >= vel)	break;
								for ( j = 0 ; j < studenti[k].br_ocjena ; j++)		suma+=studenti[k].ocjene[j];
			
							prosjek_studenta1 = (float)suma/studenti[k].br_ocjena;
		
											/* Ukoliko dva studenta imaju isti prosjek ispisuje se ime onog studenta čije je prezime ispred po leksikografskom redoslijedu */

		
							while (fabs(prosjek_studenta - prosjek_studenta1)<eps)	{
				
									p = 0;
									s = 0;
				
								while ( studenti[i].prezime[p] == studenti[k].prezime[s] && studenti[i].prezime[p] != '\0' && studenti[k].prezime[s] != '\0') {
									p++;
									s++;
								}
								
											/* Ako im je isto prezime onda im se gleda ime */ 
				
								if ( studenti[i].prezime[p] == '\0' || studenti[k].prezime[s] == '\0')	{
				
									p = 0;
									s = 0;
				
									while ( studenti[i].ime[p] == studenti[k].ime[s] && studenti[i].ime[p] != '\0' && studenti[k].ime[s] != '\0') {
										p++;
										s++;
									}
				
										if ( studenti[i].ime[p] > studenti[k].ime[s] )	{
											prosjek_studenta = prosjek_studenta1;
											i = k;
											break;
										}
					
								}
				
								if ( studenti[i].prezime[p] > studenti[k].prezime[s] )	{
									prosjek_studenta = prosjek_studenta1;
									i = k;
									break;
								}
				
									break;
							}
			
							if ( prosjek_studenta < prosjek_studenta1)	{
				
								prosjek_studenta = prosjek_studenta1;
								i = k;
							}
			
					}
			
			}
			
				
							max2 = i;
							if ( i < vel)
							printf("%s %s\n", studenti[i].prezime,studenti[i].ime);
						
						
			
			
			
			
													/* Ispis studenta sa trecim najvecim prosjekom */
			
			
						i = 0;
						suma = 0;
			
							while ( i == max1 || i == max2) i++;
							
								if ( i < vel)	{
			
									for ( j = 0 ; j < studenti[i].br_ocjena ; j++)	suma+=studenti[i].ocjene[j];
			
									prosjek_studenta = (float)suma/studenti[i].br_ocjena;
		
			
								for ( k = i+1 ; k < vel ; k++ )	{
									suma = 0;
									while ( k == max1 || k == max2) k++;
									if ( k >= vel) break;
								
										for ( j = 0 ; j < studenti[k].br_ocjena ; j++)		suma+=studenti[k].ocjene[j];
			
										prosjek_studenta1 = (float)suma/studenti[k].br_ocjena;
			
													/* Ukoliko dva studenta imaju isti prosjek ispisuje se ime onog studenta čije je prezime ispred po leksikografskom redoslijedu */

		
											while (fabs(prosjek_studenta - prosjek_studenta1)<eps)	{
				
													p = 0;
													s = 0;
				
											while ( studenti[i].prezime[p] == studenti[k].prezime[s] && studenti[i].prezime[p] != '\0' && studenti[k].prezime[s] != '\0') {
													p++;
													s++;
												}
				
															/* Ukoliko imaju isto prezime gleda se ime */
												if ( studenti[i].prezime[p] == '\0' || studenti[k].prezime[s] == '\0')	{
				
													p = 0;
													s = 0;
				
													while ( studenti[i].ime[p] == studenti[k].ime[s] && studenti[i].ime[p] != '\0' && studenti[k].ime[s] != '\0') {
														p++;
														s++;
													}
				
												if ( studenti[i].ime[p] > studenti[k].ime[s] )	{
													prosjek_studenta = prosjek_studenta1;
													i = k;
													break;
												}
					
											}
				
									if ( studenti[i].prezime[p] > studenti[k].prezime[s] )	{
										prosjek_studenta = prosjek_studenta1;
										i = k;
										break;
									}
				
										break;
									}
		
		
									if ( prosjek_studenta < prosjek_studenta1)	{
				
										prosjek_studenta = prosjek_studenta1;
										i = k;
									}
				
			
								}
		
							}
						
						
								if ( i < vel)
								printf("%s %s\n", studenti[i].prezime,studenti[i].ime);
			
			
			
			
			
			
			
			

	return vel;
}



int main() {
	

	return 0;
}
