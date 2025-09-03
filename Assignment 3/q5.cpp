#include<iostream>
#include<string>
using namespace std;
class MyStack{
    public:
    int top;
    char arr[100];
    public:
    MyStack(){
        top=-1;
    }
void push(char val){
    if(top>=99){
        cout<<"stack is full";
        return;
    }
    top++;
    arr[top]=val;

}
char pop(){
if(isempty()){
    cout<<"empty";
    return 0;
}

return arr[top--];
}
    char peek() {
        if (isempty()) return '\0';
        return arr[top];
    }
bool isempty(){
    return top<0;
}
};
int evaluate(char str[]){
    MyStack s;
    int i=0;
    while(str[i]!='\0'){
        char ch=str[i];
        if(ch>='0'&& ch<='9'){
            s.push(ch-'0');
        }
        else{
            int val1=s.pop();
            int val2=s.pop();
            switch(ch){
                case '+': s.push(val2+val1);break;
                 case '-': s.push(val2-val1);break;
                  case '*': s.push(val2*val1);break;
                   case '/': s.push(val2/val1);break;
                    case '^': s.push(val2^val1);break;
            }
        }
        i++;
    }
    return s.pop();
}

int main(){
    
 char str[100];
    cout << "Enter postfix expression: ";
    cin >> str;
    cout<<"result="<<evaluate(str)<<endl;
    return 0;
}