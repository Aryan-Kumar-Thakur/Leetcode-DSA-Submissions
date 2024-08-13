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
    Node* solve(Node* node,unordered_map<Node*,Node*> &mp){
        Node* cloneNode=new Node(node->val);
        mp[node]=cloneNode;
        vector<Node*> arr;
        for(auto it:node->neighbors){
            if(mp.find(it)!=mp.end()){
                arr.push_back(mp[it]);
            }
            else{
                arr.push_back(solve(it,mp));
            }
        }
        cloneNode->neighbors=arr;
        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* cloneNode= new Node(node->val);
            return cloneNode;
        }
        unordered_map<Node*,Node*> mp;
        return solve(node,mp);
    }
};