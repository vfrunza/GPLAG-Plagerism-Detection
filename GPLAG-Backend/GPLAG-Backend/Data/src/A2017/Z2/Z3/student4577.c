#include <stdio.h>

#include <math.h>
#define epsilon 0.0001
#define broj_elemenata 100


int main() {
	
	double matricaA[broj_elemenata][broj_elemenata],matricaB[broj_elemenata][broj_elemenata];
	
	int koloneA,redoviA,koloneB,redoviB;
	int i,j;
	
	//Prvo cemo unijeti dimenzije matrice A i njene elemente, a potom dimenzije matrice B i njene elemente.
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&koloneA,&redoviA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<redoviA;i++){
		for(j=0;j<koloneA;j++){
			scanf("%lf",&matricaA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&koloneB,&redoviB);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<redoviB;i++){
		for(j=0;j<koloneB;j++){
			scanf("%lf",&matricaB[i][j]);
		}
	}
	//Prvo moramo provjeriti da li visina prve i sirina druge matrice isti, kao i sirina prve i visina druge matrice isti( Mozemo raditi sa matricama tipa 2x3 i 3x2, 7x7 i 7x7, 14x3 i 3x14... u ovom zadatku).
	if(koloneA!=redoviB) printf("NE");
	else if(koloneB!=redoviA) printf("NE");
	//Ako je jedan od uslova iznad ispunjen program odmah prestaje da radi. U suprotnom pristupa provjeri da li je matrica B zarotirana matrica A za 90 stepeni.
	else{
		for(i=0;i<redoviA;i++){
			for(j=0;j<koloneA;j++){
				if(matricaA[i][j]!=matricaB[j][redoviA-i-1]){
				printf("NE");
				return 0;
				} 
			}
		}
		printf("DA");
	}
	return 0;
}
