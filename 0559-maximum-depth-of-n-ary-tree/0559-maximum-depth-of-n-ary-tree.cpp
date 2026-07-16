/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;

        queue<Node*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                Node* node = q.front();
                q.pop();

                for (Node* child : node->children)
                    q.push(child);
            }

            depth++;
        }

        return depth;
    }
};