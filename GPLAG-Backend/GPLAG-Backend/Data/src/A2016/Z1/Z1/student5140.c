#include <stdio.h>

int main() {
	int a,b,c;
	double tpi1,tpi2,tp,tz,tzi,bpi1,bpi2,bp,bz,bzi,mpi1,mpi2,mp,mz,mzi,tub,bub,mub;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&tpi1);
	if(tpi1<0 || tpi1>20){
		printf("Neispravan broj bodova\n");
	    } else {
	   	printf("II parcijalni ispit: ");
	   	scanf("%lf",&tpi2);
	   	if(tpi2<0 || tpi2>20){
	   		printf("Neispravan broj bodova\n");
	        } else {
	        printf("Prisustvo: ");
	        scanf("%lf",&tp);
	        if(tp<0 || tp>10){
	        	printf("Neispravan broj bodova\n");
	            } else {
	        	printf("Zadace: ");
	        	scanf("%lf",&tz);
	        	if(tz<0 || tz>10){
	        		printf("Neispravan broj bodova\n");
	                } else {
	        		printf("Zavrsni ispit: ");
	        		scanf("%lf",&tzi);
	        		if(tzi<0 || tzi>40){
	        		   printf("Neispravan broj bodova\n");
	                   } else {
	                   printf("Unesite bodove za Bojana:\n");
	                   printf("I parcijalni ispit: ");
	                   scanf("%lf",&bpi1);
	                   if(bpi1<0 || bpi1>20){
	                   	  printf("Neispravan broj bodova\n");
	                      } else {
	   	                  printf("II parcijalni ispit: ");
	   	                  scanf("%lf",&bpi2);
	   	                  if(bpi2<0 || bpi2>20){
	   	                  	 printf("Neispravan broj bodova\n");
	                         } else {
	                         printf("Prisustvo: ");
	                         scanf("%lf",&bp);
	                         if(bp<0 || bp>10){
	                         	printf("Neispravan broj bodova\n");
	                            } else {
	        	                printf("Zadace: ");
	        	                scanf("%lf",&bz);
	        	                if(bz<0 || bz>10){
	        	                   printf("Neispravan broj bodova\n");
	                               } else {
	        	                   printf("Zavrsni ispit: ");
	        		               scanf("%lf",&bzi);
	        		               if(bzi<0 || bzi>40){
	        		               	  printf("Neispravan broj bodova\n");
	                                  } else {
	                                  printf("Unesite bodove za Mirzu:\n");
	                                  printf("I parcijalni ispit: ");
                              	      scanf("%lf",&mpi1);
	                                  if(mpi1<0 || mpi1>20) {
	                                  	 printf("Neispravan broj bodova\n");
	                                     } else {
	   	                                 printf("II parcijalni ispit: ");
	                   	                 scanf("%lf",&mpi2);
	   	                                 if(mpi2<0 || mpi2>20){
	   	                                 	printf("Neispravan broj bodova\n");
	                                        } else {
	                                        printf("Prisustvo: ");
	                                        scanf("%lf",&mp);
	                                        if(mp<0 || mp>10){
	                                           printf("Neispravan broj bodova\n");
	                                           } else {
	              	                           printf("Zadace: ");
	        	                               scanf("%lf",&mz);
	        	                               if(mz<0 || mz>10){
	        	                               	  printf("Neispravan broj bodova\n");
	                                              } else {
	        		                              printf("Zavrsni ispit: ");
	        		                              scanf("%lf",&mzi);
	        		                              if(mzi<0 || mzi>40){
	        		                              	printf("Neispravan broj bodova\n");
	                                                } else {
	                                                	tub=tpi1+tpi2+tp+tz+tzi;
	                                                    bub=bpi1+bpi2+bp+bz+bzi;
	                                                    mub=mpi1+mpi2+mp+mz+mzi;
	                                                    if(tub<55 && bub<55 && mub<55)
	                                                    printf("Nijedan student nije polozio.\n");
	                                                    else if((tub>=55 && bub<55 && mub<55) || (tub<55 && bub>=55 && mub<55) || (tub<55 && bub<55 && mub>=55))
	                                                    printf("Jedan student je polozio.\n");
	                                                    else if((tub>=55 && bub>=55 && mub<55) || (tub<55 && bub>=55 && mub>=55) || (tub>=55 && bub<55 && mub>=55))
	                                                    printf("Dva studenta su polozila.\n");
	                                                    else if(tub>=55 && bub>=55 && mub>=55)
	                                                    printf("Sva tri studenta su polozila.\n");
	                                                    if(tub>=55) {
	                                                    	if(tub<65) {a=6;}
	                                                    	else if(tub>=65 && tub<75)
	                                                    		a=7;
	                                                    	else if(tub>=75 && tub<85)
	                                                    		a=8;
	                                                    	else if(tub>=85 && tub<92)
	                                                    		a=9;
	                                                    	else if(tub>=92 && tub<=100)
	                                                    		a=10;
	                                                    } 
														if(bub>=55) {
															if(bub<65) 
																b=6;
															else if(bub>=65 && bub<75)
																b=7;
														    else if(bub>=75 && bub<85) 
														    	b=8;
														    else if(bub>=85 && bub<92) 
														    	b=9;
														    else if(bub>=92 && bub<=100) 
														    	b=10;
														} 
														if(mub>=55) {
															if(mub<65) 
																c=6;
															else if(mub>=65 && mub<75) 
																c=7;
														    else if(mub>=75 && mub<85)
														    	c=8;
														    else if(mub>=85 && mub<92)
														    	c=9;
														    else if(mub>=92 && mub<=100)
														    	c=10;
														} 
														if(tub>=55 && bub>=55 && mub>=55){
														if(a==b && b==c && a==c)
														printf("Sva tri studenta imaju istu ocjenu.\n");
														else if((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a))
														printf("Dva od tri studenta imaju istu ocjenu.\n");
														else if(a!=b && a!=c && b!=c)
														printf ("Svaki student ima razlicitu ocjenu.\n");}
	        		                            
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
