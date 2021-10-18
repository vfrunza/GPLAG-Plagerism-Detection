/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector> 
#include <algorithm>
#include <iomanip>
#include <deque>
#include <cmath>
int SumaDjelilaca(long long int n) {
	long long int k=abs(n);
	int suma(0);
	for(int i(1); i<=k; i++) {
		if(k%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int n) {
	int brojac(0);
	long long int c=abs(n);
	for(int i(2); i<=abs(n); i++) {
			if(c%i==0){
				while (c%i==0) {
					brojac++;
					c/=i;
				}
			}
	}
	return brojac;
}

bool DaLiJeSavrsen(long long int br) {
	int suma(0);
	for(int i(1); i<br; i++) {
		if(br%i==0) suma+=i;
	}
	if(suma==br) return true;
	else return false;
}

int BrojSavrsenihDjelilaca(long long int n) {
	long long int k=abs(n);
	int brojac(0);	
	for(int i(1); i<=abs(n); i++) {
		if(k%i==0) {
			if (DaLiJeSavrsen(i)) brojac++;
		}
	}
	return brojac;
}

template<typename itertip1, typename itertip2>
auto UvrnutiPresjek(itertip1 p1, itertip1 p2, itertip2 q1, itertip2 q2) -> std::vector<std::vector<decltype(*p1+*p1)>> {
	typedef std::vector<std::vector<decltype(*p1+*p1)>> Matrica;
	typedef std::vector<decltype(*p1+*p1)> Vector;
	int brojac(0);
	itertip1 pom1=p1;
	itertip2 pom2=q1;
	itertip2 def=q1;
	while(p1!=p2) {
		while(q1!=q2) {
			if(*p1==*q1) brojac++;
			q1++;
		}
		q1=def;
		p1++;
	}
	Matrica mat;
	mat.resize(brojac);
	for(int i(0); i<brojac; i++) {
		mat[i].resize(3);
	}
	int i(0);
	while (pom1!=p2) {
		while (pom2!=q2) {
			if(*pom1==*pom2) {
					mat[i][0]=*pom1;
					mat[i][1]=0;
					mat[i][2]=0;
					i++;
			}
			pom2++;
		}
		pom2=def;
		pom1++;
	}
	std::sort(mat.begin(), mat.end(), [] (Vector v1, Vector v2){
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2]) {
			if(v1[0]<v2[0]) return true;
			else if(v1[0]==v2[0]) {
				if(v1[1]<v2[1]) return true;
			}
		}
		return false;
	});
	return mat;
}

template<typename itertip1, typename itertip2, typename FunkcijskiTip>
auto UvrnutiPresjek(itertip1 p1, itertip1 p2, itertip2 q1, itertip2 q2, FunkcijskiTip f) -> std::vector<std::vector<decltype(*p1+*p1)>> {
	typedef std::vector<std::vector<decltype(*p1+*p1)>> Matrica;
	typedef std::vector<decltype(*p1+*p1)> Vector;
	int brojac(0);
	itertip1 pom1=p1;
	itertip2 pom2=q1;
	itertip2 def=q1;
	while(p1!=p2) {
		while(q1!=q2) {
			if(f(*p1)==f(*q1)) brojac++;
			q1++;
		}
		q1=def;
		p1++;
	}
	Matrica mat;
	mat.resize(brojac);
	for(int i(0); i<brojac; i++) {
		mat[i].resize(3);
	}
	int i(0);
	while (pom1!=p2) {
		while (pom2!=q2) {
			if(f(*pom1)==f(*pom2)) {
					mat[i][0]=*pom1;
					mat[i][1]=*pom2;
					mat[i][2]=f(*pom1);
					i++;
			}
			pom2++;
		}
		pom2=def;
		pom1++;
	}
	std::sort(mat.begin(), mat.end(), [] (Vector v1, Vector v2){
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2]) {
			if(v1[0]<v2[0]) return true;
			else if(v1[0]==v2[0]) {
				if(v1[1]<v2[1]) return true;
			}
		}
		return false;
	});
	return mat;
}


template<typename Itertip1, typename Itertip2>
auto UvrnutaRazlika(Itertip1 p1, Itertip1 p2, Itertip2 q1, Itertip2 q2) -> std::vector<std::vector<decltype(*p1+*p1)>>  {
	typedef std::vector<std::vector<decltype(*p1+*p1)>> Matrica; 
	typedef std::vector<decltype(*p1+*p1)> Vector;
	int brojac(0);
	Itertip1 pom1=p1;
	Itertip1 def1=p1;
	Itertip2 pom2=q1;
	Itertip2 def=q1;
	int brojac2(0);
	while(p1!=p2) {
		while(q1!=q2) {
			if(*p1==*q1) break;
			q1++;
		}
		if(q1==q2) brojac++;
		q1=def;
		p1++;
	}
	//broji prvu
	p1=def1;
	q1=def;
	
	while(q1!=q2) {
		while(p1!=p2) {
			if(*p1==*q1) break;
			p1++;
		}
		if(p1==p2) brojac2++;
		p1=def1;
		q1++;
	}
	//broji drugu
	Matrica mat;
	mat.resize(brojac);
	for(int i(0); i<brojac; i++) {
		mat[i].resize(2);
	}
	Matrica mat2;
	mat2.resize(brojac2);
	for(int i(0); i<brojac2; i++) {
		mat2[i].resize(2);
	}
	
	int i(0);
	while (pom1!=p2) {
		while (pom2!=q2) {
			if(*pom1==*pom2) break;
			pom2++;
		}
		if(pom2==q2) {
			mat[i][0]=*pom1;
			mat[i][1]=0;
			i++;
		}
		pom2=def;
		pom1++;
	} // upisuje prvu
	pom2=def;
	pom1=def1;
	int j(0);
	while (pom2!=q2) {
		while (pom1!=p2) {
			if(*pom2==*pom1) break;
			pom1++;
		}
		if(pom1==p2) {
			mat2[j][0]=*pom2;
			mat2[j][1]=0;
			j++;
		}
		pom1=def1;
		pom2++;
	} //upisuje drugu
	
	Matrica glavna;
	glavna.resize(brojac+brojac2);
	for(int i(0); i<(brojac+brojac2); i++) {
		glavna[i].resize(2);
	}
	
	for(int i(0); i<brojac; i++) {
		for(int j(0); j<2; j++) {
			glavna[i][j]=mat[i][j];
		}
	}
	for(int i(0); i<brojac2; i++) {
		for(int j(0); j<2; j++) {
			glavna[i+brojac][j]=mat2[i][j];
		}
	}
	
	std::sort(glavna.begin(), glavna.end(), [] (Vector v1, Vector v2){
		if(v1[0]>v2[0]) return true;
		else if(v1[0]==v2[0]) {
			if(v1[1]>v2[1]) return true;
		}
		return false;
	});
	return glavna;
	
}

template<typename Itertip1, typename Itertip2, typename FunkcijskiTip2>
auto UvrnutaRazlika(Itertip1 p1, Itertip1 p2, Itertip2 q1, Itertip2 q2, FunkcijskiTip2 f) -> std::vector<std::vector<decltype(*p1+*p1)>>  {
	typedef std::vector<std::vector<decltype(*p1+*p1)>> Matrica; 
	typedef std::vector<decltype(*p1+*p1)> Vector;
	int brojac(0);
	Itertip1 pom1=p1;
	Itertip1 def1=p1;
	Itertip2 pom2=q1;
	Itertip2 def=q1;
	int brojac2(0);
	while(p1!=p2) {
		while(q1!=q2) {
			if(f(*p1)==f(*q1)) break;
			q1++;
		}
		if(q1==q2) brojac++;
		q1=def;
		p1++;
	}
	//broji prvu
	p1=def1;
	q1=def;
	
	while(q1!=q2) {
		while(p1!=p2) {
			if(f(*p1)==f(*q1)) break;
			p1++;
		}
		if(p1==p2) brojac2++;
		p1=def1;
		q1++;
	}
	//broji drugu
	Matrica mat;
	mat.resize(brojac);
	for(int i(0); i<brojac; i++) {
		mat[i].resize(2);
	}
	Matrica mat2;
	mat2.resize(brojac2);
	for(int i(0); i<brojac2; i++) {
		mat2[i].resize(2);
	}
	
	int i(0);
	while (pom1!=p2) {
		while (pom2!=q2) {
			if(f(*pom1)==f(*pom2)) break;
			pom2++;
		}
		if(pom2==q2) {
			mat[i][0]=*pom1;
			mat[i][1]=f(*pom1);
			i++;
		}
		pom2=def;
		pom1++;
	} // upisuje prvu
	pom2=def;
	pom1=def1;
	int j(0);
	while (pom2!=q2) {
		while (pom1!=p2) {
			if(f(*pom2)==f(*pom1)) break;
			pom1++;
		}
		if(pom1==p2) {
			mat2[j][0]=*pom2;
			mat2[j][1]=f(*pom2);
			j++;
		}
		pom1=def1;
		pom2++;
	} //upisuje drugu
	
	Matrica glavna;
	glavna.resize(brojac+brojac2);
	for(int i(0); i<(brojac+brojac2); i++) {
		glavna[i].resize(2);
	}
	
	for(int i(0); i<brojac; i++) {
		for(int j(0); j<2; j++) {
			glavna[i][j]=mat[i][j];
		}
	}
	for(int i(0); i<brojac2; i++) {
		for(int j(0); j<2; j++) {
			glavna[i+brojac][j]=mat2[i][j];
		}
	}
	
	std::sort(glavna.begin(), glavna.end(), [] (Vector v1, Vector v2){
		if(v1[0]>v2[0]) return true;
		else if(v1[0]==v2[0]) {
			if(v1[1]>v2[1]) return true;
		}
		return false;
	});
	return glavna;
	
}
int main ()
{
	int br1,br2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>br1;
	std::vector<int> v1;
	v1.resize(br1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0); i<br1; i++) {
		int pom;
		greska: std::cin>>pom;
		for(int j(0); j<v1.size(); j++) {
			if(pom==v1[j]) goto greska;
		}
		 v1[i]=pom;
	}

	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>br2;
	std::vector<int>v2;
	v2.resize(br2);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0); i<br2; i++) {
		int pom;
		greska2: std::cin>>pom;
		for(int j(0); j<v2.size(); j++) {
			if(pom==v2[j]) goto greska2;
		}
		 v2[i]=pom;
	}

	std::vector<std::vector<int>> mat = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), [] (long long int n) {
		int suma(0);
		while (1) {
			suma+=(n%10);
			n/=10;
			if(n==0) break;
		}
		return suma;
	});
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j<3;j++) {
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	std::vector<std::vector<int>> raz = UvrnutaRazlika(&v1[0], &v1[br1], &v2[0], &v2[br2], [](long long int n){
	int brojac(0);
	long long int c=abs(n);
	for(int i(2); i<=abs(n); i++) {
			if(c%i==0){
				while (c%i==0) {
					brojac++;
					c/=i;
				}
			}
	}
	return brojac;
		
	});
	for(int i(0); i<raz.size(); i++) {
		for(int j(0); j<raz[i].size();j++) {
			std::cout<<std::setw(6)<<raz[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}