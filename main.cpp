#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

node* newNode(int val){
    struct node *temp=new(struct node);
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preOrder(struct node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(struct node *root){
    if(root==NULL)
        return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}


void postOrder(struct node *root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printGivenLevel(struct node *root,int l){
    if(root==NULL)
        return;
    if(l==1)
        cout<<root->data<<" ";
    else if(l>1){
        printGivenLevel(root->left,l-1);
        printGivenLevel(root->right,l-1);
    }
}

node** createQueue(int *f,int *r){
    struct node **que=(struct node **)malloc(sizeof(struct node*)*1000);
    *f=*r=0;
    return que;
}

void enQueue(struct node **que,int *r,struct node *root){
    que[*r]=root;
    (*r)++;
}

node* dQueue(struct node **que,int *f){
    (*f)++;
    return(que[*f-1]);
}

void printLevelOrder(struct node *root){
    int f,r;
    struct node **que=createQueue(&f,&r);
    struct node *temp=root;
    while(temp){
        cout<<temp->data<<" ";
        if(temp->left)
            enQueue(que,&r,temp->left);
        if(temp->right)
            enQueue(que,&r,temp->right);
        temp=dQueue(que,&f);
    }
}

bool idTree(struct node *t1,struct node *t2){
    if(t1==NULL && t2==NULL)
        return true;
    else if(t1!=NULL && t2!=NULL){
        if(t1->data==t2->data){
            return idTree(t1->left,t2->left) & idTree(t1->right,t2->right);
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int sum(struct node *root){
    if(root==NULL)
        return 0;
    else
        return (root->data+sum(root->left)+sum(root->right));
}

bool summationTree(struct node *root){
    if(root==NULL)
        return true;
    else{
        if(root->left==NULL && root->right==NULL)
            return true;
        else if(root->data==(sum(root->left)+sum(root->right))){
            return summationTree(root->left) & summationTree(root->right);
        }
        else
            return false;
    }
}

void printBoundaryLeft(struct node *root){
    if(root==NULL)
        return;
    if(root->left!=NULL || root->right!=NULL){
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
}

void printBoundaryLeaves(struct node *root){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    else{
        printBoundaryLeaves(root->left);
        printBoundaryLeaves(root->right);
    }
}

void printBoundaryRight(struct node *root){
    if(root==NULL)
        return;
    if(root->left!=NULL || root->right!=NULL){
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}

void printBoundary(struct node *root){
    printBoundaryLeft(root);
    printBoundaryLeaves(root);
    printBoundaryRight(root->right);
}

int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}

int main()
{
    struct node *root=NULL;
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    struct node *root1=NULL;
    root1=newNode(1);
    root1->left=newNode(2);
    root1->right=newNode(3);
    root1->left->left=newNode(40);
    root1->left->right=newNode(5);
    preOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    printGivenLevel(root,2);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    cout<<idTree(root,root1);
    cout<<endl;
    struct node *root2=NULL;
    root2=newNode(27);
    root2->left=newNode(10);
    root2->right=newNode(7);
    root2->left->left=newNode(6);
    root2->left->right=newNode(4);
    cout<<summationTree(root2);
    cout<<endl;
    struct node *root3=NULL;
    root3=newNode(27);
    root3->left=newNode(10);
    root3->right=newNode(7);
    root3->left->left=newNode(6);
    root3->left->right=newNode(4);
    root3->left->right->left=newNode(1);
    printBoundary(root3);
    cout<<endl;
    cout<<"Height of root3: "<<height(root3);
    return 0;
}
