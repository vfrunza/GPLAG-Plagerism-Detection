/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main ()
{
	
	cout <<" unesi";
	int m,n;
	cin>>m>>n;
	
	cout<<"unesi el";
	
	vector <vector <int>> M;
	
	M.resize(n);
	
	int broj;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n ; j++){
			cin >> broj;
			M.at(i).push_back(broj);
		}
	}
	
	int br(0);
	
		
		for(int j = 0; j < m; j++){
			
				if(j > m/2) br = br + 2;
			
			int br1(0);
			
			for(int k = 0; k < j - br; k++){
				
				M[j].erase(M[j].begin());
				
				M[j].erase(M[j].end() - 1);
				
				br1++;
			
			}
		}
	
	cout<<endl;
		
		br=0;
		
	int *p[100];
	
	for(int i = 0; i < n; i++)	
		p[i]=&M[i][0];
		 
		 
		
		for(int j = 0; j < M.size(); j++){
			
			//if(j > n/2) br=br+2;

			for(int k = 0; k < M[j].size(); k++){
				
				/*if((j != 0 && j != n - 1) && k == 0) cout<<right<<setw(5*(j + 1 - br) - 1)<<M[j][k];
				else if((j != 0 && j != n - 1) && k == n - 1) cout<<left<<setw(5*j - br)<<M[j][k];
				else if(k == 0) cout<<right<<setw(4)<<M[j][k];
				else cout<<right<<setw(5)<<M[j][k];*/
				cout<<*p[j]++;
			}
			cout<<endl;
		}
	
	return 0;
}



