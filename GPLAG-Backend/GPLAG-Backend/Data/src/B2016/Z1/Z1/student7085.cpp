#include <iostream>
#include <vector>

int DaLiJeGadan(int n)
{
	int br0(0);
	int br1(0);
	int br2(0);

	do{
		if(n%3==0)br0++;
		else if(n%3==1 || n%3==-1)br1++;
		else if(n%3==2 || n%3==-2)br2++;
		n/=3;
	} while(n!=0) ;
	if((br0%2==0 || br0==0) && (br1%2==0 || br1==0) && (br2%2==0 || br2==0)) {
		return 1;
	} else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) {
		return 2;
	} else  return 3;

}

std:: vector<int> Duplikati(std:: vector<int> v)
{
	std:: vector<int> precisceni_vektor;
	bool ponavljaju_se;
	for(int i=0; i<v.size(); i++) {
		ponavljaju_se=false;
		for(int j=0; j<i; j++) {
			if(v[i]==v[j]) {
				ponavljaju_se=true;
				continue;
			}
		}
		if(ponavljaju_se==false) precisceni_vektor.push_back(v[i]);
	}
	return precisceni_vektor;
}

std:: vector< int> IzdvojiGadne(std:: vector<int> v, bool a)
{
	std:: vector<int> novi_vektor;
	for(int i:v) {
		if(a==true && DaLiJeGadan(i)==1) novi_vektor.push_back(i);
		else if(a==false && DaLiJeGadan(i)==2) novi_vektor.push_back(i);
	}
	auto vektor=Duplikati(novi_vektor);
	return vektor;
}


int main ()
{   
	int a;
	std:: vector<int> v(0);
	std:: vector<int> v1,v2;
	std:: cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std:: cin>> a;
		if(!(std:: cin)){std:: cout<<"Niste unijeli brojeve! "<< std:: endl;
		std:: cin.clear();
        std:: cin.ignore(1000,'\n');
        std:: cout<< "Unesite brojeve (0 za prekid unosa): ";
             a=1;
        continue;
		}
		if(a!=0)v.push_back(a);
	} while(a!=0);
	
	std:: cout<< "Opaki: ";
	v2=IzdvojiGadne(v,true);
	for(int i:v2) {
		std:: cout<< i<< " ";
	}
	std:: cout<<std::endl;
	std:: cout<< "Odvratni: ";
	v1=IzdvojiGadne(v,false);
	for(int i: v1) {
		std:: cout<< i <<" ";
	}
	

	return 0;
}