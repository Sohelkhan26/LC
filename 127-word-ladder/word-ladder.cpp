class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set <string> vis , startSet , endSet , avail(wordList.begin() , wordList.end());
        startSet.insert(beginWord);
        endSet.insert(endWord);
        if(not avail.contains(endWord))
            return 0;
        int time = 1;
        while(not startSet.empty() and not endSet.empty()){
            if(startSet.size() > endSet.size()) // smaller set for fewer branch
                swap(startSet , endSet);
            set <string> temp;
            time++;
            for(const string &word : startSet){
                string s = word;
                for(char &c : s){
                    char t = c;
                    for(char d = 'a' ; d <= 'z' ; d++){
                        c = d;
                        if(endSet.contains(s))
                            return time;
                        if(avail.contains(s) and not vis.contains(s))
                            temp.insert(s) , vis.insert(s);
                    }
                    c = t;
                }
            }
            startSet = temp;
        }
        return 0;
    }
};

/*
Need to find middle nodes in the path. starting from beginWord and ending at endWord.
Each nodes in path should only differ by 1 character.
Bidirectional BFS.
start from beginWord and endWord
need extra vis set cause we can't erase words from wordList anymore. 
*/