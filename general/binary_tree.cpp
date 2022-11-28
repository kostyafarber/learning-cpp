#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void pre_order_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);

}

void post_order_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->data << " ";
}

void in_order_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    in_order_traversal(root->left);
    cout << root->data << " ";
    in_order_traversal(root->right);
}

int main() {

    Node* root = new Node(1); // made on the heap
    root->left = new Node(4);
    root->right = new Node(5);

/*

    1
   / \
  4  5

*/

// We can remember the order relative to where the root is, with "in order" being in the middle. 

    // root
    // left
    // right
    pre_order_traversal(root);
    cout << endl;

    // left 
    // right
    // root
    post_order_traversal(root);
    cout << endl;

    // left
    // root
    // right
    in_order_traversal(root);
    cout << endl;
}