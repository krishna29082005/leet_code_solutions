class Solution {
public:
    bool check(string& w1 , string& w2){
        int n = w1.size();
        int m = w2.size();
        int i = 0;
        int j = 0;
        int skip = 0;
        while(i != n || j != m){
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
        sort(words.begin() , words.end() , [](string& a , string& b){
            return a.size() < b.size();
        });

        vector<int>dp(n , 1);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
               int w1 = words[j].size();
               int w2 = words[i].size();
               if(w2 - w1 == 1 && dp[j] + 1 > dp[i]){
                 if(check(words[j] , words[i])){
                    dp[i] = dp[j] + 1;
                  }
               }
            }
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};