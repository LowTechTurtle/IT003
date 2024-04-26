
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node* root_save = root; 
        Node* prev = root;
        if (!root) {
            Node* node = new Node(data);
            return node;
        }

        while (root) {
            if (data < root -> data) {
                prev = root;
                root = root -> left;
            } else {
                prev = root;
                root = root -> right;
            }
        }
        
        if (data < prev -> data) {
            Node* node = new Node(data);
            prev -> left = node;
        } else {
            Node* node = new Node(data);
            prev -> right = node;
        }
        return root_save;
    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}