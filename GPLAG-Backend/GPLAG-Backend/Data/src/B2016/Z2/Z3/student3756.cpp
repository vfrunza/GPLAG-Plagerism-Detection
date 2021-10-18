/*B 16/17, Zadaća 2, Zadatak 3
	NAPOMENA: i javni ATo-vi su dio postavke
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <cmath>

int fun(long long int par){
	int cif,suma(0);
	while(par!=0){
		cif=par%10;
		suma=suma+cif;
		par=par/10;
	}
	return suma;
}

int SumaDjelilaca(long long int a){
	int suma(0);
	int x=abs(a);
	for(int i=1;i<=x;i++){
        if(x%i==0) {
        	suma=suma+i;
	}
	}
  return suma;
}

int BrojProstihFaktora(long long int a){
 	int br(0);
	int b;
    int k=a%2;
while(k==0){
        b=a/2;
       br++;
        a=b;
        k=a%2;
    } 
for(int j=3;j<=a;j+=2){
    int k=a%j;
        while(k==0){
            b=a/j;
            br++;
            a=b;
            k=a%j;}
}
	return br;  
}

bool jelsavrsen(long long int a){
	int s(0);
	for(int i=1;i<a;i++)
		if(!(a%i)) s=s+i;
	if(s==a) return true;
	return false;
}
	
int BrojSavrsenihDjelilaca(long long int a){
	int br(0);
	for(int i=1;i<=a;i++){
		if(a%i==0) {
			if(jelsavrsen(i)) br++;
	}
	}
	return br;
}

template<typename tip1, typename tip2>
std::vector<std::vector<int>> UvrnutiPresjek(tip1 poc,tip1 izakraja,tip2 poc2, tip2 izakraja2,int f(long long int)){
    std::vector<std::vector<int>> mat;
	int k=0;
	tip1 pocetno=poc2;

	while(poc!=izakraja){
		poc2=pocetno;
		while(poc2!=izakraja2){
			if(f(*poc)==f(*poc2)){
				mat.resize(k+1);
				mat[k].resize(3);
			
				mat[k][0]=(*poc);
				mat[k][1]=(*poc2);
				mat[k][2]=f(*poc2);
				k++;
			}
			poc2++;
		}
		poc++;
	} 
	std::sort(mat.begin(),mat.end(),
	[](const std::vector<int> &m1,const std::vector<int> &m2)
	{
		 if(m1[2]==m2[2] && m1[0]!=m2[0]) return m1[0]<m2[0];
		else if(m1[2]==m2[2] && m1[0]==m2[0]) return m1[1]<m2[1];
		else return m1[2] < m2[2];
	});
	mat.erase(std::unique(mat.begin(),mat.end()),mat.end());
return mat;
}

template <typename tip1, typename tip2>
std::vector<std::vector<int>> UvrnutaRazlika(tip1 poc, tip1 izakraja, tip2 poc2, tip2 izakraja2,int f(long long int)){

   std::vector<std::vector<int>> mat;
	int k=0;
	tip1 pocetno2=poc2;
	tip1 pocetno1=poc;
	tip1 pocetkraj=izakraja;
	tip1 pocetkraj2=izakraja2;
	tip1 pom=poc;

	while(poc!=izakraja){
	int br(0);
		poc2=pocetno2;
		while(poc2!=izakraja2){
			if(f(*poc)==f(*poc2)){
				br++;}
					poc2++;
			}
            if(br==0 && *poc>0){
				mat.resize(k+1);
				mat[k].resize(2);
			
				mat[k][0]=(*poc);
				mat[k][1]=f(*poc);
				k++;
			}
		poc++;
} 
	while(pocetno2!=pocetkraj2){
	int br(0);
		pocetno1=pom;
	
		while(pocetno1!=pocetkraj){
			if(f(*pocetno1)==f(*pocetno2))
				br++;
					pocetno1++;
			}
            if(br==0 && *pocetno2>0){
				mat.resize(k+1);
				mat[k].resize(2);
			
				mat[k][0]=(*pocetno2);
				mat[k][1]=f(*pocetno2);
				k++;
			}
		pocetno2++;
}  
   std::sort(mat.begin(),mat.end(),
	[](const std::vector<int> &m1,const std::vector<int> &m2)
	{
	 return m1[0] > m2[0];
	});
	mat.erase(std::unique(mat.begin(),mat.end()),mat.end());
	return mat;
}

int main ()
{
	int n,m;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	
	std::vector<int>v;
	while(v.size()!=n){
		int broj;
		std::cin>>broj;
		bool ima=false;
		for(auto j=v.begin();j<v.end();j++){
			if(*j==broj) ima=true;
		}
        if(!ima)
		v.push_back(broj);
	}

	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::vector<int>v2;
	while(v2.size()!=m){
		int broj;
		std::cin>>broj;
		bool ima=false;
		for(auto j=v2.begin();j<v2.end();j++){
			if(*j==broj) ima=true;
		}
		if(!ima)
		v2.push_back(broj);
	}

	std::cout<<"Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> mat(0,std::vector<int>(3));
	mat=UvrnutiPresjek(v.begin(),v.end(),v2.begin(),v2.end(),fun);
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<3;j++){
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		std::cout<<"\n";
	}
   std::cout<<"Uvrnuta razlika kontejnera:\n";
	std::vector<std::vector<int>> mat2(0,std::vector<int>(2));
	mat2=UvrnutaRazlika(v.begin(),v.end(),v2.begin(),v2.end(),BrojProstihFaktora);
	for(int i=0;i<mat2.size();i++){
		for(int j=0;j<2;j++){
			std::cout<<std::setw(6)<<mat2[i][j]<<" ";
		}
		std::cout<<"\n";
	} 
	std::cout<<"Dovidjenja!";

	return 0;
}