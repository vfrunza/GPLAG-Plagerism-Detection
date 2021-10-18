#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
bool DaLiJeProst(int n){
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
		return true;
	}
bool SimetricniIProstiTernar(int n){
    std::vector <int> v;
	std::deque<int> d;
    std::vector<int> v1;
    if(DaLiJeProst(n)){
    int a,b;
    a=n/3;
    b=n%3;
    d.push_front(b);
    v1.push_back(b);
    while(a!=0){
    b=a%3;
    d.push_front(b);
    v1.push_back(b);
    a=a/3;
    }
    for(int i=0;i<d.size();i++){
        v.push_back(d.at(i));
    }
    for(int i=0;i<v.size();i++){
    if(v==v1){
        return true;
    }
    }
    }
    return false;
    }
bool SimetricniISlozeniTernari(int n){
     std::vector <int> v;
	std::deque<int> d;
    std::vector<int> v1;
    if(DaLiJeProst(n)!=true){
    int a,b;
    a=n/3;
    b=n%3;
    d.push_front(b);
    v1.push_back(b);
    while(a!=0){
    b=a%3;
    d.push_front(b);
    v1.push_back(b);
    a=a/3;
    }
    for(int i=0;i<d.size();i++){
        v.push_back(d.at(i));
    }
    for(int i=0;i<v.size();i++){
    if(v==v1){
        return true;
    }
    }
    }
    return false;
    }
std::vector<int> IzdvojiSimetricneTernare(std::vector<int> v, bool a){
    std::vector<int> v1;
for(int i=0;i<v.size();i++){
if(DaLiJeProst(v.at(i)) && SimetricniIProstiTernar(v.at(i))){
    v1.push_back(v.at(i));
    a=true;
    }
}
    return v1;
   
}
std::vector<int> IzdvojiSimetricneTernare2(std::vector<int> v, bool a){
    std::vector<int> v1;
    for(int i=0;i<v.size();i++){
        if(SimetricniISlozeniTernari(v.at(i)) && DaLiJeProst(v.at(i))!=true){
            v1.push_back(v.at(i));
            a=false;
        }
    }
    return v1;
}
std::vector<int> Izmjeni(std::vector<int> v){
    std::vector<int> v1;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i)==v.at(j)){
                for(int k=j+1;k<v.size();k++){
                    v.at(k-1)==v.at(k);
                }
                v.resize(v.size()-1);
                j--;
            }
        }
    }
    v1=v;
    return v1;
}
int main()
{    
	int n;
	
	int b;
	std::vector <int> v;
	std:: cout << "Unesite elemente vektora (-1 za kraj): ";
    do {
 std::cin >> n;
 if(n != -1) v.push_back(n);
} while(n != -1);
std:: cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

while(std::cin>>b, b!=1 && b!=0){
    std:: cout << "Neispravan unos!";
    std:: cout << " Unesite ponovo: ";
    
}
std::vector<int> v1;
std::vector<int> v2;
v1=IzdvojiSimetricneTernare(v,true);
v2=IzdvojiSimetricneTernare2(v,true);
v1=Izmjeni(v1);
v2=Izmjeni(v2);
if(v1.size()==0 && b==1){
    std:: cout << "Nema prostih simetricnih brojeva u vektoru.";
}
else if(v1.size()>0 && b==1){
     std:: cout << "Prosti simetricni brojevi iz vektora su: ";
for(int i=0;i<v1.size();i++){
    if(i!=v1.size()-1){std:: cout << v1.at(i) << ", ";}
			else if(i==v1.size()-1){
				std:: cout << v1.at(i) << ".";
			}
}
std:: cout << std:: endl;
}
else if(v2.size()==0 && b==0){
    std:: cout << "Nema slozenih simetricnih brojeva u vektoru.";
}
else if(v2.size()>0 && b==0){
    std:: cout << "Slozeni simetricni brojevi iz vektora su: ";
 for(int i=0;i<v2.size();i++){
    if(i!=v2.size()-1){std:: cout << v2[i] << ", ";}
			else if(i==v2.size()-1){
				std:: cout << v2.at(i) << ".";
			}
}
}
std:: cout << std:: endl;
  
    return 0;
	}