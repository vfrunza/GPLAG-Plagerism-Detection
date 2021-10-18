#include <iostream>
#include <vector>

using namespace std;

void ispisi2dniz(vector<vector<double>> niz){
    for(int i=0; i<niz.size(); i++){
        for(int j=0; j<niz[i].size(); j++){
            cout << niz[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> RastuciPodnizovi(vector<double> niz){
    vector<vector<double>> rez(0);

    int prevIndex = 0;

    for(int i=0; i<niz.size(); i++){
        if(niz[i] > niz[i+1]){
            vector<double> tmp(0);

            for(int j=prevIndex; j<=i; j++)
                tmp.push_back(niz[j]);

            rez.push_back(tmp);

            prevIndex = i+1;
        }
    }

    vector<vector<double>> realRes(0);

    for(int i=0; i<rez.size(); i++)
        if(rez[i].size() > 1)
            realRes.push_back(rez[i]);

    return realRes;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> niz){
    vector<vector<double>> rez(0);

    int prevIndex = 0;

    for(int i=0; i<niz.size(); i++){
        if(niz[i] < niz[i+1]){
            vector<double> tmp(0);

            for(int j=prevIndex; j<=i; j++)
                tmp.push_back(niz[j]);

            rez.push_back(tmp);

            prevIndex = i+1;
        }
    }

    vector<vector<double>> realRes(0);

    for(int i=0; i<rez.size(); i++)
        if(rez[i].size() > 1)
            realRes.push_back(rez[i]);

    return realRes;   
}

int main(){
    vector<double> niz = { 1, 3, 2, 6, 7, 9, 10, 4, 3, 1, 7 };
    
    ispisi2dniz(RastuciPodnizovi(niz));
}