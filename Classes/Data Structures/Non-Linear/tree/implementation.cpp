#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
class Node {
    public:
    T key;
    Node<T> *left;
    Node<T> *right;

    Node() {
        key = T();
        left = nullptr;
        right = nullptr;
    }

    Node(T key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class Tree {
    private:
    Node<T> *root;

    public:
    Tree() {
        root = nullptr;
    }

    /// Adds a node to the tree, following the specific ordering property of a BST. Time complexity: `O(n)`. Space complexity: `O(1)`.
    void add_node(T key) {
        Node<T> *new_node = new Node(key);

        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node<T> *ptr = root;
        Node<T> *parent = nullptr;
        
        while (ptr != nullptr) {
            parent = ptr;
            if (key > ptr->key)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }

        if (key > parent->key)
            parent->right = new_node;
        else
            parent->left = new_node;
    }

    /// Traverses the tree using using DFS, in NLR order. Time complexity: `O(n)`. Space complexity `O(n)`.
    void preorder(Node<T> *ptr) {
        if (ptr == nullptr)
            return;

        cout << ptr->key << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
    
    /// Traverses the tree using using DFS, in LRN order. Time complexity: `O(n)`. Space complexity `O(n)`.
    void postorder(Node<T> *ptr) {
        if (ptr == nullptr)
            return;

        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->key << " ";
    }

    /// Traverses the tree using using DFS, in LNR order. Time complexity: `O(n)`. Space complexity `O(n)`.
    void inorder(Node<T> *ptr) {
        if (ptr == nullptr)
            return;

        inorder(ptr->left);
        cout << ptr->key << " ";
        inorder(ptr->right);
    }

    /// Traverses the tree using BFS, by levels. Time complexity: `O(n)`. Space complexity `O(n)`.
    void leveled() {
        if (root == nullptr)
            return;

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* ptr = q.front();
            q.pop();

            cout << ptr->key << " ";
            if (ptr->left != nullptr)
                q.push(ptr->left);

            if (ptr->right != nullptr)
                q.push(ptr->right);
        }
    }

    /// Displays each of the data stored in the BST depending on the input parameter: 
    /// 1. Preorder
    /// 2. Inorder
    /// 3. Postorder
    /// 4. Level by level
    /// Time complexity: `O(n)`. Space complexity: `O(n)`.
    void visit(int option) {
        switch (option) {
        case 1:
        // Preorder
        preorder(root);
        break;
        case 2:
        // Inorder
        inorder(root);
        break;
        case 3:
        // Postorder
        postorder(root);
        break;
        case 4: {
            // Level by level
            leveled();
            break;
        }
        default:
            break;
        }
        cout << endl;
    }

    /// Returns the tree height using BFS. Time complexity: `O(n)`. Space complexity: `O(w)`, worst case `O(n)`. Where `w` is the width of the tree.
    int height() {
        if (root == nullptr)
            return 0;
        
        queue<Node<T> *> q;
        q.push(root);

        int h = 0; // height counter
        while (!q.empty()) {
            h++;
            // Add all nodes in the level to the queue before incrementing height by 1 again
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                Node<T>* ptr = q.front();
                q.pop();

                if (ptr->left != nullptr)
                    q.push(ptr->left);
                if (ptr->right != nullptr)
                    q.push(ptr->right);
            }
        }

        return h;
    }

    /// Prints the ancestors of a key in a BST. Time complexity: `O(h)`, worst case `O(n)`. Space complexity: `O(h)`, worst case `O(n)`. Where `h` is the height of the tree.
    void ancestors(T key) {
        if (root == nullptr)
            return;
        
        stack<Node<T> *> s;

        Node<T> *ptr = root;
        while (ptr != nullptr && ptr->key != key) {
            s.push(ptr);
            if (key > ptr->key)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }

        if (ptr == nullptr) {
            cout << "Key was not found in tree." << endl;
            return;
        }

        while (!s.empty()) {
            Node<T> *top = s.top();
            cout << top->key << " ";
            s.pop();
        }

        cout << endl;
    }

    /// Returns the level of a key using BFS, or -1 if the key is not found. Time complexity: `O(n)`. Space complexity: `O(w)`, worst case `O(n)`. Where `w` is the width of the tree.
    int levelOf(T key) {
        if (root == nullptr)
            return -1;

        if (root->key == key)
            return 0;
        
        queue<Node<T> *> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                Node<T> *ptr = q.front();
                q.pop();

                if (ptr->key == key)
                    return level;

                if (ptr->left != nullptr)
                    q.push(ptr->left);
                if (ptr->right != nullptr)
                    q.push(ptr->right);
            }
            level++;
        }

        return -1;
    }

    /// Deletes the node from the tree containing the given key. Time complexity: `O(n)`. Space complexity: `O(1)`.
    void delete_node(T key) {
        if (root == nullptr)
            return;
        
        Node<T>* ptr = root;
        Node<T>* parent = nullptr;
        
        while (ptr != nullptr) {
            if (ptr->key == key)
                break;

            parent = ptr;

            if (key > ptr->key)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }

        if (ptr == nullptr)
            return;

        // Case 3: node has two children
        if (ptr->left != nullptr && ptr->right != nullptr) {
            Node<T>* successor_parent = ptr;
            Node<T>* successor = ptr->right;

            while (successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left;
            }

            ptr->key = successor->key;

            Node<T>* successor_child = successor->right;

            if (successor_parent->left == successor)
                successor_parent->left = successor_child;
            else
                successor_parent->right = successor_child;

            delete successor;
            return;
        }

        // cases 1 and 2: node is leaf or only has one child
        Node<T>* child;

        if (ptr->left != nullptr)
            child = ptr->left;
        else 
            child = ptr->right;

        if (parent == nullptr)
            // if parent is nullptr, it means the key is in the root
            root = child;
        else if (parent->left == ptr)
            parent->left = child;
        else
            parent->right = child;

        delete ptr;
    }
};

int main() {
    // Instantiate tree and add nodes
    Tree<int> tree;
    tree.add_node(8);
    tree.add_node(3);
    tree.add_node(10);
    tree.add_node(1);
    tree.add_node(6);
    tree.add_node(5);
    tree.add_node(14);
    tree.add_node(4);
    tree.add_node(7);
    tree.add_node(13);
    tree.delete_node(5);

    // 1. Tree traversals
    cout << "Preorder Traversal: ";
    tree.visit(1);

    cout << "Inorder Traversal: ";
    tree.visit(2);

    cout << "Postorder Traversal: ";
    tree.visit(3);

    cout << "Level Traversal: ";
    tree.visit(4);

    // 2. Tree height
    cout << "The tree height is: " << tree.height() << endl;

    // 3. Ancestors of a node
    cout << "Ancestors of node with key 4: ";
    tree.ancestors(4);

    // 4. Level of a node
    cout << "Level of node with key 14: " << tree.levelOf(14) << endl;
    return 0;
}