/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cmath>
#include <algorithm>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

int SumaDjelilaca (long long int br)
{
	int n=0;
	for(unsigned long long int i=1;i<=abs(br);i++)
	{
		if(abs(br)%i==0)
			n+=i;
	}
	return n;
}

int BrojProstihFaktora(long long int br)
{
	int n=0;
	for(unsigned long long int i=2;i<=abs(br);i++)
	{
		if(abs(br)%i==0)
		{
			n++;
			br/=i;
			i=1;
		} 
	}
	return n;
}

int BrojSavrsenihDjelilaca(long long int br)
{
	int n=0;
	for(unsigned long long int i=1;i<=abs(br);i++)
	{
		if(abs(br)%i==0)
		{
            unsigned long long int suma=0;
            for(unsigned long long int j=1;j<i;j++)
            {
                if(i%j==0) suma+=j;
            }
            if(suma==i) n++;
		}
	}
	return n;
}

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<int>(br_kolona));
}

template<typename it1,typename it2>
	auto UvrnutiPresjek(it1 p1,it1 k1,it2 p2,it2 k2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
	{
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Mat;
		typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vek;
		Mat m;
		for(it1 i=p1;i<k1;i++)
		{
			for(it2 j=p2;j<k2;j++)
			{
				Vek v;
				if(*i==*j)
				{
					v.push_back(*i);
					v.push_back(0);
					v.push_back(0);
					m.push_back(v);
				}
			}
		}
		std::sort(m.begin(),m.end(),[](Vek x,Vek y){
			return x[0]<=y[0];
		});
		return m;
	}
	
template<typename it1,typename it2>
	auto UvrnutaRazlika(it1 p1,it1 k1,it2 p2,it2 k2)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
	{
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Mat;
		typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vek;
		Mat m;
		bool da;
		for(it1 i=p1;i<k1;i++)
		{
			Vek v;
			da=true;
			for(it2 j=p2;j<k2;j++)
			{
				if(*i==*j)
					da=false;
			}
			if(da)
			{
				v.push_back(*i);
				v.push_back(0);
				m.push_back(v);
			}
		}
		for(it2 j=p2;j<k2;j++)
		{
			Vek v;
			da=true;
			for(it2 i=p1;i<k1;i++)
			{
				if(*i==*j)
					da=false;
			}
			if(da)
			{
				v.push_back(*j);
				v.push_back(0);
				m.push_back(v);
			}
		}
		std::sort(m.begin(),m.end(),[](Vek x,Vek y){
			return x[0]>=y[0];
		});
		return m;
	}

template<typename it1,typename it2,typename f>
	auto UvrnutiPresjek(it1 p1,it1 k1,it2 p2,it2 k2,f pr)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
	{
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Mat;
		typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vek;
		Mat m;
		for(it1 i=p1;i<k1;i++)
		{
			for(it2 j=p2;j<k2;j++)
			{
				Vek v;
				if(pr(*i)==pr(*j))
				{
					v.push_back(*i);
					v.push_back(*j);
					v.push_back(pr(*i));
					m.push_back(v);
				}
			}
		}
		std::sort(m.begin(),m.end(),[](Vek x,Vek y){
			if(x[2]!=y[2]) return x[2]<=y[2];
			if(x[0]!=y[0]) return x[0]<=y[0];
			return x[1]<=y[1];
		});
		return m;
	}
	
template<typename it1,typename it2,typename f>
	auto UvrnutaRazlika(it1 p1,it1 k1,it2 p2,it2 k2,f r)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
	{
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Mat;
		typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vek;
		Mat m;
		bool da;
		for(it1 i=p1;i<k1;i++)
		{
			Vek v;
			da=true;
			for(it2 j=p2;j<k2;j++)
			{
				if(r(*i)==r(*j))
					da=false;
			}
			if(da)
			{
				v.push_back(*i);
				v.push_back(r(*i));
				m.push_back(v);
			}
		}
		for(it2 j=p2;j<k2;j++)
		{
			Vek v;
			da=true;
			for(it2 i=p1;i<k1;i++)
			{
				if(r(*i)==r(*j))
					da=false;
			}
			if(da)
			{
				v.push_back(*j);
				v.push_back(r(*j));
				m.push_back(v);
			}
		}
		std::sort(m.begin(),m.end(),[](Vek x,Vek y){
			if(x[0]!=y[0]) return x[0]>=y[0];
			return x[1]>=y[1];
		});
		return m;
	}

int Suma(int n)
{
	int suma=0;
	while(n!=0)
	{
		suma+=abs(n%10);
		n/=10;
	}
	return suma;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	std::deque<int> d1(n);
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n;i++)
	{
		std::cin >> d1[i];
		for(int j=0;j<i;j++)
			if(d1[j]==d1[i])
			{
				i--;
				break;
			}
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::deque<int> d2(n);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n;i++)
	{
		std::cin >> d2[i];
		for(int j=0;j<i;j++)
			if(d2[j]==d2[i])
			{
				i--;
				break;
			}
	}
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(),Suma)};
    std::cout << "Uvrnuti presjek kontejnera:\n";
    for(std::vector<int> a:v1)
    {
    	for(int b:a) std::cout <<std::setw(6) << b <<" ";
    	std::cout <<"\n";
    }
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(),BrojProstihFaktora)};
	std::cout << "Uvrnuta razlika kontejnera:\n";
	for(std::vector<int> a:v2)
    {
    	for(int b:a) std::cout <<std::setw(6) << b <<" ";
    	std::cout <<"\n";
    }
    std::cout << "Dovidjenja!";
	return 0;
}