#include <iostream>
#include <queue>
#include <stack>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 深度优先搜索 (DFS) - 递归实现
void dfsRecursive(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->val << " ";
    dfsRecursive(node->left);
    dfsRecursive(node->right);
}

// 深度优先搜索 (DFS) - 迭代实现（使用栈）
void dfsIterative(TreeNode* root) {
    if (root == nullptr) return;
    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        std::cout << node->val << " ";

        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }
}

// 广度优先搜索 (BFS) - 迭代实现（使用队列）
void bfs(TreeNode* root) {
    if (root == nullptr) return;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        std::cout << node->val << " ";

        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
}

int main() {
    // 创建一个三层的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 输出根节点的值
    std::cout << "Root value: " << root->val << std::endl;

    // 输出左子节点的值
    if (root->left != nullptr) {
        std::cout << "Left child value: " << root->left->val << std::endl;

        // 输出左子节点的左子节点的值
        if (root->left->left != nullptr) {
            std::cout << "Left child of left child value: " << root->left->left->val << std::endl;
        }

        // 输出左子节点的右子节点的值
        if (root->left->right != nullptr) {
            std::cout << "Right child of left child value: " << root->left->right->val << std::endl;
        }
    }

    // 输出右子节点的值
    if (root->right != nullptr) {
        std::cout << "Right child value: " << root->right->val << std::endl;

        // 输出右子节点的左子节点的值
        if (root->right->left != nullptr) {
            std::cout << "Left child of right child value: " << root->right->left->val << std::endl;
        }

        // 输出右子节点的右子节点的值
        if (root->right->right != nullptr) {
            std::cout << "Right child of right child value: " << root->right->right->val << std::endl;
        }
    }

    // 深度优先搜索 (DFS) - 递归实现
    std::cout << "\nDFS Recursive: ";
    dfsRecursive(root);
    std::cout << std::endl;

    // 深度优先搜索 (DFS) - 迭代实现
    std::cout << "DFS Iterative: ";
    dfsIterative(root);
    std::cout << std::endl;

    // 广度优先搜索 (BFS)
    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}