#include <iostream>
#include <deque>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

typedef std::deque<std::deque<int>> Matrica;

bool Ponavlja_li_se(std::deque<int> dek, int broj) {

	for (int i = 0; i < dek.size(); i++) {
		if(dek[i] == broj)
			return true;
	}
	return false;
}

int SumaDjelilaca (long long int broj) {

	int suma(1);

	for (int i = 2; i <= broj; i++) {
		if (broj%i==0)
			suma += i;
	}
	return suma;
}

int BrojProstihFaktora (long long int broj) {

	int suma(0);

	for (int i = 2; i <= broj; i++) {
		if(broj%i==0) {
			suma++;
			broj = broj/i;
			i--;
		}
	}
	return suma;
}

int BrojSavrsenihDjelilaca (long long int broj) {

	int suma(0);

	for (int i = 2; i <= broj; i++) {
		if(broj%i==0 && (SumaDjelilaca(i)-i)==i) {	// Suma djelilaca zbraja i samog sebe sto ne ulazi u domen savrsenog broja pa ga oduzimamo :D
			suma ++;
			broj = broj/i;
			i--;
		}
	}
	return suma;
}

template <typename Tip1, typename Tip2, typename T >
 auto UvrnutaRazlika (Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, T f, bool je_li_posebna=false)
	-> std::vector<std::vector<decltype(*poc1+*poc1)>> {
		
	typedef std::vector<std::vector<decltype(*poc1+*poc1)>> TipMatrice;
	typedef std::vector<decltype(*poc1+*poc1)> Vektor;
	
	TipMatrice mat;
	Vektor vec;
    
   	auto it1 = poc1;
	auto it2 = poc2;
   
    while (it1 != kraj1) {
    	it2 = poc2;
    	while (it2 != kraj2  && it1 != kraj1) {
  			if(f(*it1) == f(*it2)) {
  				it2 = poc2;
  				it1++;
  			}
  			else 
  				it2++;
	    }
	    if(it1 != kraj1) {
	    	vec.push_back(*it1);
	    	vec.push_back(f(*it1));
	    	mat.push_back(vec);
	    	vec.resize(0);
	    	it1++;
	    }	
    }
    it1 = poc2;
    it2 = poc1;
    
    while (it1 != kraj2) {
    	it2 = poc1;
    	while (it2 != kraj1  && it1 != kraj2) {
  			if(f(*it1) == f(*it2)) {
  				it2 = poc1;
  				it1++;
  			}
  			else 
  				it2++;
	    }
	    if(it1 != kraj2) {
	    	vec.push_back(*it1);
	    	vec.push_back(f(*it1));
	    	mat.push_back(vec);
	    	vec.resize(0);
	    	it1++;
	    }	
    }
    
    std::sort(mat.begin(), mat.end(), [] (Vektor v1, Vektor v2) {
    	if (v1[0] != v2[0])
    		return v1[0] > v2[0];
    	return v1[1] > v1[1];	
    });
    
    return mat;
	}	
template <typename Tip1, typename Tip2, typename T>
 auto UvrnutiPresjek (Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, T f, bool je_li_posebna=false)
	-> std::vector<std::vector<decltype(*poc1+*poc1)>> {

    typedef std::vector<std::vector<decltype(*poc1+*poc1)>> TipMatrice;
    typedef std::vector<decltype(*poc1+*poc1)> Vektor;

	TipMatrice mat;
	Vektor vec;

	auto it1 = poc1;
	auto it2 = poc2;

	while (it1 != kraj1) {
	    it2 = poc2;
		while (it2 != kraj2) {
			if(f(*it1) == f(*it2)) {
				vec.push_back(*it1);
				if(je_li_posebna) {
					vec.push_back(0);
					vec.push_back(0);
				} else {
					vec.push_back(*it2);
					vec.push_back(f(*it1));
				}
					mat.push_back(vec);
					vec.resize(0);
			}
			it2++;
		}
		it1++;
	}

	std::sort(mat.begin(), mat.end(), [] (Vektor v1, Vektor v2) {
        if(v1[2] != v2[2])
                return v1[2] < v2[2];
        if(v1[0] != v2[0])
                return v1[0] < v2[0];
        return v1[1] < v2[1];
    });

	return mat;
 }

template <typename Tip1, typename Tip2>
 void UvrnutiPresjek (Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2) {
	UvrnutiPresjek(poc1, kraj1, poc2, kraj2, [] (int broj) {return broj;} ,true);
}

template <typename Tip1, typename Tip2>
 void UvrnutaRazlika (Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2) {
	UvrnutaRazlika(poc1, kraj1, poc2, kraj2, [] (int broj) {return broj;} ,true);
}

int main ()
{
	int n1,n2;
	std::deque<int> d1,d2;

	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> n1;

	cout << "Unesite elemente prvog kontejnera: ";
	int broj;

	for (int i = 0; i < n1; i++) {
		cin >> broj;
		if(Ponavlja_li_se(d1,broj)) {
			i--;
			continue;
		}
		d1.push_back(broj);
	}

	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> n2;

	cout << "Unesite elemente drugog kontejnera: ";

	for (int i = 0; i < n2; i++) {
		cin >> broj;
		if(Ponavlja_li_se(d2,broj)) {
			i--;
			continue;
		}
		d2.push_back(broj);
	}

    std::vector<std::vector<int>> mat = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), [] (int broj) {
    	int suma(0);
    	while (broj!=0) {
    		suma += broj%10;
    		broj = broj/10;
    	}
    	return suma;
    });
    
    cout << "Uvrnuti presjek kontejnera:" << endl;
    
    for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << std::setw(6) << mat[i][j] << " ";
		}
		cout  << endl;
	}
	
	mat = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(),BrojProstihFaktora);
	
    cout << "Uvrnuta razlika kontejnera:" << endl;
    
    for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << std::setw(6) << mat[i][j] << " ";
		}
		cout  << endl;
	}
	cout << "Dovidjenja!";

	return 0;
}
