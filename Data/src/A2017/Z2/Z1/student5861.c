#include <stdio.h>

int main()
{
	int i, j, broj;

	do {
		printf("\nUnesite broj N:");
		scanf("%d",&broj);
		if((broj%4==0)&&(broj >=8))
			break;
		else printf(" Neispravno N!");
	} while((broj%4!=0)||(broj<8));
	printf("\n");
	for(i=0; i<broj; i++) {
		if(i<(broj/2)) {
			for(j=0; j<broj; j++) {
				if(i==0) {
					if(j==0) {
						printf("\\");
					}
					//Za  gornje coskove
					else if(j==((broj/2)-1)) {
						printf("/");
					} else if(((j>0) && (j<(broj/2))) || (j==((broj/2)-1))) {
						printf(" ");
					} else if((j==(broj/2)) || (j==(broj-1))) {
						printf("+");
					} else {
						printf("-");
					}
				}
	          //unutra
				else if((i>0) && (i<((broj/2)-1))) {
					if(i==j) {
						printf("\\");
					} else if(j==((broj/2)-1-i)) {
						printf("/");
					} else if((j==(broj/2)) || (j==(broj-1))) {
						printf("|");
					} else {
						printf(" ");
					}
				}
			//Za donje coskove
				else if(i==((broj/2)-1)) {
					if(j==0) {
						printf("/");
					} else if(j==((broj/2)-1)) {
						printf("\\");
					} else if(((j>0) && (j<(broj/2))) || (j<((broj/2)-1))) {
						printf(" ");
					} else if((j==(broj/2)) || (j==(broj-1))) {
						printf("+");
					} else {
						printf("-");
					}
				}
			}
			printf("\n");

		} else {
			for(j=0; j<broj; j++) {
				if((i==(broj/2)) || (i==(broj-1))) {
					if(j>=0 && j<(broj/2)) {
						if((j==0) || (j==(broj/2)-1)) {
							printf("+");
						} else printf("-");

					} else {
						if(j>=(broj/2)&&j<broj) {
							if((j==((broj*3)/4)) || (j==((broj*3)/4)-1)) {
								printf("|");
							} else {
								printf(" ");
							}
						}
					}
				}

				else {
					if(j>=0 && j<(broj/2)) {
						if((j==0)||(j==((broj/2)-1))) {
							printf("|");
						} else {
							printf(" ");
						}
					}

					else {
						if((i!=((broj*3)/4)) && (i!=((broj*3)/4)-1)) {
							if((j==((broj*3)/4)) || (j==((broj*3)/4)-1)) {
								printf("|");
							} else {
								printf(" ");
							}
						}

						else {
							if((j==((broj*3)/4)) || (j==((broj*3)/4)-1)) {
								printf("+");
							} else {
								printf("-");
							}
						}
					}
				}
			}
			printf("\n");
		}

	}


	return 0;
}
