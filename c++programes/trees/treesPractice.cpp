#include <iostream>
#include <stack>
#include <queue>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
    }
};

node *createTree(node *root)
{
    int data;
    cout << "Please enter the data ";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to insert at left of " << data << ":" << endl;
    root->left = createTree(root->left);
    cout << "Enter data to insert at right of " << data << ":" << endl;
    root->right = createTree(root->right);
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " , ";
    inorder(root->left);
    inorder(root->right);
}
void levelOrderTransversal(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            // complete traversal of last level is done
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void LOT(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    bool LTR=true;      
    while (!q.empty())
    {
        node* top = q.front();
        q.pop();
        if (top == NULL)
        {
            // complete traversal of last level is done
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << top->data << " , ";

            if (top->left)
            {
                q.push(top->left);
            }
            if (top->right)
            {
                q.push(top->right);
            }
        }
    }
}


vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0 ; i < nums.size() ; i++ ){
            map[nums[i]]++;
        }
        int j;
        while(k>=1){
            int max=INT_MIN;
            for(auto i : map){
                int n=i.second;
                if(n>max){
                    max=n;
                    j=i.first;
                    cout<<j<<" , ";
                }
            }
            cout<<endl;
            ans.push_back(j);
            map[j]=0;
            k--;
        }
        return ans;
    }

int main()
{
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(1);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(2);
    ans.push_back(3);
    ans=topKFrequent(ans,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" , ";
    }
    // node *root;
    // root = createTree(root);
    // inorder(root);
    // LOT(root);
    // levelOrderTransversal(root);
}