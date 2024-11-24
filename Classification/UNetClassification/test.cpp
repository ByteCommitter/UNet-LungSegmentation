#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
//get the first and second max from a given list

int main(){
    vector<int> v={9,12,10};
    int smax=0,max=0;
    for(int i=0;i<v.size();i++){
        if(max<v[i]){
            smax=max;
            max=v[i];
        }
        if(smax<)
        cout<<max<<" is  highest "<<endl;
        cout<<smax<<" is second highest "<<endl;
    }

}