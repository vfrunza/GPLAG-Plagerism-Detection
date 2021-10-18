#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>

template <typename T1>
auto makni_referencu(T1 &sa_referencom, T1 bez_reference) -> decltype(bez_reference) {
    return bez_reference;
}

template <typename T1, typename T2, typename T3, typename T4>
auto UvrnutiPresjek(T1 a, T1 b, T2 p, T2 q, T3 f(T4)) -> decltype(std::vector<std::vector<decltype(makni_referencu(*a, *a))>>()) {
    typedef decltype(makni_referencu(*a, *a)) Element;
    std::vector<std::vector<Element>> ret;
    
	for (T1 i = a; i != b; i++) {
	    T3 tmp(f(*i));
	    for (T2 j = p; j != q; j++) {
	        if (tmp == f(*j)) {
	            ret.push_back({*i, *j, tmp});
	        }
	    }
	}
	
	std::sort(ret.begin(), ret.end(), [](std::vector<Element> x, std::vector<Element> y){
	    if (x.at(2) != y.at(2)) return x.at(2) < y.at(2);
	    if (x.at(0) != y.at(0)) return x.at(0) < y.at(0);
	    return x.at(1) < y.at(1);
	});
	
	return ret;
}

template <typename T1, typename T2>
auto UvrnutiPresjek(T1 a, T1 b, T2 p, T2 q) -> decltype(std::vector<std::vector<decltype(makni_referencu(*a, *a))>>()) {
    typedef decltype(makni_referencu(*a, *a)) Element;
    std::vector<std::vector<Element>> ret;
    
    for (T1 i = a; i != b; i++) {
        for (T2 j = p; j != q; j++) {
            if (*i == *j) {
                ret.push_back({*i, 0, 0});
            }
        }
    }
    
     std::sort (ret.begin(), ret.end(), [](std::vector<Element> x, std::vector<Element> y) {
        return x[0] < y[0]; 
    });
    
    return ret;
}

template <typename T1, typename T2, typename T3, typename T4>
auto UvrnutaRazlika(T1 a, T1 b, T2 p, T2 q, T3 f(T4)) -> decltype(std::vector<std::vector<decltype(makni_referencu(*a, *a))>>()) {
    typedef decltype(makni_referencu(*a, *a)) Element;
    std::vector<std::vector<Element>> ret;
    
    for (T1 i = a; i != b; i++) {
        bool nasao(false);
        Element tmp(f(*i));
        
        for (T2 j = p; j != q; j++) {
            if (tmp == f(*j)) {
                nasao = true;
                break;
            }
        }
        
        if (!nasao) {
            ret.push_back({*i, tmp});
        }
    }
    
    for (T2 i = p; i != q; i++) {
        bool nasao(false);
        Element tmp(f(*i));
        
        for (T2 j = a; j != b; j++) {
            if (tmp == f(*j)) {
                nasao = true;
                break;
            }
        }
        
        if (!nasao) {
            ret.push_back({*i, tmp});
        }
    }
    
    std::sort (ret.begin(), ret.end(), [](std::vector<Element> x, std::vector<Element> y) {
        return x[0] > y[0]; 
    });
    
    return ret;
}

template <typename T1, typename T2>
auto UvrnutaRazlika(T1 a, T1 b, T2 p, T2 q) -> decltype(std::vector<std::vector<decltype(makni_referencu(*a, *a))>>()) {
    typedef decltype(makni_referencu(*a, *a)) Element;
    std::vector<std::vector<Element>> ret;
    
    for (T1 i = a; i != b; i++) {
        bool nasao(false);

        for (T2 j = p; j != q; j++) {
            if (*i == *j) {
                nasao = true;
                break;
            }
        }
        
        if (!nasao) {
            ret.push_back({*i, 0});
        }
    }
    
    for (T2 i = p; i != q; i++) {
        bool nasao(false);

        for (T2 j = a; j != b; j++) {
            if (*i == *j) {
                nasao = true;
                break;
            }
        }
        
        if (!nasao) {
            ret.push_back({*i, 0});
        }
    }
    
    std::sort (ret.begin(), ret.end(), [](std::vector<Element> x, std::vector<Element> y) {
        return x[0] > y[0]; 
    });
    
    return ret;
}

int SumaCifara(long long n) {
    int sum(0);
    n = std::abs(n);
    
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int SumaDjelilaca(long long n) { // prolazi li spora funkcija ?
    if (n == 0) return 0;

    n = std::abs(n);
    int sum(n + 1), sqrt(std::sqrt(n));
    
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            sum += i + n / i;
        }
    }
    
    if (sqrt * sqrt == n) sum -= sqrt;
    
    return sum;
}

int BrojProstihFaktora(long long n) {
    int cnt(0);
    
    for (int i = 2; n > 1; i++) {
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
    }
    
    return cnt;
}

int BrojSavrsenihDjelilaca(long long n) {
    int cnt(0), N(std::abs(n));
    
    for (int i = 2; i <= N; i++) {
        if (N % i == 0 && SumaDjelilaca(i) - i == i) cnt++; 
    }
    
    return cnt;
}

int main () {
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    int n; std::cin >> n;
    std::deque<int> d1(n);
    
    std:: cout << "Unesite elemente prvog kontejnera: ";
    for (int i = 0; i < n;) {
        std::cin >> d1[i];
        
        bool ponavljanje(false);
        for (int j = i - 1; j >= 0; j--) {
            if (d1[j] == d1[i]) {
                ponavljanje = true;
                break;
            }
        }
        
        if (!ponavljanje) i++;
    }
    
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    int m; std::cin >> m;
    std::deque<int> d2(m);
    
    std::cout << "Unesite elemente drugog kontejnera: ";
    
    for (int i = 0; i < m;) {
        std::cin >> d2[i];
        
        bool ponavljanje(false);
        for (int j = i - 1; j >= 0; j--) {
            if (d2[j] == d2[i]) {
                ponavljanje = true;
                break;
            }
        }
        
        if (!ponavljanje) i++;
    }
    
    auto presjek = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    auto razlika = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    
    std::cout << "Uvrnuti presjek kontejnera:\n";
    for (int i = 0; i < presjek.size(); i++) {
        std::cout << std::setw(6) << presjek[i][0] << " " << std::setw(6) << presjek[i][1] << " " << std::setw(6) << presjek[i][2] << std::endl;
    }
    
    std::cout << "Uvrnuta razlika kontejnera:\n";
    for (int i = 0; i < razlika.size(); i++) {
        std::cout << std::setw(6) << razlika[i][0] << " " << std::setw(6) << razlika[i][1] << std::endl;
    }
    
    
    std::cout << "Dovidjenja!" << std::endl;
    
	return 0;
}