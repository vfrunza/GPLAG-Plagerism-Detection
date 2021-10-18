/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>
#include <algorithm>

typedef std::vector<std::vector<int>> Matrica;

long long int Obicni_presjek (long long int a) {
	return a;
}

int SumaDjelilaca (long long int broj) {
	int suma=0; 
	for (long long int max=fabs(broj); max>0; max--)
		if (broj%max==0) suma+=max;
	return suma;
}

bool Da_li_je_prost (long long int broj) {
	if (broj<=1) return false;
	for (int i=2; i<=sqrt(broj); i++)
		if (broj%i==0) return false;
	return true;
}

int BrojProstihFaktora (long long int broj) {
	std::vector<int> pom;
	if (Da_li_je_prost(broj)) { int brojac=1; return brojac; }
	for (int i=2; i<broj/2+1; i++)
		if (broj%i==0 && Da_li_je_prost(i)==true) {
			pom.push_back(i);
			broj=broj/i;
			if (Da_li_je_prost(broj)) {pom.push_back(broj); break;}
			i--;
			if (broj==1) break;
		}
	return pom.size();
}

bool Savrsen_broj (int broj) {
	if (broj<=0) return false;
	int suma_cifara=0;
	for (int i=1; i<broj; i++)
		if (int(broj)%i==0) suma_cifara+=i;
	if (suma_cifara==int(broj)) return true;
	return false;
}

int BrojSavrsenihDjelilaca (long long int broj) {
	int savrseni=0;
	for (long long int max=fabs(broj); max>0; max--)
		if (broj%max==0 && Savrsen_broj(max)==true) savrseni++;
	return savrseni;
}

int SumaCifara (long long int broj) {
	int suma=0;
	while (broj!=0){
		int cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}

template <typename Tip1, typename Tip2>
//std::vector<std::vector<int>> UvrnutiPresjek (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2) {
auto UvrnutiPresjek (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2)-> std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> {
	std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> mat;
	std::vector<typename std::remove_reference <decltype(*poc1)>::type> p;
	int i=0;
	bool da=true;
	for (auto temp1=poc1; temp1 != iza_k1; temp1++){
		da=true;
		for (auto temp2=poc2; temp2 != iza_k2; temp2++) {
			if (Obicni_presjek(*temp1)==Obicni_presjek(*temp2)) {
				p.push_back(*temp1);
				p.push_back(0);
				p.push_back(0);
				mat.resize(i);
				mat.push_back(p);
				p.resize(0);
				i++;
			}
		}
	}
	std::sort(mat.begin(), mat.end());
	return mat;
}

template <typename Tip1, typename Tip2, typename Tip, typename P_Tip>
//std::vector<std::vector<int>> UvrnutiPresjek (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2, P_Tip f(Tip)) {
auto UvrnutiPresjek (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2, P_Tip f(Tip))-> std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> {
	std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> mat;
	std::vector<typename std::remove_reference <decltype(*poc1)>::type> p;
	int i=0;
	for (auto temp1=poc1; temp1!=iza_k1; temp1++) {
		for (auto temp2=poc2; temp2!=iza_k2; temp2++) {
			if (f(*temp1)==f(*temp2)) {
				p.push_back(*temp1);
           		p.push_back(*temp2);
        	 	p.push_back(f(*temp1));
           		mat.resize(i);
            	mat.push_back(p);
            	p.resize(0);
            	i++;
			}
		}
	}
//std::cout<<"mat "<<mat.size();
	std::sort(mat.begin(),mat.end(), [](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b) {
									//	for (int i=a.size()-1; i>0; i--) 
										int i=a.size()-1;
										if (a[i]!=b[i]) return a[i]<b[i]; 
										else if (a[i]==b[i] && a[0]==b[0]) return a[i-1]<b[i-1];
										return a[0]<b[0]; });
	return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2)-> std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> {
	std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> mat;
	std::vector<typename std::remove_reference <decltype(*poc1)>::type> p;
	int i=0;
	bool pom=true, r=true;
	for (auto temp1=poc1; temp1 != iza_k1; temp1++) {
		pom=true;
		for (auto temp2=poc2; temp2 != iza_k2; temp2++) 
			if (Obicni_presjek(*temp1)==Obicni_presjek(*temp2)) pom=false;
		if (pom==true) {
			p.push_back(*temp1);
			p.push_back(0);
			mat.resize(i);
			mat.push_back(p);
			p.resize(0);
			i++;
		}
	}
	for (auto temp2=poc2; temp2!=iza_k2; temp2++) {
		r=true;
		for (auto temp1=poc1; temp1!=iza_k1; temp1++)
			if (Obicni_presjek(*temp2)==Obicni_presjek(*temp1)) r=false;
		if (r==true) {
			p.push_back(*temp2);
			p.push_back(0);
			mat.resize(i);
			mat.push_back(p);
			p.resize(0);
			i++;
		}
	}
	std::sort (mat.begin(),mat.end(),[](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b) { return a>b;});
	return mat;
}


template <typename Tip1, typename Tip2, typename Tip, typename P_Tip>
//std::vector<std::vector<int>> UvrnutaRazlika (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2, P_Tip f(Tip)) {
auto UvrnutaRazlika (Tip1 poc1, Tip1 iza_k1, Tip2 poc2, Tip2 iza_k2, P_Tip f(Tip))-> std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> { 
	std::vector<std::vector<typename std::remove_reference <decltype(*poc1)>::type>> mat;
	std::vector<typename std::remove_reference <decltype(*poc1)>::type> p;
	int i=0;
	bool pom=true, r=true;
	for (auto temp1=poc1; temp1 != iza_k1; temp1++) {
		pom=true;
		for (auto temp2=poc2; temp2 != iza_k2; temp2++) 
			if (f(*temp1)==f(*temp2)) pom=false;
		if (pom==true) {
			p.push_back(*temp1);
			p.push_back(f(*temp1));
			mat.resize(i);
			mat.push_back(p);
			p.resize(0);
			i++;
		}
	}
	for (auto temp2=poc2; temp2!=iza_k2; temp2++) {
		r=true;
		for (auto temp1=poc1; temp1!=iza_k1; temp1++)
			if (f(*temp2)==f(*temp1)) r=false;
		if (r==true) {
			p.push_back(*temp2);
			p.push_back(f(*temp2));
			mat.resize(i);
			mat.push_back(p);
			p.resize(0);
			i++;
		}
	}
	std::sort (mat.begin(),mat.end(),[](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b) { return a>b;});
	return mat;
}

template <typename Tip>
void Ispisi(std::vector<std::vector<Tip>> m){
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++)
			std::cout<<std::right<<std::setw(6)<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
}

int main ()
{
	int vel1,vel2,pom=0;
	int broj;
   	std::deque<int> dek1, dek2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>vel1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
	for (int i=0; i<vel1; i++) {
		std::cin>>broj;
		pom=0;
		for (auto j=dek1.begin(); j!=dek1.end(); j++)
			if (broj==*j) pom=1;
		if (pom==0) dek1.push_back(broj);
		else {i--;}
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>vel2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for (int i=0; i<vel2; i++){
      std::cin>>broj;
      pom=0;
      for (auto j=dek2.begin(); j!=dek2.end(); j++)
         if (broj==*j) pom=1;
      if (pom==0) dek2.push_back(broj);
      else { i--; }
   }
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	auto presjek=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	Ispisi(presjek);
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	auto razlika=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	Ispisi(razlika);
	std::cout<<"Dovidjenja!";
	return 0;
}