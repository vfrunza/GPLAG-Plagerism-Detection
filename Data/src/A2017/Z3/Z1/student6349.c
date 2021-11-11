#include <stdio.h>

int dva_od_tri(int nizj[],int velicinaj,int nizd[],int velicinad,int nizt[],int velicinat) {
	int i,j,k,l,m,brojac=0,nexist=0;
	int velicinaTempj=0,velicinaTempd=0,velicinaTempt=0,nizTempj[100],nizTempd[100],nizTempt=0;
	int exist=0;
	
	for (i=0;i<velicinaj;i++){
		exist=0;
		for (j=0;j<velicinaTempj;j++){
			if(nizj[i]==nizTempj[j])
			nexist=1;
		}
		if (exist==0){
			nizTempj[velicinaTempj]=nizj[i];
			velicinaTempj++;
		}
	}
	
	for (i=0;i<velicinad;i++){
		exist=0;
		for (j=0;j<velicinaTempd;j++){
			if(nizd[i]==nizTempd[j])
			nexist=1;
		}
		if (exist==0){
			nizTempd[velicinaTempd]=nizd[i];
			velicinaTempd++;
		}
	}
	
	for (i=0;i<velicinaTempt;i++){
		exist=0;
		for (j=0;j<velicinaTempt;j++){
			if(nizt[i]==nizTempt[j])
			nexist=1;
		}
		if (exist==0){
			nizTempt[velicinaTempt]=nizt[i];
			velicinaTempt++;
		}
	}
	
	for (i=0;i<velicinaTempj;i++){
		exist=0;
		for(j=0;j<velicinaTempd;j++){
			if(nizTempj[i]==nizTempd[j]) exist=1;
				for (k=0;k<velicinaTempj;k++){
					for(l=0;l<velicinaTempd;l++){
						for(m=0;m<velicinaTempt;m++){
							if((nizTempj[k]==nizTempj[i]) && (nizTempd[l]==nizTempj[i]) && (nizTempt[m]==nizTempj[i]))
							nexist=0;
						}
					}
				}
			}
		}
		if(exist==1)
		brojac++;
	}
	
	for (i=0;i<velicinaTempd;i++){
		exist=0;
		for(j=0;j<velicinaTempt;j++){
			if(nizTempd[i]==nizTempt[j]) {
				exist=1;
				for (k=0;k<velicinaTempj;k++){
					for(l=0;l<velicinaTempd;l++){
						for(m=0;m<velicinaTempt;m++){
							if((nizTempj[k]==nizTempd[i]) && (nizTempd[l]==nizTempd[i]) && (nizTempt[m]==nizTempd[i]))
							nexist=0;
						}
					}
				}
			}
		}
		if(exist==1)
		brojac++;
	}
	
	for (i=0;i<velicinaTempj;i++){
		exist=0;
		for(j=0;j<velicinaTempt;j++){
			if(nizTempj[i]==nizTempt[j]) {
				exist=1;
				for (k=0;k<velicinaTempj;k++){
					for(l=0;l<velicinaTempd;l++){
						for(m=0;m<velicinaTempt;m++){
							if((nizTempj[k]==nizTempj[i]) && (nizTempd[l]==nizTempj[i]) && (nizTempt[m]==nizTempj[i]))
							nexist=0;
						}
					}
				}
			}
		}
		if(exist==1)
		velicinaTempt++;
	}
	
	if(exist=0){
	(brojac++);
	}
	return brojac;
}

int main () {
	
	int i,j,exist=0,nizj[100],nizd[100],nizt[100],velicinaj,velicinad,velicinat;
	int nizTempj[100],nizTempd[100],nizTempt[100],velicinaTempj=0,velicinaTempd=0,velicinaTempt=0;
	int rezultat;

	printf ("Unesite velicinu prvog niza: ");
		scanf ("%d",&velicinaj);
	printf ("Unesite clanove prvog niza: ");
		for(i=0;i<velicinaj;i++){
			scanf ("%d",&nizj[i]);
			if(i==0){
				nizTempj[velicinaTempj]=nizj[i];
					velicinaTempj++;
			}
			else{
			for (j=0;j<velicinaTempj;j++){
				if (nizTempj[j]==nizj[i]){
					exist=1;
				}
			}
			
			if(exist==0) {
				nizTempj[velicinaTempj]=nizj[i];
				++velicinaTempj;
			}
		}
	}
	
	printf ("Unesite velicinu drugog niza: ");
		scanf ("%d",&velicinad);
	printf ("Unesite clanove drugog niza: ");
		for(i=0;i<velicinad;i++){
			scanf ("%d",&nizd[i]);
			if(i==0){
				nizTempd[velicinaTempd]=nizd[i];
					++velicinaTempd;}
			else{
				for(j=0;j<velicinaTempd;j++){
					if(nizTempd[j]==nizd[i]){
						exist=1;
					}
			
			if(exist==0) {
				nizTempd[velicinaTempd]=nizd[i];
				++velicinaTempd;
			}
		}
	}
	
	printf ("Unesite velicinu treceg niza: ");
		scanf ("%d",&velicinat);
	printf ("Unesite clanove treceg niza: ");
		for(i=0;i<velicinat;i++){
			scanf ("%d",&nizt[i]);
			if(i==0){
				nizTempt[velicinaTempt]=nizt[i];
					++velicinaTempt;}
			else {
				for(j=0;j<velicinaTempt;j++){
					if(nizTempt[j]==nizt[i]){
						exist=1;
					}
			if(exist==0) {
				nizTempt[velicinaTempt]=nizt[i];
				++velicinaTempt;
			}
		}
	}
}
}
}
	
	
	rezultat=dva_od_tri(nizTempj,velicinaTempj,nizTempd,velicinaTempd,nizTempt,velicinaTempt);
		printf("%d",rezultat);
			return 0;
}				