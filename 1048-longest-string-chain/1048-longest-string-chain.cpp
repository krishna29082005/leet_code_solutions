class Solution {
public:
    int check(string& w1 , string& w2){
       int i = 0;
       int j = 0;
       int skip = 0;
       int n = w1.size();
       int m = w2.size();
       while(i != n && j != m){
          if(w1[i] == w2[j]){
            i++;
            j++;
          }else{
            if(skip == 1) return false;
            j++;
            skip = 1;
          }
       }
       return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , [](string &a , string&b){
            return a.size() < b.size();
        });
        vector<int>dp(n , 1);

        for(int i =1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                string w2 = words[i];
                string w1 = words[j];
                if(w2.size() - w1.size() == 1 && dp[i] < dp[j] + 1){
                    if(check(w1 , w2)){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};