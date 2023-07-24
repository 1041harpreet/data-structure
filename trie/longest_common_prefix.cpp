#include<vector>
#include<iostream>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    //traverse first string
    for(int i=0; i<arr[0].size();i++){
        //check ch matches  with other arr characters or not
        char ch=arr[0][i];
        bool isMatched=true;
        for(int j=0;j<n;j++){
            
            if( arr[j].size() <i ||ch !=arr[j][i]){
                isMatched=false;
                break;
            }
        }
        if(isMatched==false){
            break;
        }else{
            ans.push_back(ch);
        }

    }
    return ans;
}


//sc : O(1) or if ans consider O(m)    , tc: O(m*n)

//using trie , but it is not optimal as tc O(m*n) and space O(m*n)

class TrieNode {
public:
  char data;
  TrieNode *arr[26];
  bool isTerminal;
  int childCount;
  TrieNode(char data) {
    this->data = data;
    for (int i = 0; i < 26; i++) {
      arr[i] = NULL;
    }
    childCount=0;
    isTerminal = false;
  }
};
class Trie {
  TrieNode *root;

public:
  /** Initialize your data structure here. */
  Trie(char ch) { root = new TrieNode(ch); }

  void insertUtil(TrieNode *root, string word) {
    // base case
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }
    TrieNode *child;
    int index = word[0] - 'a';
    if (root->arr[index] != NULL) {
      child = root->arr[index];
    } else {
      child = new TrieNode(word[0]);
      root->childCount++;
      root->arr[index] = child;
    }
    insertUtil(child, word.substr(1));
  }
  /** Inserts a word into the trie. */
  void insert(string word) { insertUtil(root, word); }

  void lca(string str,string& ans){
    for(int i=0;i<str.length();i++){
        char c=str[i];
        if(root->childCount==1){
            ans.push_back(c);
            int index=c-'a';
            root=root->arr[index];
        }else{
            break;
        }
        if(root->isTerminal){
            break;
        }
    }
}
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    Trie* t=new Trie('\0');
    for(int i=0; i<n;i++){
        t->insert(arr[i]);
    }
    string str=arr[0];
    t->lca( str, ans);
    return ans;
}


