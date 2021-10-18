/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
using std::cout;
using std::cin;


std::vector<int>PretvaranjeUTernarne(long long int a){
	std::vector<int>v;
	if(a==0)v.push_back(a);
		while(a!=0){
			int c=std::abs(a%3);
			v.push_back(c);
			a=a/3;
		}
		
	
	return v;
}


std::vector<int>
IzdvojiGadne(std::vector<int>v1, bool a){
	std::vector<int>v;
if(a)
{
		for(long long int i: v1){
			std::vector<int>v3(PretvaranjeUTernarne(i));
			long long int brnula(0),brjed(0),brdv(0);
			for(auto j: v3){
					
					if(j==0)brnula++;
					if(j==1)brjed++;
					if(j==2)brdv++;
				
				
				
			}
			if(brnula%2==0 && brjed%2==0 && brdv%2==0)v.push_back(i);
		}
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
			
		}
	}	
	return v;
}
else{
	for(long long int i: v1){
		std::vector<int>v3(PretvaranjeUTernarne(i));
		long long int brnula(0),brjed(0),brdv(0);
		for(auto j: v3){
	
				if(j==0)brnula++;
				if(j==1)brjed++;
				if(j==2)brdv++;
			
			
		}
		if((brnula%2!=0 || brnula==0) && (brjed%2!=0 || brjed==0) && (brdv%2!=0 || brdv==0))v.push_back(i);
		
	}
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
			
		}
	}

	return v;
}
		
	
}


int main ()
{   std::vector<int>v;
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    int n;
    do{
    	cin>>n;
    	if(n!=0){
    		v.push_back(n);
    	}
    }while(n!=0);
    auto opaki=IzdvojiGadne(v,true), odvratni=IzdvojiGadne(v,false);
    cout<<"Opaki: ";
    for(const auto &x: opaki){
    	cout<<x<<" ";
    }
    cout<<std::endl<<"Odvratni: ";
    for(const auto &x: odvratni)
    {
    	cout<<x<<" ";
    }
    
	return 0;
}