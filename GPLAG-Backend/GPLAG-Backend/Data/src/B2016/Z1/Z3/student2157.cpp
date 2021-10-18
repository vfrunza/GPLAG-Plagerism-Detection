#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
using std::cout;
using std::cin;
typedef vector<vector<double>> Matrica;
Matrica RastuciPodnizovi(vector<double> A){
	Matrica R;
	for ( int i = 0; i < A.size()-1; i++){
		vector<double> C;
		if((i+1)<A.size() && A[i+1]>=A[i]) C.push_back(A[i]);
		while ( (i+1) < A.size() && A[i+1] >= A[i]){
		C.push_back(A[i+1]);
		i++;
		}
		R.push_back(C);
	}
	return R;
}
Matrica OpadajuciPodnizovi(vector<double> A){
	Matrica O;
	for ( int i = 0; i < A.size()-1; i++){
		vector<double> C;
		if((i+1)<A.size() && A[i+1]<=A[i]) C.push_back(A[i]);
		while ( (i+1) < A.size() && A[i+1] <= A[i] ){
		C.push_back(A[i+1]);
		i++;
		}
		O.push_back(C);
	}
	return O;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> A;
	double a;
	for( int i = 0; i < n; i++){
		cin>>a;
		A.push_back(a);
	}
		auto R=RastuciPodnizovi(A);
	cout<<"Maksimalni rastuci podnizovi: \n";
	for( vector<double> red : R){
		for ( double x: red){
			cout<<x<<" ";
	}
	cout<<"\n";
	}
	auto O=OpadajuciPodnizovi(A);
	cout<<"Maksimalni opadajuci podnizovi: \n";
	for(vector<double> red: O){
		for (double x: red){
			cout<<x<<" ";
	}
	cout<<"\n";
	}
	return 0;
}