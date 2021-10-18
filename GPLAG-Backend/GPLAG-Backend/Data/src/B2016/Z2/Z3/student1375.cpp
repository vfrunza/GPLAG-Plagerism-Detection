/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <deque>

int SumaDjelilaca (long long int n) {
	int suma(0);
	n=abs(n);
	for(int i=1;i<=n;i++) {
		if(n%i==0) suma+=i;
	}
	return suma;
}


int BrojProstihFaktora (long long int n) {
	int broj(0), prvi(2);
	n=abs(n);
	while(n>1) {
		if(n%prvi==0) {
			broj++;
			n/=prvi;
		} else prvi++;
	}
	return broj;
}

int BrojSavrsenihDjelilaca (long long int n) {
	int broj(0);
	n=abs(n);
	for(int i=2;i<=n;i++) {
		if(n%i==0) {
			if(i==SumaDjelilaca(i)-i) broj++;
		}
	}
	return broj;
}

int SumaCifara (long long int n) {
	int suma(0),c; 
	while(n>0) {
		c=n%10;
		suma+=c;
		n/=10;
	}
	return suma;
}

template<typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(NekiTip1 pocetak1, NekiTip1 kraj1, NekiTip2 pocetak2, NekiTip2 kraj2, int fun (long long int)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	int n(0);
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
	while(pocetak1!=kraj1) {
		NekiTip2 p(pocetak2);
		while(p!=kraj2) {
			if(fun(*pocetak1)==fun(*p)) {
				v.push_back(*pocetak1);
				v.push_back(*p);
				v.push_back(fun(*pocetak1));
				n++;
			}
			p++;
		}
		pocetak1++;
	}
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat(n, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (3));
	int brojac(0);
	for(int i=0;i<n;i++) {
		mat[i][0]=v[brojac];
		brojac++;
		mat[i][1]=v[brojac];
		brojac++;
		mat[i][2]=v[brojac];
		brojac++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> x , std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) { 
		if(x[2]==y[2]) {
			if(x[0]==y[0]) {
				return x[1]<y[1];
			} else return x[0]<y[0];
		} else return x[2]<y[2];
	});
	return mat;
}

template<typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(NekiTip1 pocetak1, NekiTip1 kraj1, NekiTip2 pocetak2, NekiTip2 kraj2, int fun(long long int)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
	int n(0);
	bool razlika;
	NekiTip2 p2;
	NekiTip1 p1(pocetak1);
	while(p1!=kraj1) {
		razlika=true;
		p2=pocetak2;
		while(p2!=kraj2) {
			if(fun(*p1)==fun(*p2)) {
				razlika=false;
				break;
			}
			p2++;
		}
		if(razlika) {
			v.push_back(*p1);
			v.push_back(fun(*p1));
			n++;
		}
		p1++;
	}
	NekiTip1 s1;
	NekiTip2 s2(pocetak2);
	while(s2!=kraj2) {
		razlika=true;
		s1=pocetak1;
		while(s1!=kraj1) {
			if(fun(*s1)==fun(*s2)) {
				razlika=false;
				break;
			}
			s1++;
		}
		if(razlika) {
			v.push_back(*s2);
			v.push_back(fun(*s2));
			n++;
		}
		s2++;
	}
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat(n,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (2));
	for(int i=0;i<n;i++) {
		mat[i][0]=v[brojac];
		brojac++;
		mat[i][1]=v[brojac];
		brojac++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> x , std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) { 
		if(x[0]==y[0]) {
			return x[1]>y[1];
		} else return x[0]>y[0];
	});
	return mat;
}

template<typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(NekiTip1 pocetak1, NekiTip1 kraj1, NekiTip2 pocetak2, NekiTip2 kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
	int n(0);
	while(pocetak1!=kraj1) {
		NekiTip2 p(pocetak2);
		while(p!=kraj2) {
			if(*pocetak1==*p) {
				v.push_back(*pocetak1);
				v.push_back(0);
				v.push_back(0);
				n++;
			}
		p++;
		}
	pocetak1++;
	}
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat(n, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (3));
	int brojac(0);
	for(int i=0;i<n;i++) {
		mat[i][0]=v[brojac];
		brojac++;
		mat[i][1]=v[brojac];
		brojac++;
		mat[i][2]=v[brojac];
		brojac++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> x , std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) { 
		if(x[2]==y[2]) {
			if(x[0]==y[0]) {
		  		return x[1]<y[1];
			} else return x[0]<y[0];
		} else return x[2]<y[2];
	});
	return mat;
}

template<typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(NekiTip1 pocetak1, NekiTip1 kraj1, NekiTip2 pocetak2, NekiTip2 kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
	int n(0);
	bool razlika;
	NekiTip2 p2;
	NekiTip1 p1(pocetak1);
	while(p1!=kraj1) {
		razlika=true;
		p2=pocetak2;
		while(p2!=kraj2) {
			if(*p1==*p2) {
				razlika=false;
				break;
			}
			p2++;
		}
		if(razlika) {
			v.push_back(*p1);
			v.push_back(0);
			n++;
		}
		p1++;
	}
	NekiTip1 s1;
	NekiTip2 s2(pocetak2);
	while(s2!=kraj2) {
		razlika=true;
		s1=pocetak1;
		while(s1!=kraj1) {
			if(*s1==*s2) {
				razlika=false;
				break;
			}
			s1++;
		}
		if(razlika) {
			v.push_back(*s2);
			v.push_back(0);
			n++;
		}
		s2++;
	}
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat(n,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (2));
	for(int i=0;i<n;i++) {
		mat[i][0]=v[brojac];
		brojac++;
		mat[i][1]=v[brojac];
		brojac++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> x , std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) { 
		if(x[0]==y[0]) {
			return x[1]>y[1];
		} else return x[0]>y[0];
	});
	return mat;
}

int main ()
{
	int n1,n2;
	std::deque<int> v1,v2;	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int x;
	for(int i=0;i<n1;i++) {
		std::cin >> x;
		bool ima(false);
		if(i==0) {
			v1.push_back(x);
			continue;
		}
		for(int j=0;j<v1.size();j++) {
			if(v1[j]==x) {
				n1++;
				ima=true;
				break;
			}
		}
		if(ima) continue;
		else v1.push_back(x);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++) {
		std::cin >> x;
		bool ima(false);
		if(i==0) {
			v2.push_back(x);
			continue;
		}
		for(int j=0;j<v2.size();j++) {
			if(v2[j]==x) {
				n2++;
				ima=true;
				break;
			}
		}
		if(ima) continue;
		else v2.push_back(x);
	}
	auto mat(UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara));
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for(int i=0;i<mat.size();i++) {
		for(int j=0;j<mat[0].size();j++) {
			std::cout << std::setw(6) <<  mat.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	auto mat2(UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora)) ;
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(int i=0;i<mat2.size();i++) {
		for(int j=0;j<mat2[0].size();j++) {
			std::cout << std::setw(6) << mat2.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!" << std::endl;

	return 0;
}