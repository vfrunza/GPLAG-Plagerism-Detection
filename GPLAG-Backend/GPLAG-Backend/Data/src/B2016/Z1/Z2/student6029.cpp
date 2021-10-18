/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using std::cout;
using std::cin;
using std::vector;


vector<vector<double>> horizontalno(vector<vector<double>> mat) {
    vector<vector<double>> h(mat.size());
    int p(0);
    for(int i=0; i<mat.size(); i++)
        h[i].resize(mat[0].size());
    for(int i=0; i<mat.size(); i++) {
        p=mat[0].size()-1;
        for(int j=0; j<mat[0].size(); j++) {
            h[i][p]=mat[i][j];
            p--;
        }
    }
    return h;
}

vector<vector<double>> vertikalno(vector<vector<double>> mat) {
    vector<vector<double>> v(mat.size());
    int p(0);
    for (int i=0; i<mat.size(); i++)
        v[i].resize(mat[0].size());
    p=mat.size()-1;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[0].size(); j++) {
            v[p][j]=mat[i][j];
        }
        p--;
    }
    return v;
}

double unesi (double broj) {
    if (broj>=0)
        goto kraj;
    else return broj;
    kraj:
        return broj;
}

vector<vector<double>> kombinovano (vector<vector<double>> mat) {
    return horizontalno(vertikalno(mat));
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat) {
    bool grbava=false;
    for (int i=0; i<mat.size(); i++)
        if (mat[i].size()!=mat[0].size())
            throw std::domain_error ("Matrica nije korektna");
            
    vector<vector<double>> pom(mat.size()*3);
    for (int i=0; i<pom.size(); i++) {
        pom[i].resize(mat[0].size()*3);
        if(mat[i%mat.size()].size()==0 && i<mat.size())
            grbava=true;
    }
    if (grbava)
        return pom;
        
    vector<vector<double>> h=horizontalno(mat);
    vector<vector<double>> v=vertikalno(mat);
    vector<vector<double>> hv=kombinovano(mat);

    for (int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[i].size(); j++)
            pom[i][j]=unesi(hv[i][j]);
    int t(0);
    for (int i=mat.size()*2; i<mat.size()*3; i++) {
        int k=0;
        for (int j=mat[t].size()*2; j<mat[t].size()*3; j++) {
            pom[i][j]=hv[t][k];
            k++;
        }
        t++;
    }
    for (int i=0; i<mat.size(); i++)
        for (int j=mat[i].size()*2, k=0; j<mat[i].size()*3; j++, k++)
            pom[i][j]=unesi(hv[i][k]);
            
    t=0;
    for (int i=mat.size()*2; i<mat.size()*3; i++) {
        int k=0;
        for (int j=0; j<mat[t].size(); j++) {
            pom[i][j]=hv[t][k];
            k++;
        }
        t++;
    }

    for (int i=0; i<mat.size(); i++)
        for (int j=mat[i].size(), k=0; j<mat[i].size()*2; j++, k++)
            pom[i][j]=v[i][k];
    t=0;
    for (int i=mat.size()*2; i<mat.size()*3; i++) {
        int k=0;
        for (int j=mat[t].size(); j<mat[t].size()*2; j++) {
            pom[i][j]=unesi(v[t][k]);
            k++;
        }
        t++;
    }     
    t=0;
    for (int i=mat.size(); i<mat.size()*2; i++) {
        int k=0;
        for (int j=mat[t].size()*2; j<mat[t].size()*3; j++) {
            pom[i][j]=unesi(h[t][k]);
            k++;
        }
        t++;
    }
    t=0;
    for (int i=mat.size(); i<mat.size()*2; i++) {
        int k=0;
        for (int j=0; j<mat[t].size(); j++) {
            pom[i][j]=unesi(h[t][k]);
            k++;
        }
        t++;
    }
    t=0;
    for (int i=mat.size(); i<mat.size()*2; i++) {
        int k=0;
        for (int j=mat[t].size(); j<mat[t].size()*2; j++) {
            pom[i][j]=mat[t][k];
            k++;
        }
        t++;
    }

    return pom;
}


int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if (m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne! ";
		return 0;
	}
	cin.ignore(10000,'\n');
	cout<<"Unesite elemente matrice: ";
	vector<vector<double>> M(m,vector<double>(n));
	for (int i=0; i<m;i++) {
		for(int j=0; j<n;j++) {
			cin>>M[i][j];
		}
	}

	try{
		vector<vector<double>> NovaM(OgledaloMatrica(M));
		cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		for(int i=0; i<NovaM.size(); i++){
			for(int j=0; j<NovaM[i].size(); j++) {
				cout<<std::setw(4)<<NovaM[i][j];
			}
		cout<<std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		cout<<izuzetak.what()<<std::endl;
	}
	
	return 0;
}