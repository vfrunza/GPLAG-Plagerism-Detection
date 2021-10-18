#include <iostream>
#include <vector>
#include <cmath>


std::vector< long long int> UkloniDuple(std::vector<long long int>niz){
    long long int size=niz.size(),i,j,k;
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
    std::vector< long long int>Vraceni;
   for(i=0;i<size;i++){
      Vraceni.push_back(niz[i]);
}
return Vraceni;
}

 int  Terca( int n) 
{
	std::vector< int>arr(100);
	int i=0,j;
	std::vector< int>brojaci(3,0);
	while(abs(n)>0)
	{
		arr[i]=abs(n)%3;
		i++;
		n=abs(n)/3;
	}
	for(j=i-1;j>=0;j--){
	brojaci[arr[j]]++;
	}
 int Neparnih=0,Parnih=0,Nule=0;
	for(int i=0;i<3;i++){
		if(brojaci[i]%2!=0 and brojaci[i]!=0) Neparnih++;
		if(brojaci[i]%2==0 and brojaci[i]!=0) Parnih++;
		if(brojaci[i]==0) Nule++;
}

    if((Nule==1 and Neparnih==2) or (Neparnih==3 and Parnih==0 and Nule==0) or (Nule==2 and Neparnih==1 and Parnih==0)) return 2;
    if((Neparnih==0 and Parnih==3 ) or (Parnih==2 and Nule ==1 ) or (Nule==2 and Parnih==1 and Neparnih==0) )  return 1; 
    return 0; 
}

std::vector< long long int> IzdvojiGadne (std::vector<int>v,bool f){
	std::vector<long long int>Izdvojeni;
	for(int i=0;i<v.size();i++){
    if(Terca(v[i])==1 and f==true) Izdvojeni.push_back(v[i]); 
    if(Terca(v[i])==2 and f==false)  Izdvojeni.push_back(v[i]); 
    if(Terca(v[i])==0) continue;
	}
    return UkloniDuple(Izdvojeni);
}

int main(){
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    std::vector<int>a;
    int d;
    do{
    	std::cin>>d;
    	if(d!=0) a.push_back(d);
    }while(d!=0);
    std::vector< long long int>b;
    std::vector< long long int>c;
    b=IzdvojiGadne(a,true);
    c=IzdvojiGadne(a,false);
    std::cout<<"Opaki: ";
    for(auto x:b){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl<<"Odvratni: ";
    for(auto y: c){
        std::cout<<y<<" ";
    }
   return 0;
   }
	