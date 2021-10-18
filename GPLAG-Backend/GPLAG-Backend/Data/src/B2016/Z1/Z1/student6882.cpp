/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	

#include <iostream>
#include <cmath>
#include <ctime>
bool Neparan(int n){
	
	if(n%2==0) return false;
	return true;
}

bool Prost(int broj){
bool je_li_prost=true;
for(int i=2;i<=sqrt(broj);++i){
	if(broj%i==0){
		je_li_prost=false; break;
	}
	
}

return je_li_prost;
}


void Goldbach (int n, int& p, int &q){
	if(n<2) throw "Broj n je manji od broja 2. ";
	if(Neparan(n)) throw "Broj n je neparan broj. ";
	/*for(int i=1;i<n;i++){
		 if(Prost(i)){
		   for(int j=1;j<n;j++){
			if(Prost(j)){
				if(n==i+j) {p=i; q=j; break;}
			}
		    }
     	}
    }* // bilo
   /* for(int i=2;i<=n;i++){
    	if(Prost(i)){
    		if(Prost(n-i)){
    			p=i;
    			q=n-i;
    			break;
    		}
    	}
    }
    
}



int main ()
{
	int n,p,q;
	std::cout<<"Unesite broj n: "<<std::endl;
	std::cin>>n;
	p=1;
	q=1;
	try{
		Goldbach(n,p,q);
		std::cout<<"n="<<n<<", p="<<p<<", q="<<q<<std::endl;
	}
	catch(const char poruka[]){
		std::cout<<poruka<<std::endl;
	}
	
	clock_t vrijeme1=clock();
	Goldbach(n,p,q);
	clock_t vrijeme2=clock();
	int ukvrijeme=(vrijeme2-vrijeme1)/(CLOCKS_PER_SEC/1000);
	std::cout<<"vrijeme izvrsenja: "<<ukvrijeme<<"ms";
	return 0;
}*/

#include <iostream>
#include <cmath>
#include <string>

void funkcija(){
	std::string s="QUNZWDOTLOUKJWFRWGEFWGEFOKWZWTESEJERFOJERCROGEKCZOJWLCBRCJELWTELEFKW";
    for(int i = 0;i<s.size();i++){ 
         s[i] = fabs((15+(19)*s[i])%26) + 65; 
  
    } 
    std::cout<<s; 
} 
int main(){
	funkcija();
	return 0;

}
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool sadrzi(vector<char> vektor, char slovo){
    for(int i=0; i<vektor.size(); i++){
        if(vektor.at(i)==slovo) return true;
    }
    return false;
}

int prebroji(string slova, char slovo){
    int brojac(0);
    for(int i=0; i<slova.size(); i++){
        if(slova.at(i)==slovo) brojac++;
    }
    return brojac;
}

void sortiraj(vector<char> &slova, vector<int> &ponavljanja){
    for(int i=0; i<int(ponavljanja.size())-1; i++){
        for(int j=i+1; j<ponavljanja.size(); j++){
            if(ponavljanja.at(j)>ponavljanja.at(i)){
                char temp1 = slova.at(i);
                slova.at(i)=slova.at(j);
                slova.at(j)=temp1;

                int temp2 = ponavljanja.at(i);
                ponavljanja.at(i)=ponavljanja.at(j);
                ponavljanja.at(j)=temp2;
            }
        }
    }
}

int main(){
    cout<<"Unesite sifru: ";
    string sifra="QUNZWDOTLOUKJWFRWGEFWGEFOKWZWTESEJERFOJERCROGEKCZOJWLCBRCJELWTELEFKW";
   
    vector<char> slova;
    vector<int> ponavljanja;
    for(int i=0; i<sifra.size(); i++){
        if(!sadrzi(slova,sifra.at(i))){
            slova.push_back(sifra.at(i));
            ponavljanja.push_back(prebroji(sifra,sifra.at(i)));
        }
    }
    sortiraj(slova,ponavljanja);
    for(int i=0; i<slova.size(); i++){
        cout<<slova.at(i)<<": "<<ponavljanja.at(i)<<endl;
    }
}
*/