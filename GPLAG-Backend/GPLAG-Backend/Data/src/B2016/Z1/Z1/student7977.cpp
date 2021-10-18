/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

int absolutno(int n){
	if(n >= 0){
		return n;
	}else{
		return n*(-1);
	}
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	
	std::vector<int> v1;
	enum Gadni {Nista, Opaki, Odvratni} broj(Nista);
	
	for(int i=0; i<v.size(); i++){
		std::vector<int> v2;
		for(int j = v[i]; j!=0; j/=3){
			v2.push_back(absolutno(j%3));
		}
        
		std::vector<int> v3(3, 0);
		for(int j=0; j<v2.size(); j++){
			v3[v2[j]]++;
		}
		for(int j=0; j<3; j++){
			if(v3[j] != 0 && v3[j]%2 == 0){
				int k;
				for(k=j+1; k<3; k++){
					if(v3[k] != 0 && v3[k]%2 == 0){
						continue;
					}else if(v3[k] != 0 && v3[k]%2 != 0){
						break;
					}
				}
				if(k == 3){
					broj = Opaki;
					break;
				}else{
					broj = Nista;
					break;
				}
			}else if(v3[j] > 0 && v3[j]%2 != 0){
				int k;
				for(k=j+1; k<3; k++){
					if(v3[k] > 0 && v3[k]%2 !=0){
						
					}else if(v3[k] > 0 && v3[k]%2 == 0){
						break;
					}
				}
				if(k == 3){
					broj = Odvratni;
					break;
				}else{
					broj = Nista;
					break;
				}
			}
		}
		if(a == true && broj == Opaki){
			int h;
			for(h=0; h<v1.size(); h++){
				if(v1[h] == v[i]){
					break;
				}
			}
			if(h==v1.size()){
				v1.push_back(v[i]);
			}
		}else if((a == false && broj == Odvratni) || (v[i] == 0 && a == false)){
			int h;
			for(h=0; h<v1.size(); h++){
				if(v1[h] == v[i]){
					break;
				}
			}
			if(h==v1.size()){
				v1.push_back(v[i]);
			}
		}
	}
	return v1;
}

int main ()
{
	bool a(true);
	std::vector<int> v;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::cin >> broj;
	while(broj != 0){
		v.push_back(broj);
		std::cin >> broj;
	}
	
	std::vector<int> v1(IzdvojiGadne(v, a));
	std::cout << "Opaki: ";
	for(int i=0; i<v1.size(); i++){
		if(i != v1.size() - 1){
			std::cout << v1[i] << " ";
		}else{
			std::cout << v1[i] << std::endl;
		}
	}
	
	a = false;
	v1 = IzdvojiGadne(v, a);
	std::cout << "Odvratni: ";
	for(int i=0; i<v1.size(); i++){
		if(i != v1.size() - 1){
			std::cout << v1[i] << " ";
		}else{
			std::cout << v1[i];
		}
	}
	return 0;
}