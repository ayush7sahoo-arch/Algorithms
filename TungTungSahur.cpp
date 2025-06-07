#include<iostream>
#include<vector>

using namespace std;

typedef struct {
    char c;
    int len;
}Tung;


int main(){
    int t;
    cin >> t;
    vector<string>ans(t);
    for(int i=0;i<t;i++){
        string p;
        string s;
        cin >> p >> s;
        
        if(p==s){
            ans[i] = "YES";
            continue;
        }else if(s.length()<p.length()){
            ans[i] = "NO";
            continue;
        }else{
            vector<Tung> _p;
            for(int i=0;i<p.length();i++){
                if(_p.empty()){
                    _p.push_back({p[i], 1});
                }else{
                    if(_p.back().c == p[i]){
                        _p.back().len++;
                    }else{
                        _p.push_back({p[i], 1});
                    }
                }
            }
            vector<Tung> _s;
            for(int i=0;i<s.length();i++){
                if(_s.empty()){
                    _s.push_back({s[i], 1});
                }else{
                    if(_s.back().c == s[i]){
                        _s.back().len++;
                    }else{
                        _s.push_back({s[i], 1});
                    }
                }
            }
            if(_p.size() != _s.size()){
                ans[i] = "NO";
                continue;
            }else{
                for(int j=0;j<_p.size();j++){
                    if(_p[j].c!=_s[j].c || _s[j].len>2*_p[j].len || _s[j].len<_p[j].len){
                        ans[i] = "NO";
                        break;
                    }
                    
                }
                if(ans[i] != "NO"){
                    ans[i] = "YES";
                }
            }
            
        }
    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl;
    }
    
}