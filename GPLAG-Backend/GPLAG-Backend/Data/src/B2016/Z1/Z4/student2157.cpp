#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::string;
using std::cin;
using std::getline;
string ObrniFraze(string A, vector<string> B){
	vector<string> C(B.size());
	for(int i = 0; i < B.size(); i++){
		for(int j = 0; j<B[i].length()/2; j++){
			C[i][B[i].length()-i]=B[i][j];
		}
	}
	int br(0);
	for ( int i = 0; i < B.size(); i++){
		br=0;
		for ( int j = 0; j < A.length(); j++){
			if( A[j]==B[i][j])
				br++;
			}
		}
	}
	int br(0);
	
	return A;
}
string IzmijeniUPigLatin(string A, vector<string> B){
	vector<string> C(B.size());
	for ( int i = 0; i < B.size(); i++){
		for ( int i = 0; j < B[i])
	}
}
int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(std::cin, recenica );
	cout<<"Unesite fraze: ";
	vector<std::string> A;
	string a;
	for(int i=0; i<200; i++){
		getline(cin, a);
		if(a=="\n"){
			break;
		}
		A.push_back(a);
	}
	/*B=IzmijeniUPigLatin(recenica, A);*/
	string C=ObrniFraze(recenica, A);
	/*cout<<"Recenica nakon PigLatin transformacije: "<<B;*/
	cout<<"\nRecenica nakon obrtanja fraza: "<<C;
	return 0;
}