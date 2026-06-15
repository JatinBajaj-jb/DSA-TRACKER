// Approach 1- I used BFS traversal
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> mp;

        queue<Node*> que;
        que.push(node);
        Node* curr=new Node(node->val);
        mp[node]=curr;

        while(!que.empty()){
            Node* top=que.front();
            que.pop();

            for(Node* neigh:top->neighbors){
                if(mp.find(neigh)==mp.end()){
                    mp[neigh]=new Node(neigh->val);
                    que.push(neigh);
                }
                mp[top]->neighbors.push_back(mp[neigh]);
            }                
        }
        return curr;        
    }
};

// Approach 2 : I solve the question using DFS traversal
class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp.find(node)!=mp.end()) return mp[node];

        Node* curr=new Node(node->val);
        mp[node]=curr;
        for(Node* neigh:node->neighbors){
            curr->neighbors.push_back(cloneGraph(neigh));
        }
        return curr;
    }
};


