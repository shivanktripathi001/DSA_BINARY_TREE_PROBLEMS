
#include<iostream>
#include<queue>
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


void pre_order(Node *root){


if(root == NULL ){
    return;
}

cout<<root->data<<" ";

pre_order(root->left);


pre_order(root->right);


}



void in_order(Node *root){


if(root == NULL ){
    return;
}



in_order(root->left);

cout<<root->data<<" ";

in_order(root->right);


}




void post_order(Node *root){


if(root == NULL ){
    return;
}



post_order(root->left);


post_order(root->right);

cout<<root->data<<" ";

}


void level_order(Node* root){


queue<Node*> q;
q.push(root);
q.push(NULL);


while(!q.empty()){


    Node *front = q.front();
    q.pop();

    if(front == NULL){
        cout<<endl;
        if(!q.empty()){
        q.push(NULL);
        }
    }

    else{

    cout<<front->data<<" ";

    if(front->left != NULL){
        q.push(front->left);

    }

     if(front->right != NULL){
        q.push(front->right);

    }
    }

}


}


int main(){


Node *root = creat_tree();


cout<<"printing pre order"<<endl;
pre_order(root);
cout<<endl;


cout<<"printing inorder"<<endl;
in_order(root);
cout<<endl;

cout<<"printing post order"<<endl;
post_order(root);
cout<<endl;



cout<<"printing level order"<<endl;
level_order(root);
cout<<endl;

return 0;
}
