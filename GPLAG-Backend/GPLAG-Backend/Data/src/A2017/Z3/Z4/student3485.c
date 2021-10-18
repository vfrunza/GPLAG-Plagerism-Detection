#include <stdio.h>

int  UkloniDuple(int *niz,int size){
    int i,j,k;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;){
            if(niz[j]==niz[i]){
                for(k=j;k<size-1;k++){
                    niz[k]=niz[k+1];
                }
                size--;
            }else
            j++;
        }
    }
 return  size;
}


int bacaj(int *pro,int n,int sta){
	int i,j;
		for(i=0;i<n;i++){
		if(pro[i]==sta){
			for(j=i;j<n-1;j++){
				pro[j]=pro[j+1];
			}n--;
			i--;}
		}
		return n;
}

void BubbleSort(int a[], int array_size)
 {
 int i, j, temp;
 for (i = 0; i < (array_size - 1); ++i)
 {
      for (j = 0; j < array_size - 1 - i; ++j )
      {
           if (a[j] > a[j+1])
           {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
           }
      }
 }
 }  
 
int razliciti(int *a,int vel){
	int i,br=0;
	BubbleSort(a,vel);
	for(i=0;i<vel;i++){
		if(a[i]==a[i+1]) br++;
	}
	if(br==0) return 1;
	else return 0;
}

int stand(int *a,int vel ){
int max_count = 0,pom[100]={0},h=vel,i,j;
for(i=0;i<vel;i++){
	pom[i]=a[i];
}
if(razliciti(a,vel)){
	int min=9999;
	for(i=0;i<h;i++){
	    if(pom[i]<min) min=pom[i];
	}
	return min;
}
if(razliciti(a,vel)==0){
for (i=0;i<vel;i++)
{
   int count=1;
   for ( j=i+1;j<vel;j++)
       if (a[i]==a[j])
           count++;
   if (count>max_count)
      max_count = count;
}

for ( i=0;i<vel;i++)
{
   int count=1;
   for (j=i+1;j<vel;j++)
       if (a[i]==a[j])
           count++;
   if (count==max_count)
       return a[i];
}
}
}



int ucestanost_max(int *arr,int size){
    int  freq[100],temp[100]={0},k=0,ar[100]={0},velko=size,aa[100]={0},h=size,pom[100]={0},o=0,bb[100]={0},bbel=size,er=0,xxx[100]={0},xi=size;
    int  i, j, count,vel=size;
    for(i=0;i<size;i++){
    	ar[i]=arr[i];
	}
	 for(i=0;i<size;i++){
    	xxx[i]=arr[i];
	}
	  for(i=0;i<size;i++){
    	aa[i]=arr[i];
	}
	 for(i=0;i<size;i++){
    	bb[i]=arr[i];
	}
    for(i=0; i<size; i++)
    {
        freq[i] = -1;
    }
    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    for(i=0; i<size; i++)
    {
        if(freq[i] >1)
        {
            temp[k++]=arr[i];
            pom[o++]=freq[i];
        }
    }
    for(i=0;i<k;i++){
    	vel=bacaj(arr,vel,temp[i]);
	}
	 
	int min=999,hist[100]={0},histvel=0;
	int novo=o;
	o=UkloniDuple(pom,o);
	if(vel==0  && o==novo){	
	return stand(ar,velko);
	}

	if(vel==0  && novo!=o){	
				for(i=0;i<h;i++){
			if(aa[i]<min) min=aa[i];
		}
		return min;
	}
	if(vel!=0 ){
		return stand(xxx,xi);
	}
}


int max(int matrica[100][100], int visina, int sirina){
	int i,j,tempi[100]={0},k=0;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			    tempi[k++]=matrica[i][j];
		}
	}
return ucestanost_max(tempi,k);
}

int brisi_kol(int a[100][100],int V,int S,int koja){
    int i,j,t;
	for(t=koja,j=koja+1;t<S-koja-1,j<S;t++,j++){
        for(i=0;i<V;i++){
            a[i][t]=a[i][j];
        }
    }
S--;
return S;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N){
    int i,j;
    for(i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
            if(matrica[i][j]==N){
                sirina=brisi_kol(matrica,visina,sirina,j);
            }
        }
    }
    return sirina;
}

void IspisiMat(int mat[100][100],int v,int s){
    int i,j;
    for(i=0;i<v;i++){
        for(j=0;j<s;j++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
  
int v,s,i,j,mat[100][100]={{0}};
printf("Unesite sirinu i visinu matrice: ");
scanf("%i %i",&s,&v);
for(i=0;i<v;i++){
    if(v-1!=i){
    printf("Unesite elemente %i. reda: ",i+1);
    for(j=0;j<s;j++){
        scanf("%i",&mat[i][j]);
    }
    }
     if(v-1==i){
    printf("Unesite elemente %i. reda: \n",i+1);
    for(j=0;j<s;j++){
        scanf("%i",&mat[i][j]);
    }
    }
}
int p=0;
while(s!=0){
  
    s=izbaci_kolone(mat,v,s,max(mat,v,s));
    if(s!=0){
        if(p==0){
    printf("Nakon %i. prolaza matrica glasi:\n",p+1);
     IspisiMat(mat,v,s);
        }
        
        if(p!=0){
    printf("\nNakon %i. prolaza matrica glasi:\n",p+1);
     IspisiMat(mat,v,s);
        }
        
    }
    if(s==0){
        printf("\nNakon %d. prolaza matrica je prazna!",p+1);
    }
    p++;
}
     return 0;
}
