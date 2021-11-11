#include <stdio.h>		
	int dva_od_tri(int nizc[], int nizd[], int nizf[], int velc, int veld, int velf) {
		int a,b,c,e;
		int brojac=0;
		
		for (a=0; a<velc; a++) { 
			for (e=0; e<a; e++) 
			if (nizc[a]==nizc[e] && e!=a) break;
			
			if (e==a) {
				for (b=0; b<veld; b++)
				if (nizc[a]==nizd[b]) {
					for (c=0; c<velf; c++)
						if (nizc[a]==nizf[c]) break;
							if (c==velf) { 
							brojac++;
							break; }
				}
				
			}
			
		}
		
		
		for (b=0; b<veld; b++) {
			for (e=0; e<b; e++)
				if (nizd[b]==nizd[e] && e!=b)
				break;
			if (e==b) {
				for (c=0; c<velf; c++)
					if(nizd[b]==nizf[c]) {
					for (a=0; a<velc; a++)
						if (nizd[b]==nizc[a]) break;
				if (a==velc) { 
				brojac++; 
				break; }
				}
			}
		}
			for (c=0; c<velf; c++) {
				for (e=0; e<c; e++) 
				if (nizf[c]==nizf[e] && e!=c) 
				break;
				
				if (e==c) {
					for (a=0; a<velc; a++)
						if(nizf[c]==nizc[a]) {
							for (b=0; b<veld; b++)
							if (nizf[c]==nizd[b]) 
							break;
						if (b==veld) {
							brojac++;
							break;}
						}
					}
				}	
				
		return brojac;	
		}
		
		
int main() {

	return 0;
}
