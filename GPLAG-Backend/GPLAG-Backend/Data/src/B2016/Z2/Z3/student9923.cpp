#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <iomanip>

std::deque<int> Pravilan_unos (int n)
{
	std::deque<int> rezultat;
	
	int upisani = 0;
	
	while(upisani!=n)
		{
			int x;
			std::cin>>x;
			
			bool postoji = false;
			for (int i{};i<rezultat.size();i++)
				{
					if (rezultat[i] == x)
						postoji = true;
				}
				
			if (postoji == false)
				{
					rezultat.push_back(x);
					upisani++;
				}
		}
	
	std::fflush(stdin);
	
	
	return rezultat;
}

int SumaCifara (long long int x)
{
	if (x<0)
		x*=-1;
			
		int suma = 0;
		
		while (x>0)
			{
				int a = x%10;
				suma+=a;
				x/=10;
			}
			
		return suma;
}

int SumaDjelilaca (long long int x)
{
	int suma = 0;
	if (x<0)
		x*=-1;
		
	for (int i{1};i<=x;i++)
		{
			if (x%i==0)
				suma+=i;
		}
		
	return suma;
}

int BrojProstihFaktora (long long int x)
{
	if (x<0)
		x*=-1;
		
	int n = 0;
	
	int djelilac = 2;
	
	while(x!=1)
	{
		if (x%djelilac == 0)
			{
				n++;
				x/=djelilac;
			}
		else
			djelilac++;
	}
	
	
	return n;
}

int BrojSavrsenihDjelilaca (long long int x)
{
	std::vector<int> savrseni_brojevi {6,28,496,8128,33550336};
	
	int n = 0;
	for (int i{};i<savrseni_brojevi.size();i++)
		{
			if (x%savrseni_brojevi[i] == 0)
				n++;
		}
	
	
	return n;
}

template<typename pok_tip_1, typename pok_tip_2, typename tip_1, typename tip_2>
std::vector<std::vector<tip_2>> UvrnutiPresjek (pok_tip_1 p1, pok_tip_1 p2, pok_tip_2 p3, pok_tip_2 p4, tip_2 f (tip_1))
{
	pok_tip_1 p = p1;
	int n = 0;
	while(p!=p2)							///Dio za prebrojavanje elemenata.
	{
		pok_tip_2 pomocni = p3;
		while(pomocni!=p4)
		{
			if (f(*p) == f(*pomocni))
				n++;
			
			pomocni++;
		}
		
		p++;
	}
	
	std::vector<std::vector<tip_2>> matrica (n, std::vector<tip_2> (3));
	
	p = p1;
	int i = 0;
	while(p!=p2)							///Dio za upisivanje elemenata.
	{
		pok_tip_2 pomocni = p3;
		while(pomocni!=p4)
		{
			if (f(*p) == f(*pomocni))
				{
					matrica[i][0] = *p;
					matrica[i][1] = *pomocni;
					matrica[i][2] = f(*p);
					
					i++;
				}
			
			pomocni++;
		}
		
		p++;
	}
	
	std::sort(matrica.begin(),matrica.end(), [] (std::vector<tip_2> v1, std::vector<tip_2> v2)
	{
		if (v1[2] < v2[2])
			return true;
		if (v1[2] == v2[2])
			{
				if (v1[0] < v2[0])
					return true;
				if (v1[0] == v2[0])
					return v1[1] < v2[1];
			}
			
		return false;
	});
	
	return matrica;
}

template<typename pok_tip_1, typename pok_tip_2>
auto UvrnutiPresjek (pok_tip_1 p1, pok_tip_1 p2, pok_tip_2 p3, pok_tip_2 p4) -> std::vector<std::vector<decltype (*p1+*p1)>>
{
	pok_tip_1 p = p1;
	int n = 0;
	while(p!=p2)							///Dio za prebrojavanje elemenata.
	{
		pok_tip_2 pomocni = p3;
		while(pomocni!=p4)
		{
			if (*p == *pomocni)
				n++;
			
			pomocni++;
		}
		
		p++;
	}
	
	std::vector<std::vector<decltype (*p1+*p1)>> matrica (n, std::vector<decltype(*p1+*p1)> (3));
	
	p = p1;
	int i = 0;
	while(p!=p2)							///Dio za upisivanje elemenata.
	{
		pok_tip_2 pomocni = p3;
		while(pomocni!=p4)
		{
			if (*p == *pomocni)
				{
					matrica[i][0] = *p;
					matrica[i][1] = 0;
					matrica[i][2] = 0;
					
					i++;
				}
			
			pomocni++;
		}
		
		p++;
	}
	
	return matrica;
}


template<typename pok_tip_1, typename pok_tip_2, typename tip_1, typename tip_2>
std::vector<std::vector<tip_2>> UvrnutaRazlika (pok_tip_1 p1, pok_tip_1 p2, pok_tip_2 p3, pok_tip_2 p4, tip_2 f(tip_1))
{
	pok_tip_1 pomocni_p1 = p1;
	
	std::vector<std::vector<tip_2>> matrica;
	
	while (pomocni_p1 != p2)
		{
			pok_tip_2 pomocni_p3 = p3;
			bool ima_par = false;
			while(pomocni_p3 != p4)
			{
				if (f(*pomocni_p1) == f(*pomocni_p3))
					ima_par = true;
				
				pomocni_p3++;
			}
			
			if (ima_par == false)
				{
					std::vector<tip_2> rezultat (2);
					
					rezultat[0] = *pomocni_p1;
					rezultat[1] = f(*pomocni_p1);
					
					matrica.push_back(rezultat);
				}
			
			pomocni_p1++;
		}
		
		pok_tip_2 pomocni_p3 = p3;
		
		while (pomocni_p3 != p4)
		{
			pomocni_p1 = p1;
			bool ima_par = false;
			while (pomocni_p1 != p2)
			{
				if (f(*pomocni_p3) == f(*pomocni_p1))
					ima_par = true;
					
				pomocni_p1++;
			}
			
			if (ima_par == false)
			{
				std::vector<tip_2> rezultat (2);
				rezultat[0] = *pomocni_p3;
				rezultat[1] = f(*pomocni_p3);
				
				matrica.push_back(rezultat);
			}
			
			pomocni_p3++;
		}
	
	std::sort (matrica.begin(),matrica.end(), [] (std::vector<tip_2> v1, std::vector<tip_2> v2)
	{
		if (v1[0] > v2[0])
			return true;
			
		if (v1[0] == v2[0])
			return v1[1] > v2[1];
		
		return false;
	});
	
	return matrica;
	
}

template<typename pok_tip_1, typename pok_tip_2>
auto UvrnutaRazlika (pok_tip_1 p1, pok_tip_1 p2, pok_tip_2 p3, pok_tip_2 p4) -> std::vector<std::vector<decltype(*p1+*p1)>>
{
	pok_tip_1 pomocni_p1 = p1;
	
	std::vector<std::vector<decltype(*p1+*p1)>> matrica;
	
	while (pomocni_p1 != p2)
		{
			pok_tip_2 pomocni_p3 = p3;
			bool ima_par = false;
			while(pomocni_p3 != p4)
			{
				if (*pomocni_p1 == *pomocni_p3)
					ima_par = true;
				
				pomocni_p3++;
			}
			
			if (ima_par == false)
				{
					std::vector<decltype(*p1+*p1)> rezultat (2);
					
					rezultat[0] = *pomocni_p1;
					rezultat[1] = 0;
					
					matrica.push_back(rezultat);
				}
			
			pomocni_p1++;
		}
		
		pok_tip_2 pomocni_p3 = p3;
		
		while (pomocni_p3 != p4)
		{
			pomocni_p1 = p1;
			bool ima_par = false;
			while (pomocni_p1 != p2)
			{
				if (*pomocni_p3 == *pomocni_p1)
					ima_par = true;
					
				pomocni_p1++;
			}
			
			if (ima_par == false)
			{
				std::vector<decltype(*p1+*p1)> rezultat (2);
				rezultat[0] = *pomocni_p3;
				rezultat[1] = 0;
				
				matrica.push_back(rezultat);
			}
			
			pomocni_p3++;
		}
		
		std::sort (matrica.begin(),matrica.end(), [] (std::vector<decltype(*p1+*p1)> v1, std::vector<decltype(*p1+*p1)> v2)
	{
		if (v1[0] > v2[0])
			return true;
		
		return false;
	});
	
	return matrica;
}


int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1 = Pravilan_unos(n);
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> d2 = Pravilan_unos(n);
	
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	std::vector<std::vector<int>> v = UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	
	for (int i{};i<v.size();i++)
		std::cout<<std::right<<std::setw(6)<<v[i][0]<<" "<<std::right<<std::setw(6)<<v[i][1]<<" "<<std::right<<std::setw(6)<<v[i][2]<<" "<<std::endl;
		
		
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	std::vector<std::vector<int>> v1 = UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	
	for (int i{};i<v1.size();i++)
		std::cout<<std::right<<std::setw(6)<<v1[i][0]<<" "<<std::right<<std::setw(6)<<v1[i][1]<<" "<<std::endl;
		
	std::cout<<"Dovidjenja!";
	
	
	return 0;
}