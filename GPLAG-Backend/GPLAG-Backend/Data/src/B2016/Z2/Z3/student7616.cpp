/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include <complex>

int SumaCifara(long long int broj)
{
	int suma=0;
	while(broj!=0)
	{
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}
long long int SumaDjelilaca(long long int broj)
{
	long long int suma(0);
	for(int i=1; i<=broj; i++)
	{
		if(broj%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n)
{
	int br(0);
	int a,pom(n);
	pom = n%2;
	while(pom==0)
	{
		a=n/2;
		br++;
		n=a;
		pom=n%2;
	}
	for(int i=3; i<=n;i+=2)
	{
		int p(n%i);
		while(p==0)
		{
			a=n/i;
		    br++;
			n=a;
			p=n%i;
		}
	}
	return br;
}

bool Savrsen(int n)
{
	bool cs(false);
	int s(0);
	for(int i=1; i<n; i++)
	{
		if(n%i==0) s+=i;
	}
	if(n==s) cs=true;
	if(cs) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int br(0);
	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
		{
			if(Savrsen(i))
			{
				br++;
			}
		}
	}
	return br;
}
template <typename Tip1, typename Tip2, typename Funkcija>

	auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Funkcija f) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
	{
		std::vector<typename std::remove_reference<decltype(*p1)>::type> v1,v2,v3;
		while(p1!=p2)
		{
			Tip2 pom=p3;
			while(pom!=p4)
			{
				if(f(*pom) == f (*p1))
				{
					v1.push_back(*p1);
					v2.push_back(*pom);
					v3.push_back(f(*p1));
				}
				pom++;
			}
			p1++;
		}
		
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat(v1.size(), std::vector<typename std::remove_reference<decltype(*p1)>::type>(3));
		int j=0;
		for(int i=0; i<mat.size(); i++)
		{
			mat[i][0]=v1[j];
			mat[i][1]=v2[j];
			mat[i][2]= v3[j];
			j++;
		}
		std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type>v1,std::vector<typename std::remove_reference<decltype(*p1)>::type> v2)
		{
			if(v1[0]==v2[0]) return v1[1]>v2[1];
			return v1[0] < v2[0];
		});
		return mat;
	}
	template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)
    -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	std::vector<typename std::remove_reference<decltype(*p1)>::type> v1;
	while(p1 != p2){
        Tip2 pom = p3;
        while(pom != p4){
                if(*pom == *p1){
                    v1.push_back(*p1);
                }
            pom++;
        }
        p1++;
	}

std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> mat(v1.size(),
                        std::vector<typename std::remove_reference<decltype(*p1)>::type>(3));
	int j = 0;
        for(int i = 0; i < mat.size(); i++){
             mat[i][0] =  v1[j];
                mat[i][1] = 0;
                mat[i][2] = 0;
            j++;
        }
      
   std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> v1,
                                      std::vector<typename std::remove_reference<decltype(*p1)>::type> v2){
             if(v1[0] == v2[0])return v1[1] > v2[1];
             return v1[0] < v2[0];
             });
	return mat;
}
	
	
template <typename Tip1, typename Tip2,typename Funkcija>
auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Funkcija f)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, v2 ;
	auto mat= UvrnutiPresjek(p1,p2,p3,p4,f);
	Tip1 pom1=p1;
	while(pom1!=p2) v1.push_back(*pom1++);
	Tip2 pom2 =p3;
	while(pom2!=p4) v2.push_back(*pom2++);
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<v1.size(); j++)
		{
			if(v1[j]== mat[i][0]) v1.erase(v1.begin()+j);
		}
	}
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<v2.size(); j++)
		{
			if(v2[j]== mat[i][1]) v2.erase(v2.begin()+j);
		}
	}
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> m(v1.size() + v2.size(), std::vector<typename std::remove_reference<decltype(*p1)>::type>(2));
	int j=0;
	for(int i=0; i<m.size(); i++)
	{
		m[i][0] = v1[j];
		m[i][1]= f(v1[j]);
		j++;
	}
	j=0;
	for(int i=v1.size(); i<m.size(); i++)
	{
		m[i][0]= v2[j];
		m[i][1]= f(v2[j]);
		j++;
	}
	std::sort(m.begin(), m.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type>v1,std::vector<typename std::remove_reference<decltype(*p1)>::type> v2)
	{
		if(v1[0]==v2[0]) return v1[1] <v2[1];
		return v1[0] > v2[0];});
		return m;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, v2 ;
	auto mat= UvrnutiPresjek(p1,p2,p3,p4);
	Tip1 pom1=p1;
	while(pom1!=p2) v1.push_back(*pom1++);
	Tip2 pom2 =p3;
	while(pom2!=p4) v2.push_back(*pom2++);
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<v1.size(); j++)
		{
		if(v1[j]== mat[i][0]) v1.erase(v1.begin()+j);
		}
	}
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<v2.size(); j++)
		{
			if(v2[j]== mat[i][0]) v2.erase(v2.begin()+j);
		}
	}
	//for(int i = 0; i < v2.size(); i++)std::cout<< v2[i] <<"  ";
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> m(v1.size() + v2.size(), std::vector<typename std::remove_reference<decltype(*p1)>::type>(2));
	int j=0;
	for(int i=0; i<m.size(); i++)
	{
		m[i][0] = v1[j];
		m[i][1]=  0;
		j++;
	}
	j=0;
	for(int i=v1.size(); i<m.size(); i++)
	{
		m[i][0]= v2[j];
		m[i][1]= 0;
		j++;
	}
	std::sort(m.begin(), m.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type>v1,std::vector<typename std::remove_reference<decltype(*p1)>::type> v2)
	{
		if(v1[0]==v2[0]) return v1[1] <v2[1];
		return v1[0] > v2[0];});
		return m;
}


	
int main(){
    int br1,br2;
    std::cout<<"Unesite broj elemenata prvog kontejnera: "; std::cin>>br1;
    std::deque<int> d1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
        for(int i = 0; i < br1; i++){
            int pom;
            std::cin>> pom;
       		auto it = std::find(d1.begin(),d1.end(),pom);
       		if(it == d1.end())d1.push_back(pom); else i--;
        }
     std::cout<<"Unesite broj elemenata drugog kontejnera: "; std::cin>>br2;
    std::deque<int> d2;
    std::cout<<"Unesite elemente prvog kontejnera: ";
        for(int i = 0; i < br2; i++){
       int pom;
            std::cin>> pom;
       		auto it = std::find(d2.begin(),d2.end(),pom);
       		if(it == d2.end() ) d2.push_back(pom); else i--;
       		}

	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	auto matrica = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	for(int i = 0; i < matrica.size(); i++){
        for(int j = 0; j < matrica[i].size(); j++)
            std::cout<<std::setw(6)<< matrica[i][j]<<" ";
        std::cout<<std::endl;
	}

	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	auto matrica1 = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	for(int i = 0; i < matrica1.size(); i++){
        for(int j = 0; j < matrica1[i].size(); j++)
            std::cout<<std::setw(6)<< matrica1[i][j]<<" ";
        std::cout<<std::endl;
	}
std::cout << "Dovidjenja!";

    return 0;

}