#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int oo =2e5;
const int mod =1e9 +7;
int sz;
int arr[oo <<1];
long long dp [oo <<1];
void store(){
    dp[0] =1;
    for(int i =1 ; i <=oo ; i ++){
        dp[i] =(long long)(10 *dp[i -1] +1) %mod; 
    }   
}
int substrings(string n) {
    sz =n.size();
    for(int i =0 ; i <sz ; i ++) arr[i] =n[i] -'0';
    int ans =0;
    store();
    int st =0;
    for(int i =sz -1 ; i >=0 ; i --){
        int x =arr[i];
        ans =(ans +dp[st] *(x *(i +1))) %mod;
        st ++;
    }return ans %mod;
}
int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string n;
    getline(cin, n);
    int result = substrings(n);
    fout << result << "\n";
    fout.close();
    return 0;
}
