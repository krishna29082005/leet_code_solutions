class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin() , wordList.end());

        queue<pair<string , int>>q;
        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){
            string temp = q.front().first;
            int step = q.front().second;
            q.pop();

            if(temp == endWord) return step;
            for(int i = 0 ; i < temp.size() ; i++){
                char original = temp[i];
                for(char ch = 'a' ;  ch <= 'z' ; ch++){
                    temp[i] = ch;
                    if(st.find(temp) != st.end()){
                        q.push({temp , step + 1});
                        st.erase(temp);
                    }
                }
                temp[i] = original;
            }
        }
        return 0;
    }
};