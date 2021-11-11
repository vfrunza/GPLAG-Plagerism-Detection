	#include <stdio.h>
	
	int main() {
		
		int i;
		char c;
		double udioVOZILA;
		
		//brojaci auta
		double brojacC=0, brojacP=0, brojacB=0, brojacS=0, brojacV=0, brojacTOTAL=0;
		double pobjednik;
		
		//brojaci unosa
		double brojacUNOSAc=0, brojacUNOSAp=0, brojacUNOSAs=0, brojacUNOSAv=0, brojacUNOSAb=0;
		
		
		//varijable za mjesto u unosu
		double mjestoCRNA=1, mjestoPLAVA=5, mjestoSIVA=3, mjestoCRVENA=4, mjestoBIJELA=2;
		int min=10000, prviUNOS;
		
		printf("Unesite vozila: ");
		
		//petlja unosa
		
		for(i=1;i<10000;i++){
			scanf("%c", &c);
			if(c=='c' || c=='C'){
				brojacC++;
				brojacTOTAL++;
				//brojacUNOSAc=brojacUNOSAc+i;
				if(brojacC==1){
					//mjestoCRNA=i;
				}
			}
			else if(c=='p' || c=='P'){
				brojacP++;
				brojacTOTAL++;
				//brojacUNOSAp=brojacUNOSAp+i;
				if(brojacP==1){
					//mjestoPLAVA=i;
				}
			}
			else if(c=='b' || c=='B'){
				brojacB++;	
				brojacTOTAL++;
				//brojacUNOSAb=brojacUNOSAb+i;
				if(brojacB==1){
					//mjestoBIJELA=i;
				}
			}
			else if(c=='s' || c=='S'){
				brojacS++;
				brojacTOTAL++;
				//brojacUNOSAs=brojacUNOSAs+i;
				if(brojacS==1){
				//	mjestoSIVA=i;
				}
			}
			else if(c=='v' || c=='V'){
				brojacV++;
				brojacTOTAL++;
				//brojacUNOSAv=brojacUNOSAv+i;
				if(brojacV==1){
					//mjestoCRVENA=i;
				}
			}
			else if(c=='k' || c=='K'){
				break;
			}
			else if(c!='k' || c!='K' || c!='c' || c!='C' || c!='p' || c!='P' || c!='v' || c!='V' || c!='s' || c!='S' || c!='b' || c!='B'){
				printf("Neispravan unos\n");
			}
		}
		
		
		//najfrekventije i prvo vozilo
		
		//Mj.Crna
		if(brojacC==brojacB && mjestoCRNA<mjestoBIJELA) brojacB=0;
		if(brojacC==brojacV && mjestoCRNA<mjestoCRVENA) brojacV=0;
		if(brojacC==brojacS && mjestoCRNA<mjestoSIVA) brojacS=0;
		if(brojacC==brojacP && mjestoCRNA<mjestoPLAVA) brojacP=0;
		//Mj. Crvena
		if(brojacV==brojacC && mjestoCRVENA<mjestoCRNA) brojacC=0;
		if(brojacV==brojacB && mjestoCRVENA<mjestoBIJELA) brojacB=0;
		if(brojacV==brojacS && mjestoCRVENA<mjestoSIVA) brojacS=0;
		if(brojacV==brojacP && mjestoCRVENA<mjestoPLAVA) brojacP=0;
		//Mj. plava
		if(brojacP==brojacV && mjestoPLAVA<mjestoCRVENA) brojacV=0;
		if(brojacP==brojacC && mjestoPLAVA<mjestoCRNA) brojacC=0;
		if(brojacP==brojacB && mjestoPLAVA<mjestoBIJELA) brojacB=0;
		if(brojacP==brojacS && mjestoPLAVA<mjestoSIVA) brojacS=0;
		//Mj. Siva
		if(brojacS==brojacC && mjestoSIVA<mjestoCRNA) brojacC=0;
		if(brojacS==brojacV && mjestoSIVA<mjestoCRVENA) brojacV=0;
		if(brojacS==brojacP && mjestoSIVA<mjestoPLAVA) brojacP=0;
		if(brojacS==brojacB && mjestoSIVA<mjestoBIJELA) brojacB=0;
		//Mj. Bijela
		if(brojacB==brojacC && mjestoBIJELA<mjestoCRNA) brojacC=0;
		if(brojacB==brojacV && mjestoBIJELA<mjestoCRVENA) brojacV=0;
		if(brojacB==brojacP && mjestoBIJELA<mjestoPLAVA) brojacP=0;
		if(brojacB==brojacS && mjestoBIJELA<mjestoSIVA) brojacS=0;
		
		if(brojacC>=brojacV){
			if(brojacC>=brojacS){
				if(brojacC>=brojacP){
					if(brojacC>=brojacB){
						//if(brojacC!=0){
							//	if(mjestoCRNA<mjestoCRVENA && mjestoCRNA<mjestoSIVA && mjestoCRNA<mjestoPLAVA && mjestoCRNA<mjestoBIJELA){
							pobjednik=brojacC;
							//printf("crna");
				//}	
				}
				}
				}
				}
		 if(brojacB>brojacC){
			if(brojacB>=brojacS){
				if(brojacB>=brojacV){
					if(brojacB>=brojacP){
						//if(mjestoBIJELA<mjestoCRNA && mjestoBIJELA<mjestoSIVA && mjestoBIJELA<mjestoCRVENA && mjestoBIJELA<mjestoPLAVA){
						//if(brojacB!=0){
						//printf("crvena");
						pobjednik=brojacB;
					//}
				}
				}
				}
				}
				
		
		 if(brojacS>brojacC){
			if(brojacS>brojacB){
				if(brojacS>=brojacV){
					if(brojacS>=brojacP){
							//if(mjestoSIVA<mjestoCRNA && mjestoSIVA<mjestoBIJELA && mjestoSIVA<mjestoCRVENA && mjestoSIVA<mjestoPLAVA){
						//if(brojacS!=0){
							pobjednik=brojacS;
							//printf("siva");
				//}
				}
				}
				}
				}
	
		if(brojacV>brojacC){
			if(brojacV>brojacB){
				if(brojacV>brojacS){
					if(brojacV>=brojacP){
						//if(mjestoCRVENA<mjestoCRNA && mjestoCRVENA<mjestoBIJELA && mjestoCRVENA<mjestoSIVA && mjestoCRVENA<mjestoPLAVA){
						//if(brojacV!=0){
							pobjednik=brojacV;
							//printf("plava");
				//}
				}
				}	
				}
				}
		
		if(brojacP>brojacC){
			if(brojacP>brojacB){
				if(brojacP>brojacS){
					if(brojacP>brojacV){
				//		if(mjestoPLAVA<mjestoCRNA && mjestoPLAVA<mjestoBIJELA && mjestoPLAVA<mjestoSIVA && mjestoPLAVA<mjestoCRVENA){
					//	if(brojacP!=0){
						pobjednik=brojacP;
						//printf("bijela");
				//}
				}
				}
				}
				}	

		//udio vozila u totalu
		
		if(pobjednik!=0){
		udioVOZILA=(pobjednik/brojacTOTAL)*100;
		}
		else udioVOZILA=0;
		
		//rasporedba boja i ispis
		
		printf("Ukupno evidentirano %.f vozila.\n", brojacTOTAL);
		
		if(pobjednik==brojacC	){
			printf("Najpopularnija boja je crna (%.2f%).", udioVOZILA);
			return 0;
		}
		if(pobjednik==brojacP){
			printf("Najpopularnija boja je plava (%.2f%).", udioVOZILA);
			return 0;
		}
		if(pobjednik==brojacB){
			printf("Najpopularnija boja je bijela (%.2f%).", udioVOZILA);
			return 0;
		}
		if(pobjednik==brojacV){
			printf("Najpopularnija boja je crvena (%.2f%).", udioVOZILA);
			return 0;
		}
		if(pobjednik==brojacS){
			printf("Najpopularnija boja je siva (%.2f%).", udioVOZILA);
			return 0;
		}
		
		return 0;
	}
