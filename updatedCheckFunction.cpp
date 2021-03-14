inline int check(vector<int>& initialVector,vector<int>& sortedVector)
{
    int sz=(int)sortedVector.size();

    sort(initialVector.begin(),initialVector.end());

    if((int)initialVector.size()!=sz)
    {
        return 0;
    }

    for(int i=0;i<sz;i++)
        if(initialVector[i]!=sortedVector[i]) return 0;
    return 1;
}
