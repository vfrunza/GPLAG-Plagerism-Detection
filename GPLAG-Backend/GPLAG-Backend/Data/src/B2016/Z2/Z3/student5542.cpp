#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>

int SumaCifara(long long int broj) {
    int suma=0;
    int cifra;
    while(broj!=0) {
        cifra=broj%10;
        suma+=cifra;
        broj=broj/10;
    }
    
    return suma;
    
}
int SumaDjelilaca(long long int broj) {
    int suma=0;
    for(int i=1; i<=abs(broj); i++) {
        if(broj%i==0) suma+=i;
    }
    return suma;
}

bool DaLiJeProst(long long int broj)
{
	bool k=true;
	for(int i=2; i<broj; i++)
	{
		if(broj%i==0) k=false;
	}
	
	return k;
}
int BrojProstihFaktora(long long int broj)
{
	int suma=0;
	
	for(int i=2;i<=broj; i++)
		{
			while(broj%i==0)
			{
				if(DaLiJeProst(i)) 
				{
					suma++;
				broj=broj/i;
				}
			}
		}
	return suma;
}

int BrojSavrsenihDjelilaca(long long int broj) {
    
    int savrsen =0;
    int brojac=0;
    int sumadjeliocadjelioca=0;
    int djelioc;
    
    for(int i=2; i<=broj; i++) {
        if(broj%i==0){ djelioc=i;
        
        sumadjeliocadjelioca=0;
        for(int j=1; j<djelioc; j++) {
        if(djelioc%j==0) sumadjeliocadjelioca+=j;
        }
        if(djelioc==sumadjeliocadjelioca) savrsen=1;
        
        if(savrsen==1) brojac++;
        
        savrsen=0;
        }
    }
    
    return brojac;
}

template <typename POKIT, typename POKIT1, typename NekiTip1, typename NekiTip2>
    auto     UvrnutiPresjek(POKIT p1, POKIT p2, POKIT1 p3, POKIT1 p4, NekiTip1 f(NekiTip2)) -> std::vector<std::vector<decltype(0+*p1)>> {
            std::vector<std::vector<decltype(*p1+0)>> matrica;
            
            int k=0;
            auto pok=p3;
            
            while(p1<p2) {
                p3=pok;
                while(p3<p4) {

        
                    if(f(*p1)==f(*p3)) {
                        matrica.resize(k+1);
                        matrica[k].resize(3);
                        
                        matrica[k][0]=*p1;
                        matrica[k][1]=*p3;
                        matrica[k][2]=f(*p1);
                        k++;
                    }
                p3++;
                
                }
                p1++;
                
            }
            
            std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype(*p1+0)> v1, std::vector<decltype(*p1+0)> v2) {
                if(v1[2]==v2[2]) {
                    if(v1[0]==v2[0]) {
                        return v1[1]<v2[1];
                        
                    }
                    else return v1[0]<v2[0];
                }
                else return v1[2]<v2[2];
            });
            
            return matrica;
            
        }
        
template <typename POKIT, typename POKIT1>
    auto     UvrnutiPresjek(POKIT p1, POKIT p2, POKIT1 p3, POKIT1 p4) -> std::vector<std::vector<decltype(0+*p1)>> {
        std::vector<std::vector<decltype(*p1+0)>> matrica;
        int k=0;
        auto pok=p3;
        while(p1<p2) {
            p3=pok;
            while(p3<p4) {
                if(*p1==*p3) {
                    matrica.resize(k+1);
                    matrica[k].resize(3);
                    matrica[k][0]=*p1; 
                    matrica[k][1]=0;
                    matrica[k][2]=0;
                    k++; break;
                }
                p3++;
            }
            p1++;
        }
         std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype(*p1+0)> v1, std::vector<decltype(*p1+0)> v2) {
                if(v1[2]==v2[2]) {
                    if(v1[0]==v2[0]) {
                        return v1[1]<v2[1];
                        
                    }
                    else return v1[0]<v2[0];
                }
                else return v1[2]<v2[2];
            });
        return matrica;
    }
    
template <typename POKIT, typename POKIT1, typename NekiTip1, typename NekiTip2>
    auto     UvrnutaRazlika(POKIT p1, POKIT p2, POKIT1 p3, POKIT1 p4, NekiTip1 f(NekiTip2)) -> std::vector<std::vector<decltype(0+*p1)>> {
        
        std::vector<std::vector<decltype(*p1+0)>> matrica;
        bool a=true;
        int k=0;
        auto pok=p3;
        auto pok1=p1;
        while(p1<p2) {
            a=true;
            p3=pok;
            while(p3<p4) {
                if(f(*p1)==f(*p3)) a=false;
                p3++;
            }
            if(a==true) {
                matrica.resize(k+1);
                matrica[k].resize(2);
                matrica[k][0]=*p1;
                matrica[k][1]=f(*p1);
                k++;
            }
            p1++;
        }
        p3=pok;
        p1=pok1;
        auto pok2=p1;
        while(p3<p4) {
            a=true;
            p1=pok2;
            while(p1<p2) {
                if(f(*p3)==f(*p1)) a=false;
                p1++;
            }
            if(a==true) {
                matrica.resize(k+1);
                matrica[k].resize(2);
                matrica[k][0]=*p3;
                matrica[k][1]=f(*p3);
                k++;
            }
            p3++;
        }
         std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype(*p1+0)> v1, std::vector<decltype(*p1+0)> v2) {
                    if(v1[0]==v2[0]) {
                        return v1[1]>v2[1];
                        
                    }
                    else return v1[0]>v2[0];
                }
        );
        return matrica;
    }
template <typename POKIT, typename POKIT1>
    auto     UvrnutaRazlika(POKIT p1, POKIT p2, POKIT1 p3, POKIT1 p4) -> std::vector<std::vector<decltype(0+*p1)>> {
        
        std::vector<std::vector<decltype(*p1+0)>> matrica;
        auto pomocni(p3);
        auto pomocni1(p1);
        bool ima;
        int i=0;
        while(p1!=p2) {
            ima=0;
            p3=pomocni;
            while(p3!=p4) {
                if(*p1==*p3) { ima=1; break; }
                p3++;
                
            }
            if(ima==0) {
                matrica.resize(i+1);
                matrica[i].resize(2);
                matrica[i][0]=*p1; 
                matrica[i][1]=0;
                i++;
            }
            
            
            p1++;
        }
        p3=pomocni;
        while(p3<p4) {
            ima=0;
            p1=pomocni1;
            while(p1<p2) {
                if(*p3==*p1) { ima=1; break; }
                p1++;
            }
            if(ima==0) {
                matrica.resize(i+1);
                matrica[i].resize(2);
                matrica[i][0]=*p3; 
                matrica[i][1]=0;
                i++;
            }
            p3++;
        }
         std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype(*p1+0)> v1, std::vector<decltype(*p1+0)> v2) {
                    if(v1[0]>v2[0])
                    return true;
                    else return false;
         }
        );
      
        
        return matrica;
        
    }

int main ()
{
    int n1, n2;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> n1;
    std::deque<int> d1;
    std::deque<int> d2;
    int broj;
    bool isti=0;
    std::cout << "Unesite elemente prvog kontejnera: ";
    for(int i=0; i<n1; i++) {
        std::cin >> broj;
        isti =0;
        for(int j=0; j<d1.size(); j++) {
            if(d1[j]==broj) { isti=1;
            i--;
            }
        }
        if(isti==0) d1.push_back(broj);
    }
    
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> n2;
    
    std::cout << "Unesite elemente drugog kontejnera: ";
    for(int i=0; i<n2; i++) {
        std::cin >> broj;
        isti =0;
        for(int j=0; j<d2.size(); j++) {
            if(d2[j]==broj){ isti=1;
            i--;
            }
        }
        if(isti==0) d2.push_back(broj);
    }
    
    std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
    
    
    
    auto matrica1=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    
    for(int i=0; i<matrica1.size(); i++) {
        for(int j=0; j<matrica1[0].size(); j++) {
            std::cout << std::setw(6) << matrica1[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
    
    auto matrica2=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    
    for(int i=0; i<matrica2.size(); i++) {
        for(int j=0; j<matrica2[0].size(); j++) {
            std::cout << std::setw(6) << matrica2[i][j]<<" ";
        }
        std::cout << std::endl;
    }
   
   std::cout << "Dovidjenja!";
    
   
	return 0;
}