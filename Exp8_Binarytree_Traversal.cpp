//Implements Inorder, Preorder, Postorder

#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Build tree using level order input
Node* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }

    return root;
}

// Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (LRN)
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}