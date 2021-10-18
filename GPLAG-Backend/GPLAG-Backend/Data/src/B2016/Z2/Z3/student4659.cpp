/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <type_traits>
#include <iomanip>
template <typename Tip>
bool VecUVektoru(std::vector<Tip>v,Tip a){
    bool flag(true);
    for(int i=0;i<v.size();i++)if(v[i]==a)flag=false;
    return flag;
}

int SumaCifara(int x){
    int br(0);
    if(x<0)x=x*-1;
    while(x!=0){
        br=br+x%10;x=x/10;
    }
    return br;
}

int SumaDjelilaca(long long int n){
    int sum(0);
    if(n<0)n=n*-1;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    return sum;
}
bool DaLiJeProst (int n){
    for(int i=2;i<n;i++){
        if(i<=2 || i==3) return true;
        if(n%i==0)return false;
    }
    return true;
}

int BrojProstihFaktora(long long int n){
    int br(0);
    long long int a(n);
    for(int i=2;i<=n;i++){
        if(i==a){
            br=1;
            break;
        }
        if(n%i==0){
            if(DaLiJeProst(i)){
                br++;
                n=n/i;
                i=1;
            }    
        }
    }
    return br;
}

int Suma(int n){
    int sum(0);
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    return sum;
}

int BrojSavrsenihDjelilaca(long long int n){
    int br(0);
    for(int i=2;i<=n;i++){
        if(n%i==0){
            if( Suma(i)==i)br++;
        }
    } 
    return br;
}

template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
auto UvrnutiPresjek(Tip1 it1,Tip1 it2,Tip2 it3,Tip2 it4,Tip3 f(Tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> m;
    int br(0);

        while(it1!=it2){
            typename std::remove_reference<decltype(*it1)>::type a=f(*it1);
            Tip2 p(it3);
            while(p!=it4){
                if(a==f(*p)){
                    m.resize(++br);
                    m[br-1].resize(3);
                    m[br-1][0]=*it1;
                    m[br-1][1]=*p;
                    m[br-1][2]=a;
                }
                p++;
            }
            it1++;
        }
        std::sort(m.begin(),m.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type> x,std::vector<typename std::remove_reference<decltype(*it1)>::type> y){if(x[2]==y[2]){if(x[0]==y[0]){return x[1]<y[1];};return x[0]<y[0];}return x[2]<y[2];});
    return m;
}

template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
auto UvrnutaRazlika(Tip1 it1,Tip1 it2,Tip2 it3,Tip2 it4,Tip3 f( Tip4 ))->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> m;
    int br(0),flag(1);
    Tip2 p2(it3);
    Tip1 p3(it1);
        while(it1!=it2){
            flag=1;
            typename std::remove_reference<decltype(*it1)>::type a=f(*it1);
            Tip2 p(it3);
            while(p!=it4){
                if(a==f(*p))flag=0;
                p++;
            }
            if(flag){
                    m.resize(++br);
                    m[br-1].resize(2);
                    m[br-1][0]=*it1;
                    m[br-1][1]=a;
            }
            it1++;
        }
        while(p2!=it4){
            flag=1;
            typename std::remove_reference<decltype(*it1)>::type a=f(*p2);
            Tip1 p1(p3);
            while(p1!=it2){
                if(a==f(*p1))flag=0;
                p1++;
            }
            if(flag){
                m.resize(++br);
                m[br-1].resize(2);
                m[br-1][0]=*p2;
                m[br-1][1]=a;
            }
            p2++;
        }
        std::sort(m.begin(),m.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type>x,std::vector<typename std::remove_reference<decltype(*it1)>::type>y){if(x[0]==y[0])return x[1]>y[1]; return x[0]>y[0];});

    return m;    
}

int main ()
{
    int a(0);
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> a;
        std::vector<int>v1(a);
        std::cout << "Unesite elemente prvog kontejnera: ";
        for(int i=0;i<a;i++){
            int x(0);
            std::cin >> x;
            if(VecUVektoru(v1,x))v1[i]=x;
            else i--;
        }
    int b(0);
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> b;
        std::vector<int>v2(b);
        std::cout << "Unesite elemente drugog kontejnera: ";
        for(int i=0;i<b;i++){
            int x(0);
            std::cin >> x;
            if(VecUVektoru(v2,x))v2[i]=x;
            else i--;
        }
 
            std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
            std::vector<std::vector<int>> m;
            m=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
            
                for(int i=0;i<m.size();i++){
                    for(int j=0;j<3;j++){
                        std::cout << std::setw(6) << m[i][j] << " " ;
                    }
                    std::cout  << std::endl; 
                }
        
                    std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
                    std::vector<std::vector<int>> m1;
                    m1=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
                    
                        for(int i=0;i<m1.size();i++){
                            for(int j=0;j<2;j++){
                                std::cout << std::setw(6) << m1[i][j]<< " " ;
                            }
                            std::cout  << std::endl;
                        }
                        
                        std::cout << "Dovidjenja!" << std::endl;
	return 0;
}
