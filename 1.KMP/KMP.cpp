#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

inline void get_next(string T,vector<int> &next)
{
    next[0] = -1;
    for(int i=1;i<T.size();i++ ){
        int j = next[i-1];
        while(T[i] != T[j+1] && j>=0 ) j=next[j];
        if(T[i]==T[j+1])next[i]=j+1;
        else next[i]=0;             
    }
};

inline string::size_type KMP(const string& S,const string& T)
{
    vector<int> next(T.size());
    get_next(T,next);

    string::size_type index,count=0;
    for(index=0;index<S.size();++index){
        int pos=0;
        string::size_type iter=index;
        while(pos<T.size() && iter<S.size()){
            if(S[iter]==T[pos]){
                ++iter;++pos;
            }
            else{
                 if(pos==0)++iter;
                 else pos=next[pos-1]+1;
            }
        }//while end
        if(pos==T.size()&&(iter-index)==T.size())++count;
    } //for end
    return count;
}

int main()
{
    string S="ababcabcacbab";
    string T="abcac";
    string::size_type count = KMP(S,T);
    cout<<count<<endl;
    system("pause");  
    return 0;
}
