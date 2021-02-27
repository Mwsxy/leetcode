#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

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
        if (node==nullptr) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> um;
        q.push(node);
        while (!q.empty()) {
            Node *p = q.front(), *p1;
            p1 = new Node(p->val);
            um[p]=p1;
            for (const auto &i:p->neighbors) {
                if (um.find(i)==um.end()) {
                    um[i]=nullptr;
                    q.push(i);
                }
            }
            q.pop();
        }

        for (auto &[p, p1]:um) {
            for (const auto &i:p->neighbors) {
                p1->neighbors.push_back(um[i]);
            }
        }
        return um[node];
    }
};


int main() {

    return 0;
}