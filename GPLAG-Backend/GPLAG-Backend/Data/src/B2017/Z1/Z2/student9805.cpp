/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
using namespace std;

bool provjera(vector<vector<double>> matrica,int a,int b,int vel){
	double suma=matrica[a][b];
	int i;
	for(i=1;i<vel/2;i++){
		double s=0;
		for(int j=a-i;j<=a+i;j++){
			for(int k=b-i;k<=b+i;k++){
				if(k!=b-i && k!=b+i) continue;
				s+=matrica[j][k];
			}
		}
		if (s>suma) return false;
		s=suma;
	}
	return true;
}
bool DaLiJePlanina(vector<vector<double>> mat,int m,int n,int vel){//vel je velicina planine,m i n koordinate centra
    double vecasuma = mat[m][n];
    int k;
    for(k = 1;k <= vel/2;k++){
        double manjasuma(0);
        for(int i = m-k;i <= m + k;i++){
            for(int j = n -k;j <= n+k;j++){
                    if(j != n-k && j != n+k)continue;
                    manjasuma+=mat[i][j];
            }
        }
 
        if(manjasuma > vecasuma)return false;
        manjasuma=vecasuma;
    }
    return true;
}

vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>> mat){
int k,maxi=0,maxj=0;
    if(mat.size() > mat[0].size()) k = mat[0].size();
    else k = mat.size();
    for(k;k > 2;k--){
        for(int i = 0;i < mat.size();i++){
             if(i+k/2 >= mat.size() || i-k/2 < 0)continue;
            for(int j = 0;j < mat[0].size();j++){
                if(j + k/2 >= mat[0].size() || j - k/2 < 0) continue;
                if(DaLiJePlanina(mat,i,j,k)){
                    if(!maxi){
                            maxi=i;
                            maxj=j;
                    }else{
                        if(mat[i][j] > mat[maxi][maxj]){
                            maxi=i;
                            maxj=j;
                        }else if(mat[i][j] == mat[maxi][maxj]){
                            if(i < maxi){
                                maxi=i;
                                maxj=j;
                            }else if(i == maxi){
                                if(j < maxi){
                                    maxi=i;
                                    maxj=j;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(maxi)break;
    }
int a(0);
 
vector<vector<double>> planina(k,vector<double>());
        for(int i = maxi-k/2;i <= maxi+k/2;i++){
            for(int j = maxj-k/2;j <= maxj+k/2;j++){
                planina[a].push_back(mat[i][j]);
            }
            a++;
        }
    return planina;
}
int main ()
{
	
	return 0;
}