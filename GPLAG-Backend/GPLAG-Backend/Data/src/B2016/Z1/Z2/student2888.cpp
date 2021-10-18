/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;
typedef vector<vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova,vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto M(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
 cin>>M[i][j];
 }
 return M;
}
int BrojRedova(Matrica M) {
 return M.size();
}
 int BrojKolona(Matrica M) {
  for(int i=0;i<M.size();i++){
  if(M[i].size()==0) return 0;
  else
 return M[i].size(); 
  }
}
Matrica HorizontalnoOgledalo(Matrica M){
	   int m=BrojRedova(M);
   int n=BrojKolona(M);
   Matrica h;
h.resize(m); // 10 redova
for(int i = 0; i < m; i++) h[i].resize(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            h[i][j]=M[i][n-1-j];
        }
    } 

   return h;
}
Matrica VertikalnoOgledalo(Matrica M){
	 int m=BrojRedova(M);
   int n=BrojKolona(M);
	    Matrica v;
    v.resize(m);
    for(int i = 0; i < m; i++) v[i].resize(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
      //      v[i][j]=M[m-1][j];
            v[i][j]=M[m-1-i][j];
            
        }
        
    }
    return v;
}
Matrica OgledaloMatrica(Matrica M) {
Matrica h=HorizontalnoOgledalo(M);
Matrica hv=VertikalnoOgledalo(h);
Matrica v=VertikalnoOgledalo(M);
 int m=BrojRedova(M);
   int n=BrojKolona(M);
   Matrica g;
   for(int i=1;i<M.size();i++)
 if(M[0].size()!=M[i].size()) throw domain_error("Matrica nije korektna");
   g.resize(3*m);
   for(int i=0;i<3*m;i++) g[i].resize(3*n);
   for(int i=0;i<m;i++){
   for(int j=0;j<n;j++)
   g[i][j]=hv[i][j];
   //cout<<endl;
   }
   for(int i=0;i<m;i++){
       for(int j=n;j<2*n;j++)
       
       g[i][j]=v[i][j-n];
       //cout<<endl;
   }
 for(int i=0;i<m;i++){
       for(int j=2*n;j<3*n;j++)
       g[i][j]=hv[i][j-2*n];
       //cout<<endl;
   }
   for(int i=m;i<2*m;i++){
       for(int j=0;j<n;j++)
       g[i][j]=h[i-m][j];
       //cout<<endl;
   }
   //m-2m
    for(int i=m;i<2*m;i++){
       for(int j=0;j<n;j++)
       g[i][j]=h[i-m][j];
       //cout<<endl;
   }
    for(int i=m;i<2*m;i++){
       for(int j=n;j<2*n;j++)
       g[i][j]=M[i-m][j-n];
       //cout<<endl;
   }
     for(int i=m;i<2*m;i++){
       for(int j=2*n;j<3*n;j++)
       g[i][j]=h[i-m][j-2*n];
       //cout<<endl;
   }
   //2m-3m
      for(int i=2*m;i<3*m;i++){
       for(int j=0;j<n;j++)
       g[i][j]=hv[i-2*m][j];
      // cout<<endl;
   }
   for(int i=2*m;i<3*m;i++){
       for(int j=n;j<2*n;j++)
       g[i][j]=v[i-2*m][j-n];
     //  cout<<endl;
   }
     for(int i=2*m;i<3*m;i++){
       for(int j=2*n;j<3*n;j++)
       g[i][j]=hv[i-2*m][j-2*n];
      // cout<<endl;
   }
   return g;
  
}
void IspisiMatricu(Matrica M) {
    int	m=BrojRedova(M);
	int n=BrojKolona(M);
 for(int i = 0; i <m; i++) {
 for(int j = 0; j <n; j++)
 cout<<setw(4)<<M[i][j];
 cout<<endl;
 }
}






int main ()
{
 Matrica A;
	 int m,n;
 cout<<"Unesite dimenzije matrice (m n): ";
 cin>>m>>n;
 if(m<0 || n<0) {
  cout<<"Dimenzije matrice moraju biti nenegativne!";
  return 0;
 }
 cout<<"Unesite elemente matrice: \n";
 try{
 A=(UnesiMatricu(m, n));
 }
 catch(domain_error izuzetak){
  cout<<izuzetak.what();
 }
 cout<<"Rezultantna matrica:\n";
  auto M(OgledaloMatrica(A));
 IspisiMatricu(M);
// }
	return 0;
}

