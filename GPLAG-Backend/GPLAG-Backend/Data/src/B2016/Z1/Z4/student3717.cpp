#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::vector;
using std::string;

string ObrniFraze(string s, vector<string> v){
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<v.size(); j++){
			for(int k=0; k<v[i].size(); k++){
				while(v[i][j]!=s[i]) i++;
				while(v[i][j]==s[i] && j<v[i].size()){
					
				}
			}
		}
	}
}

int main ()
{
	vector<string> v{"Lijep"};
	string s;
	cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	string x=ObrniFraze(s, v);
	cout<<x<<v[0];
	return 0;
}