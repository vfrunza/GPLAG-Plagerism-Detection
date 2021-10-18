#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne( std::vector<int> v, bool p){
	if(v.size()!=0){
	for(int i=0; i<v.size()-1; i++){
		for(int j=i+1; j<v.size(); j++)
		if(v.at(j)==v.at(i)){
		 v.erase(v.begin()+j);
		 j--;
		 if(j==(v.size()-1)) break;
		}
		if(i==(v.size()-1)) break;
	}}
	std::vector<int>novi;
for(int element :v){
	std::vector<int>brojaci{0,0,0};
	
	int x=element;
	
	do{
		int y=x%3;
		if (y<0) y*=(-1);
		x/=3;
		brojaci[y]++;
	}while(x!=0);
	int broji;
	broji=0;
	for(int i=0; i<3; i++)
		if(((brojaci[i]%2 == 0 || brojaci[i]==0) && p==true)||((brojaci[i]%2!=0 || brojaci[i]==0)&& p==false)) broji++;
	if(broji==3) novi.push_back (element);
}
	return novi;
	}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	do {
		std::cin>>x;
		if(!(std::cin)){
			std::cout<<"Niste unijeli brojeve! "<<std::endl;
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cout<<"Unesite brojeve(0 za prekid unosa): ";
			x=1;
			continue;
		}
		if(x!=0) v.push_back(x);
	}while(x!=0);
	std::vector<int>a;
	std::vector<int>b;
	a=IzdvojiGadne(v,true);
	b=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++)std::cout<<a[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<b.size(); i++) std::cout<<b[i]<<" ";
	return 0;
}