#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>

template <typename PokTip1, typename PokTip2, typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek (PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip2 p4, NekiTip1 f(NekiTip2)) -> std::vector<std::vector<NekiTip1>> {
    std::vector<std::vector<NekiTip1>> mat;
    while (p1!=p2) {
        PokTip2 pom(p3);
        while (pom!=p4) {
            if (f(*p1)==f(*pom)) {
                std::vector<NekiTip1> v;
                v.push_back(*p1);
                v.push_back(*pom);
                v.push_back(f(*pom));
                mat.push_back(v);
            }
            pom++;
        }
        p1++;
    }
    sort (mat.begin(), mat.end(), [] (std::vector<NekiTip1> a, std::vector<NekiTip1> b) {
       return a[2]<b[2] || (a[2]==b[2] && a[0]<b[0]) || (a[2]==b[2] && a[0]==b[0] && a[1]<b[1]);
    });
    return mat;
}

template <typename PokTip1, typename PokTip2, typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika (PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip2 p4, NekiTip1 f(NekiTip2)) -> std::vector<std::vector<NekiTip1>> {
    std::vector<std::vector<NekiTip1>> mat;
    PokTip1 tmp(p1);
    while (tmp!=p2) {
        bool postoji(false);
        PokTip2 pom(p3);
        while (pom!=p4) {
            if (f(*tmp)==f(*pom)) {
                postoji=true;
            }
            pom++;
        }
        if (postoji==false) {
            std::vector<NekiTip1> v;
            v.push_back(*tmp);
            v.push_back(f(*tmp));
            mat.push_back(v);
        }
        tmp++;
    }
    while (p3!=p4) {
        bool postoji(false);
        PokTip1 pom(p1);
        while (pom!=p2) {
            if (f(*p3)==f(*pom)) {
                postoji=true;
            }
            pom++;
        }
        if (postoji==false) {
            std::vector<NekiTip1> v;
            v.push_back(*p3);
            v.push_back(f(*p3));
            mat.push_back(v);
        }
        p3++;
    }
    sort (mat.begin(), mat.end(), [] (std::vector<NekiTip1> a, std::vector<NekiTip1> b) {
       return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]); 
    });
    return mat;
}

int SumaCifara (long long int n) {
    if (n<0) n=n*(-1);
    int suma(0);
    while (n!=0) {
        suma=suma+n%10;
        n/=10;
    }
    return suma;
}

int SumaDjelilaca (long long int n) {
    if (n<0) n=n*(-1);
    int suma(0);
    for (int i=1; i<=n; i++) 
        if (n%i==0) suma+=i;
    return suma;
}

int BrojProstihFaktora (long long int n) {
    if (n<0) n=n*(-1);
    int br(0), i(2);
    while (n!=1) {
        if (n%i==0) 
            while (n%i==0) {
                n=n/i;
                br++;
            }
        i++;
    }
    return br;
}

int BrojSavrsenihDjelilaca (long long int n) {
    if (n<0) n=n*(-1);
    int br(0);
    for (int i=1; i<=n; i++) {
        int suma(0);
        if (n%i==0) {
            for (int j=1; j<i; j++) 
                if (i%j==0) suma+=j;
        }
        if (suma==i) br++;
    }
    return br;
}

int main ()
{ 
    int n;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> n;
    if (n<0) return 0;
    std::deque<int> d1;
    std::cout << "Unesite elemente prvog kontejnera: ";
    int broj;
    do {
        int postoji(false);
        std::cin >> broj;
        for (int i=0; i<d1.size(); i++) 
            if (broj==d1[i])
                postoji=true;
        if (postoji==false) 
            d1.push_back(broj);
    }while (d1.size()<n);
    int m;
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> m;
    if (n<0) return 0;
    std::deque<int> d2;
    std::cout << "Unesite elemente drugog kontejnera: ";
    do {
        int postoji(false);
        std::cin >> broj;
        for (int i=0; i<d2.size(); i++) 
            if (broj==d2[i])
                postoji=true;
        if (postoji==false) 
            d2.push_back(broj);
    }while (d2.size()<m);
    std::vector<std::vector<int>> m1;
    m1=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
    std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
    for (int i=0; i<m1.size(); i++) { 
        for (int j=0; j<m1[i].size(); j++)
            std::cout << std::setw(6) << m1[i][j] << " ";
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> m2;
    m2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
    std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
    for (int i=0; i<m2.size(); i++) { 
        for (int j=0; j<m2[i].size(); j++)
            std::cout << std::setw(6) << m2[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Dovidjenja!";
	return 0;
}