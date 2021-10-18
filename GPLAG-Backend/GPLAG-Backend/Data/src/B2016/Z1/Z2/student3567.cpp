#include<iostream>
#include<vector>
#include <iomanip>
#include<stdexcept>
using namespace std;

vector<vector<double>> OgledaloMatrica (vector<vector<double>> m) {
	vector<vector<double>> w  {0, vector<double> (0)} ;
	if(m.size()==0){
		return w;
	}
	//int k=3*m.size();
	//int d=3*m[0].size();
	vector<vector<double>> r {3*m.size(),vector<double> (3*m[0].size())};
	//for(int c=0;c<m.size()-1;c++){
		//if(m[c].size()!=m[c+1].size()) throw domain_error("Matrica nije korektna");
	//}
		if(m.size()==0 && m[0].size()==0){
			return r;
		}
		vector<vector<double>> h {m.size(), vector<double> (m[0].size())};
		vector<vector<double>> hv {m.size(), vector<double> (m[0].size())};
		vector<vector<double>> v {m.size(),vector<double> (m[0].size())};
		int b=(m.size()-1);
		int c=m.size();
		int z=(2*m[0].size());
		int g=(2*m.size());
		int f=(m[0].size()-1);
		for(int l=0;l<m.size();l++){
			for(int p=0;p<m[0].size();p++){
			v[l][p]=m[b-l][p];
			}
		} 
		for(int s=0;s<m.size();s++){
			for(int q=0;q<m[0].size();q++){
				h[s][q]=m[s][f-q];
			}
		}
		for(int l=0;l<m.size();l++){
			for(int p=0;p<m[0].size();p++){
				hv[l][p]=h[b-l][p];
			}
		}
		for(int i=0;i<m.size();i++){
			for(int u=0;u<m[0].size();u++){
				r[i][u]=hv[i][u];
				r[i][u+f+1]=v[i][u];
				r[i][u+z]=hv[i][u];
				r[i+c][u]=h[i][u];
				r[i+c][u+f+1]=m[i][u];
				r[i+c][u+z]=h[i][u];
				r[i+g][u]=hv[i][u];
				r[i+g][u+f+1]=v[i][u];
				r[i+g][u+z]=hv[i][u];
				
			}
		}
		
		return r;
		
}

int main ()
{
	int m,n	;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m;
	cin>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	int b=3*m;
	int t=3*n;
		vector<vector<double>> a (m,vector<double> (n));
		vector<vector<double>> z (b,vector<double> (t));
		/*try{
			int m,n;
	cin>>m>>n;
		}
		catch(domain_error izuzetak){
			cout<<izuzetak.what()<<endl;
		}*/
	cout<<"Unesite elemente matrice:";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j]>>ws;
		}
	}
	cout<<endl<<"Rezultantna matrica: "<<endl;
		if(m==0 && n==0){
		return 0;
	}
 z=OgledaloMatrica(a);
	for(int i=0;i<b;i++) {
		for(int j=0;j<t;j++){
			cout<<setw(4)<<z[i][j];
			
		}
		cout<<endl;
	}
	return 0;
}