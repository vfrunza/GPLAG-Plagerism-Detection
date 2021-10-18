#include<iostream>
#include<vector>
#include<iomanip>

unsigned long long int Ternarni(unsigned long long int a){
	unsigned long long int b=0, p=1;
	long long int n=a;
	if (n<0) n=-n; 
	while(n!=0){
		b+=(n%3)*p;
		p*=10;
		n/=3;
	}
	return b;
}

bool opaki(int b){
	if(b<0) b=-b;
	unsigned long long int n=Ternarni(b);
	int brojac[3]={0};
	do{ 
		brojac[n%10]++;
		n/=10;
	}while(n!=0);
	int a=1;
	for(int i=0;i<3;i++){
		if(brojac[i]!=0) {
			a=brojac[i];
			break;
		}
	}
	bool dobro=true;

	if((a%2)==0){
		for(int i=0;i<3;i++){
			if(brojac[i]!=0 && brojac[i]%2!=0){
				dobro=false; break;
			}
		}
	}
	
	else if((a%2)!=0) dobro=false;
	return dobro;
}

bool odvratni(int b){
	if(b<0) b=-b;
	unsigned long long int n=Ternarni(b);
	int brojac[3]={0};
	do{
		brojac[n%10]++;
		n/=10;
	}while(n!=0);
	int a=0;
	for(int i=0;i<3;i++){
		if(brojac[i]!=0){
			a=brojac[i];
			break;
		}
	}
	
	bool dobro=true;
	if(a%2!=0){
		for(int i=0;i<3;i++){
			if(brojac[i]!=0 && brojac[i]%2==0){
				dobro=false; break;
			}
		}
	} 
	
	else if(a%2==0) dobro=false;
	return dobro;
}

std::vector<int> IzdvojiGadne(std::vector<int>v, bool n){

	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	std::vector<int>v1;
	if(n==true){
		for(int i=0;i<v.size();i++){
			if(opaki(v[i])) v1.push_back(v[i]);
		}
	}
	
	else if(n==false){
		for(int i=0;i<v.size();i++){
			if(odvratni(v[i])) v1.push_back(v[i]);
		}
	}
	return v1;
}

int main ()
{
	std::vector<int> v, v1,v2;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	do{
		std::cin>>x;
		if(x==0) break;
		v.push_back(x);
	}while(x!=0);

	
	v1=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<v1.size();i++)
		std::cout<<v1[i]<<" ";

	v2=IzdvojiGadne(v,false);
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<v2.size();i++)
		std::cout<<v2[i]<<" ";
		
	return 0;
}