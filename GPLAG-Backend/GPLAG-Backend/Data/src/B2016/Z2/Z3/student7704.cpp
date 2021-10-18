/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <deque>
#include <cmath>

using namespace std;

int SumaDjelilaca(long long int);

template <typename tip1, typename tip2, typename tipFje, typename tip3>

auto UvrnutiPresjek(tip1 it1, tip1 it2, tip2 it3, tip2 it4, tipFje (*foo)(tip3))
	-> vector<vector<typename remove_reference<decltype(*it1 + *it3)>::type>>
{
	typedef typename remove_reference<decltype(*it1 + *it3)>::type ludTip;
	vector<vector<ludTip>> rez;
	while(it1!=it2){
		tip2 temp=it3;
		while(temp!=it4){
			if(foo==nullptr && *it1==*temp) rez.push_back(vector<ludTip> {*it1, 0, 0});
			else if(foo!=nullptr && foo(*it1)==foo(*temp)){
				rez.push_back(vector<ludTip> {*it1, *temp, foo(*temp)});
			}
			temp++;
		}
		it1++;
	}
	sort(rez.begin(), rez.end(), [](vector<ludTip> v1, vector<ludTip> v2){
		return v1.at(2)==v2.at(2) ? ( v1.at(0)==v2.at(0) ? v1.at(1)<v2.at(1) : v1.at(0)<v2.at(0)) : v1.at(2)<v2.at(2);	
	});
	return rez;
}

template <typename tip1, typename tip2>

auto UvrnutiPresjek(tip1 it1, tip1 it2, tip2 it3, tip2 it4)
	-> vector<vector<typename remove_reference<decltype(*it1 + *it3)>::type>>
{
	typedef typename remove_reference<decltype(*it1 + *it3)>::type ludTip;
	ludTip (*pok_na_fun)(ludTip)=nullptr;
	return UvrnutiPresjek(it1, it2, it3, it4, pok_na_fun);
}

template <typename tip1, typename tip2, typename tipFje, typename tip3>

auto UvrnutaRazlika(tip1 it1, tip1 it2, tip2 it3, tip2 it4, tipFje (*foo)(tip3))
	-> vector<vector<typename remove_reference<decltype(*it1 + *it3)>::type>>
{
	typedef typename remove_reference<decltype(*it1 + *it3)>::type ludTip;
	vector<vector<ludTip>> rez;
	tip1 it=it1;
	while(it1!=it2){
		tip2 temp=it3;
		tipFje rezFoo = foo != nullptr ? foo(*it1) : 0;
		bool postoji(false);
		while(temp!=it4){
			if(foo!=nullptr && rezFoo==foo(*temp)){
				postoji = true;
				break;
			}
			else if(foo==nullptr && *it1==*temp){
				postoji=true;
				break;
			}
			temp++;
		}
		if(!postoji) rez.push_back(vector<ludTip> {*it1, rezFoo});
		it1++;
	}
	it1=it;
	while(it3!=it4){
		tip1 temp=it1;
		tipFje rezFoo = foo != nullptr ? foo(*it3) : 0;
		bool postoji(false);
		while(temp!=it2){
			if(foo!=nullptr && rezFoo==foo(*temp)){
				postoji=true;
				break;
			}
			else if(foo==nullptr && *it3==*temp){
				postoji=true;
				break;
			}
			temp++;
		}
		if(!postoji) rez.push_back(vector<ludTip> {*it3, rezFoo});
		it3++;
	}
	sort(rez.begin(), rez.end(), [](vector<ludTip> v1, vector<ludTip> v2){
    	return v1.at(0)==v2.at(0) ? v1.at(1)>v2.at(1) : v1.at(0)>v2.at(0);
    });
    return rez;
}

template <typename tip1, typename tip2>

auto UvrnutaRazlika(tip1 it1, tip1 it2, tip2 it3, tip2 it4)
	-> vector<vector<typename remove_reference<decltype(*it1 + *it3)>::type>>
{
	typedef typename remove_reference<decltype(*it1 + *it3)>::type ludTip;
	ludTip (*pok_na_fun)(ludTip)=nullptr;
	return UvrnutaRazlika(it1, it2, it3, it4, pok_na_fun);
}

int SumaDjelilaca(long long int n){
	int suma=0;
	n=fabs(n);
	for(int i(1); i<=n; i++)
		if(n%i==0) suma +=i;
	return suma;
}

bool SavrsenBroj(long long int n){
	int suma(0);
	for(int x(1); x<=n/2; x++) if(n%x==0) suma+=x;
	return suma==n;
}

int BrojProstihFaktora(long long int n){
	int rez(0);
	n=fabs(n);
	int x(2);
	while(x<=n)
		n%x==0 ? rez++, n/=x : x++;
	return rez;
}

int BrojSavrsenihDjelilaca(long long int n){
	int rez(0);
	n=fabs(n);
	int x(2);
	while(x<=n)
		if(n%x==0 && SavrsenBroj(x)){ rez++; 
		n/=x;
		}
		else
		x++;
	return rez;
}

int SumaCifara(long long int n){
	int suma=0;
    n=fabs(n);
    while(n!=0){
    	suma+=n%10;
    	n/=10;
    }
    return suma;
}

int main()
{
    int x, y;
    cout<< "Unesite broj elemenata prvog kontejnera: ";
    cin>> x;
    deque<int> d1;
    cout << "Unesite elemente prvog kontejnera: ";
    for(int i(0); i < x;){
    	int n;
    	cin >> n;
    	if(d1.end()==find(d1.begin(), d1.end(), n)){
    		d1.push_back(n);
    		i++;
    	}
    }

    //cin.clear(); cin.ignore(1000, '\n');

    cout<< "Unesite broj elemenata drugog kontejnera: ";
    cin>> y;
    deque<int> d2;
    cout << "Unesite elemente drugog kontejnera: ";
    for(int i(0); i < y;){
    	int n;
    	cin >> n;
    	if(d2.end()==find(d2.begin(), d2.end(), n)){
    		d2.push_back(n);
    		i++;
    	}
    }

    //cin.clear(); cin.ignore(1000, '\n');

    auto mat=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);

    cout<< "Uvrnuti presjek kontejnera: " << endl;
    for(auto x : mat){
        for(auto z : x)
            cout.width(6), cout << z << " ";
        cout << endl;
    }

    mat=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);

    cout<< "Uvrnuta razlika kontejnera:" << endl;
    for(auto x : mat){
        for(auto z : x)
            cout.width(6), cout << z << " ";
        cout << endl;
    }
	cout<< "Dovidjenja!" << endl;
	
    return 0;
}