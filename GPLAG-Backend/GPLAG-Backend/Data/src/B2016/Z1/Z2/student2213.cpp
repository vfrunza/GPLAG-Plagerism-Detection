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
using namespace std;

vector<vector<double>> VeritikalnoOgledalo(vector<vector<double>> Ulazna)
{
vector<vector<double>> rezultantna;
	for(int i=Ulazna.size()-1;i>=0;i--)
	{
	rezultantna.push_back(Ulazna.at(i));
}
	return rezultantna;
}

vector<vector<double>> HorizontalnoOgledalo(vector<vector<double>>Ulazna)
{
	vector<vector<double>>rezultantna;
		for(int i=0;i<Ulazna.size();i++)
		{
		vector<double> temp;
		for(int j=Ulazna[i].size()-1;j>=0;j--)
		{
			temp.push_back(Ulazna[i][j]);
		}
		rezultantna.push_back(temp);
	}
	return rezultantna;
}

vector<vector<double>> KombinovanoOgledalo(vector<vector<double>>Ulazna){
	
	vector<vector<double>> rezultantna;
	rezultantna=HorizontalnoOgledalo(Ulazna);
	rezultantna=VeritikalnoOgledalo(rezultantna);
	return rezultantna;
}

 vector<vector<double>> OgledaloMatrica(vector<vector<double>>Ulazna){
 	
 	vector<vector<double>> rezultantna;
 	vector<vector<double>>horizontalna=HorizontalnoOgledalo(Ulazna);
 	vector<vector<double>>vertikalna=VeritikalnoOgledalo(Ulazna);
 	vector<vector<double>>kombinovana=KombinovanoOgledalo(Ulazna);
 	
 	int pozicija=0;
 	int velicina=Ulazna.size();
 	int red_veliki=1;
 	int pozicija_unutarnja=0;
 	
 	for(int i(0);i<velicina*3;i++){
 		
 		int red_trenutni=i;
 		if( (red_trenutni+1) > velicina){
 			red_trenutni=(red_trenutni)-(velicina*(red_veliki-1));
 		}
 		
 		vector<double>temp;
 		if(red_veliki==1) pozicija=0;
 		else if(red_veliki==2) pozicija=1;
 		else if (red_veliki==3) pozicija=0;
 		switch(pozicija){
 			case 0: {
 				for(int k=0;k<3;k++){
 					pozicija_unutarnja=k%2;
 					
 					switch(pozicija_unutarnja){
 						case 0:{
 							for(int l=0;l<Ulazna[red_trenutni].size();l++){
 								temp.push_back(kombinovana[red_trenutni][l]);
 							}
 						}
 						break;
 						case 1:
 						{
 							for(int l=0;l<Ulazna[red_trenutni].size();l++){
 								temp.push_back(vertikalna[red_trenutni][l]);
 							}
 						}
 						break;
 							}
 						}
 			}break;
 						 case 1:
 						 {
 						 	for(int k=0;k<3;k++){
 						 		pozicija_unutarnja=k%2;
 						 		switch(pozicija_unutarnja){
 						 			case 0:
 						 			{
 						 				for(int l=0;l<Ulazna[red_trenutni].size();l++){
 						 					temp.push_back(horizontalna[red_trenutni][l]);
 						 				}
 						 			}
 						 			break;
 						 			
 						 			case 1: {
 						 				for(int l=0;l<Ulazna[red_trenutni].size();l++){
 						 					temp.push_back(Ulazna[red_trenutni][l]);
 						 				}
 						 			}
 						 			break;
 						 		}
 						 	}
 						 }
 						 break;
 					}
 					if((red_trenutni+1)%velicina==0) red_veliki++;
 					rezultantna.push_back(temp);
 					temp.clear();
 				
 			}
 			
 				return rezultantna;
 			
 }
 
int main ()
{
	vector<vector<double>> parametralna;

	cout<<"Unesite dimenzije matrice (m n):";
	int m,n;
	cin>>m>>n;
	if(m<0||n<0) {cout<<" Dimenzije matrice moraju biti nenegativne!"; return 0;}
	
	cout<<" Unesite elemente matrice:";
	for(int i=0;i<m;i++){
		vector<double>temp;
		for(int j=0;j<n;j++)
		{ double element;
		cin>>element;
			temp.push_back(element);
		}
		parametralna.push_back(temp);
		cout<<endl;
	}
	
	cout << endl;
	cout<<"Rezultantna matrica:" << endl;
	
    parametralna=OgledaloMatrica(parametralna);
    
	for(int i=0;i<parametralna.size();i++){
		
		cout << " ";
		for(int j=0;j<parametralna[i].size();j++){
			if(j < (parametralna[i].size()-1)) cout<<setw(3)<<right<<parametralna[i][j] <<" ";
			else cout<<setw(3)<<right<<parametralna[i][j];
		}
		cout<<endl;
	}
			

	return 0;
}