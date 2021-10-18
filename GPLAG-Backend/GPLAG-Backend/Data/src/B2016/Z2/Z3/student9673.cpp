/*B 16/17, Zadaća 2, Zadatak 3 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <algorithm>


int SumaDjelilaca (long long int broj){
    int s(0);
    if(broj<0) broj=-broj;
    for(int i=1; i<=broj; i++) if(broj%i==0) s+=i;
    
    return s;
}

int BrojProstihFaktora (long long int broj){
    int s(0);
    
    if(broj<0) broj=-broj;
    for(int i=2; i<=broj; i++){
        if(broj%i==0){
            broj/=i;
            i=1; 
            s++;
        }
    }
    return s;
}

int SumaCifara (long long int broj){
	int s(0);

	if(broj<0) broj=-broj;
	while(broj!=0){
        s+=broj%10;
        broj/=10;
	}

	return s;
}

int BrojSavrsenihDjelilaca (long long int broj){
    int s(0);
    
    if(broj<0) broj=-broj;
    for(int i=1; i<=broj; i++){
        if(broj%i==0){
        	int suma(0);
        	for(int j=1; j<i; j++) if(i%j==0) suma+=j;
        	if(suma==i) s++;
        }
    }
    return s;
} 

template <typename Tip>
		std::vector<std::vector<Tip>> SortirajPresjek (std::vector<std::vector<Tip>> mat){
 		mat.resize(mat.size()+1);
    	int n(mat.size());

    	std::vector<std::vector<Tip>*> niz_pok(0);
    	niz_pok.resize(n);

    	for(int i=0; i<n; i++) niz_pok[i]=&mat[i];

    	std::sort(niz_pok[0], niz_pok[n-1], [](std::vector<Tip> p1, std::vector<Tip> p2) -> bool { if(p1[2]==p2[2]){ if(p1[0]==p2[0]) return (p1[1]<p2[1]); return (p1[0]<p2[0]);} return(p1[2]<p2[2]);});
    	mat.resize(mat.size()-1);
		return mat;
}

template <typename Tip>
 	std::vector<std::vector<Tip>> SortirajRazliku (std::vector<std::vector<Tip>> mat){
    	mat.resize(mat.size()+1);
    	int n(mat.size());

    	std::vector<std::vector<Tip>*> niz_pok(0);
    	niz_pok.resize(n);

    	for(int i=0; i<n; i++) niz_pok[i]=&mat[i];

    	std::sort(niz_pok[0], niz_pok[n-1], [](std::vector<Tip> p1, std::vector<Tip> p2) -> bool { if(p1[0]==p2[0]) return (p2[1] < p1[1]); return(p2[0] < p1[0]); });
    	mat.resize(mat.size()-1);
    	return mat;
	}
	
template <typename PokTip, typename ItTip, typename Tip1, typename Tip2>
	auto UvrnutiPresjek (PokTip p1, PokTip p2, ItTip it1, ItTip it2, Tip1 fun (Tip2)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		
		typedef typename std::remove_reference<decltype(*p1)>::type PovratniTip;
		std::vector<std::vector<PovratniTip>> mat;
		std::vector<PovratniTip> red;
		ItTip pomocni(it1); 
		
		while(p1!=p2){
			pomocni=it1;
			while(pomocni!=it2){
				if(fun (*pomocni) == fun (*p1)){
					red.push_back(*p1);
					red.push_back(*pomocni);
					red.push_back(fun(*pomocni));
					mat.push_back(red);
					red.resize(0);

				}
				pomocni++;
			}
			p1++;
		}
		mat=SortirajPresjek(mat);
		
		return mat;	
	}
	
template <typename PokTip, typename ItTip>
	auto UvrnutiPresjek (PokTip p1, PokTip p2, ItTip it1, ItTip it2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		
		typedef typename std::remove_reference<decltype(*p1)>::type PovratniTip;
		std::vector<std::vector<PovratniTip>> mat;
		std::vector<PovratniTip> red;
		ItTip pomocni(it1); 
		
		while(p1!=p2){
			pomocni=it1;
			while(pomocni!=it2){
				if(*p1==*pomocni){
					red.push_back(*p1);
					red.push_back(0);
					red.push_back(0);
					mat.push_back(red);
					red.resize(0);
				}
				pomocni++;
			}
			p1++;
		}
		
		return mat;
	}
	
template <typename PokTip, typename ItTip, typename Tip1, typename Tip2>
	auto UvrnutaRazlika (PokTip p1, PokTip p2, ItTip it1, ItTip it2, Tip1 fun (Tip2)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	
	typedef typename std::remove_reference<decltype(*p1)>::type PovratniTip;
	std::vector<std::vector<PovratniTip>> mat;
	std::vector<PovratniTip> red;
	ItTip pomocni(it1);
	PokTip pocetni(p1);
	
	while(p1!=p2){
		pomocni=it1;
		while(pomocni!=it2){
			if(fun(*p1)==fun(*pomocni)) break;
			pomocni++;
		}
		if(pomocni==it2){
			red.push_back(*p1);
			red.push_back(fun(*p1));
			mat.push_back(red);
			red.resize(0);
		}
		p1++;
	}
	
	while(it1!=it2){
		pomocni=pocetni;
		while(pomocni!=p2){
			if(fun(*it1)==fun(*pomocni)) break;
			pomocni++;
		}
		if(pomocni==p2){
			red.push_back(*it1);
			red.push_back(fun(*it1));
			mat.push_back(red);
			red.resize(0);
		}
		it1++;
	}
	
    mat=SortirajRazliku(mat);
	
	return mat;
}

template <typename PokTip, typename ItTip>
	auto UvrnutaRazlika (PokTip p1, PokTip p2, ItTip it1, ItTip it2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	
	typedef typename std::remove_reference<decltype(*p1)>::type PovratniTip;
	std::vector<std::vector<PovratniTip>> mat;
	std::vector<PovratniTip> red;
	ItTip pomocni(it1);
	PokTip pocetni(p1);
	
	while(p1!=p2){
		pomocni=it1;
		while(pomocni!=it2){
			if(*p1==*pomocni) break;
			pomocni++;
		}
		if(pomocni==it2){
			red.push_back(*p1);
			red.push_back(0);
			mat.push_back(red);
			red.resize(0);
		}
		p1++;
	}
	
	while(it1!=it2){
		pomocni=pocetni;
		while(pomocni!=p2){
			if(*it1==*pomocni) break;
			pomocni++;
		}
		if(pomocni==p2){
			red.push_back(*it1);
			red.push_back(0);
			mat.push_back(red);
			red.resize(0);
		}
		it1++;
	}
	
    mat=SortirajRazliku(mat);
	
	return mat;
}
	
int main(){
	std::deque<int> d1(0), d2(0);
	int n1(0), n2(0);
	int broj;
	bool Isti(false);
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	
	while (d1.size()!=n1){
		Isti=false;
		std::cin >> broj;
		for(int i=0; i<d1.size(); i++) {
			if(d1[i]==broj) Isti=true;
		}
		if(!Isti) d1.push_back(broj);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	
	while(d2.size()!=n2){ 
		Isti=false;
		std::cin >> broj;
		for(int i=0; i<d2.size(); i++) {
			if(d2[i]==broj) Isti=true;
		}
		if(!Isti) d2.push_back(broj);
	}
	
	auto mat = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			std::cout << std::setw(6) << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	auto matrica = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			std::cout << std::setw(6) << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Dovidjenja!";
	return 0;
}
