#include<iostream>
#include<vector>
#include<cmath>

long long int Pretvaranje(int n){
	int a=n;
	if(n<0) n=abs(n);
	int k,br(0);
	long long int s(0);
	while(n!=0){
		k=n%3;
		s=s+k*pow(10,br);
		br++;
		n=n/3;
	}
	if(a<0){ return s*(-1);}
	return s;

}
std::vector<int> Pomocna(long long int n){
	int k;
	if(n<0) n=abs(n);
	std::vector<int> v(3,0);
	while(n!=0){
		k=n%10;
		for(int i=0;i<v.size();i++){
			if (i==k) v[i]++;
		}
		n=n/10;
	}
	return v;
}

std::vector<int>IzdvojiGadne(std::vector<int> v, bool t){
		std::vector<int> pomocni(0);
		std::vector<int> opaki;
		std::vector<int> odvratni;
	    std::vector<int> bezduplikata;
		int s(0);
		for(int j=0;j<v.size();j++){
			s=0;
			for(int k=0;k<bezduplikata.size();k++){
				if(v[j]==bezduplikata[k])s++;
			}
			if(s==0) bezduplikata.push_back(v[j]);
		}
		v=bezduplikata;
		for(int i=0;i<v.size();i++){
			pomocni=Pomocna(Pretvaranje(v[i]));
			if((pomocni[0]%2==0 || pomocni[0]==0) && (pomocni[1]%2==0 || pomocni[1]==0)&& (pomocni[2]%2==0 || pomocni[2]==0)) opaki.push_back(v[i]);
			else if((pomocni[0]%2!=0 || pomocni[0]==0) && (pomocni[1]%2!=0 || pomocni[1]==0)&& (pomocni[2]%2!=0 || pomocni[2]==0)) odvratni.push_back(v[i]);
		}
		if(t==true) return opaki;
		else return odvratni;
		}

int main ()
{
	std::vector<int>v ;
	std::vector<int>gadni;
	std::vector<int>gadni2;
	int n(1);
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while(n!=0){
		std::cin >> n;
		if(n==0)break;
		v.push_back(n);
	}
	if(v.size()==0)return 0;
	gadni=IzdvojiGadne(v,true);
	if(gadni.size()!=0){
	std::cout << "Opaki: ";
	for(int i=0;i<gadni.size()-1;i++){
		std::cout << gadni[i]<<" ";
	}
	std::cout<<gadni[gadni.size()-1]<< std::endl;
	}
	gadni2=IzdvojiGadne(v,false);
	if(gadni2.size()!=0){
		std::cout << "Odvratni: ";
		for(int i=0;i<gadni2.size()-1;i++){
			std::cout << gadni2[i]<<" ";
		}
		std::cout<<gadni2[gadni2.size()-1]<< std::endl;
	}
	return 0;
}