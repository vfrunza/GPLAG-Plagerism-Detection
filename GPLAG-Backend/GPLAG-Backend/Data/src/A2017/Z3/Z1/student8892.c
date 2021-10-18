#include <stdio.h>


int dva_od_tri (int niz_jedan[], int velicina_prvog, int niz_dva[], int velicina_drugog, int  niz_tri[], int velicina_treceg){
	
	int i, j, k,l=0,  isti_jedan_i_dva = 0, isti_dva_i_tri = 0, isti_tri_i_jedan = 0, brojac = 0, isti=0, br = 0, pomocni1, pomocni2 ;
	i = 0;
	
	
	do{
		
		for(j = 0; j < velicina_drugog; j++){
		
			if ( niz_jedan[i] == niz_dva[j]) {
				
				isti_jedan_i_dva = 1;
				pomocni1 = niz_dva[j];
				break;
				}
				
		}
		for(k = 0; k < velicina_treceg; k++){
			if (niz_jedan[i] == niz_tri[k]){
				isti_tri_i_jedan = 1;
				pomocni2 = niz_tri[k];
				break;
			}
		}
		
	
		if( (isti_jedan_i_dva == 0 && isti_tri_i_jedan == 1) || (isti_jedan_i_dva == 1 && isti_tri_i_jedan == 0)) brojac++;
		
	
		isti_jedan_i_dva = 0;
		isti_dva_i_tri = 0;
		isti_tri_i_jedan = 0;
		
		
		i++;
		
	
	}while (i < velicina_prvog);
	
	if (l==0){
			
			for(j = 0; j < velicina_drugog; j++){
				for( k = 0; k < velicina_treceg; k++){
					if (niz_dva[j] == niz_tri[k]){
						isti_dva_i_tri = 1; 
						
						break;
					}
						if(isti_dva_i_tri == 1) break;
					
				}
				if(isti_dva_i_tri == 1){
					if ((niz_dva[j] != pomocni1) && (niz_dva[j] != pomocni2)){
					brojac++;
					}
				}
					
				
				isti_dva_i_tri = 0;
	
				
			}
		
		}
	

	
	
	return brojac;
}



int main (){
	
	return 0;
}