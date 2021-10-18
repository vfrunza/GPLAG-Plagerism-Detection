/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t){
	std::vector<int> rez;

	for(int x: v){
	int br0(0),br1(0),br2(0);
	std::vector<int> cifre;	
	double temp=x;
	int cif;
	
	while(x!=0){
		cif=abs(x)%3;
		x=x/3;
		cifre.push_back(abs(cif));
	}

	for(int y: cifre){
	if(y==0) br0++;
	else if(y==1) br1++;
	else  br2++;	
	}
   
	if(br0%2==0 && br1%2==0 && br2%2==0 && t) 
		rez.push_back(temp);
	
	else if(((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0) && !t) || temp==0) 
		rez.push_back(temp);
	}

	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez.size();j++){
			if((i!=j) && (rez[i]==rez[j])){
				rez.erase(rez.begin()+j);
				j--;
			}
		}
	}
	return rez;
}

int main ()
{
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    
    int unos;
    std::vector<int> v;
    
    do{
    	std::cin>>unos;
    	if(unos!=0)
    	v.push_back(unos);
    }while(unos!=0);
    	
    std::vector<int> rez=IzdvojiGadne(v,true);
    	std::cout<<"Opaki: ";
    for(int x: rez)
    	std::cout<<x<<" ";
    
    std::cout<<"\n";
    
    std::vector<int> rez2=IzdvojiGadne(v,false);
    
    	std::cout<<"Odvratni: ";
    for(int x: rez2)
    	std::cout<<x<<" ";
    
	return 0;
}