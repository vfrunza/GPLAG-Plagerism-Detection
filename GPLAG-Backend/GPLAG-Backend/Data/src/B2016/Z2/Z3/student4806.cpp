/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <algorithm>

int SumaCifara(int n){
	int suma(0);
	while (n>0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int n){
	int brojac(0);
	for(int i=1;i<=n;i++){
		if(n%i==0) brojac+=i;
	}
	
	return brojac;
}

bool Prost(int n){
	for(int i=2;i<n/2-1;i++){
		if(n%i==0) return false;
	}
	return true;
	
}
int BrojProstihFaktora(long long int n){
	int brojac(0);
	for(int i=2;i<n;i++){
		if(n%i==0 && Prost(i)==true) brojac++;
	}
	return brojac;
}




template<typename Tip1 ,typename Tip2,typename Tip>
std::vector<std::vector<Tip>>  UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4, Tip fun(Tip)){
		int n(0);
		Tip2 pom(p3);
		Tip1 pom1(p1);
		Tip1 pom2(p2);
		Tip2 pom3(p3);
		Tip2 pom4(p4);
		
		while(pom1!=pom2){
			pom3=p3;
			while(pom3!=pom4){
				if(fun(*pom1)==fun(*pom3))
					n++;
					pom3++;
				
			}
			pom1++;
		}
	//	typename std::remove_reference<decltype (p1[0])>::type ** mat=new typename std::remove_reference<decltype (p1[0])>::type *[n];
	//for(int i=0;i<n;i++) mat[i]=new typename std::remove_reference<decltype (p1[0])>::type[3];
		std::vector<std::vector<Tip>> mat(n,std::vector<Tip>(3));
		
		int brojac1(0);
		while(p1!=p2){
			p3=pom;
			while(p3!=p4){
				if(fun(*p1)==fun(*p3)){
					mat[brojac1][0]=*p1;
					mat[brojac1][1]=*p3;
					mat[brojac1][2]=fun(*p1);
					brojac1++;
				}
				p3++;
			}
			p1++;
		}
		
		std::sort(mat,mat+n,[](typename std::remove_reference<decltype (p1[0])>::type *a,typename std::remove_reference<decltype (p1[0])>::type *b){
							if(a[2]==b[2] && a[1]==b[1]) return a[0]<b[0];
							else if(a[2]==b[2]) return a[1]<b[1];
							return a[2]<b[2];
		});
		
		return mat;
}

	template<typename Tip1 ,typename Tip2>
auto UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4)-> typename std::remove_reference<decltype (p1[0])>::type **{
		int n(0);
		Tip2 pom(p3);
		Tip1 pom1(p1);
		Tip1 pom2(p2);
		Tip2 pom3(p3);
		Tip2 pom4(p4);
		
		while(pom1!=pom2){
			pom3=p3;
			while(pom3!=pom4){
				if(*pom1==*pom3)
					n++;
					pom3++;
				
			}
			pom1++;
		}
		typename std::remove_reference<decltype (p1[0])>::type ** mat=new typename std::remove_reference<decltype (p1[0])>::type *[n];
		for(int i=0;i<n;i++) mat[i]=new typename std::remove_reference<decltype (p1[0])>::type[3];
		int brojac1(0);
		while(p1!=p2){
			p3=pom;
			while(p3!=p4){
				if(*p1==*p3){
					mat[brojac1][0]=*p1;
					mat[brojac1][1]=0;
					mat[brojac1][2]=0;
					brojac1++;
				}
				p3++;
			}
			p1++;
		}
		
		std::sort(mat,mat+n,[](typename std::remove_reference<decltype (p1[0])>::type *a,typename std::remove_reference<decltype (p1[0])>::type *b){
							return a[0]<b[0];
		});
		
		
		
		
		return mat;
}



template<typename Tip1 ,typename Tip2,typename Tip>
std::vector<std::vector<Tip1>> UvrnutaRazlika(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4, Tip fun(Tip)) {
		int n(0);
		Tip2 pom(p3);
		Tip1 pom1(p1);
		Tip1 pom2(p2);
		Tip2 pom3(p3);
		Tip2 pom4(p4);
		
		while(pom1!=pom2){
			pom3=p3;
			while(pom3!=pom4){
				if(fun(*pom1)!=fun(*pom3)){
					n++;
					break;
				}
					pom3++;
				
			}
			pom1++;
		}
		//typename std::remove_reference<decltype (p1[0])>::type ** mat=new typename std::remove_reference<decltype (p1[0])>::type *[n];
		//for(int i=0;i<n;i++) mat[i]=new typename std::remove_reference<decltype (p1[0])>::type[2];
		std::vector<std::vector<Tip1>> mat(n,std::vector<Tip1>(3));
		int brojac1(0);
		while(p1!=p2){
			p3=pom;
			while(p3!=p4){
				if(fun(*p1)!=fun(*p3)){
					mat[brojac1][0]=*p1;
					mat[brojac1][1]=fun(*p1);
					brojac1++;
					break;
				}
				p3++;
			}
			p1++;
		}
		
		std::sort(mat.begin(),mat.end(),[](typename std::remove_reference<decltype (p1[0])>::type *a,typename std::remove_reference<decltype (p1[0])>::type *b){
							if(a[0]==b[0]) return a[1]>b[1];
							return a[0]>b[0];
		});
		
		return mat;
}
int main ()
{
	
/*	std::deque<int> a{12,44,55,66,2,17};
	std::deque<int> b{21,53,55,89,2,71};
//	auto mat(UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end()));
	int n(0);
	auto mat1(UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),SumaCifara));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(SumaCifara(a[i])!=SumaCifara(b[j])){
				n++;
				break;
			} 
		}
		
	}
	std::cout<<"n= "<<n<<std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			std::cout<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<n;i++){
		delete[] mat1[i];
	}
	delete[] mat1;*/
	
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> a;
	int broj;
	for(int i=0;i<n;i++){
		std::cin>>broj;
		a.push_back(broj);
		for(int j=0;j<i;j++) if(broj==a[j]) std::remove(a.begin(),a.end(),broj);
		
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> b;
	for(int i=0;i<m;i++){
		std::cin>>broj;
		b.push_back(broj);
		for(int j=0;j<i;j++) if(broj==b[j]) std::remove(b.begin(),b.end(),broj);
	} 
	std::cout<<"Uvrnuti presjek kontejnera: ";
	//std::vector<std::vector<int>> v(UvrnutiPresjek,a.begin(),a.end(),b.begin(),b.end(),SumaCifara);
		std::vector<std::vector<int>> s{UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),SumaCifara)};
	
	return 0;
}