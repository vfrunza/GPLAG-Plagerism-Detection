/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<double> > Matrica;
typedef vector<double> Vektor;
Vektor UnesiVektor(int n){
    double broj;
    Vektor v;
    for(int i=0;i<n;i++){
        cin>>broj;
        v.push_back(broj);
    }

    return v;
}
Matrica RastuciPodnizovi(Vektor v){
    Matrica M(10);
    int red(0);

    for(int i=1;i<v.size();i++){
         if(v[i]>=v[i-1]) {
            M.resize(red+1);
            M[red].push_back(v[i-1]);
            while(v[i]>=v[i-1]){
              if(i==v.size()) break;
             M[red].push_back(v[i]);
             i++;
                
            }
            i--;
             red++;

        }
         

   }
    return M;
}
Matrica OpadajuciPodnizovi(Vektor v){
    Matrica M(10);
    int red(0);
   for(int i=1;i<v.size();i++){
   if(v[i]<=v[i-1]) {
            M.resize(red+1);
            M[red].push_back(v[i-1]);
            while(v[i]<=v[i-1]){
                if(i==v.size()) break;
             M[red].push_back(v[i]);
             i++;
            }
             red++;
             
            }
           
        
    }
    return M;
}
void IspisiMatricu(Matrica M){
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M[i].size();j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    cout<<"Unesite elemente vektora: ";
    Vektor v(UnesiVektor(n));
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
    Matrica M(RastuciPodnizovi(v));
   IspisiMatricu(M);
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    Matrica N(OpadajuciPodnizovi(v));
    IspisiMatricu(N);
    return 0;
}