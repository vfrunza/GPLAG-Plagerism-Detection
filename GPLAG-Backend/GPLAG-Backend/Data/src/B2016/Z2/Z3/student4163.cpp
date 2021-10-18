#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<iomanip>

template <typename Tip1, typename Tip2,typename paramF,typename povratniTip>

auto UvrnutiPresjek(Tip1 pocetak1,Tip1 kraj1, Tip2 pocetak2,Tip2 kraj2, povratniTip f(paramF)) -> std::vector<std::vector<decltype(0+*pocetak1)>>
{
    std::vector<std::vector<povratniTip> > matrica;
    Tip2 pomocni(pocetak2);

    while(pocetak1!=kraj1)
    {
        pomocni=pocetak2;
        while(pomocni!=kraj2)
        {
            if(f(*pocetak1)==f(*pomocni))
            {
                std::vector<povratniTip> red;
                red.push_back(povratniTip(*pocetak1));
                red.push_back(povratniTip(*pomocni));
                red.push_back(f(*pocetak1));
                matrica.push_back(red);
            }
            pomocni++;
        }
        pocetak1++;
    }

    std::sort(matrica.begin(),matrica.end(),[](std::vector<povratniTip> a, std::vector<povratniTip> b)
              {
                  if(a[2]!=b[2]) return a[2]<b[2];
                  else if(a[0]!=b[0])return a[0]<b[0];
                  else return a[1]<b[1];
              });

    return matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek (Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2) -> std::vector<std::vector<decltype(0+*pocetak1)>> {
	std::vector<std::vector<decltype(0+*pocetak1)>> matrica;
	Tip2 pomocni(pocetak2);
	while(pocetak1 != kraj1) {
		pomocni = pocetak2;
		while (pomocni != kraj2) {
			if(*pocetak1 == *pomocni) {
				std::vector<decltype(0+*pocetak1)> red;
				red.push_back(*pocetak1);
				red.push_back(0);
				red.push_back(0);
				matrica.push_back(red);
			}
			pomocni++;
		}
		pocetak1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<decltype(0+*pocetak1)>a, std::vector<decltype(0+*pocetak1)> b)
	{
		return a[2] < b[2];	
	});
	return matrica;
}

template <typename Tip1, typename Tip2, typename paramF, typename povratniTip>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2, povratniTip f(paramF)) -> std::vector<std::vector<decltype(0+*pocetak1)>>{
	std::vector<std::vector<povratniTip>> matrica;
	Tip2 pomocni(pocetak2);
	Tip1 pomocni1(pocetak1);
	while(pomocni1 != kraj1) {
		pomocni = pocetak2;
		int nadjen(0);
		while(pomocni != kraj2) {
			if(f(*pomocni1) == f(*pomocni)) {
				nadjen = 1;
				break;
			}
			pomocni++;
		}
		if(!nadjen) {
			std::vector<povratniTip> red;
			red.push_back(povratniTip(*pomocni1));
			red.push_back(f(*pomocni1));
			matrica.push_back(red);
		}
		pomocni1++;
	}
	pomocni1 = pocetak2;
	pomocni = pocetak1;
	while(pomocni1 != kraj2) {
		pomocni = pocetak1;
		int nadjen(0);
		while(pomocni != kraj1) {
			if(f(*pomocni1) == f(*pomocni)) {
				nadjen = 1;
				break;
			}
			pomocni++;
		}
		if(!nadjen) {
			std::vector<povratniTip> red;
			red.push_back(povratniTip(*pomocni1));
			red.push_back(f(*pomocni1));
			matrica.push_back(red);
		}
		pomocni1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<povratniTip>a, std::vector<povratniTip> b)
	{
		if(a[0] != b[0]) return a[0] > b[0];
		else return a[1] > b[1];
	});
	return matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2) -> std::vector<std::vector<decltype(0+*pocetak1)>>{
	std::vector<std::vector<decltype(0+*pocetak1)>> matrica;
	Tip2 pomocni(pocetak2);
	Tip1 pomocni1(pocetak1);
	while(pomocni1 != kraj1) {
		pomocni = pocetak2;
		int nadjen(0);
		while(pomocni != kraj2) {
			if(*pomocni1 == *pomocni) {
				nadjen = 1;
				break;
			}
			pomocni++;
		}
		if(!nadjen) {
			std::vector<decltype(0+*pocetak1)> red;
			red.push_back(*pomocni1);
			red.push_back(0);
			matrica.push_back(red);
		}
		pomocni1++;
	}
	pomocni1 = pocetak2;
	pomocni = pocetak1;
	while(pomocni1 != kraj2) {
		pomocni = pocetak1;
		int nadjen(0);
		while(pomocni != kraj1) {
			if(*pomocni1 == *pomocni) {
				nadjen = 1;
				break;
			}
			pomocni++;
		}
		if(!nadjen) {
			std::vector<decltype(0+*pocetak1)> red;
			red.push_back(*pomocni1);
			red.push_back(0);
			matrica.push_back(red);
		}
		pomocni1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<decltype(0+*pocetak1)>a, std::vector<decltype(0+*pocetak1)> b)
	{
		if(a[0] != b[0]) return a[0] > b[0];
		else return a[1] > b[1];
	});
	return matrica;
}

int SumaDjelilaca(long long int broj) {
	long long int suma(0);
	for(int i(1); i <= broj; i++) {
		if(broj % i == 0) suma += i;
	}
	return suma;
}

bool JeliProst(int broj) {
	int brojac(0);
	for(int i(2); i <= broj; i++) {
		if(broj % i == 0) brojac++;
	}
	return brojac <= 1;
}

int BrojProstihFaktora(long long int broj) {
	int brojac(0);
	for(int i(2); i <= broj; i++) {
		if(JeliProst(i)) {
			while (broj % i == 0) {
				brojac++;
				broj /= i;
			}
		}
	}
	return brojac;
}

bool JeLiSavrsen(int broj) {
	int suma(0);
	for(int i(1); i < broj; i++) {
		if(broj % i == 0) suma += i;
	}
	return broj == suma;
}

int BrojSavrsenihDjelilaca(long long int broj) {
	int brojac(0);
	for(int i(2); i<=broj; i++) {
		if(JeLiSavrsen(i) && broj % i == 0) brojac++;
	}
	return brojac;
}

int suma(int a) {
	int suma(0);
	while(a > 0) {
		suma+=a%10;
		a/=10;
	}
	return suma;
}

int main ()
{
	int broj;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>broj;
	std::deque<int> a;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int element;
	while(a.size()<broj) {
		std::cin>>element;
		bool nadjen(false);
		for(int j(0); j<a.size(); j++) 
			if(a[j] == element) nadjen=true;
		if(!nadjen) a.push_back(element);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>broj;
	std::deque<int> b;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	while(b.size()<broj) {
		std::cin>>element;
		bool nadjen(false);
		for(int j(0); j<b.size(); j++) 
			if(b[j] == element) nadjen=true;
		if(!nadjen) b.push_back(element);
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<int>> krajnji=UvrnutiPresjek(a.begin(), a.end(), b.begin(), b.end(), suma);
	for(int i(0); i<krajnji.size(); i++) {
		for(int j(0); j<krajnji[i].size(); j++) {
			std::cout<<std::setw(6)<<krajnji[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	std::vector<std::vector<int>> krajnji2=UvrnutaRazlika(a.begin(), a.end(), b.begin(), b.end(), BrojProstihFaktora);
	for(int i(0); i<krajnji2.size(); i++) {
		for(int j(0); j<krajnji2[i].size(); j++) {
			std::cout<<std::setw(6)<<krajnji2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}