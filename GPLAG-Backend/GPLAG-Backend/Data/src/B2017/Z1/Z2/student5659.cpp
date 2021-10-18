#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

typedef vector <vector <double>> Matrica;

Matrica IskopirajMatricu(Matrica m, int br_vrsta, int br_redova, int odakle_i, int odakle_j){
	
	Matrica M;
	
	M.resize(br_vrsta);
	
	for(int i = 0; i < br_vrsta ; i++)
		M.at(i).resize(br_redova);
		
	for(int i = 0; i < br_vrsta; i++ )
		
		for(int j = 0; j < br_redova; j++)
			M.at(i).at(j)=m.at(odakle_i + i).at(odakle_j + j);
		
	return M;
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	
	vector<Matrica> matrice;
	
	vector<int> koordinate_i, koordinate_j;
	
	vector<double> planine;
	
	for(int i = 0; i < m.size() - 1; i++)
			if(m.at(i).size() != m.at(i+1).size() )	throw domain_error("Matrica nije korektna");
			
	
	
	for(int i = 1; i < m.size() - 1; i++){
		
		for(int j = 1; j < m.at(i).size() - 1; j++){
			
			int br(1);
			
			double suma1(0), suma2(0);
			
			while(1){
				
				for(int k = i - br; k <= i + br; k++){
					
					for(int l = j - br; l <=  j + br; l++){
						
						if(k == i - br || k == i + br || l == j -br || l == j + br)
	
						suma1+=m.at(k).at(l);
						
					}
				}
				
				if(suma1 >= m.at(i).at(j) && br == 1) break;
				
				if(suma1 >= suma2 && br != 1){
							
					matrice.push_back(IskopirajMatricu(m, 2*br + 1, 2*br + 1, i - br, j - br));
					
					koordinate_i.push_back(i);
					koordinate_j.push_back(j);
					
					planine.push_back(m.at(i).at(j));
					
					break;
				}
				
				suma2=suma1;
				
				suma1=0;
				
				br++;
				
				if(i - br < 0 || i + br > m.size() - 1 || j - br < 0 || j + br > m.at(0).size() - 1){
					
					br--;
					
					matrice.push_back( IskopirajMatricu(m ,2*br + 1, 2*br + 1, i - br, j - br) );
					
					koordinate_i.push_back(i);
					koordinate_j.push_back(j);
					
					planine.push_back(m.at(i).at(j));
					
					break;
				}
			}
		}
	}
	
	if(matrice.size() == 0){
		
		int max(m.at(0).at(0));
	
		for(int i = 0; i < m.size(); i++)
		
			for(int j = 0; j < m.at(i).size(); j++)
				
				if(m.at(i).at(j) > max) max = m.at(i).at(j);
	
		Matrica mmax;
		
		mmax.resize(1);
		
		mmax.at(0).push_back(max);
		
		return mmax;
	}
	
	Matrica max( matrice.at(0) );
	
	int maxi(0);
	
	for(int  i = 1; i < matrice.size(); i++){
		
		if(matrice.at(i).size() > max.size()) { max = matrice.at(i); maxi = i; }
		
		else if(matrice.at(i).size() == max.size()) {
			
			if(planine.at(i) > planine.at(maxi)) { max = matrice.at(i); maxi = i; }
			
			else if(planine.at(i) == planine.at(maxi)) {
				
				 if(koordinate_i.at(i) < koordinate_i.at(maxi)) { max = matrice.at(i); maxi = i; }
				 
				 else if(koordinate_j.at(i) < koordinate_j.at(maxi)) { max = matrice.at(i); maxi = i; }
			}
			
		}
	}
		
	
	return max;
}

int main ()
{
	
	try{
	
	cout<<"Unesite dimenzije matrice (m i n): ";
	
	int m,n;
	
	cin>>m>>n;
	
	if(m < 0 || n < 0) { cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; } 
	
	Matrica M;
	
	M.resize(m);
	
	cout<<"Unesite elemente matrice:"<<endl;
	
	for(int i = 0; i < m ; i++){
		int broj;
		for(int j = 0; j < n; j++){
			
			cin >> broj;
			M.at(i).push_back(broj);
		}
	}
			
	M = NajvecaPlaninaMatrice(M);
	
	cout<<"Najveca planina unesene matrice je:"<<endl;
	
	for(auto v : M){
		
		for(auto x : v)
		
			cout<<right<<setw(6)<<x;
			
		cout<<endl;
	}
			
	}
	
	catch(const domain_error &e){
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	
	return 0;
}












