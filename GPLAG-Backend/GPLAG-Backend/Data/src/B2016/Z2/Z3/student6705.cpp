/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <functional>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

using namespace std;

int SumaDjelilaca(long long int n) {
	int br = n;
	
	for (long long int i = 1; i < n / 2 + 1; i++)
		if (n % i == 0)
			br += i;
	
	return br;
}

bool Prost(const long long int &n) {
	if (n > 2 && n % 2 == 0)
		return false;
	
	for (int i = 2; i < n/2 + 1; i++)
		if (n % i == 0)
			return false;
		
	return true;
}

int BrojProstihFaktora(long long int n) {
	int br = 0;
	const int poc = n;
	
	for (long long int i = 2; i <= poc; i++) {
		if (!Prost(i))
			continue;
		if (n % i == 0) {
			n /= i;
			br++;
			i--;
		}
	}
	
	return br;
}

int BrojSavrsenihDjelilaca(long long int n) {
	int br = 0;
	
	for (long long int i = 2; i < n; i++) {
		if(n % i == 0 && i == SumaDjelilaca(i) - i){
			br++;
		}
		
	}
	
	return br;
}

template <typename ItS1, typename ItS2, typename TipFun, typename TipF>
void UvrnutiPresjekPomocna(const ItS1 &s1_poc, const ItS1 &s1_kraj, const ItS2 &s2_poc, const ItS2 &s2_kraj, TipF fun, std::vector<std::vector<TipFun>> &izlaz) {
	TipFun tmp;
	vector<TipFun> tmp_trojka;
	
	for(ItS1 iS1 = s1_poc; iS1 != s1_kraj; iS1++) {
		tmp = fun(*iS1);
		for(ItS2 iS2 = s2_poc; iS2 != s2_kraj; iS2++) {
			if (tmp == fun(*iS2)) {
				tmp_trojka.clear();
				tmp_trojka.push_back(*iS1);
				tmp_trojka.push_back(*iS2);
				tmp_trojka.push_back(tmp);
				izlaz.push_back(tmp_trojka);
			}
		}
	}
	
	sort(izlaz.begin(), izlaz.end(), [](vector<TipFun> t1, vector<TipFun> t2) {
		if (t1[2] < t2[2])
			return true;
		else if (t1[2] > t2[2])
			return false;
		if (t1[0] < t2[0])
			return true;
		else if (t1[0] > t2[0])
			return false;
		if (t1[1] < t2[1])
			return true;
		else
			return false;
	});
}

template <typename ItS1, typename ItS2>
auto UvrnutiPresjek(ItS1 s1_poc, ItS1 s1_kraj, ItS2 s2_poc, ItS2 s2_kraj) -> vector<vector<decltype(*s1_poc + 1)>> {
	typedef decltype(*s1_poc + 1) TipFun;
	
	function<TipFun(TipFun)> fun = [](TipFun n) { return n; };
	vector<vector<TipFun>> izlaz;
	
	UvrnutiPresjekPomocna(s1_poc, s1_kraj, s2_poc, s2_kraj, fun, izlaz);
	
	return izlaz;
}

template <typename ItS1, typename ItS2, typename TipF>
auto UvrnutiPresjek(ItS1 s1_poc, ItS1 s1_kraj, ItS2 s2_poc, ItS2 s2_kraj, TipF fun) -> vector<vector<decltype(*s1_poc + 1)>> {
    typedef decltype(*s1_poc + 1) TipFun;

    vector<vector<TipFun>> izlaz;

    UvrnutiPresjekPomocna(s1_poc, s1_kraj, s2_poc, s2_kraj, fun, izlaz);

    return izlaz;
}

template <typename ItS1, typename ItS2, typename TipFun, typename Tipf>
void UvrnutaRazlikaPomocna(const ItS1 &s1_poc, const ItS1 &s1_kraj, const ItS2 &s2_poc, const ItS2 &s2_kraj, Tipf fun, std::vector<std::vector<TipFun>> &izlaz){
    TipFun tmp;
    std::vector<TipFun> tmp_par;
    
    bool has_equal;
    
    for (ItS1 iS1 = s1_poc; iS1 != s1_kraj; iS1++) {
    	has_equal = false;
    	tmp = fun(*iS1);
    	
    	for (ItS2 iS2 = s2_poc; iS2 != s2_kraj; iS2++) {
    		if (tmp == fun(*iS2)) {
    			has_equal = true;
    			break;
    		}
    	}
    	
    	if (!has_equal) {
    		tmp_par.clear();
    		tmp_par.push_back(*iS1);
    		tmp_par.push_back(tmp);
    		izlaz.push_back(tmp_par);
    	}
    }
    
    for (ItS2 iS2 = s2_poc; iS2 != s2_kraj; iS2 ++) {
    	has_equal = false;
    	tmp = fun(*iS2);
    	
    	for (ItS1 iS1 = s1_poc; iS1 != s1_kraj; iS1++) {
    		if (tmp == fun(*iS1)) {
    			has_equal = true;
    			break;
    		}
    	}
    	
    	if (!has_equal) {
    		tmp_par.clear();
    		tmp_par.push_back(*iS2);
    		tmp_par.push_back(tmp);
    		izlaz.push_back(tmp_par);
    	}
    }
    
    sort(izlaz.begin(), izlaz.end(), [](vector<TipFun> t1, vector<TipFun> t2){
    	if (t1[0] < t2[0])
    		return false;
    	else if (t1[0] > t2[0])
    		return true;
    	if (t1[1] < t2[1])
    		return false;
    	else
    		return true;
    });
}

template <typename ItS1, typename ItS2>
auto UvrnutaRazlika(ItS1 s1_poc, ItS1 s1_kraj, ItS2 s2_poc, ItS2 s2_kraj) -> vector<vector<decltype(*s1_poc + 1)>> {
    typedef decltype(*s1_poc + 1) TipFun;
    function<TipFun(TipFun)> fun = [](TipFun n){ return n; };

    vector<vector<TipFun>> izlaz;

    UvrnutaRazlikaPomocna(s1_poc, s1_kraj, s2_poc, s2_kraj, fun, izlaz);

    return izlaz;

}

template <typename ItS1, typename ItS2, typename TipF>
auto UvrnutaRazlika(ItS1 s1_poc, ItS1 s1_kraj, ItS2 s2_poc, ItS2 s2_kraj, TipF fun) -> vector<vector<decltype(*s1_poc + 1)>> {
    typedef decltype(*s1_poc + 1) TipFun;

    std::vector<std::vector<TipFun>> izlaz;

    UvrnutaRazlikaPomocna(s1_poc, s1_kraj, s2_poc, s2_kraj, fun, izlaz);

    return izlaz;

}

int main(){
    deque<int> s1;
    deque<int> s2;

    int n, v;
    cout << "Unesite broj elemenata prvog kontejnera: ";
    cin >> n;

    cout << "Unesite elemente prvog kontejnera: ";
    for(int i = 0; i < n; i++){
        cin >> v;
        while (find(s1.begin(), s1.end(), v) != s1.end())
        	cin >> v;
        s1.push_back(v);
    }

    cout << "Unesite broj elemenata drugog kontejnera: ";
    cin >> n;

    cout << "Unesite elemente drugog kontejnera: ";
    for(int i = 0; i < n; i++){
        cin >> v;
        while (find(s2.begin(), s2.end(), v) != s2.end())
        	cin >> v;
        s2.push_back(v);
    }

    cout << "Uvrnuti presjek kontejnera:\n";
    std::vector<std::vector<int>> izlaz = UvrnutiPresjek(s1.begin(), s1.end(), s2.begin(), s2.end(), [](int x) {
    	int suma = 0;
    	while(x != 0){
    		suma += x%10;
    		x/=10;
    	}
    	return suma;
    });
    for(int i = 0; i < izlaz.size(); i++){
        for(int j = 0; j < 3; j++)
            cout << setw(6) << izlaz[i][j] << " ";
        cout << "\n";
    }

    cout << "Uvrnuta razlika kontejnera:\n";
    izlaz = UvrnutaRazlika(s1.begin(), s1.end(), s2.begin(), s2.end(), BrojProstihFaktora);
    for(int i = 0; i < izlaz.size(); i++){
        for(int j = 0; j < 2; j++)
            cout << setw(6) << izlaz[i][j] << " ";
        cout << "\n";
    }

    cout << "Dovidjenja!";
	return 0;
}