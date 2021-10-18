#include <stdio.h>

int dva_od_tri(int* a1, int el1, int* a2, int el2, int* a3, int el3){
	int br=0, i, j, k, l, t1, t2, t3;
	for(i=0; i<el1; i++){
		t1=1;
		if(i>0){
			for(k=i-1; k>=0; k--){
				if(a1[i]==a1[k]){
					t1=0;
					break;
				}
			}
		}
		if(t1==0) continue;
		else{
			for(j=0; j<el2; j++){
				t2=1;
				if(j>0){
					for(k=j-1; k>=0; k--){
						if(a2[j]==a2[k]){
							t2=0;
							break;
						}
					}
				}
				if(t2==0) continue;
				else{
					if(a1[i]==a2[j]){
						br++;
						for(k=0; k<el3; k++){
							t3=1;
							if(k>0){
								for(l=k-1; l>=0; l--){
									if(a3[k]==a3[l]){
										t3=0;
										break;
									}
								}
							}
							if(t3==0) continue;
							else{
								if(a1[i]==a3[k]) br--;
							}
						}
					}
				}
			}
		}
		
	}
	
	
	for(i=0; i<el2; i++){
		t2=1;
		if(i>0){
			for(k=i-1; k>=0; k--){
				if(a2[i]==a2[k]){
					t2=0;
					break;
				}
			}
		}
		if(t2==0) continue;
		else{
			for(j=0; j<el3; j++){
				t3=1;
				if(j>0){
					for(k=j-1; k>=0; k--){
						if(a3[j]==a3[k]){
							t3=0;
							break;
						}
					}
				}
				if(t3==0) continue;
				else{
					if(a2[i]==a3[j]){
						br++;
						for(k=0; k<el1; k++){
							t1=1;
							if(k>0){
								for(l=k-1; l>=0; l--){
									if(a1[k]==a1[l]){
										t1=0;
										break;
									}
								}
							}
							if(t1==0) continue;
							else{
								if(a2[i]==a1[k]) br--;
							}
						}
					}
				}
			}
		}
		
	}
	
	for(i=0; i<el3; i++){
		t3=1;
		if(i>0){
			for(k=i-1; k>=0; k--){
				if(a3[i]==a3[k]){
					t3=0;
					break;
				}
			}
		}
		if(t3==0) continue;
		else{
			for(j=0; j<el1; j++){
				t1=1;
				if(j>0){
					for(k=j-1; k>=0; k--){
						if(a1[j]==a1[k]){
							t1=0;
							break;
						}
					}
				}
				if(t1==0) continue;
				else{
					if(a3[i]==a1[j]){
						br++;
						for(k=0; k<el2; k++){
							t2=1;
							if(k>0){
								for(l=k-1; l>=0; l--){
									if(a2[k]==a2[l]){
										t2=0;
										break;
									}
								}
							}
							if(t2==0) continue;
							else{
								if(a3[i]==a2[k]) br--;
							}
						}
					}
				}
			}
		}
		
	}
	return br;
}
	
	
int main() {

	return 0;
}
