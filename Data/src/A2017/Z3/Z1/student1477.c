#include <stdio.h>
#include <math.h>

float roundoff(float br)
{	
	 int precision=1;
      int temp=(int )(br*pow(10,precision));
      int br1=br*pow(10,precision+1);
      temp*=10;
      temp+=5;
      if(br1>=temp)
              br1+=10;
      br1/=10;
      br1*=10;
      br=br1/pow(10,precision+1);
      return br;
}



void zaokruzi1(float niz[],int vel){
	int i;
	for(i=0;i<vel;i++){
		niz[i]=roundoff(niz[i]);
	}
}

void preslozi(float niz[],int vel,int k){
	int i;
	float niz[vel];
	for(i=0;i<vel;i++){
		if(jelveci(niz[i],k)==true)
	}
}


int main() {
	
	float niz[]={13.1,15.749999,15.75,9.222,78.1};
	int i=0;
	zaokruzi1(niz,5);
	for(i=0;i<5;i++){
		printf("%f ",niz[i]);
	}
	
	return 0;
}
