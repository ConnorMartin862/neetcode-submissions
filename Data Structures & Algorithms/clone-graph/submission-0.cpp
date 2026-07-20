/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {return node;}
        unordered_map<Node*, Node*> visited;
        return helper(visited, node);
    }

    Node* helper(unordered_map<Node*, Node*>& visited, Node* curr) {
        if (visited.count(curr)) {return visited[curr];}

        Node* clone = new Node(curr->val);
        visited[curr] = clone;
        for (auto& i : curr->neighbors) {
            clone->neighbors.push_back(helper(visited, i));
        }
        return clone;
    }
};
