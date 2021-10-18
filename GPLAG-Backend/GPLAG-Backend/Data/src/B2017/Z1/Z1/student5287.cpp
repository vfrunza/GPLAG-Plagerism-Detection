#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> vector;

//Sa tutorijala 2
bool Prost(int n) {
    if(n >= -1 && n <= 1) return false;
    
    //Abs broja
    n *= (n < 0)? -1 : 1;
    
	for (int i = 2; i <= std::sqrt(n); i+=1) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

vector Ternarni(int n){
    vector t;
    bool neg = false;
    
    //Negativan broj
    if(n < 0){
        neg = true;
        n *= -1;
    }
    
    if(n == 0) t.push_back(0);
    
    while(n > 0){
        t.insert(t.begin(), n % 3);
        n /= 3;
    }
    
    return t;
}

bool Simetricni(vector n){
    int size = n.size();
    
    for(int i = 0; i < size; i++){
        if(n.at(i) != n.at(size-1-i))
            return false;
    }
    
    return true;
}

vector IzdvojiSimetricneTernarne(vector v, bool prosti){
	vector ret;
	
	for(int b1 : v){
	    //Pretpostavimo da ne postoji u novom nizu
	    bool postoji = false;
	    
	    for(int b2 : ret){
	        if(b2 == b1){
	            postoji = true;
	            break;
	        }
	    }
	    //Nema potrebe za dodavanjem
	    if(postoji) continue;
	    
	    //Da li se trazi slozen ili prost broj
	    if(Prost(b1) == prosti){
	        //Ako je simetrican, ubaciti ga u novi vector
	        if(Simetricni(Ternarni(b1))){
	            ret.push_back(b1);
	        }
	    }
	}
	
	return ret;
}

int main ()
{
    vector v;
    
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    
    int temp;
    while(true){
        std::cin >> temp;
        if(temp == -1) break;
        v.push_back(temp);
    }
    
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int prosti;
    while(true){
        std::cin >> prosti;
        if(prosti == 0 || prosti == 1)
            break;
        
        std::cout << "Neispravan unos! Unesite ponovo: ";
    }
    
    v = IzdvojiSimetricneTernarne(v, prosti);
    
    if(v.size() == 0){
        std::cout << "Nema " << ((prosti)? "prostih" : "slozenih") << " simetricnih brojeva u vektoru.";
        return 0;
    }
    
    std::cout << ((prosti)? "Prosti" : "Slozeni") << " simetricni brojevi iz vektora su: ";
    for(int i = 0; i < v.size(); i++){
        if(i != v.size()-1) std::cout << v.at(i) << ", ";
        else std::cout << v.at(i) << ".\n";
    }
    
    
	return 0;
}