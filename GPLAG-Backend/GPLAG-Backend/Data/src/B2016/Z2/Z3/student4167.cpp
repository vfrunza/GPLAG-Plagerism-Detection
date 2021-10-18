#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <type_traits>

int SumaCifara(long long int n) {
    int suma(0);
    while(n!=0) {
        suma+=n%10;
        n/=10;
    }
    return suma;
}

int SumaDjelilaca(long long int n) {
    int suma(0);
    if(n<0) n=-n;
    for(int i(1); i<=n; i++)
        if(n%i==0)
            suma+=i;
    return suma;
}

int BrojProstihFaktora(long long int n) {
    int broj(0);
    for(int i(2); i<=n; i++)
        if(n%i==0) {
            broj++;
            n/=i;
            i=1;
        }
    return broj;
}

int BrojSavrsenihDjelilaca(long long int n) {
    int broj(0);
    for(int i(n); i>1; i--)
        if(n%i==0) {
            int suma(0);
            for(int j(1); j<i; j++)
                if(i%j==0) {
                    suma+=j;
                }
            if(suma==i) {
                broj++;
                n/=i;
                i=n+1;
            }
        }
    return broj;
}

template <typename tip1, typename tip2, typename tip3>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip3 f) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> mat;
    int i(0);
    tip2 p(p3);
    while(p1!=p2) {
        while(p3!=p4) {
            if(f(*p1)==f(*p3)) {
                mat.resize(++i);
                mat[i-1].push_back(*p1);
                mat[i-1].push_back(*p3);
                mat[i-1].push_back(f(*p1));
            }
            p3++;
        }
        p3=p;
        p1++;
    }
    std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> d1, std::vector<typename std::remove_reference<decltype(*p1)>::type> d2) {if(d1[2]>d2[2]) return false;
                                                                                  if(d1[2]==d2[2]) {
                                                                                      if(d1[0]>d2[0]) return false;
                                                                                      if(d1[0]==d2[0]) {
                                                                                          if(d1[1]>d2[1]) return false;
                                                                                      }
                                                                                  }
                                                                                  return true; });
    return mat;
}

template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 p3, tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> mat;
    int i(0);
    tip2 p(p3);
    while(p1!=p2) {
        while(p3!=p4) {
            if(*p1==*p3) {
                mat.resize(++i);
                mat[i-1].push_back(*p1);
                mat[i-1].push_back(0);
                mat[i-1].push_back(0);
            }
            p3++;
        }
        p3=p;
        p1++;
    }
    std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> d1, std::vector<typename std::remove_reference<decltype(*p1)>::type> d2) {if(d1[2]>d2[2]) return false;
                                                                                  if(d1[2]==d2[2]) {
                                                                                      if(d1[0]>d2[0]) return false;
                                                                                      if(d1[0]==d2[0]) {
                                                                                          if(d1[1]>d2[1]) return false;
                                                                                      }
                                                                                  }
                                                                                  return true; });
    return mat;
}

template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 p1, tip1 p2, tip2 p3, tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> mat;
    int i(0);
    tip2 p_3(p3);
    tip1 p_1(p1);
    bool a(true);
    while(p1!=p2) {
        a=true;
        while(p3!=p4) {
            if(*p1==*p3) {
                a=false;
            }
            p3++;
        }
        if(a) {
                mat.resize(++i);
                mat[i-1].push_back(*p1);
                mat[i-1].push_back(0);
        }
        p3=p_3;
        p1++;
    }
    p1=p_1; p3=p_3;
    while(p3!=p4) {
        a=true;
        while(p1!=p2) {
            if(*p3==*p1) {
                a=false;
            }
            p1++;
        }
        if(a) {
                mat.resize(++i);
                mat[i-1].push_back(*p3);
                mat[i-1].push_back(0);
        }
        p1=p_1;
        p3++;
    }
    std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> d1, std::vector<typename std::remove_reference<decltype(*p1)>::type> d2) {if(d1[0]<d2[0]) return false;
                                                                                  if(d1[0]==d2[0]) {
                                                                                      if(d1[1]<d2[1]) return false;
                                                                                  }
                                                                                  return true; });
    return mat;
    
}

template <typename tip1, typename tip2, typename tip3>
auto UvrnutaRazlika(tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip3 f) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> mat;
    int i(0);
    tip2 p_3(p3);
    tip1 p_1(p1);
    bool a(true);
    while(p1!=p2) {
        a=true;
        while(p3!=p4) {
            if(f(*p1)==f(*p3)) {
                a=false;
            }
            p3++;
        }
        if(a) {
                mat.resize(++i);
                mat[i-1].push_back(*p1);
                mat[i-1].push_back(f(*p1));
        }
        p3=p_3;
        p1++;
    }
    p1=p_1; p3=p_3;
    while(p3!=p4) {
        a=true;
        while(p1!=p2) {
            if(f(*p3)==f(*p1)) {
                a=false;
            }
            p1++;
        }
        if(a) {
                mat.resize(++i);
                mat[i-1].push_back(*p3);
                mat[i-1].push_back(f(*p3));
        }
        p1=p_1;
        p3++;
    }
    std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> d1, std::vector<typename std::remove_reference<decltype(*p1)>::type> d2) {if(d1[0]<d2[0]) return false;
                                                                                  if(d1[0]==d2[0]) {
                                                                                      if(d1[1]<d2[1]) return false;
                                                                                  }
                                                                                  return true; });
    return mat;
    
}
int main ()
{
    int m,n, broj;
    std::deque<int> d1, d2;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> m;
    std::cout << "Unesite elemente prvog kontejnera: ";
    while(d1.size()!=m) {
        bool a(true);
        std::cin >> broj;
        for(int x : d1)
            if(x==broj) a=false;
        if(a) d1.push_back(broj);
    }
    //std::cin.ignore(10000, '\n');
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> n;
    std::cout << "Unesite elemente drugog kontejnera: ";
    while(d2.size()!=n) {
        bool a(true);
        std::cin >> broj;
        for(int x : d2)
            if(x==broj) a=false;
        if(a) d2.push_back(broj);
    }
    std::vector<std::vector<int>> mat1, mat2;
    mat1 = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
    for(auto x : mat1) {
        for(auto y : x)
            std::cout << std::setw(6) << std::right << y << " ";
        std::cout << " " << std::endl;
    }
    
    /*mat3 = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end());
    std::cout << "Uvrnuto nesta kontejnera:" << std::endl;
    for(auto x : mat3) {
        for(auto y : x)
            std::cout << std::setw(6) << std::right << y << " ";
        std::cout << " " << std::endl;
    }*/
    
    mat2 = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
    for(auto x : mat2) {
        for(auto y : x)
            std::cout << std::setw(6) << std::right << y << " ";
        std::cout << " " << std::endl;
    }
    std::cout << "Dovidjenja!";
	return 0;
}