#include <iostream>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* child[26];
        bool isTerminal;

        trieNode(char data){
            this->data=data ;
            for(int i=0;i<26;i++){
                child[i]=0;
            }
            isTerminal=false;
        }
};

class trie{
    public:
        trieNode* head;
    
    void insertUtils(trieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int index=word[0]-'A';
            trieNode* child;
            if(root->child[index]!=NULL){
                child=root->child[index];
            }
            else{
                root->child[index]=new trieNode(word[index]);
                child=root->child[index];
            }
            insertUtils(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtils(head,word);
        }

        bool searchUtils(trieNode* root,string word){
            if(word.length()==0){
                return root->isTerminal;
            }
            int index=word[0]-'A';
            trieNode* child;
            if(root->child[index]!=NULL){
                child=root->child[index];
            }
            else{
                return false;
            }
            return searchUtils(root,word.substr(1));
        }

        void searchWord(string word){
            searchUtils(head,word);
        }
};

int main(){
    return 0;
}