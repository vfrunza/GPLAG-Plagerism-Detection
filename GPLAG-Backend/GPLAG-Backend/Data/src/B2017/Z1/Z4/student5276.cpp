/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>

int BrojRedova(Matrica m){
    return m.size();
}

int BrojKolona(Matrica m){
    return m[0].size();
}

Matrica UnesiMatricu(int brred, int brkol){
    
auto m (KreirajMatricu(brred, brkol));
for(int i=0; i<brred; i++)
for(int j=0; j<brkol; j++){
    cin>>m.at(i).at(j);
}
return m;
}

void Ispisi(Matrica m){
    for(int i=0; i<BrojRedova(m); i++)
    for(int j=0; j<BrojKolona(m); j++){
        cout<<m.at(i).at(j);
    } cout<<endl;
}

Matrica KopirajMatricu(Matrica n, Matrica m, int a, int b, int c,int d){
    for(int i=0; i<BrojRedova(m); i++)
    for(int j=0; j<BrojKolona(m); j++){
        if(i==a && j==b){
            while(i!=c && j!=d){
            for(int k=0; k<BrojRedova(n); k++)
            for(int h=0; h<BrojKolona(n); h++){
                n.at(k).at(h)=m.at(i).at(j);
            }
            i++; j++;
        }
        return n;
    }
    }
}
int main ()
{

	return 0;
}