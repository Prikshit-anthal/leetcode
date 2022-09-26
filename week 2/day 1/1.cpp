//https://leetcode.com/problems/satisfiability-of-equality-equations/


//disjoint set op
class disJointSet{
    vector<int> parent;
    vector<int> rank;
    public:
    disJointSet()
    {
        makeset();
    }
    
    void uniion(int x,int y)
    {
        int px=findParent(x);
        int py=findParent(y);
        
        if(px==py)
            return;
        
        if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else{
            rank[px]++;
            parent[py]=px;
        }
    }
    
    void makeset()
    {
        parent.resize(26);
        rank.resize(26,0);
        
        for(int i=0;i<26;i++)
            parent[i]=i;
    }
    
    int findParent(int x)
    {
        if(parent[x]==x)
            return x;
        
        return parent[x]=findParent(parent[x]);
    }
    
    
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        disJointSet obj;
        vector<string> neg;
        
        for(auto i:equations)
        {
            if(i[1]=='!')
                neg.push_back(i);
            else{
                obj.uniion(i[0]-'a',i[3]-'a');
            }
        }
        
        for(auto i:neg)
        {
            if(obj.findParent(i[0]-'a')==obj.findParent(i[3]-'a'))
                return false;
        }
        
        return true;
    }
};

