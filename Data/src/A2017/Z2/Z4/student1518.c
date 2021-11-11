#include <stdio.h>
#define MAX 100
#define MAXNIZ 10000

int main() {
	
	int i, j, M, N, matricaA[MAX][MAX], matricaB[MAX][MAX], matricaC[MAX][MAX], nizA[MAXNIZ], nizB[MAXNIZ], min, nizC[MAXNIZ], brojacniza=0, temp, isti=1;
	
	do {
	    printf("Unesite brojeve M i N: ");
	    scanf("%d", &M);
	    scanf("%d", &N);
	} while (M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        scanf("%d", &matricaA[i][j]);
	    }
	}
	
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        scanf("%d", &matricaB[i][j]);
	    }
	}
	
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        scanf("%d", &matricaC[i][j]);
	    }
	}
	
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        nizA[brojacniza]=matricaA[i][j];
	        brojacniza++;
	    }
	}
	brojacniza=0;
	
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        nizB[brojacniza]=matricaB[i][j];
	        brojacniza++;
	    }
	}
	brojacniza=0;
	
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        nizC[brojacniza]=matricaC[i][j];
	        brojacniza++;
	    }
	}
	
	for (i=0; i<brojacniza; i++) {
	    min=i;
	    for (j=i+1; j<brojacniza; j++) {
	        if (nizA[j]<nizA[min]) {
	            min=j;
	        }
	    }
	    temp=nizA[i];
	    nizA[i]=nizA[min];
	    nizA[min]=temp;
	}
	
	for (i=0; i<brojacniza; i++) {
	    min=i;
	    for (j=i+1; j<brojacniza; j++) {
	        if (nizB[j]<nizB[min]) {
	            min=j;
	        }
	    }
	    temp=nizB[i];
	    nizB[i]=nizB[min];
	    nizB[min]=temp;
	}
	
	for (i=0; i<brojacniza; i++) {
	    min=i;
	    for (j=i+1; j<brojacniza; j++) {
	        if (nizC[j]<nizC[min]) {
	            min=j;
	        }
	    }
	    temp=nizC[i];
	    nizC[i]=nizC[min];
	    nizC[min]=temp;
	}
	
	for (i=0; i<brojacniza; i++) {
	    if (nizA[i]!=nizB[i] || nizA[i]!=nizC[i]) {
	        isti=0;
	        i=brojacniza;
	    }
	}
	
	if (isti) {
	    printf("DA");
	}
	else {
	    printf("NE");
	}
	
	return 0;
}
