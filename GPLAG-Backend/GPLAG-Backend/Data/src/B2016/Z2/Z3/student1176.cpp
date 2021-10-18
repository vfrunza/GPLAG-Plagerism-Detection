#include<iostream>
#include<vector>
#include<deque> 
#include<algorithm>  
#include<iomanip>
#include<type_traits>   
int SumaCifara(long long int x){
    int n=std::abs(x);
    int suma(0);
    while(n!=0){
        suma+=n%10;
        n/=10;
    } 
    return suma;
}
int SumaDjelilaca(long long int x){
    int suma(0); 
    for(int i(1); i<=x; i++){
        if(x%i==0) suma+=i;
    } 
    return suma;
} 
int BrojProstihFaktora(long long int x){
    int br1(0), br2(0); 
    for(int i(2); i<x; i++){
        if(x%i==0){
            for(int j(1); j<=i; j++){
                if(i%j==0) br1++;
            } 
        } 
        if(br1==2) br2++; 
        br1=0;
    } 
    return br2;
} 
int BrojSavrsenihDjelilaca(long long int x){
    int br(0), suma(0); 
    for(int i(2); i<x; i++){
        if(x%i==0){
            for(int j(1); j<i; j++){
                if(i%j==0) suma+=j;
            }  
            if(suma==i) br++;
        }  
        suma=0;
    } 
    return br;
}
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratni(100);
    int i(0); 
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    while(p1!=p2){ 
        while(pomocni3!=pomocni4){
            if(f(*p1)==f(*pomocni3)){
            povratni[i].push_back(*p1);
            povratni[i].push_back(*pomocni3);
            povratni[i].push_back(f(*p1));
            i++; 
            }
        pomocni3++; 
        }
    pomocni3=p3;
    p1++;
    }  
    povratni.resize(i);
    std::sort(povratni.begin(), povratni.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
        if(v2[2]>v1[2]) return true; else if(v1[2]==v2[2] && v2[0]>v1[0]) return true; else if(v1[2]==v2[2] && v1[0]==v2[0] && v2[1]>v1[1]) return true; else return false;});
    return povratni;
}   
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratni;
    int i(0); 
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    while(p1!=p2){ 
        while(pomocni3!=pomocni4){
            if(*p1==*pomocni3){ 
            povratni.resize(i+1);
            povratni[i].push_back(*p1);
            povratni[i].push_back(0); 
            povratni[i].push_back(0);
            i++; 
            }
        pomocni3++; 
        }
    pomocni3=p3;
    p1++;
    }  
    povratni.resize(i);
    std::sort(povratni.begin(), povratni.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
        if(v2[0]>v1[0]) return true;  else return false;});
    return povratni;
}  
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))->  std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratni; 
    int br(0);
    int i(0); 
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    Tip1 pomocni1=p1;
    Tip1 pomocni2=p2;
    while(p1!=p2){
        while(pomocni3!=pomocni4){
            if(f(*p1)==f(*pomocni3)) br++; 
            pomocni3++;
        }  
        if(br==0){  
            povratni.resize(i+1);
            povratni[i].push_back(*p1);
            povratni[i].push_back(f(*p1)); 
            i++;
        }  
        br=0;
        pomocni3=p3; 
        p1++;
    } 
    br=0; 
    p1=pomocni1;
    p2=pomocni2;
    pomocni3=p3;
    while(pomocni3!=pomocni4){
        while(pomocni1!=pomocni2){
            if(f(*pomocni3)==f(*p1)) br++; 
            pomocni1++;
        } 
        if(br==0){  
            povratni.resize(i+1);
            povratni[i].push_back(*pomocni3);
            povratni[i].push_back(f(*pomocni3)); 
            i++;
        }   
        br=0;
        pomocni1=p1; 
        pomocni3++;
    }   
    std::sort(povratni.begin(), povratni.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
        if(v2[0]<v1[0]) return true; else if(v1[0]==v2[0] && v2[1]<v1[1]) return true;  else return false;});
    return povratni;
}    
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)->  std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratni; 
    int br(0);
    int i(0); 
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    Tip1 pomocni1=p1;
    Tip1 pomocni2=p2;
    while(p1!=p2){
        while(pomocni3!=pomocni4){
            if(*p1==*pomocni3) br++; 
            pomocni3++;
        }  
        if(br==0){ 
            povratni.resize(i+1);
            povratni[i].push_back(*p1);
            povratni[i].push_back(0); 
            i++;
        }                 
        br=0;
        pomocni3=p3; 
        p1++;
    } 
    br=0; 
    p1=pomocni1;
    p2=pomocni2;
    pomocni3=p3;
    while(pomocni3!=pomocni4){
        while(pomocni1!=pomocni2){
            if(*pomocni3==*p1) br++; 
            pomocni1++;
        } 
        if(br==0){ 
            povratni.resize(i+1);
            povratni[i].push_back(*pomocni3);
            povratni[i].push_back(0); 
            i++;
        }   
        br=0;
        pomocni1=p1; 
        pomocni3++;
    }   
    std::sort(povratni.begin(), povratni.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
        if(v2[0]<v1[0]) return true; else return false;});
    return povratni;
}  
int main(){
    int a, b, x;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> a; 
    std::deque<int> d1; 
    std::cout<<"Unesite elemente prvog kontejnera: ";  
    std::cin>>x; 
    d1.push_back(x);
    int br1(1), br2(0);
    while(br1!=a){
        std::cin >> x;
        for(int i(0); i<br1; i++){
            if(x==d1[i]) br2++;
        } 
        if(br2==0){ 
            d1.push_back(x);  
            br1++;
        }  
        br2=0;
    }
    std::cout << "Unesite broj elemenata drugog kontejnera: "; 
    std::cin >> b;  
    std::deque<int> d2;  
    br1=1;
    br2=0;
    std::cout<<"Unesite elemente drugog kontejnera: ";  
    std::cin >> x;
    d2.push_back(x);
     while(br1!=b){
        std::cin >> x;
        for(int i(0); i<br1; i++){
            if(x==d2[i]) br2++;
        } 
        if(br2==0){ 
            d2.push_back(x);  
            br1++;
        }  
        br2=0;
    }
    std::vector<std::vector<int>> Presjek=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    std::vector<std::vector<int>> Razlika=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
    for(int i(0); i<Presjek.size(); i++){
        for(int j(0); j<Presjek[i].size(); j++){ 
            if(j==0) std::cout << std::setw(6) << Presjek[i][j]; 
            else if(j==Presjek[i].size()-1) std::cout << " " << std::setw(6) << Presjek[i][j] << " "; 
            else std::cout << " " << std::setw(6) << Presjek[i][j];
        } 
        std::cout << std::endl;
    } 
    std::cout << std::endl << "Uvrnuta razlika kontejnera:" << std::endl;
    for(int i(0); i<Razlika.size(); i++){
        for(int j(0); j<Razlika[i].size(); j++) std::cout << " " << std::setw(6) << Razlika[i][j]; 
        std::cout << std::endl;
    } 
    std::cout << "Dovidjenja!";
    return 0;
}