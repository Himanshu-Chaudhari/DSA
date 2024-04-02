#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtils(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            root->children[index]=new TrieNode(word[0]);
            child=root->children[index];
        }
        insertUtils(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtils(root,word);
    }

    bool searchUtils(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtils(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtils(root,word);
    }
};

int main(){
    Trie* root=new Trie();
    root->insertWord("ABCD");
    root->insertWord("ABC");
    cout<<root->searchWord("ABCD");
    return 0;
}
// #include<iostream>
// using namespace std;

// class TrieNode {
// public:
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;

//     TrieNode(char data) {
//         this->data = data;
//         for (int i = 0; i < 26; i++) {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };

// class Trie {
// public:
//     TrieNode* root;

//     Trie() {
//         root = new TrieNode('\0');
//     }

//     void insertUtils(TrieNode* root, string word) {
//         if (word.length() == 0) {
//             root->isTerminal = true;
//             return;
//         }
//         int index = word[0] - 'A';
//         TrieNode* child;
//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             root->children[index] = new TrieNode(word[0]);
//             child = root->children[index];
//         }
//         insertUtils(child, word.substr(1));
//     }

//     void insertWord(string word) {
//         insertUtils(root, word);
//     }

//     bool searchUtils(TrieNode* root, string word) {
//         if (word.length() == 0) {
//             return root->isTerminal;
//         }

//         int index = word[0] - 'A';
//         TrieNode* child;
//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             return false;
//         }
//         // Return the result of the recursive call
//         return searchUtils(child, word.substr(1));
//     }

//     bool searchWord(string word) {
//         return searchUtils(root, word);
//     }
// };

// int main() {
//     Trie* trie = new Trie();
//     trie->insertWord("ABCD");
//     cout << trie->searchWord("ABCD") << endl;
//     return 0;
// }
