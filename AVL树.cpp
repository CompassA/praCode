#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int val, height;
    node* left, *right;
    node(const int &v): val(v), height(1), left(nullptr), right(nullptr) {}
};

vector<int> output;

int getHeight(node* root) {
    if (root == nullptr) return 0;
    return root->height;
}

void updateHeight(node *root) {
    root->height = max(getHeight(root->left), getHeight(root->right))+1; 
}

int getBalanceFactor(node *root) {
    return getHeight(root->left)- getHeight(root->right);
}

void L(node*& root) {
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node*& root) {
    node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void search(node* root, const int &v) {
    if (root == nullptr) {
        output.push_back(0);
        return;
    }
    if (root->val == v) {
        output.push_back(1);
    } else if (root->val > v) {
        search(root->left, v);
    } else {
        search(root->right, v);
    }
}

void insert(node*& root, const int &v) {
    if (root == nullptr) {
        root = new node(v);
        return;
    }
    if (root->val > v) {
        insert(root->left, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            int factor = getBalanceFactor(root->left);
            if (factor == 1) {
                R(root);
            } else if (factor == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            int factor = getBalanceFactor(root->right);
            if (factor == -1) {
                L(root);
            } else if (factor == 1) {
                R(root->right);
                L(root);
            }
        }
    }
}

int main() {
    int n, k;
    node* root(nullptr);
    scanf("%d%d", &n, &k);
    while (n--) {
        int v;
        scanf("%d", &v);
        insert(root, v);
    }
    
    while (k--) {
        int v;
        scanf("%d", &v);
        search(root, v);
    }
    
    for (int i = 0; i < output.size(); ++i) {
        if (i == output.size()-1) printf("%d\n", output[i]);
        else printf("%d ", output[i]);
    }
    return 0;
} 
