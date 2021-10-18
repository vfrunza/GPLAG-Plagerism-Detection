#include <stdio.h>
struct Oblik {
	char naziv[20];
	int br_stranica;
	float stranice[300];
};

int main()
{

	struct Oblik oblici[3]= {
		{"Kvadrat",4,{4.5,4.5,4.5,4.5}},
		{"Trougao",3,{3,4,5}},
		{"Petougao",5,{4,5,6,4,3.77}}
	};

	struct Oblik moji_oblici[3];
	int i,j;

	FILE* dat = fopen("moja.bin","wb");
	int N=3;

	fwrite(&N,2,1,dat);
	for ( i = 0; i < 3; i++) {
		fwrite(oblici[i].naziv,1,20,dat);
		fwrite(&oblici[i].br_stranica,1,1,dat);
		fwrite(oblici[i].stranice,4,oblici[i].br_stranica,dat);
	}

	fclose(dat);


	dat=  fopen("oblici.dat","rb");

	fread(&N,2,1,dat);
	for  (i = 0; i < N; i++) {
		fread(moji_oblici[i].naziv,1,20,dat);
		fread(&moji_oblici[i].br_stranica,1,1,dat);
		fread(moji_oblici[i].stranice,4,moji_oblici[i].br_stranica,dat);
	}

	for  (i = 0; i < N; i++) {
		printf("%s %d ",moji_oblici[i].naziv,moji_oblici[i].br_stranica);
		for  (j = 0; j < moji_oblici[i].br_stranica; j++) {
			printf("%.2f, ",moji_oblici[i].stranice[j]);
		}
		printf("\n\n\n");
	}




	return 0;
}
