#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<vector<double>> Horizontalno(vector<vector<double>>mat)
{
    for(unsigned int i=0; i<mat.size(); i++) {
        
        for(unsigned int j=0; j<mat[i].size()/2; j++)
        {
            double temp=mat[i][j];
            mat[i][j]=mat[i][mat[i].size()-1-j];
            mat[i][mat[i].size()-1-j]=temp;
        }
    }
    return mat;
}
vector<vector<double>> Vertikalno(vector<vector<double>>mat)
{
    for(unsigned int i=0; i<mat.size()/2; i++)
    {
        vector<double> temp=mat[i];
        mat[i]=mat[mat.size()-1-i];
        mat[mat.size()-1-i]=temp;
    }
    return mat;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>>mat)
    {
        vector<vector<double>> H,V,O;
        H=Horizontalno(mat);
        V=Vertikalno(mat);
        O=Vertikalno(Horizontalno(mat));
        
        vector<vector<double>> ExpMat(mat.size()*3);
        for(int i=0; i<ExpMat.size(); i++)
        ExpMat[i].resize(mat[0].size()*3);
        
        for(unsigned int i=0; i<ExpMat.size(); i++) {
    
    for(unsigned int j=0; j<ExpMat[i].size(); j++)
    { 
        if((i<mat.size() && j<mat[0].size()) || (i<mat.size() && j/mat[0].size()==2) || (i>=2*mat.size()
        && j/mat[0].size()==0) || (i>=2*mat.size() && j/mat[0].size()==2))
        ExpMat[i][j]=O[i%mat.size()] [j%mat[0].size()];
        else if((i/mat.size()==1 && j<mat[0].size())|| (i/mat.size()==1 && j>=2*mat[0].size()))
        ExpMat[i][j]=H[i%mat.size()] [j%mat[0].size()];
        else if((j/mat[0].size()==1 && i<mat.size())|| (j/mat[0].size()==1 && i>=2*mat.size()))
        ExpMat[i][j]=V[i%mat.size()] [j%mat[0].size()];
        else ExpMat[i][j]=mat[i%mat.size()][j%mat[0].size()];
    }
    }
    return ExpMat;
    }
    int main() {
    int Red, Kolone;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>Red>>Kolone;
    if(Red<0 || Kolone<0) {
        cout<<"Dimenzije matrice moraju biti nenegativne!"; 
        return 0; } 
        vector<vector<double>> Mat(Red);
        for(int i=0;i<Mat.size(); i++)
        Mat[i].resize(Kolone);
        cout<<"Unesite elemente matrice: ";
        for(int i=0; i<Mat.size(); i++) {
            for(int j=0; j<Mat[i].size(); j++)
            {
                cin>>Mat[i][j];
            }
        }
        cout<<endl<<"Rezultantna matrica: "<<endl;
        vector<vector<double>> EMat=OgledaloMatrica(Mat);
   for(int i=0; i<EMat.size();i++){
       for(int j=0; j<EMat[i].size();j++)
   {
       cout<<setw(4)<<EMat[i][j]; }
       cout<<endl; }
       return 0;
    }
  