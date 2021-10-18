#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
#include <cmath>
int SumaDjelilaca(long long n)
{
	int suma(0);
	for(int i=1; i<=fabs(n); i++) {
		if(n%i==0)
			suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int n)
{
	int broj(0);
	for(int i=2; i<=fabs(n); i++) {
		if(n%i==0) {
			broj++;
			n/=i;
			i--;
		}
	}
	return broj;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	int broj(0);
	for(int i=2; i<=n; i++) {
		if(n%i==0) {
			int suma(SumaDjelilaca(i)-i);
			if(i==suma)
				broj++;
		}
	}
	return broj;
}

int SumaCifara(long long int x)
{
	int suma(0);
	while(x!=0) {
		int c(x%10);
		suma+=c;
		x/=10;
	}
	return suma;
}


template <typename Tip1, typename Tip2, typename TipF>

auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 x1, Tip2 x2, TipF f) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	typedef typename std::remove_reference<decltype(*p1)>::type Tip;
	int n(0);
	Tip1 q1(p1);
	Tip1 q2(p2);
	Tip2 y1(x1);
	Tip2 y2(x2);
	for(int i=0; i<p2-p1; i++) {
		Tip2 y1(x1);
		for(int j=0; j<x2-x1; j++) {
			if(f(*q1)==f(*y1))

				n++;
			y1++;
		}
		q1++;
	}
	std::vector<std::vector<Tip>> matrica(n);
	int duzina(0);
	q1=p1;
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		for(int j=0; j<x2-x1; j++) {
			if(f(*q1)==f(*y1)) {
				matrica[duzina].push_back(*q1);
				matrica[duzina].push_back(*y1);
				matrica[duzina].push_back(f(*q1));
				duzina++;
			}
			y1++;
		}
		q1++;
	}
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<Tip> &v1, const std::vector<Tip> &v2) {
		if(v1[2]==v2[2] && v1[0]==v2[0])
			return v1[1]<v2[1];
		if(v1[2]==v2[2]) {
			return v1[0]<v2[0];
		}
		return v1[2]<v2[2];
	});



	return  matrica;
}
template <typename Tip1, typename Tip2, typename TipF, typename TipA>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 x1, Tip2 x2, TipF f(TipA x)) ->  typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	typedef typename std::remove_reference<decltype(*p1)>::type Tip;
	int n(0);
	Tip1 q1(p1);
	Tip1 q2(p2);
	Tip2 y1(x1);
	Tip2 y2(x2);
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		while(y1!=y2) {
			if(f(*q1)==f(*y1))
				break;
			y1++;
		}
		if(y1==y2)
			n++;
		q1++;
	}
	int n2(0);
	y1=x1;
	for(int i=0; i<x2-x1; i++) {
		q1=p1;
		while(q1!=p2) {
			if(f(*q1)==f(*y1))
				break;
			q1++;
		}
		if(q1==p2)
			n2++;
		y1++;
	}
	std::vector<std::vector<Tip>> matrica(n+n2);
	int duzina(0);
	q1=p1;
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		while(y1!=x2) {
			if(f(*q1)==f(*y1))
				break;
			y1++;
		}
		if(y1==x2) {
			matrica[duzina].push_back(*q1);
			matrica[duzina].push_back(f(*q1));
			duzina++;
		}
		q1++;
	}
	y1=x1;
	for(int i=0; i<x2-x1; i++) {
		q1=p1;
		while(q1!=p2) {
			if(f(*q1)==f(*y1))
				break;
			q1++;
		}
		if(q1==p2) {
			matrica[duzina].push_back(*y1);
			matrica[duzina].push_back(f(*y1));
			duzina++;
		}
		y1++;
	}
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<Tip> &v1, const std::vector<Tip> &v2) {
		if(v1[0]==v2[0])
			return v1[1]>v1[2];
		return v1[0]>v2[0];
	});
	return matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 x1, Tip2 x2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	typedef typename std::remove_reference<decltype(*p1)>::type Tip;
	int n(0);
	Tip1 q1(p1);
	Tip1 q2(p2);
	Tip2 y1(x1);
	Tip2 y2(x2);
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		for(int j=0; j<x2-x1; j++) {
			while(y1!=x2) {
				if(*q1==*y1)
					n++;
				y1++;
			}
		}
		q1++;
	}

	std::vector<std::vector<Tip>> matrica(n, std::vector<Tip>(3));
	int duzina(0);
	q1=p1;
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		for(int j=0; j<x2-x1; j++) {
			if(*q1==*y1) {
				matrica[duzina][0]=*q1;
				duzina++;
			}
			y1++;
		}
		q1++;
	}
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<Tip> &v1, const std::vector<Tip> &v2) {
		if(v1[2]==v2[2] && v1[0]==v2[0])
			return v1[1]<v2[1];
		if(v1[2]==v2[2]) {
			return v1[0]<v2[0];
		}
		return v1[2]<v2[2];
	});



	return  matrica;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 x1, Tip2 x2) ->  typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	typedef typename std::remove_reference<decltype(*p1)>::type Tip;
	int n(0);
	Tip1 q1(p1);
	Tip1 q2(p2);
	Tip2 y1(x1);
	Tip2 y2(x2);
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		while(y1!=y2) {
			if(*q1==*y1)
				break;
			y1++;
		}
		if(y1==y2)
			n++;
		q1++;
	}
	int n2(0);
	y1=x1;
	for(int i=0; i<x2-x1; i++) {
		q1=p1;
		while(q1!=p2) {
			if(*q1==*y1)
				break;
			q1++;
		}
		if(q1==p2)
			n2++;
		y1++;
	}
	std::vector<std::vector<Tip>> matrica(n+n2, std::vector<Tip>(2));
	int duzina(0);
	q1=p1;
	for(int i=0; i<p2-p1; i++) {
		y1=x1;
		while(y1!=x2) {
			if(*q1==*y1)
				break;
			y1++;
		}
		if(y1==x2) {
			matrica[duzina][0]=*q1;
			duzina++;
		}
		q1++;
	}
	y1=x1;
	for(int i=0; i<x2-x1; i++) {
		q1=p1;
		while(q1!=p2) {
			if(*q1==*y1)
				break;
			q1++;
		}
		if(q1==p2) {
			matrica[duzina][0]=*y1;
			duzina++;
		}
		y1++;
	}
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<Tip> &v1, const std::vector<Tip> &v2) {
		if(v1[0]==v2[0])
			return v1[1]>v1[2];
		return v1[0]>v2[0];
	});
	return matrica;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	std::deque<int> k1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int a;
	int j;
	for(int i=0; i<n; i++) {
		std::cin >> a;
		if(i==0) k1.push_back(a);

		else {
			for(j=0; j<i; j++) {
				if(k1[j]==a)
					break;
			}
			if(j==i)
				k1.push_back(a);
			else i--;
		}
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::deque<int> k2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n; i++) {
		std::cin >> a;
		if(i==0) k2.push_back(a);
		else {
			for(j=0; j<i; j++) {
				if(k2[j]==a)
					break;
			}
			if(j==i)
				k2.push_back(a);
			else i--;
		}
	}
	std::cout << "Uvrnuti presjek kontejnera:" ;
	auto m=UvrnutiPresjek(std::begin(k1), std::end(k1), std::begin(k2), std::end(k2), SumaCifara);
	for(int i=0; i<m.size(); i++) {
		std::cout << std::endl;
		for(int j=0; j<m[1].size(); j++)
			std::cout << std::setw(6) << m[i][j] << " ";
	}

	auto x2=UvrnutaRazlika(std::begin(k1), std::end(k1), std::begin(k2), std::end(k2), BrojProstihFaktora);
	std::cout <<std:: endl <<  "Uvrnuta razlika kontejnera:";
	for(int i=0; i<x2.size(); i++) {
		std::cout << std::endl;
		for(int j=0; j<x2[0].size(); j++)
			std::cout << std::setw(6) << x2[i][j] <<" ";
	}
	std::cout << std::endl;
	std::cout << "Dovidjenja!";
	
	
	
 
return 0;
}