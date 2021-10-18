/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

int SumaCifara(long long int n)
{
	int suma(0);
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int n)
{
	int rez(0);
	if(n<0) n*=-1;
	for(int i(1); i<=n; i++)
	{
		if(n%i==0) rez+=i;
	}
	return rez;
}

bool Prost(long long int n)
{
	bool prost(true);
	if(n==1) prost=false;
	for(int i(2); i<=std::sqrt(n); i++)
	if(n%i==0)
	{
		prost=false;
		break;
	}
	else prost=true;
	return prost;
}

int BrojProstihFaktora(long long int n)
{
	int prost(1); 
	int br(0),pom(n);
	for(int i(2); i<=n; i++)
	{
		while(pom!=0 && pom%i==0 && Prost(i)==true)
		{
			prost*=i;
			br++;
			pom/=i;
		}
	}
	return br;
}

bool SavrsenBroj(long long int n)
{
	int suma(0);
	for(int i(1); i<n; i++)
	{
		if(n%i==0)
		{
			suma+=i;
		}
	}
	if(suma==n) return true;
	else return false;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int rez(0);
	for(int i(1); i<=n; i++)
	{
		if(n%i==0 && SavrsenBroj(i)==true) rez++; 
	}
	return rez;
}


template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	typedef typename std::remove_reference<decltype(*poc1)>::type tip;
	std::vector<std::vector<tip>> mat;
	int br(0);
	tip2 temp2=poc2;
	while(poc1!=kraj1)
	{
		temp2=poc2;
		while(temp2!=kraj2)
		{
			if(*poc1==*temp2)
			{
				br++;
				mat.resize(br);
				mat.at(br-1).resize(3);
				mat.at(br-1).at(0)=*poc1;
			}
			temp2++;
		}
		poc1++;
	}
	std::sort(mat.begin(),mat.end(), [] (std::vector<tip> a, std::vector<tip> b) { if(a[2]==b[2]){ if(a[0]==b[0]) return a[1]<b[1];
		else return a[0]<b[0];
	}
	else return a[2]<b[2]; });
	return mat;
}



template <typename tipv, typename tipp, typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, tipv f(tipp)) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> 
{
	typedef typename std::remove_reference<decltype(*poc1)>::type tip;
	std::vector<std::vector<tip>> mat;
	
	int br(0);
	tip1 temp1=poc1;
	tip2 temp2=poc2;

	while(temp1!=kraj1)
	{
		temp2=poc2;
		while(temp2!=kraj2)
		{
			if(f(*temp1)==f(*temp2))
			{
				br++;
				mat.resize(br);
				mat.at(br-1).resize(3);
				mat.at(br-1).at(0)=*temp1;
				mat.at(br-1).at(1)=*temp2;
				mat.at(br-1).at(2)=tip(f(*temp1));
			}
			temp2++;
		}
		temp1++;
	}
	std::sort(mat.begin(),mat.end(), [] (std::vector<tip> a, std::vector<tip> b) { if(a[2]==b[2]){ if(a[0]==b[0]) return a[1]<b[1];
		else return a[0]<b[0];
	}
	else return a[2]<b[2]; });
	return mat;
}



template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	typedef typename std::remove_reference<decltype(*poc1)>::type tip;
	tip1 temp1=poc1;
	tip2 temp2=poc2;
	bool par;
	int br(0);
	std::vector<std::vector<tip>> mat;
	while(temp1!=kraj1)
	{
		temp2=poc2;
		while(temp2!=kraj2)
		{
			if((*temp2)==(*temp1))
			{
				par=false;
				break;
			}
			else par=true;
			temp2++;
		}
		if(par==true)
		{
			br++;
			mat.resize(br);
			mat.at(br-1).resize(2);
			mat.at(br-1).at(0)=*temp1;
		}
		temp1++;
	}
	tip1 pom1=poc1;
	tip2 pom2=poc2;
	bool par2(true);
	int br2(0);
	while(pom2!=kraj2)
	{
		pom1=poc1;
		while(pom1!=kraj1)
		{
			if((*pom2)==(*pom1))
			{
				par2=false;
				break;
			}
			else par2=true;
			pom1++;
		}
		if(par2==true)
		{
			br2++;
			mat.resize(br+br2);
			mat.at(br+br2-1).resize(2);
			mat.at(br+br2-1).at(0)=*pom2;
		}
		pom2++;
	} 
	std::sort(mat.begin(),mat.end(), [](std::vector<tip> a, std::vector<tip> b) { if(a[0]==b[0]) return a[1]>b[1];
	else return a[0]>b[0]; } );
	return mat;
} 





template <typename tipv, typename tipp, typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, tipv f(tipp)) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	typedef typename std::remove_reference<decltype(*poc1)>::type tip;
	tip1 temp1=poc1;
	tip2 temp2=poc2;
	bool par;
	int br(0);
	std::vector<std::vector<tip>> mat;
	while(temp1!=kraj1)
	{
		temp2=poc2;
		while(temp2!=kraj2)
		{
			if(f(*temp2)==f(*temp1))
			{
				par=false;
				break;
			}
			else par=true;
			temp2++;
		}
		if(par==true)
		{
			br++;
			mat.resize(br);
			mat.at(br-1).resize(2);
			mat.at(br-1).at(0)=*temp1;
			mat.at(br-1).at(1)=tip(f(*temp1));
		}
		temp1++;
	}
	tip1 pom1=poc1;
	tip2 pom2=poc2;
	bool par2(true);
	int br2(0);
	while(pom2!=kraj2)
	{
		pom1=poc1;
		while(pom1!=kraj1)
		{
			if(f(*pom2)==f(*pom1))
			{
				par2=false;
				break;
			}
			else par2=true;
			pom1++;
		}
		if(par2==true)
		{
			br2++;
			mat.resize(br+br2);
			mat.at(br+br2-1).resize(2);
			mat.at(br+br2-1).at(0)=*pom2;
			mat.at(br+br2-1).at(1)=f(*pom2);
		}
		pom2++;
	} 
	std::sort(mat.begin(),mat.end(), [](std::vector<tip> a, std::vector<tip> b) { if(a[0]==b[0]) return a[1]>b[1];
	else return a[0]>b[0]; } );
	return mat;
} 

int main ()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::deque<long long int> d1;
	int br1(0),i(0);
	for(;;)
	{
		long long int a;
		std::cin >> a;
		if(i==0)
		{
			d1.push_back(a);
			br1++;
		}
		else if /*(NePonavljaSe(d1,i,a)==true)  */ (std::find(d1.begin(),d1.end(),a)==d1.end())
		{
			d1.push_back(a);
			br1++;
		}
		if(br1==n) break;
		i++; 
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin >> m;
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::deque<long long int> d2;
	int br2(0),j(0);
	for(;;)
	{
		long long int a;
		std::cin >> a;
		if(j==0)
		{
			d2.push_back(a);
			br2++;
		}
		else if /*(NePonavljaSe(d2,j,a)==true)*/(std::find(d2.begin(),d2.end(),a)==d2.end())
		{
			d2.push_back(a);
			br2++;
		}
		if(br2==m) break;
		j++; 
	}
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	std::vector<std::vector<long long int>> v;
	v=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	
	for(int i(0); i<v.size(); i++)
	{
		for(int j(0); j<v[0].size(); j++)
		{
			std::cout << std::setw(6) << v.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	std::vector<std::vector<long long int>> v2;
	v2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
   /*	for(int i(0); i<d1.size(); i++) std::cout << d1[i] << " ";
	std::cout << " a sada drugi: " << std::endl; 
	for(int i(0); i<d2.size(); i++) std::cout << d2[i] << " " << std::endl;
	std::cout << " velicina: " << v2.size() << std::endl; */
	for(int i(0); i<v2.size(); i++)
	{
		for(int j(0); j<v2[0].size(); j++)
		{
			std::cout << std::setw(6) << v2.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}