/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include<iomanip>
using namespace std;


int SumaDjelilaca(long long int x){
    
    int suma = 0;
    if(x >= 0){
        for(int i = 1 ; i <= x ; i++){
            if(x % i == 0){
                suma += i;
            }
        }
    }
    else{
        for(int i = -1 ; i >= x ; i--){
            if(x % i == 0){
                suma += -1 * i;
            }
        }
    }
    
    return suma;
}

bool DaLiJeProst(long long int x){
    
    for(int i = 2 ; i < x ; i++){
        if(x % i == 0){
            return false;
        }
    }
    
    return true;
}

int BrojProstihFaktora(long long int x){
    int broj = 0;
    
    int i = 2;      
    while(x != 1){
        
        if(x % i == 0){
            if(DaLiJeProst(i)){
                broj++;
            }
            x = x / i;
            i = 1;
        }
        i++; 
    }
    
    return broj;
}

bool DaLiJeSavrsen(long long int x){
    int suma = 0;
    for(int i = 1 ; i < x ; i++){
        if(x % i == 0){
            suma += i;
        }
    }
    if(suma == x){
        return true;
    }
    else{
        return false;
    }
    
}

int BrojSavrsenihDjelilaca(int x){
    int broj = 0;
    
    for(int i = 2 ; i <= x ; i++){
        if(x % i == 0) {
        }
        if(x % i == 0 && DaLiJeSavrsen(i)){
            broj++;
        }
    }
    
    return broj;
}

int ObicniPresjek(int x){
    return x;
}

template <typename Tip1, typename Tip2, typename Tip3>
auto UvrnutiPresjek(Tip1 poc_1, Tip1 kraj_1, Tip2 poc_2, Tip2 kraj_2, Tip3 fun) -> vector<vector<decltype(*poc_1 + *poc_2)>>{
    vector<vector<decltype(*poc_1 + *poc_2)>> v;
    decltype(*poc_1 + *poc_2) a;
    
    int k = 0;
    Tip1 pom = poc_1;
    while(poc_2 < kraj_2){
        
        if(fun(*pom) == fun(*poc_2)){
            
            bool provjera = true;
            for(int i = 0 ; i < v.size() ; i++){
                if((v[i][0] == *pom && v[i][1] == *poc_2)){
                    provjera = false;
                    break;
                }
            }
            
            if(provjera){
                k++;
                v.resize(k);
                v[k - 1].push_back(*pom);
                v[k - 1].push_back(*poc_2);
                v[k - 1].push_back(fun(*pom));
            }
        }
        pom++;
        if(pom == kraj_1){
            poc_2++;
            pom = poc_1;
        }
    }
    
    
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[1] < y[1];});
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[0] < y[0];});
     sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[2] < y[2];});
    return v;
}


template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 poc_1, Tip1 kraj_1, Tip2 poc_2, Tip2 kraj_2) -> vector<vector<decltype(*poc_1 + *poc_2)>>{
    vector<vector<decltype(*poc_1 + *poc_2)>> v;
    decltype(*poc_1 + *poc_2) a;
    
    int k = 0;
    Tip1 pom = poc_1;
    while(poc_2 < kraj_2){
        
        if(ObicniPresjek(*pom) == ObicniPresjek(*poc_2)){
            
            bool provjera = true;
            for(int i = 0 ; i < v.size() ; i++){
                if((v[i][0] == *pom && v[i][1] == *poc_2)){
                    provjera = false;
                    break;
                }
            }
            
            if(provjera){
                k++;
                v.resize(k);
                v[k - 1].push_back(*pom);
                v[k - 1].push_back(*poc_2);
                v[k - 1].push_back(ObicniPresjek(*pom));
            }
        }
        pom++;
        if(pom == kraj_1){
            poc_2++;
            pom = poc_1;
        }
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        v[i][1] = 0;
        v[i][2] = 0;
    }
    
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[1] < y[1];});
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[0] < y[0];});
     sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[2] < y[2];});
    return v;
}



template <typename Tip1, typename Tip2, typename Tip3>
auto UvrnutaRazlika(Tip1 poc_1, Tip1 kraj_1, Tip2 poc_2, Tip2 kraj_2, Tip3 fun) -> vector<vector<decltype(*poc_1 + *poc_2)>>{
    vector<vector<decltype(*poc_1 + *poc_2)>> v;
    decltype(*poc_1 + *poc_2) a;
    
    int k = 0;
    Tip1 p1 = poc_1;
    Tip2 p2 = poc_2;
    bool ubaci = true;
    while(p1 < kraj_1){
        if(fun(*p1) == fun(*p2)){
            ubaci = false;
        }
        p2++;
        if(p2 == kraj_2){
            if(ubaci){
                bool provjera1 = true;
                for(int i = 0 ; i < v.size() ; i++){
                    if(*p1 == v[i][0]){
                        provjera1 = false;
                        break;
                    }
                }
                
                if(provjera1){
                    k++;
                    v.resize(k);
                    v[k - 1].push_back(*p1);
                    v[k - 1].push_back(fun(*p1));
                }
            }
            p1++;
            p2 = poc_2;
            ubaci = true;
        }
    }
    
    p1 = poc_1;
    p2 = poc_2;
    while(p2 < kraj_2){
        if(fun(*p1) == fun(*p2)){
            ubaci = false;
        }
        p1++;
        if(p1 == kraj_1){
            if(ubaci){
                bool provjera2 = true;
                for(int i = 0 ; i < v.size() ; i++){
                    if(*p2 == v[i][0]){
                        provjera2 = false;
                        break;
                    }
                }
                
                if(provjera2){
                    k++;
                    v.resize(k);
                    v[k - 1].push_back(*p2);
                    v[k - 1].push_back(fun(*p2));
                }
            }
            p2++;
            p1 = poc_1;
            ubaci = true;
        }
    }
    
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[1] > y[1];});
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[0] > y[0];});
    
    return v;
}


template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 poc_1, Tip1 kraj_1, Tip2 poc_2, Tip2 kraj_2) -> vector<vector<decltype(*poc_1 + *poc_2)>>{
    vector<vector<decltype(*poc_1 + *poc_2)>> v;
    decltype(*poc_1 + *poc_2) a;
    
    int k = 0;
    Tip1 p1 = poc_1;
    Tip2 p2 = poc_2;
    bool ubaci = true;
    while(p1 < kraj_1){
        if(ObicniPresjek(*p1) == ObicniPresjek(*p2)){
            ubaci = false;
        }
        p2++;
        if(p2 == kraj_2){
            if(ubaci){
                bool provjera1 = true;
                for(int i = 0 ; i < v.size() ; i++){
                    if(*p1 == v[i][0]){
                        provjera1 = false;
                        break;
                    }
                }
                
                if(provjera1){
                    k++;
                    v.resize(k);
                    v[k - 1].push_back(*p1);
                    v[k - 1].push_back(ObicniPresjek(*p1));
                }
            }
            p1++;
            p2 = poc_2;
            ubaci = true;
        }
    }
    
    p1 = poc_1;
    p2 = poc_2;
    while(p2 < kraj_2){
        if(ObicniPresjek(*p1) == ObicniPresjek(*p2)){
            ubaci = false;
        }
        p1++;
        if(p1 == kraj_1){
            if(ubaci){
                bool provjera2 = true;
                for(int i = 0 ; i < v.size() ; i++){
                    if(*p2 == v[i][0]){
                        provjera2 = false;
                        break;
                    }
                }
                
                if(provjera2){
                    k++;
                    v.resize(k);
                    v[k - 1].push_back(*p2);
                    v[k - 1].push_back(ObicniPresjek(*p2));
                }
            }
            p2++;
            p1 = poc_1;
            ubaci = true;
        }
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        v[i][1] = 0;
    }
    
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[1] > y[1];});
    sort(v.begin() , v.end() , [] (vector<decltype(a)> x , vector<decltype(a)> y) { return x[0] > y[0];});
    
    return v;
}



int zbirCifara(int a){
    
    int zbir = 0;
    while(a != 0){
        zbir = zbir + a % 10;
        a = a / 10;
    }
    
    return zbir;
}

bool provjeraVectora(vector<int> v , int broj){
    
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == broj){
            return false;
        }
    }
    return true;
}

int main ()
{
    
    vector<int> a;
    vector<int> b;
    
    cout << "Unesite broj elemenata prvog kontejnera: ";
    int broj1;
    cin >> broj1;
    
    cout << "Unesite elemente prvog kontejnera: ";
    int i = 0; 
    while(i < broj1){
        int x;
        cin >> x;
        if(provjeraVectora(a,x)){
            a.push_back(x);
            i++;
        }
    }


    
    cout << "Unesite broj elemenata drugog kontejnera: ";
    int broj2;
    cin >> broj2;
    
    cout << "Unesite elemente drugog kontejnera: ";
    i = 0; 
    while(i < broj2){
        int x;
        cin >> x;
        if(provjeraVectora(b,x)){
            b.push_back(x);
            i++;
        }
    }
        
    cout << "Uvrnuti presjek kontejnera: " << endl;
    vector<vector<int>> v = UvrnutiPresjek(begin(a) , end(a) , begin(b) , end(b) , zbirCifara);
    
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(j == 0){
                cout << setw(6) << v[i][j];
            }
            else if(j == 1){
                cout << setw(7) << v[i][j];
            }
            else {
                if(v[i][j] == 1){
                     cout << setw(7) << v[i][j];
                }
                else {
                    cout << setw(7) << v[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
   
    
    cout << "Uvrnuta razlika kontejnera: " << endl;
    v = UvrnutaRazlika(begin(a) , end(a) , begin(b) , end(b) , BrojProstihFaktora);
    
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[0].size() ; j++){
            if(j == 0){
                cout << setw(6) << v[i][j];
            }
            else{
                cout << setw(7) << v[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    cout << "Dovidjenja!" << endl;
	
	
	return 0;
}