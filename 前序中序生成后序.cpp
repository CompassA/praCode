#include <stdio.h>
#include <string.h>

char pre[100], mid[100];

struct node {
    char data;
    node *left, *right;
    node(const char &c): data(c), left(nullptr), right(nullptr) {} 
};

node* create(const int &preL, const int &preR, const int &lnL, const int &lnR) {
    if (preR < preL) {
        return nullptr;
    }
    
    node *root = new node(pre[preL]);
    int i;
    for (i = lnL; i <= lnR; ++i) {
        if (mid[i] == pre[preL]) {
            break;
        }
    }
    
    int leftNum = i - lnL;
    root->left = create(preL+1, preL+leftNum, lnL, i-1);
    root->right = create(preL+leftNum+1, preR, i+1, lnR);
    return root;
}

void f(node * root) {
    if (root != nullptr) {
        f(root->left);
        f(root->right);
        printf("%c", root->data);
        delete root;
        root = nullptr;
    }
}

int main() {
    while (scanf("%s%s", pre, mid) != EOF) {
        node *root = create(0, strlen(pre)-1, 0, strlen(mid)-1);
        f(root);
        putchar('\n');
    }
    return 0;
}
