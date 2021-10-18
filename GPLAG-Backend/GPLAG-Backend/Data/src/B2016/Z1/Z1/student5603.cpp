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

std::vector<int>IzdvojiGadne(std::vector<int>v,bool p){

  std::vector<int> vec;
  std::vector<int> vektor;
  vektor.resize(3);
  
	for(int i=0;i<v.size();i++){
		
    bool test1(true);
    bool test2 (true);
    bool test3 (true);
    
     for(int j=0;j<3;j++){
     	vektor[j]=0;
     }
     
     int n=fabs(v[i]);
     int broj=v[i];
     
     while(n!=0){
     	vektor[n%3]++;
     	n/=3;
     }
     for(int j=0;j<3;j++){
     	if(vektor[j]%2!=0)
     	test1=false;
     }
     for(int j=0;j<3;j++){
     	if(vektor[j]%2==0 && vektor[j] != 0)
     	test3=false;
     }
    for(int j = 0; j < vec.size(); j++)
    	if(vec[j] == broj) test2 = false;
    	
    if(p==false && test3==true && test2) vec.push_back(broj);
    if(p==true && test1==true && test2) vec.push_back(broj);
     	
     
			
		}
	
		
return vec;
}
int main ()
{
	std::vector<int>v;
	int n;

	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>n;
	
	while(n!=0){
		v.push_back(n);
		std::cin>>n;
	}
	
	
	
	std::vector<int>a=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<a.size();i++){
		
		if(i!=a.size()-1)std::cout<<a[i]<<" ";
		else
		std::cout<<a[i]<<std::endl;;
		
	}
	std::vector<int>b=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	
	for(int i=0;i<b.size();i++){
		
		if(i!=b.size()-1) std::cout<<b[i]<<" ";
		else 
		std::cout<<b[i]<<std::endl;
	}
	return 0;
}