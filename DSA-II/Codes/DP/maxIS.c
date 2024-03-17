#include <stdio.h>
#include <stdlib.h>

// references
// 1) Algorithm: https://www.youtube.com/watch?v=-LN5-GvV-bQ
// 2) How to build a tree in C: https://www.geeksforgeeks.org/largest-independent-set-problem-using-dynamic-programming/

struct node
{
    int data;
    int liss;
    struct node *left, *right;

};

struct node *newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> liss = 0;
    return temp;
};

int max_value(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int LISS(struct node *root){
    // By recurrsion
    // if (root == NULL){
    //     return 0;
    // }

    // int size_excl = LISS(root->left) + LISS(root->right);

    // int size_inclu = 1;
    // if (root->left){
    //     size_inclu += LISS(root->left->left) + LISS(root->left->right);
    // }
    // if (root->right){
    //     size_inclu += LISS(root->right->right) + LISS(root->right->left);
    // }

    // return max_value(size_excl, size_inclu);

    // By DP
    if (root == NULL){
        return 0;
    }
    if (root -> liss){
        return root -> liss;
    }
    if (root -> left == NULL && root -> right == NULL){
        return root -> liss = 1;
    }

    int liss_excl = LISS(root -> left) + LISS(root -> right);

    int liss_incl = 1;
    if (root -> left){
        liss_incl += LISS(root -> left -> left) + LISS(root -> left -> right);
    }

    if (root -> right){
        liss_incl += LISS(root -> right ->right) + LISS(root -> right -> left);
    }

    return max_value(liss_excl, liss_incl);
}


int main(){
    struct node *root = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printf("LISS = %d", LISS(root));
}