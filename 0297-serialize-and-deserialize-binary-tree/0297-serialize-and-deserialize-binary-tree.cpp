/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode(1001);
        q.push(root);
        while (!q.empty()) {
            int x = q.size();
            while (x--) {
                auto ele = q.front();
                q.pop();
                if (!ele) {
                    ans += "N,";
                } else {
                    string k = to_string(ele->val);
                    ans += k;
                    ans += ",";
                    if (ele->left) {
                        q.push(ele->left);
                    } else {
                        q.push(NULL);
                    }
                    if (ele->right) {
                        q.push(ele->right);
                    } else {
                        q.push(NULL);
                    }
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N,") {
            return NULL;
        }
        stringstream ss(data);
        string val;
        queue<TreeNode*> q;
        TreeNode* root = NULL;
        getline(ss, val, ',');
        root = new TreeNode(stoi(val));
        q.push(root);
        while (!q.empty()) {
            int x = q.size();
            while (x--) {
                TreeNode* ele = q.front();
                q.pop();
                getline(ss, val, ',');
                if (val == "N") {
                    ele->left = NULL;
                } else {
                    int data = stoi(val);
                    ele->left = new TreeNode(data);
                    q.push(ele->left);
                }
                getline(ss, val, ',');
                if (val == "N") {
                    ele->right = NULL;
                } else {
                    int data = stoi(val);
                    ele->right = new TreeNode(data);
                    q.push(ele->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));