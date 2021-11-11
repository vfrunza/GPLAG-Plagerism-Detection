#include <stdio.h>

int main() {
    int broj_tacaka=0, i=0, j=0, k=0, x=0, y=0, z=0, kolona[10]={0}, red[10]={0}, temp_red=0, temp_kolona=0;
	do{
	    printf("Unesite broj tacaka: ");
	    scanf("%d", &broj_tacaka);
	    if(broj_tacaka<=0 || broj_tacaka>10)
	    printf("Pogresan unos\n");
	}while(broj_tacaka<=0 || broj_tacaka>10);
	for(i=0; i<broj_tacaka; i++){
	    do{
	        printf("Unesite %d. tacku: ", i+1);
	        scanf("%d %d", &kolona[i], &red[i]);
	        if(kolona[i]<0 || kolona[i]>19 || red[i]<0 || red[i]>19)
	            printf("Pogresan unos\n");
	    }while(kolona[i]<0 || kolona[i]>19 || red[i]<0 || red[i]>19);    
	}
	
	for(i=0; i<broj_tacaka-1; i++){
	    for(j=i+1; j<broj_tacaka; j++){
	        if(red[i]>red[j] || (red[i]==red[j] && kolona[i]>kolona[j])){
	            temp_red=red[j];
	            red[j]=red[i];
	            red[i]=temp_red;
	            temp_kolona=kolona[j];
	            kolona[j]=kolona[i];
	            kolona[i]=temp_kolona;
	        }
	    }
	    
	}
	for(x=0; x<broj_tacaka-1; x++){
	    for(y=x+1; y<broj_tacaka; y++){
	        if(kolona[y]==kolona[x] && red[y]==red[x]){
	            for(z=x; z<broj_tacaka-1; z++){
	                kolona[z]=kolona[z+1];
	                red[z]=red[z+1];
	                
	            }
	            broj_tacaka--;
	            x--;
	            break;
	        }
	    }
	}
	    k=0;
	    for(i=0; i<20; i++){
	        for(j=0; j<20; j++){
	            if(i==red[k] && j==kolona[k]){
	                printf("*");
	                k++;
	                if(k==broj_tacaka)
	                k=0;
	            }
	            else
	                printf(" ");
	        }
	        printf("\n");
	    }
	return 0;
}
