class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        //horizontal distance --- mapped--- levelwise_nodes
        // levelwise nodes  ---map--- level and nodes
        map<int,map<int,vector<int>>> nodes;
        // queue has a node along with horizontaldistance and level 
        queue<pair<Node*,pair<int,int>>> q;
        
        if(root==NULL){
            return ans;
        }
        //initial q with root node and hd = 0, level = 0
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            //front value nikal li aur pop krdi
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            //uss value se cheeze nikal li alag alag
            Node * frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            //map me daal di key, value
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                // hd - 1 kyuki left pe number line pe decrease hoga ana lvl positive kyuki level increase hoga
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
                
            }
            
            if(frontNode->right){
                // hd + 1 kyuki left pe number line pe increase hoga ana lvl positive kyuki level increase hoga
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
                
            }
        }//while loop ends
            
            for(auto i : nodes){
                for(auto j:i.second){
                    //nodes ke andar vector tak aa gye jha pe values hai nodes ki
                    for(auto k : j.second){
                        ans.push_back(k);
                        
                    }
                }
            }
            
            return ans;
            
        
    }
};