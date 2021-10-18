/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

int Obrni (int x) {
    int m=0;
    while (x!=0) {
        m=m*10+x%10;
        x/=10;
    }
    return m;
}

std::vector<int> IzbaciDuple (std::vector<int> v) {
    for (int i=0; i<v.size(); i++){
        for (int j=i+1; j<v.size(); j++){
            if (v[i]==v[j]) v.erase(v.begin()+i), j=i+1;
            else continue;
        }
    }
    return v;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool x) {
    v=IzbaciDuple(v);
    for (int i=0; i<v.size()-1; i++) {
        int m=0;
        while (v[i] != 0) {
            m+=v[i]%3;
            v[i]/=3;
        }
        if (m<0) m*=(-1);
        m=Obrni(m);
        v[i]=m;
    }
    return v;
}

int main(){
	
    return 0;
}
