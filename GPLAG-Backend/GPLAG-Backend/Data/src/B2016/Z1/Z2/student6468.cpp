#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

bool isMatrix(vector<vector<double>> matrix){
	if(matrix.size() == 0)
		return true;
	
	int n = matrix[0].size();
	
	for(int i=0; i<matrix.size(); i++){
		if(matrix[i].size() != n)
			return false;
	}
	
	return true;
}

void printMatrix(vector<vector<double>> matrix){
	if(!isMatrix(matrix))
		return;
	
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[i].size(); j++){
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
}

vector<vector<double>> horizontalMatrix(vector<vector<double>> matrix){
	vector<vector<double>> m(matrix.size());
	
	for(int i=0; i<matrix.size(); i++)
		m[i].resize(matrix[i].size());
		
	for(int i=0; i<matrix.size(); i++)
		for(int j=0; j<matrix[i].size(); j++)
			m[i][j] = matrix[i][matrix[i].size() - 1 - j];
			
	return m;
}

vector<vector<double>> verticalMatrix(vector<vector<double>> matrix){
	vector<vector<double>> m(matrix.size());
	
	for(int i=0; i<matrix.size(); i++)
		m[i].resize(matrix[i].size());
		
	for(int i=0; i<matrix.size(); i++)
		for(int j=0; j<matrix[i].size(); j++)
			m[i][j] = matrix[matrix.size() - 1 - i][j];
			
	return m;
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrix){
	if(!isMatrix(matrix))
		throw domain_error("Matrica nije korektna");
	
	if(matrix.size() == 0)
		return {};
		
	vector<vector<double>> m(matrix.size()*3);
	
	int n = matrix[0].size();
	
	for(int i=0; i<m.size(); i++)
		m[i].resize(n*3);
		
	vector<vector<double>> hv = horizontalMatrix(verticalMatrix(matrix));
	vector<vector<double>> v = verticalMatrix(matrix);
	vector<vector<double>> h = horizontalMatrix(matrix);
	
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			if(i<matrix.size()){
				if(j<matrix[i].size())
					m[i][j] = hv[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else if(j<matrix[i].size()*2)
					m[i][j] = v[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else
					m[i][j] = hv[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
			}
			else if(i<matrix.size()*2){
				if(j<matrix[i%matrix.size()].size())
					m[i][j] = h[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else if(j<matrix[i%matrix.size()].size()*2)
					m[i][j] = matrix[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else
					m[i][j] = h[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
			}
			else {
				if(j<matrix[i%matrix.size()].size())
					m[i][j] = hv[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else if(j<matrix[i%matrix.size()].size()*2)
					m[i][j] = v[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
				else
					m[i][j] = hv[i%matrix.size()][j%matrix[i%matrix.size()].size()];				
			}
		}
	}
	
	return m;
}

int main ()
{
	int m,n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	vector<vector<double>> matrix(m);
	
	for(int i=0; i<matrix.size(); i++)
		matrix[i].resize(n);
		
	cout << "Unesite elemente matrice:";	
		
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			double x;
			cin >> x;
			matrix[i][j] = x;
		}
	}
	
	cout << endl << "Rezultantna matrica:" << endl;
	
	printMatrix(OgledaloMatrica(matrix));
}