#include <bits/stdc++.h>
using namespace std;

//Shayan Erfanian - 40311126044

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data_): data(data_){
        left = nullptr;
        right = nullptr;
    } 
};

class bst{
private:
    Node* root;
    void inOrderPrint(Node* p){
        if(p == nullptr){
            return;
        }
        inOrderPrint(p->left);
        cout << p->data << ' ';
        inOrderPrint(p->right);
    }
    bool search(int x , Node* p){
        if(p == nullptr){
            return false;
        }
        else if(p->data == x){
            return true;
        }
        else if(p->data > x){
            return search(x , p->left);
        }
        else if(p->data < x){
            return search(x , p->right);
        }
    }
public:
    bst():root(nullptr){}
    void insert(int data){
        if(root == nullptr){
            root = new Node(data);
            return;
        }
        Node* cur = root;
        while(true){
            if(data == cur->data){
                return;
            }
            if(data < cur->data){
                if(cur->left != nullptr){
                    cur = cur->left;
                }
                else{
                    cur->left = new Node(data);
                    return;
                }
            }
            else if(data > cur->data){
                if(cur->right != nullptr){
                    cur = cur->right;
                }
                else{
                    cur->right = new Node(data);
                }
            }
        }
    }
    void print(){
        inOrderPrint(root);
        cout << '\n';
    }
    bool find(int target){
        return search(target , root);
    }
    int Min(){
        if(root == nullptr){
            return -1e9;
        }
        Node* p = root;
        while(p->left != nullptr){
            p = p->left;
        }
        return p->data;
    }
    int Max(){
        if(root == nullptr){
            return -1e9;
        }
        Node* p = root;
        while(p->right != nullptr){
            p = p->right;
        }
        return p->data;
    }
};
int main(){
    bst tree;
    tree.insert(15);
    tree.insert(67);
    tree.insert(45);
    tree.insert(4);
    tree.insert(10);
    tree.insert(6);

    tree.print();
    cout << tree.find(45) << '\n';
    cout << tree.Min() << '\n';
    cout << tree.Max() << '\n';
}