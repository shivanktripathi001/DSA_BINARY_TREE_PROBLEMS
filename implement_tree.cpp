
#include<iostream>
using namespace std;


class Node{

    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){


    this->data = val;
    this->left = NULL;
    this->right = NULL;

    }



};

Node *creat_tree(){

cout<<"enter the root value"<<endl;

int data;
cin>>data;


if(data == -1){
return NULL;
}


Node *root = new Node(data);


cout<<"enter the left node for "<<root->data;
root->left = creat_tree();


cout<<"enter the right node for "<<root->data;
root->right = creat_tree();


return root;

}


int main(){


Node *root = creat_tree();
return 0;
}
