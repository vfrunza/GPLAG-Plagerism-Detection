/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <deque>   
#include <vector>
#include<cmath>
#include <iomanip>
int SumaCifara(long long int x ) {
	int s(0);
	while(x!=0) {
		s+=(x%10);
		x/=10;
	}
	return s;
}

int SumaDjelilaca(long long int x) {
	long long int pom(abs(x));
	int s(0);
	for(int i=1;i<=pom;i++) {
		if(pom%i==0) s+=i;
	}
	return s;
}

int BrojProstihFaktora(long long int x) {
	int s(0);
	for(int i=2;i<=x;i++) {
		if(x%i==0) {
			s++;
			x/=i;
		}
		while(x%i==0) {
			x/=i;
			s++;
		}
	}
	return s;
}

int BrojSavrsenihDjelilaca(long long int x) {
	int s(0),s1(0);
	long long int pom(abs(x));
	for(int i=1;i<=pom;i++) {
		s=0;
		if(pom%i==0) {
			for(int j=1; j<i; j++) {
				if(i%j==0) s+=j;
			}
			if(s==i) s1++;
		}
	}
	return s1;
}
template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
 auto UvrnutiPresjek (IterTip1 pocetak1, IterTip1 kraj1, IterTip2 pocetak2, IterTip2 kraj2, Tip2 f(Tip1)) -> 
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
 	int br(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		for (auto j=pocetak2; j!=kraj2; j++) {
 			if(f(*i)==f(*j)) br++;
 		}
 	} 	 
 	std::vector<std::vector<Tip2>> mat (br, std::vector<Tip2> (3));
 	int red(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		for (auto j=pocetak2; j!=kraj2; j++) {
 			if(f(*i)==f(*j)) {
 				mat[red][0]=*i;
 				mat[red][1]=*j;
 				mat[red][2]=f(*i);
 				red++;
 			}
 		} 
 	}
	std::sort(mat.begin(),mat.end(), [](std::vector<Tip2> x, std::vector<Tip2> y) {
		if(x[2]!=y[2]) return x[2]<y[2];
		else if(x[0]!=y[0]) return x[0]<y[0];
		else return x[1]<y[1];
	}); 
 	return mat;
}
template <typename IterTip1, typename IterTip2>
 auto UvrnutiPresjek (IterTip1 pocetak1, IterTip1 kraj1, IterTip2 pocetak2, IterTip2 kraj2) -> 
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
 	int br(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		for (auto j=pocetak2; j!=kraj2; j++) {
 			if(*i==*j) br++;
 		}
 	}
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat
 	(br, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (3));
 	int red(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		for (auto j=pocetak2; j!=kraj2; j++) {
 			if(*i==*j) {
 				mat[red][0]=*i;
 				red++;
 			}
 		} 
 	}
	std::sort(mat.begin(),mat.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> x,
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) {
		if(x[2]!=y[2]) return x[2]<y[2];
		else if(x[0]!=y[0]) return x[0]<y[0];
		else return x[1]<y[1];
	}); 
 	return mat;
}
template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
 auto UvrnutaRazlika (IterTip1 pocetak1, IterTip1 kraj1, IterTip2 pocetak2, IterTip2 kraj2, Tip2 f(Tip1)) -> 
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
 	int br(0);
for (auto i=pocetak1; i!=kraj1; i++) {
 		auto j(pocetak2);
 		for (j=pocetak2; j!=kraj2; j++) {
 			if(f(*i)==f(*j)) break;
 		}
 		if(j==kraj2) {
 			br++;
 		}
 	}
 	for (auto j=pocetak2; j!=kraj2; j++) {
 		auto i(pocetak1);
 		for (i=pocetak1; i!=kraj1; i++) {
 			if(f(*i)==f(*j)) break;
 		}
 		if(i==kraj1) {
 			br++;
 		}
 	}	
 	std::vector<std::vector<Tip2>> mat (br, std::vector<Tip2> (2));
 	int red(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		auto j(pocetak2);
 		for (j=pocetak2; j!=kraj2; j++) {
 			if(f(*i)==f(*j)) break;
 		}
 		if(j==kraj2) {
 			mat[red][0]=*i;
 			mat[red][1]=f(*i);
 			red++;
 		}
 	}
 	for (auto j=pocetak2; j!=kraj2; j++) {
 		auto i(pocetak1);
 		for (i=pocetak1; i!=kraj1; i++) {
 			if(f(*i)==f(*j)) break;
 		}
 		if(i==kraj1) {
 			mat[red][0]=*j;
 			mat[red][1]=f(*j);
 			red++;
 		}
 	}
	std::sort(mat.begin(), mat.end(), [](std::vector<Tip2> x, std::vector<Tip2> y) {
		if(x[0]!=y[0]) return x[0]>y[0];
		else return x[1]>y[1];
	}); 
 	return mat;
}
template <typename IterTip1, typename IterTip2>
 auto UvrnutaRazlika (IterTip1 pocetak1, IterTip1 kraj1, IterTip2 pocetak2, IterTip2 kraj2) -> 
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
 	int br(0);
for (auto i=pocetak1; i!=kraj1; i++) {
 		auto j(pocetak2);
 		for (j=pocetak2; j!=kraj2; j++) {
 			if(*i==*j) break;
 		}
 		if(j==kraj2) {
 			br++;
 		}
 	}
 	for (auto j=pocetak2; j!=kraj2; j++) {
 		auto i(pocetak1);
 		for (i=pocetak1; i!=kraj1; i++) {
 			if(*i==*j) break;
 		}
 		if(i==kraj1) {
 			br++;
 		}
 	}
 	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
 	mat (br, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> (2));
 	int red(0);
 	for (auto i=pocetak1; i!=kraj1; i++) {
 		auto j(pocetak2);
 		for (j=pocetak2; j!=kraj2; j++) {
 			if(*i==*j) break;
 		}
 		if(j==kraj2) {
 			mat[red][0]=*i;
 			red++;
 		}
 	}
 	for (auto j=pocetak2; j!=kraj2; j++) {
 		auto i(pocetak1);
 		for (i=pocetak1; i!=kraj1; i++) {
 			if(*i==*j) break;
 		}
 		if(i==kraj1) {
 			mat[red][0]=*j;
 			red++;
 		}
 	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>
	x, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> y) {
		return x[0]>y[0];
	}); 
 	return mat;
}
int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> dek1;
	bool ima(false);
	int x;
	int pom(n);
	for(auto j=0;j<pom;j++) {
		std::cin>>x;
		for(auto i=0;i<dek1.size();i++)
		if(x==dek1[i]) {ima=true; pom++; break;}
		if(!ima) dek1.push_back(x);
		ima=false;
	
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> dek2;
	bool ima1(false);
	int y;
	int pom1(m);
	for(auto j=0; j<pom1;j++) {
		std::cin>>y;
		for(auto i=0;i<dek2.size();i++) 
			if(y==dek2[i]) {
				ima1=true;
				pom1++;
				break;
			}
			if(!ima1) dek2.push_back(y);
			ima1=false;
	}
	std::vector<std::vector<int>> mat=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0;i<mat.size();i++) {
		for(int j=0;j<3;j++) {
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::vector<std::vector<int>> mat2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0;i<mat2.size();i++) {
		for(int j=0;j<2;j++) {
			std::cout<<std::setw(6)<<mat2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}