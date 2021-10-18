#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <vector>
#include <deque>
int SumaCifri(long long int x){
    if(x==0)return 0;
    return abs(x%10)+abs(SumaCifri(x/10));
}
int SumaDjelilaca(long long int x){
    int suma(0);
    if(x >= 0)
        for(int i(1);i <= x;i++){
            if(x%i==0)suma+=i;
        }
    else for(int i(-1);i >= x;i--){
        if(x%i==0)suma+=abs(i);
    }

    return suma;
}
int BrojProstihFaktora(long long int x){
    int brojac(0);
    if(x >= 0)
        for(int i(2);i <= x;i++){
            if(x%i==0){
                while(x%i==0)x/=i,brojac++;
            }
        }
    else for(int i(-2);i >= x;i--){
            if(x%i==0){
                while(x%i==0)x/=i,brojac++;
            }
        }
    return brojac;
}
int BrojSavrsenihDjelilaca(long long int x){
    int brojac(0);
    if(x >= 0)
        for(int i(1);i <= x;i++){
            if(x%i==0 && abs(i)==SumaDjelilaca(i)-abs(i))brojac++;
        }
    else for(int i(-1);i >= x;i--){
            if(x%i==0 && abs(i)==SumaDjelilaca(i)-abs(i))brojac++;
        }
    return brojac;
}
template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
    auto UvrnutiPresjek(Tip1 beg1,Tip1 end1,Tip2 beg2,Tip2 end2,Tip3 funk(Tip4)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type>>{
        
        std::vector<std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type>> matrica;
        
        while(beg1 != end1){
            Tip2 tmp(beg2);
            while(tmp != end2){
                if(funk(*beg1) == funk(*tmp)){
                 
                   matrica.push_back({*beg1,*tmp,funk(*beg1)});
                }
                tmp++;
            }
            beg1++;
        }
        std::sort(std::begin(matrica),std::end(matrica),[](std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type> x,std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type> y){
            if(x[2] < y[2]){
                return true;
            }else if(x[2] > y[2]){
                return false;
            }else{
                if(x[0] < y[0]) return true;
                else if(x[0] > y[0]) return false;
                else{
                    return x[1] < y[1];
                }
            }
        });
        return matrica;
    }
template <typename Tip1,typename Tip2>
    auto UvrnutiPresjek(Tip1 beg1,Tip1 end1,Tip2 beg2,Tip2 end2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*beg1)>::type>>{
        
        std::vector<std::vector<typename std::remove_reference<decltype(*beg1)>::type>> matrica;
        
        while(beg1 != end1){
            Tip2 tmp(beg2);
            while(tmp != end2){
                if(*beg1 == *tmp){
                 
                   matrica.push_back({*beg1,0,0});
                }
                tmp++;
            }
            beg1++;
        }
        std::sort(std::begin(matrica),std::end(matrica));
        return matrica;
    }	
	
template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
    auto UvrnutaRazlika(Tip1 beg1,Tip1 end1,Tip2 beg2,Tip2 end2,Tip3 funk(Tip4)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type>> matrica;
	Tip1 tmp1(beg1);
	Tip2 tmp2(beg2);
	while(tmp1!=end1){
	    Tip2 tmp(beg2);
	    bool x(true);
	    while(tmp != end2){
	        if(funk(*tmp1) == funk(*tmp)){
	            x = false;
	            break;
	        }
	       
	        tmp++;
	    }
	     if(x){
	            matrica.push_back({*tmp1,funk(*tmp1)});
	        }
	    tmp1++;
	}
	while(tmp2!=end2){
	    Tip1 tmp(beg1);
	    bool x(true);
	    while(tmp != end1){
	        if(funk(*tmp2) == funk(*tmp)){
	            x = false;
	            break;
	        }
	       
	        tmp++;
	    }
	     if(x){
	            matrica.push_back({*tmp2,funk(*tmp2)});
	        }
	    tmp2++;
	}
	std::sort(std::begin(matrica),std::end(matrica),[](std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type> x,std::vector<typename std::remove_reference<decltype(funk(*beg1))>::type> y){
            if(x[0] < y[0]){
                return false;
            }else if(x[0] > y[0]){
                return true;
            }else{
                return x[1] > y[1];
            }
        });
	return matrica;
    }
template <typename Tip1,typename Tip2>
    auto UvrnutaRazlika(Tip1 beg1,Tip1 end1,Tip2 beg2,Tip2 end2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*beg1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*beg1)>::type>> matrica;
	Tip1 tmp1(beg1);
	Tip2 tmp2(beg2);
	while(tmp1!=end1){
	    Tip2 tmp(beg2);
	    bool x(true);
	    while(tmp != end2){
	        if(*tmp1 == *tmp){
	            x = false;
	            break;
	        }
	       
	        tmp++;
	    }
	     if(x){
	            matrica.push_back({*tmp1,0});
	        }
	    tmp1++;
	}
	while(tmp2!=end2){
	    Tip1 tmp(beg1);
	    bool x(true);
	    while(tmp != end1){
	        if(*tmp2 == *tmp){
	            x = false;
	            break;
	        }
	       
	        tmp++;
	    }
	     if(x){
	            matrica.push_back({*tmp2,0});
	        }
	    tmp2++;
	}
	std::sort(matrica.rbegin(),matrica.rend());
	return matrica;
    }
int main ()
{
    int n;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> n;
    std::deque<int> a;
    std::cout << "Unesite elemente prvog kontejnera: ";
    for(int i(0);i < n;i++){
        int x;
        bool test(true);
        std::cin >> x;
        for(int j(0);j < i;j++){
            if(a[j]==x){
                test=false;
                break;
                
            }
        }
        if(test)a.push_back(x);
        else i--;
    }
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> n;
    std::deque<int> b;
    std::cout << "Unesite elemente drugog kontejnera: ";
    for(int i(0);i < n;i++){
        int x;
        bool test(true);
        std::cin >> x;
        for(int j(0);j < i;j++){
            if(b[j]==x){
                test=false;
                break;
                
            }
        }
        if(test)b.push_back(x);
        else i--;
    }
    
    std::cout << "Uvrnuti presjek kontejnera:\n";
    auto matrica(UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifri));
    for(auto x: matrica){
        for(auto y:x)std::cout << std::setw(6) << y << " ";
        std::cout << "\n";
    }
    std::cout << "Uvrnuta razlika kontejnera:\n";
    matrica =(UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora));
    for(auto x: matrica){
        for(auto y: x)std::cout << std::setw(6) << y << " ";
        std::cout << "\n";
    }
    std::cout << "Dovidjenja!";
	return 0;
}