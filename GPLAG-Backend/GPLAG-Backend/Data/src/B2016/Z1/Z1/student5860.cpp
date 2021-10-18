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

typedef std::vector<int> vektor;

std::vector<int> BrisiDuplikate(std::vector<long long int> V){

	for(int i=0; i<V.size(); i++){   
		for(int j=i+1; j<V.size(); j++){ 
			if(V[i]==V[j]){ 
				V[j]=0;
			}
		}
	}
	std::vector<int> v;
		for(int i=0; i<V.size(); i++){
			if(V[i]!=0){
				v.push_back(V[i]);
			}
		} 
	
	return v;
}

std::vector<long long int> Pretvorba(std::vector<long long int> V){
	std::vector<long long int> gadni(V.size());
	for (int i = 0; i < V.size(); i++){
		int brojaci(0);
		int deci(0);
		while (V[i] != 0){
			int ostatak = V[i] % 10;
			//std::cout<<"OSTATAK:"<<ostatak<<std::endl;
			deci = deci + ostatak*pow(3, brojaci);
			brojaci++;
			V[i] /= 10;
        	//std::cout<<"CLAN VEKTORA:"<<V[i];
			//std::cout<<std::endl;
		}
		gadni.push_back(deci);
	}
	return gadni;
}

std::vector<long long int> Pomoc(long long int clan){
	std::vector<long long int> brojevi;
	if(clan<0) clan=clan*(-1);
	while(clan!=0){
		int ostatak=clan%10;
		brojevi.push_back(ostatak);
	    clan/=10;
	}
	std::vector<long long int> brojac(brojevi.size());
	for(int i=0; i<brojevi.size(); i++){
		brojac[brojevi[i]]++;
	}
	return brojac;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){

int ternar;
long double clan(0);
int brojac(0);
std::vector<long long int> v_ternar;
std::vector<long long int> v_ternar_0;
std::vector<long long int> v_ternar_1;
std::vector<long long int> v_ternar_2;

	for(int i=0; i<v.size(); i++){
		while(v[i]!=0){
	   		  int ostatak=v[i]/3;
			  ternar=v[i]-ostatak*3;
        	  v[i]=v[i]/3;
		      clan=clan*0.1+ternar;
		      brojac++;
        }
    	brojac--;
		clan=clan*pow(10,brojac);
    	v_ternar.push_back(clan);
		clan=0;
		brojac=0;
	}

	for(int i=0; i<v_ternar.size(); i++){
		std::vector<long long int> Brojac(Pomoc(v_ternar[i]));
		bool paran(1);
		for(int j=0; j<Brojac.size(); j++){
			if(Brojac[j]%2!=0){
			paran=0;
			break;
     	}
	}
	bool neparan(0);
	for(int j=0; j<Brojac.size(); j++){
		if(Brojac[j]==0 || Brojac[j]%2!=0) neparan=1;
		else{ 
			neparan=0;
			break;
		}
	}

	if (paran){
		v_ternar_1.push_back(v_ternar[i]);
		v_ternar_2.push_back(v_ternar[i]);
	}
	else if(neparan){
		v_ternar_0.push_back(v_ternar[i]);
	    v_ternar_2.push_back(v_ternar[i]);
	}
}


	std::vector<int> v_ternar_0_0;
	std::vector<int> v_ternar_1_1;
	std::vector<int> Gadni;

	std::vector<long long int> gadni=Pretvorba(v_ternar_2);
    std::vector<long long int> Opaki=Pretvorba(v_ternar_1);
    std::vector<long long int> Odvratni=Pretvorba(v_ternar_0);

	v_ternar_0_0 = BrisiDuplikate(Odvratni);
	v_ternar_1_1 = BrisiDuplikate(Opaki);
	Gadni = BrisiDuplikate(gadni);

	if (a) return v_ternar_1_1;
	else if (a == 0) return v_ternar_0_0;

	return Gadni;

}

int main (){
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	//Unos vektora:
	int broj;
	while(std::cin>>broj, broj!=0){
		if(!(std::cin)){
		    std::cout<<"Nije unesen cijeli broj!";
			std::cin.clear();
			std::cin.ignore(10000, '\n');	
		}
		v.push_back(broj);
	}

	std::vector<int> V=IzdvojiGadne(v, true);
	std::vector<int> V1=IzdvojiGadne(v, false);


	std::cout<<"Opaki: ";
		for(int i=0; i<V.size(); i++){
			if(V[i]!=0)
			std::cout<<V[i]<<" ";
		}
	
	std::cout<<std::endl;

	std::cout<<"Odvratni: ";
		for(int i=0; i<V1.size(); i++){
			if(V1[i]!=0)
			std::cout<<V1[i]<<" ";
		}

return 0;
}

