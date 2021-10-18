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

std::vector<int> IzdvojiGadne (std::vector<int> v, bool b){

std::vector<int> y;
for(int i=0; i<v.size(); i++){
	int brojac0(0), brojac1(0), brojac2(0);
	int broj=v[i];
	while (broj!=0){
		int ostatak=broj%3;
		if(ostatak==0) brojac0++;
		else if(ostatak==1) brojac1++;
		else if(ostatak==2) brojac2++;
		broj=broj/3;
	}
	
	if(b){
		if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0)
		y.push_back(v[i]);
		
	}
	
	else if(!b){
		if((brojac0%2==1 || brojac0==0) && (brojac1%2==1 || brojac1==0) && (brojac2%2==1 || brojac2==0))
		y.push_back(v[i]);
		
		
	}
 for (int i=0; i<y.size(); i++){
 	for (int j=0; j<y.size(); j++){
 		if(y[i]==y[j]){
 			y.erase(y.begin()+j);
 			{
 				j--;
 				
 			}
 		}
 	}
 }

}

return y; 

}



int main ()
{
  
	std::cout <<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> brojevi;  
  int broj;
  std::cin>>broj;
   while (broj!= 0){
    brojevi.push_back(broj);
    std::cin >>broj;
    
 }
	
		for(int i=0; i<brojevi.size(); i++){
			brojevi.push_back(broj);
			std::cin >>broj;
			
		}
		
	auto opaki=IzdvojiGadne(brojevi,1); 
	std::cout << "Opaki: ";
	for(int x: opaki)
	std::cout <<x<<"";
	for(int i=0; i<brojevi.size(); i++){
		std::cout <<brojevi[i]<< " ";
		
	}
	std::cout <<std::endl; 
	auto odvratni=IzdvojiGadne(brojevi,0);
	std::cout <<"Odvratni: ";
	for(int x: odvratni){
		std::cout <<x<<" ";
		
	}
	for(int i=0; i<brojevi.size(); i++){
		std::cout <<brojevi[i]<<" ";
		
	}
	
	return 0;
}

