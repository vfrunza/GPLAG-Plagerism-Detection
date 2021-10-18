/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdexcept>

template <typename Tip1,typename Tip2,typename Tip3, typename T>

bool JeLiProst(int n) {
	for(int i=2;i<n/2;i++) 
		if(n%i==0) return false;
return true;
}
int BrojProstihFaktora(int n){
	int br(0),c(0);
	while(n!=0) {
		c=n%10;
		if(JeLiProst(c)==true) br++;
		n/=10;
	}
return br;
}
bool Kriterij_p(T p1,T p2) {
	if(BrojProstihFaktora(*p1)!=BrojProstihFaktora(*p2))
		return BrojProstihFaktora(*p1)>BrojProstihFaktora(*p2);
	else return *p1>*p2;
}

void SortirajPodrucjeVrijednosti (Tip1 p1, Tip1 k1, Tip2 p2, Tip3 p3,Tip3 f(Tip1, Tip2)), bool Kriterij(T, T)){
	Sort(Tip1 p1, Tip1 k1, Kriterij);
	Sort(Tip2 p2, Tip2 p2+(k1-p1), Kriterij);
	try {
	bool pron(true);
	for(auto it1=p1,it2=p2,it3=p3;it1!=k1;it1++,it2++,p3++) {
		Tip3 f1=f(it1,it2);
		for(auto it=p3;it!=p3+(k1-p1);it++) {
			if(f1!=*it) pron=false;
			else if(f1==*it) pron=true;
		}
		if(!=pron) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		else *p3=f1;
	}
	}
	catch(std::logic_error izuzetak) {
		std::cout<<izuzetak.what();
	}
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n(0),a(0),b(0),c(0);
	std::cin<<n;
	std::cout<<"Unesite elemente 3 vektora ";
	std::vector<int> v1(0),v2(0),v3(0);
	for(int i=0;i<n;i++) {
		std::cin<<a<<b<<c;
		for(int j=0;j<v1.size();j++) {
			if(v1[i]==a || v2[i]==b || v3[i]==c) {
				continue;
			}
		}
		v1.push_back(a);
		v2.push_back(b);
		v3.push_back(c);
	}
	
	SortirajPodrucjeVrijednosti(int v1.begin(),int v1.end(),int v2.begin(), int v3.begin(),[](int x,int y){return -2*x+y;}, Kriterij_p(v1.begin(),v2.begin()));
	
		
	return 0;
}