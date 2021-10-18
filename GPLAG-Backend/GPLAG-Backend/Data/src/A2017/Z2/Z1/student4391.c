#include <stdio.h>

int main() {
	int n,i,j;
	do {
	printf("Unesite cijeli broj N: ");
	scanf("%d", &n);
	} while (n%4!=0 || n<8);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			
			if(i==1){
				if(j>=1 && j<=(n/2)){
				if(j==1){ printf("\\");}
				else if(j==(n/2)){ printf("/");
				else printf(" ");}
				}
				else if(j>(n/2) && j<=n){
			    if(j==(n/2)+1 || j==n){
				printf("+");
				else printf("-"); }
				}
			}
			else if(i>1 && i<(n/4)){
				if(j<=(n/4)){
					if(i==j){
				printf("\\");
				else printf(" "); }
				}
				else if(j>(n/4) && j<(n/2)){
					if(j+i==(n/2)+1){
			    printf("/");
				else printf(" "); }
				}
				else if(j>(n/2)){
				if(j==(n/2)+1 || j==n)
					printf("|");
					else printf(" "); }
			}
			else if(i>(n/4) && i<(n/2)){
				if(j<=(n/4)){
					if(j+i==(n/2)+1){
				printf("/");
				else printf(" "); }
				}
				else if(j>(n/4) && j<(n/2)){
					if(i==j){
				printf("\\");
				else printf(" "); }
				}
				else if(j>(n/2)){
				if(j==(n/2)+1 || j==n)
					printf("|");
					else printf(" "); }	
				}
			else if(i==(n/2)){
				if(j>=1 && j<=(n/2)){
				if(j==1){ printf("/");}
				else if(j==(n/2)){ printf("\\");
				else printf(" ");}
				}
				else if(j>(n/2) && j==n){
			    else if(j==(n/2)+1 || j==n){
				printf("+");
				else printf("-");}
			}
			else if(i==(n/2)+1){
				if(j>=1 || j<=(n/2)){
				if(j==1 || j==(n/2)){
				printf("+");
				else printf("-");}
				}
				else if(j>(n/2) && j<n){
				if(j==(3./4)*n || j==j==(3./4)*n+1){
				printf("|");
				else printf(" "); }
				}
			}
			else if(i>(n/2)+1 && i<(3/4)*n){
				if(j==1 || j==(n/2) || j==(3./4)*n || j==(3./4)*n+1){
					printf ("|");
					else printf(" "); }
			}
			else if(i>=(3./4)*n && i<=(3./4)*n+1){
				if(j<=(n/2)){
					if(j==1 || j==(n/2)){
						printf("|");
						else printf(" "); }
				}
				else if(j>(n/2)){
					if(j==(3./4)*n || j==(3./4)*n+1){
						printf("+");
						else printf("-"); }
				}
			}
			else if(i>(3./4)*n+1 && i<n){
				if(j==1 || j==(n/2) || j==(3./4)*n || j==(3./4)*n+1){
					printf ("|");
					else printf(" "); }
			}
			else if(i==n){
				if(j<=(n/2)){
				    if(j==1 || j==(n/2)){
				    printf("+");
				    else printf("-");}	
				}
				else if(j>(n/2) && j<=n){
				if(j==(3./4)*n || j==(3./4)*n+1){
					printf("|");
					else printf(" ");}
				}
			}
			}
		}
	}	
	
	return 0;
}
