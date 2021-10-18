/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
using std :: abs;
std::vector<int> IzdvojiGadne(std::vector<int> v,bool a)
{
	//IZBACIVANJE DUPLIKATA
	for(int i = 0; i<v.size()-1; i++){     										
		for(int k = i+1; k<v.size(); k++){
			if (v[i]==v[k]) {
				v.erase(v.begin()+k--);
 		}
	}
}
	long long int rez=0;
	std::vector<int> cifre ;
	std::vector<int> novi;
		for (int i = 0; i < v.size(); i++) {
			long long int temp=std :: abs((long long int)(v[i]));
			for( ; ; ){															//PRETVARANJE U TERNARNI
				rez=temp/3;
				cifre.push_back(abs(temp%3));                                        
				temp=temp/3;
				if(rez==0) break;
			}
			
			int jedan=0;
			int dva=0;
			int nula=0;
			int j=0;
				for(j = 0; j < cifre.size(); j++){                              //PREBROJAVANJE CIFARA
					if (cifre[j]==1) jedan++;
					if (cifre[j]==2) dva++;
					if (cifre[j]==0) nula++;
			}
			
			if (a) { //OPAKI
					if (jedan%2==0 && dva%2==0 && nula%2==0) {
						novi.push_back(v[i]);
				}
			}
			else {	//ODVRATNI
					if (jedan%2!=0 && dva%2!=0 && nula%2!=0) { novi.push_back(v[i]);}
			   else if(jedan==0 && dva==0 && nula==0) { novi.push_back(v[i]);}
				
			   else	if (nula==0 && jedan%2!=0 && dva%2!=0) {  novi.push_back(v[i]);	}
			   else	if (jedan==0 && nula%2!=0 && dva%2!=0) {  novi.push_back(v[i]);	}
			   else	if (dva==0 && nula%2!=0 && jedan%2!=0) {  novi.push_back(v[i]);	}
				
			   else	if (nula==0 && jedan==0 && dva%2!=0) {    novi.push_back(v[i]); }
			   else	if (nula==0 && dva==0 && jedan%2!=0) {    novi.push_back(v[i]);	}
				
		   	   else	if (jedan==0 && nula==0 && dva%2!=0) {    novi.push_back(v[i]);	}
			   else	if (jedan==0 && dva==0 && nula%2!=0) {    novi.push_back(v[i]); }
				
			   else	if (dva==0 && nula==0 && jedan%2!=0) {    novi.push_back(v[i]);	}
			   else	if (dva==0 && jedan==0 && nula%2!=0) {    novi.push_back(v[i]);	}
			}
			cifre.clear();
		}
	return novi;	
} 


int main ()
{
   std::vector<int> v;
   int a;
	
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std ::cin>>a;
		if (a!=0) { v.push_back(a); }
 	}while (a!=0);

   std::vector<int>Opaki(IzdvojiGadne(v,true));								
   std::vector<int>Odvratni(IzdvojiGadne(v,false));
   
   std::cout << "Opaki: ";
		for(int i = 0; i < Opaki.size(); i++){
			std::cout << Opaki[i]<<" ";
	   }
	std::cout  << std::endl;
	std::cout << "Odvratni: ";
		for(int i = 0; i<Odvratni.size(); i++){
			std::cout << Odvratni[i]<<" ";
    	}	

	return 0;
}