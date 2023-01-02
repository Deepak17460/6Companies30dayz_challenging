#define ll long long

class Solution {
public:

    long long helper(ll op1, ll op2, string oper){
        if(oper=="+")
            return op1+op2;
        
        if(oper=="-")
            return op1-op2;
        
        if(oper=="*")
            return op1*op2;
        
        if(oper=="/")
            return op1/op2;
        

        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<ll> st;

        int n = tokens.size();

        for(int i=0;i<n;i++){
            string curr = tokens[i];

            if(curr.size()>1){
                int a = stoi(curr);
                st.push(a);
            }
            else{
                if(isdigit(curr[0])){
                    int a = stoi(curr);
                    st.push(a);
                }
                else{
                    ll a = st.top();
                    st.pop();
                    ll b = st.top();
                    st.pop();
                    ll c = helper(b,a,curr);
                    st.push(c);
                }
            }
        }


        return st.top();
    }
};

//2nd Approach
  stack<ll> st;
       for(string str:tokens){
           // + operator
           if(str=="+"){
               int a=st.top();
               st.pop();
               int b=st.top();
               st.pop();
               st.push(a+b);
           }
           else if(str=="*"){
               int a=st.top();
               st.pop();
               int b=st.top();
               st.pop();
               st.push(a*b);
           }
          else if(str=="/"){
               int a=st.top();
               st.pop();
               int b=st.top();
               st.pop();
               st.push(b/a);
           }
           else if(str=="-"){
               int a=st.top();
               st.pop();
               int b=st.top();
               st.pop();
               st.push(b-a);
           }
           else{
               st.push(stoi(str));
           }
       }
       return st.top();
