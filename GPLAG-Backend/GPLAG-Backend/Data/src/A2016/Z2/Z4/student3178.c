/*#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main() {

	int M, N, i, j;
	int mat[VISINA][SIRINA];
	int pomocna=0, teplicova_i=0, teplicova_j=0, teplicova=0, cirkularna=0;
	int niz1[100],niz2[100];
	int f,k;

	do{

	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100)
	printf("Pogresan unos!\n");
	}
   while(M<=0 || M>100 || N<=0 || N>100);

	printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		scanf("%d", &mat[i][j]);
    	}
    	}


    	cirkularna=1;

    	for(i=0; i<(M-1); i++){
    	    if (cirkularna==0) break;
        	for(j=0; j<N; j++){
        	niz1[j] = mat[i][j];
        	}
    	    for(k=i+1; k<(i+2); k++){
        	for(j=0; j<N; j++){
        	niz2[j] = mat[k][j];
        	}
         	}


         		if(niz1[N-1] != niz2[0]){
    			cirkularna=0;
    			break;
    			}

         	for(f=0; f<(N-1); f++){
         	    if(niz1[f] != niz2[f+1]){
    			cirkularna=0;
    			break;
    			}
         	}
    	};

    	if(cirkularna==1){
    	printf("Matrica je cirkularna");
    	return 0;}


    	teplicova_i=1;
    for(i=0; i<M; i++){
        if(teplicova_i==0) break;
    	j=0;
        pomocna=mat[i][j];
    	while( ++i<M && ++j<N){
    	if(mat[i][j] != pomocna){
    	teplicova_i=0;
    	break;}
    	}
    }

    	teplicova_j=1;
    for(j=0; j<N; j++){
        if(teplicova_j==0) break;
    	i=0;
        pomocna=mat[i][j];
    	while( ++i<M && ++j<N){
    	if(mat[i][j] != pomocna){
    	teplicova_j=0;
    	break;}
    	}
    }


    	if(teplicova_i==1 && teplicova_j==1){
    		teplicova=1;
    	}

    if(teplicova==1)
    printf("Matrica je Teplicova");




  if(teplicova !=1  && cirkularna != 1)
  printf("Matrica nije ni cirkularna ni Teplicova");



	return 0;
}
*/
#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main()
{


    int M, N, i, j,l,m;
    float mat[VISINA][SIRINA];
   float pomocna=0;
   int teplicova_i=0, teplicova_j=0, teplicova=0, cirkularna=0;
    int niz1[100],niz2[100];
    int f,k;

    do {

        printf("Unesite M i N: ");
        scanf("%d %d", &M, &N);
        if(M<=0 || M>100 || N<=0 || N>100)
            printf("Pogresan unos!\n");
    } while(M<=0 || M>100 || N<=0 || N>100);

    printf("Unesite elemente matrice: ");


    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%f", &mat[i][j]);
        }
    }


    cirkularna=1;
    /*    najpre pamtim sukcesivno dva susjedna reda matrice u dva niza niz1 i niz2 */
    for(i=0; i<M-1; i++) {
        if (cirkularna==0) break;
        for(j=0; j<N; j++) {
            niz1[j] = mat[i][j];
        }
        for(k=i+1; k<(i+2); k++) {
            for(j=0; j<N; j++) {
                niz2[j] = mat[k][j];
            }
        }

        /*zatim proveravam da li su jednaki zadnji clan od niz1 i prvi clan od niz2, ako nisu postavljam cirkularna=0 i prekidam petlju*/
        if(niz1[N-1] != niz2[0]) {
            cirkularna=0;
            break;
        }
        /*zatim poredim element f od niz1 sa element f+1 niz2 da li su jednaki, ako nisu postavljam cirkularna=0 i prekidam petlju*/
        for(f=0; f<(N-1); f++) {
            if(niz1[f] != niz2[f+1]) {
                cirkularna=0;
                break;
            }
        }
    };

    if(cirkularna==1) {
        printf("Matrica je cirkularna");
        return 0;
    }


    teplicova_i=1;
    for(i=0; i<M; i++) {
        if(teplicova_i==0) break;
        j=0;
        l=i;
        pomocna=mat[i][j];
        while( ++l<M && ++j<N) {
            if(mat[l][j] != pomocna) {
                teplicova_i=0;
                break;
            }
        }

    }

    teplicova_j=1;
    for(j=0; j<N; j++) {
        if(teplicova_j==0) break;
        i=0;
        m=j;
        pomocna=mat[i][j];
        while( ++i<M && ++m<N) {
            if(mat[i][m] != pomocna) {
                teplicova_j=0;
                break;
            }
        }
    }


    if(teplicova_i==1 && teplicova_j==1) {
        teplicova=1;
    }

    if(teplicova==1)
        printf("Matrica je Teplicova");




    if(teplicova !=1  && cirkularna != 1)
        printf("Matrica nije ni cirkularna ni Teplicova");



    return 0;
}
