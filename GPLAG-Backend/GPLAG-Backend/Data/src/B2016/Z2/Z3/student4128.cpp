#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
int SumaCifara(long long int n) {
	if(n<0) n=abs(n);
	int suma(0);
	while(n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}
bool savrsen(long long int n) {
	int suma=0;
	
	for(int i(1);i<n;i++) {
		if(n%i==0) {
			suma+=i;
		}
	}
	if(suma==n) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n) {
	if(n<0) n=abs(n);
	int brojac=0;
	for(int i=1;i<=n;i++) {
		if(n%i==0 && savrsen(i)) brojac++;
	}
	return brojac;
}
int SumaDjelilaca(long long int n) {
	int suma=0;
	if(n<0) n=abs(n);
	for(int i(1);i<=n;i++) {
		if(n%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n) {
	int br(0);
	if(n<0) n=abs(n);
	for(int i(2);i<=n;i++) {
		if(n%i==0) {
			while(n%i==0) {
			br++;
			n/=i;
			}
	}
	}
	return br;
}
template <typename tip1, typename tip2,  typename tip3>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 q1, tip2 q2, tip3 f ) ->std::vector<std::vector<decltype(*p1+*q1)>>{
	std::vector<std::vector<decltype(*p1+*q1)>> M;
	int n=1,i=0;
	while(p1!=p2) {
		tip2 cuvaj=q1;
		while(q1!=q2) {
			if(f(*p1)==f(*q1)) {
			    M.resize(n);
				M[i].resize(3);
					M[i][0]=*p1;
					M[i][1]=*q1;
					M[i][2]=f(*p1);
					i++;
						n++;
			}
			q1++;
		}
		
		q1=cuvaj;
		p1++;
	}
	std::sort(M.begin(),M.end(),[](std::vector<decltype(M[0][0]+M[0][0])> V1, std::vector<decltype(M[0][0]+M[0][0])> V2 ) {
		if(V1[2]<V2[2]) return true;
		if(V1[2]==V2[2]) {
			if(V1[0]<V2[0]) return true;
			if(V1[0]==V2[0]) {
				if(V1[1]<V2[1]) return true;
			}
		}
		return false;
	});
	return M;
}
template <typename tip, typename tips>
auto UvrnutiPresjek(tip p1, tip p2, tips q1, tips q2)-> std::vector<std::vector<decltype(*p1+*q1)>>{
	std::vector<std::vector<decltype(*p1+*q1)>> M;
	int n=1,i=0;
	while(p1!=p2) {
		tips cuvaj=q1;
		while(q1!=q2) {
			if(*p1==*q1) {
			    M.resize(n);
				M[i].resize(3);
					M[i][0]=*p1;
					M[i][1]=0;
					M[i][2]=0;
					i++;
						n++;
			}
			q1++;
		}
		
		q1=cuvaj;
		p1++;
	}
	std::sort(M.begin(),M.end(),[](std::vector<decltype(M[0][0]+M[0][0])> V1, std::vector<decltype(M[0][0]+M[0][0])> V2 ) {
		if(V1[0]<V2[0]) return true;
		
		return false;
	});
	return M;
}
template <typename Tip1, typename Tip2,  typename Tip3>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 q1, Tip2 q2, Tip3 f )-> std::vector<std::vector<decltype(*p1+*q1)>>{
	std::vector<std::vector<decltype(*p1+*q1)>>M;
	int n=1,i=0;
	Tip1 tmp=p1;
	Tip2 temp=q1;
	while(p1!=p2) {
		Tip2 cuvaj=q1;
		bool nema=true;
		while(q1!=q2) {
			if(f(*p1)==f(*q1))  {
				nema=false;
				break;
			}
			q1++;
		}
		if(nema && f(*p1)!=0) {
		M.resize(n);
		M[i].resize(2);
		M[i][0]=*p1;
		M[i][1]=f(*p1);
		i++;
		n++;
		}
		q1=cuvaj;
		p1++;
	}
	
	p1=tmp;
	q1=temp;
		while(q1!=q2) {
		Tip1 cuvaj=p1;
		bool nema=true;
		while(p1!=p2) {
			if(f(*q1)==f(*p1))  {
				nema=false;
				break;
			}
			p1++;
		}
		if(nema) {
		M.resize(n);
		M[i].resize(2);
		M[i][0]=*q1;
		M[i][1]=f(*q1);
		i++;
		n++;
		}
		p1=cuvaj;
		q1++;
	}
	std::sort(M.begin(),M.end(),[](std::vector<decltype(M[0][0]+M[0][0])> V1, std::vector<decltype(M[0][0]+M[0][0])> V2 ) {
		if(V1[0]>V2[0]) return true;
		if(V1[0]==V2[0]) {
			if(V1[1]>V2[1]) return true;
			
		}
		return false;
	});
	return M;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 q1, Tip2 q2 )->std::vector<std::vector<decltype(*p1+*q1)>> {
	std::vector<std::vector<decltype(*p1+*q1)>>M;
	int n=1,i=0;
	Tip1 tmp=p1;
	Tip2 temp=q1;
	while(p1!=p2) {
		Tip2 cuvaj=q1;
		bool nema=true;
		while(q1!=q2) {
			if(*p1==*q1)  {
				nema=false;
				break;
			}
			q1++;
		}
		if(nema) {
		M.resize(n);
		M[i].resize(2);
		M[i][0]=*p1;
		M[i][1]=0;
		i++;
		n++;
		}
		q1=cuvaj;
		p1++;
	}
	
	p1=tmp;
	q1=temp;
		while(q1!=q2) {
		Tip1 cuvaj=p1;
		bool nema=true;
		while(p1!=p2) {
			if(*q1==*p1)  {
				nema=false;
				break;
			}
			p1++;
		}
		if(nema) {
		M.resize(n);
		M[i].resize(2);
		M[i][0]=*q1;
		M[i][1]=0;
		i++;
		n++;
		}
		p1=cuvaj;
		q1++;
	}
	std::sort(M.begin(),M.end(),[](std::vector<decltype(M[0][0]+M[0][0])> V1, std::vector<decltype(M[0][0]+M[0][0])> V2 ) {
		if(V1[0]>V2[0]) return true;
	
		
		return false;
	});
	return M;
}

int main ()
{
	
		std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<int> kon1;
	int p;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0);i<n;i++) {
		
		std::cin>>p;
		bool nema=true;
		for(int j(0);j<i;j++) {
		    if(p==kon1[j]) {nema=false;
		    i--;
		    }
		}
		if(nema) kon1.push_back(p);
	}
		std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int k;
	std::cin>>k;
	std::deque<int> kon2;
	int d;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0);i<k;i++) {
		
		std::cin>>d;
		bool nema=true;
		for(int j(0);j<i;j++) {
		    if(d==kon2[j]) {nema=false;
		    i--;
		    }
		}
		if(nema) kon2.push_back(d);
	}
	std::vector<std::vector<int>>M;
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	M=UvrnutiPresjek(kon1.begin(),kon1.end(),kon2.begin(),kon2.end(),SumaCifara);
	for(int i(0);i<M.size();i++) {
		for(int j(0);j<M[i].size();j++) {
			std::cout<<std::setw(6)<<M[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::vector<std::vector<int>> N;
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	N=UvrnutaRazlika(kon1.begin(),kon1.end(),kon2.begin(),kon2.end(),BrojProstihFaktora);
	for(int i(0);i<N.size();i++) {
		for(int j(0);j<N[i].size();j++) {
			std::cout<<std::setw(6)<<N[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}