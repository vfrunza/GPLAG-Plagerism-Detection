#include<iostream>
#include<vector>
#include<stdexcept>
#include <iomanip>

using namespace std;
vector<vector<double>> ogledalo1(vector<vector<double>>mat)
{
    vector<vector<double>>ogledalo;
    ogledalo.resize(mat.size());
    for(int i=0; i<ogledalo.size(); i++)
        ogledalo[i].resize(mat[0].size());

    for(int i=0; i<ogledalo.size(); i++) {
        int k=mat[i].size()-1;
        for(int j=0; j<ogledalo[i].size(); j++) {
            if(k<0) break;
            ogledalo[i][j]=mat[i][k];
            k--;
        }
    }
    return ogledalo;
}
vector<vector<double>> ogledalo2(vector<vector<double>>mat)
{
    vector<vector<double>>ogledalo;
    ogledalo.resize(mat.size());
    for(int i=0; i<ogledalo.size(); i++)
        ogledalo[i].resize(mat[0].size());

    for(int i=0; i<ogledalo.size(); i++) {
        int k=mat.size()-(i+1);
        for(int j=0; j<ogledalo[i].size(); j++) {
            ogledalo[i][j]=mat[k][j];
        }
    }
    return ogledalo;
}
vector<vector<double>> ogledalo3(vector<vector<double>>mat)
{
    vector<vector<double>>ogledalomat=ogledalo1(mat);
    vector<vector<double>>ogledalomat2=ogledalo2(ogledalomat);
    return ogledalomat2;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>>mat)
{
    for(int i=0; i<mat.size(); i++) {
        if(mat[0].size()!=mat[i].size()) throw domain_error("Matrica nije korektna");
    }
    vector<vector<double>>mat1=ogledalo1(mat);
    vector<vector<double>>mat2=ogledalo2(mat);
    vector<vector<double>>mat3=ogledalo3(mat);
    vector<vector<double>>mat4;
    mat4.resize(mat.size()*3);
    for(int i=0; i<mat4.size(); i++)
        mat4[i].resize(mat[0].size()*3);


    for(int i=0; i<mat4.size(); i++) {
        for(int j=0; j<mat4[i].size(); j++) {
            if(i<mat.size() && j<mat[0].size()) mat4[i][j]=mat3[i][j];
            else if (i<mat.size() && j>=mat[0].size()*2) mat4[i][j]=mat3[i][j-2*mat[0].size()];
            else if(i>=mat.size()*2 && j<mat[0].size()) mat4[i][j]=mat3[i-2*mat.size()][j];
            else if(i>=mat.size()*2 && j>=mat[0].size()*2) mat4[i][j]=mat3[i-2*mat.size()][j-2*mat[0].size()];
            else if(i<mat.size() && j<mat[0].size()*2) mat4[i][j]=mat2[i][j-mat[0].size()];
            else if(i>=mat.size()*2 && j<mat[0].size()*2) mat4[i][j]=mat2[i-mat.size()*2][j-mat[0].size()];
            else if(i>=mat.size() && j<mat[0].size() && i<mat.size()*2) mat4[i][j]=mat1[i-mat.size()][j];
            else if(i>=mat.size() && j>=mat[0].size()*2 && i<mat.size()*2) mat4[i][j]=mat1[i-mat.size()][j-mat[0].size()*2];
            else mat4[i][j]=mat[i-mat.size()][j-mat[0].size()];
        }
    }
    return mat4;



}


int main ()
{
    int m,n;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
    vector<vector<double>>mat;
    mat.resize(m);
    for(int i=0; i<m; i++)
        mat[i].resize(n);
        cout<<"Unesite elemente matrice:";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
            cout<<endl;
    try {
        vector<vector<double>>mat2=OgledaloMatrica(mat);
        cout<<"Rezultantna matrica:"<<endl;
        for(int i=0; i<mat2.size(); i++) {
            for(int j=0;j<mat2[i].size();j++)
            cout<<setw(4)<<mat2[i][j];
            cout<<endl;
            }
    }
    catch(domain_error izuzetak)
    {
        cout<<izuzetak.what();
    }
    return 0;
}