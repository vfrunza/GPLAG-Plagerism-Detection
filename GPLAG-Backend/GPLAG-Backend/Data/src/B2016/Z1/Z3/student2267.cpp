/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

   std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>vektor1){
	std::vector<std::vector<double>>novi;

	if(vektor1.size()!=0 ){
		
	for(int i=0;i<vektor1.size()-1;i++){
		int pocetak;
		int z=i+1;
		int kraj;
	   
		if(vektor1[z]>=vektor1[i]){
			 pocetak=i;
			 kraj=i;
			while(z<vektor1.size()){
				if(vektor1[z]<vektor1[i]){
					kraj=z-1;
					break;
				}
			if(z==vektor1.size()-1){
			kraj=z;	
			break;}
				
				z++;
				i++;
				
			}
    std::vector<double>pomocni_vektor(0);
	for(int l=pocetak;l<=kraj;l++){
       pomocni_vektor.push_back(vektor1[l]);
	}
		
	novi.push_back(pomocni_vektor);
   
 	}}}
	return novi;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>vektor2){
	std::vector<std::vector<double>>novi;
	if(vektor2.size()!=0){
	for(int i=0;i<vektor2.size()-1;i++){
		int pocetak;
		int kraj;
		int z=i+1;
		
		if(vektor2[z]<=vektor2[i]){
			pocetak=i;
			kraj=i;
			while(z<vektor2.size()){
				if(z==vektor2.size()-1 && vektor2[z]<=vektor2[i]){
					kraj=z;
					break;
				}
				if(vektor2[z]>vektor2[i]){
					kraj=z-1;
					break;
				}
				z++;
				i++;
			}
			
		std::vector<double>pomocni_vektor;
		for(int p=pocetak;p<=kraj;p++){
			pomocni_vektor.push_back(vektor2[p]);
		}
		novi.push_back(pomocni_vektor);
		}
	}}
	
	return novi;
}





int main ()
{
	int broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>v(broj);
	for(int i=0;i<broj;i++){
		std::cin>>v[i];
	}
	
   std::vector<std::vector<double>>rastuci;
   rastuci=RastuciPodnizovi(v);
   std::cout<<"Maksimalni rastuci podnizovi: ";
   std::cout<<std::endl;
   for(int i=0;i<rastuci.size();i++){
   	for(int j=0;j<rastuci[i].size();j++){
   		std::cout<<std::left<<std::setw(2)<<rastuci[i][j];
   	}
   	std::cout<<std::endl;
   }
   std::vector<std::vector<double>>opadajuci;
   opadajuci=OpadajuciPodnizovi(v);
   std::cout<<"Maksimalni opadajuci podnizovi: ";
   std::cout<<std::endl;
   for(int i=0;i<opadajuci.size();i++){
   	for(int j=0;j<opadajuci[i].size();j++){
   		std::cout<<opadajuci[i][j]<<" ";
   	}
   	std::cout<<std::endl;
   }
	
	return 0;
}