/*
 *We can build a min-heap using an array of N
N integers by assuming an empty heap,
 inserting the integers one by one,
 and using the above technique to restore the heap property after every insertion.
 *
#include "/Users/helingeleri/stdc++.h"
#include<iostream>
using namespace std;

void min_heapify_bottom_up(int arr[], int N, int idx) {
    if (idx == 0)
        return;
    int parent = (idx - 1) / 2;
    if (arr[parent] > arr[idx]) {
        swap(arr[parent], arr[idx]);
    }
    min_heapify_bottom_up(arr, N, parent);
}

void build_heap(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        min_heapify_bottom_up(arr, N, i);
    }
}

int main() {
    srand (time(NULL));
    int N = 10;
    int arr[N];
    for(int i = 0; i < N; i++)
        arr[i] = rand() % 32 + 1;

    for(int i = 0; i < N; i++) cout << arr[i]<<" "; cout << "\n";
    build_heap(arr, N);
    for(int i = 0; i < N; i++) cout << arr[i]<<" "; cout << "\n";
    return 0;
}

*/

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kth_largest(vector<int> &v, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < v.size(); i++){
        if (pq.size() < K) {
            pq.push(v[i]);
        }
        else {
            if (v[i] > pq.top()) {
                pq.pop();
                pq.push(v[i]);
            }
        }
    }
    int answer = pq.top();
    while (!pq.empty()) {
        answer = min(answer, pq.top());
        pq.pop();
    }
    return answer;
}

int main() {
    int N = 5;
    vector<int> v = {3, 6, 5, 1, 4};

    cout<<kth_largest(v, 1)<<"\n";
    cout<<kth_largest(v, 4)<<"\n";

    return 0;
}
*/

/*
//delete a key from a binary search tree.
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int val){
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insert(struct Node* &root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    Node* pCrawl = root;
    Node* pCrawlParent;
    while(pCrawl) {
        pCrawlParent = pCrawl;

        if (val < pCrawl->val)
            pCrawl = pCrawl->left;
        else
            pCrawl = pCrawl->right;
    }

    if (val < pCrawlParent->val)
        pCrawlParent->left = new Node(val);
    else
        pCrawlParent->right = new Node(val);
}

void in_order(struct Node* node)  {
    if (node == NULL)
        return;

    in_order(node -> left);
    cout << node -> val << " ";
    in_order(node -> right);
}

struct Node* min_value_node(struct Node* node) {
    struct Node* pCrawl = node;

    while (pCrawl->left != NULL)
        pCrawl = pCrawl->left;

    return pCrawl;
}

Node* delete_node(struct Node* root, int val) {
    if (root == NULL) return root;

    if (val < root->val) // The key to be deleted is in the left subtree
        root->left = delete_node(root->left, val);

    else if (val > root->val) // The key to be deleted is in the right subtree
        root->right = delete_node(root->right, val);

    else {  // The current node is to be deleted
        if (root->left == NULL && root->right == NULL) { // Case 1
            // Returning null here will make the parent's pointer to this node null
            // effectively removing this node from the tree
            return NULL;
        }
        else if (root->right == NULL) {  // Case 2
            // Parent's pointer to this node is replaced with left child of this node
            return root->left;
        }
        else if (root->left == NULL) {  // Case 3
            // Parent's pointer to this node is replaced with right child of this node
            return root->right;
        }
        else { // Case 3
            // Find minimum value in the right subtree (in-order successor)
            // Copy to this node
            // Delete the inorder successor
            struct Node* temp = min_value_node(root->right);
            root->val = temp->val;
            root->right = delete_node(root->right, temp->val);
        }
    }
    return root;
}

int main() {
    // Creating the same tree as in the illustration above for Case 1
    Node* root1 = NULL;
    insert(root1, 5);insert(root1, 2);insert(root1, 7);
    insert(root1, 1);insert(root1, 3);
    in_order(root1); cout << "\n";
    delete_node(root1, 3);
    in_order(root1); cout << "\n\n";


    // Creating the same tree as in the illustration above for Case 2
    Node* root2 = NULL;
    insert(root2, 5);insert(root2, 2);insert(root2, 6);
    insert(root2, 1);insert(root2, 3);insert(root2, 7);
    insert(root2, 8);
    in_order(root2); cout << "\n";
    delete_node(root2, 6);
    in_order(root2); cout << "\n\n";


    // Creating the same tree as in the illustration above for Case 3
    Node* root3 = NULL;
    insert(root3, 5);insert(root3, 3);insert(root3, 7);
    insert(root3, 1);insert(root3, 6);insert(root3, 8);
    insert(root3, 9);
    in_order(root3); cout << "\n";
    delete_node(root3, 7);
    in_order(root3); cout << "\n\n";



    return 0;
}
 */
