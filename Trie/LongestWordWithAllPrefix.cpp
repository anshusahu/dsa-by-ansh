class Node{
    public:
        bool isEnd;
        Node* children[26];
        
        Node(){
            isEnd = false;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
};

class Trie{
    public:
        Node* root;
        
        Trie(){
            root = new Node();
        }
        
        void insert(string& s){
            Node* node = root;
            for(auto& ch: s){
                int ind = ch-'a';
                if(!node->children[ind]){
                    node->children[ind] = new Node();
                }
                node = node->children[ind];
            }
            node->isEnd = true;
        }
        
        bool allPrefixPresent(string& s){
            Node* node = root;
            for(auto &ch: s){
                int ind = ch-'a';
                
                if(!node->children[ind] || !(node->children[ind]->isEnd)){
                    return false;
                }
                node = node->children[ind];
            }
            return true;
        }
};
class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        Trie root;
        
        for(auto& str:words){
            root.insert(str);
        }
        
        string longestString = "";
        
        for(auto& word: words){
            if(root.allPrefixPresent(word)){
                if(word.length() > longestString.length()||
                (word.length() == longestString.length() && word < longestString)){
                    longestString = word;
                }
            }
        }
        return longestString;
    }
};