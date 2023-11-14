#include<bits/stdc++.h>
using namespace std;
bool isEqual(unordered_map<char,int> mp1,unordered_map<char,int> mp2){
    for(auto element : mp1){
        char key = element.first;
        int value = element.second;
        // cout<<key<<" value at map 1 "<<value<<". value at map 2 "<<mp2[key]<<endl;
        if(mp2[key] != value) return false;
    }
    return true;
}
bool permutation(string s1,int n,string s2,int m){
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    for(auto ch : s1){
        mp1[ch]++;
    }
    for(auto ele:mp1){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    int i=0,j=0;
    // i=1;
    while(j < m){
        mp2[s2[j]]++;
        if(j-i+1 < n) j++;
        if(j-i+1 == n){
            cout<<"\n elements in mp2 in iteration"<<endl;
            for(auto ele:mp2){
                cout<<ele.first<<" "<<ele.second<<endl;
            }
            // checking if its equal
            if(isEqual(mp1,mp2) == true) return true;
            // removing the computations of 'i' index
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0) mp2.erase(mp2[s2[i]]);
            i++;
            j++;
        }
        
    }
    return false;


}
int main(){
    string s1 = "adc";
    string s2 = "dcda";
    // cout<<s1.length()<<" "<<s2.length()<<endl;
    bool ans = permutation(s1,s1.length(),s2,s2.length());
    // if(ans == true)cout<<"true"<<endl;
    // else cout<<"false"<<endl;
    return 0;
}