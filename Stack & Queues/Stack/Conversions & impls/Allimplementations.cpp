#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Stack using array
class StImpl{
private:
    int top1 = -1;
    int st[10];

public:

    void push(int x){
        if(top1>=9){
            cout<<"Stack Overflow\n";
            return;
        }
        st[++top1]=x;
    }

    int top(){
        if(top1==-1){
            cout<<"Stack Underflow\n";
            return -1;
        }
        return st[top1];
    }

    void pop(){
        if(top1==-1){
            cout<<"Stack Underflow\n";
            return;
        }
        top1--;
    }

    int size(){
        return top1+1;
    }
};



//Queue using array (circular)
class QImpl{

private:
    int currSize=0,start=-1,end=-1;
    static const int size=10;
    int q[size];

public:

    void push(int x){

        if(currSize==size){
            cout<<"Queue overflow\n";
            return;
        }

        if(currSize==0){
            start=end=0;
        }
        else{
            end=(end+1)%size;
        }

        q[end]=x;
        currSize++;
    }

    void pop(){

        if(currSize==0){
            cout<<"Queue underflow\n";
            return;
        }

        if(currSize==1){
            start=end=-1;
        }
        else{
            start=(start+1)%size;
        }

        currSize--;
    }

    int top(){

        if(currSize==0){
            cout<<"Queue underflow\n";
            return -1;
        }

        return q[start];
    }

    int Size(){
        return currSize;
    }
};



//Stack using LL
class StLL{

private:
    ListNode* topNode=nullptr;
    int sz=0;

public:

    void push(int x){

        ListNode* temp=new ListNode(x);
        temp->next=topNode;
        topNode=temp;
        sz++;
    }

    void pop(){

        if(!topNode){
            cout<<"Stack underflow\n";
            return;
        }

        ListNode* temp=topNode;
        topNode=topNode->next;
        delete temp;
        sz--;
    }

    int peek(){

        if(!topNode){
            cout<<"Stack underflow\n";
            return -1;
        }

        return topNode->val;
    }

    int size(){
        return sz;
    }
};



//Queue using LL
class QLL{

private:
    ListNode* start=nullptr;
    ListNode* end=nullptr;
    int sz=0;

public:

    void push(int x){

        ListNode* temp=new ListNode(x);

        if(!start){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }

        sz++;
    }

    void pop(){

        if(!start){
            cout<<"Queue underflow\n";
            return;
        }

        ListNode* temp=start;
        start=start->next;

        if(!start) end=nullptr;

        delete temp;
        sz--;
    }

    int top(){

        if(!start){
            cout<<"Queue underflow\n";
            return -1;
        }

        return start->val;
    }

    int size(){
        return sz;
    }
};



//Stack using queue
class StQ{

private:
    queue<int> q;

public:

    void push(int x){

        int s=q.size();

        q.push(x);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){

        if(q.empty()){
            cout<<"Stack underflow\n";
            return;
        }

        q.pop();
    }

    int top(){

        if(q.empty()){
            cout<<"Stack underflow\n";
            return -1;
        }

        return q.front();
    }

    int size(){
        return q.size();
    }
};



//Queue using stack (method 1)
class QSt{

private:
    stack<int> s1,s2;

public:

    void push(int x){

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){

        if(s1.empty()){
            cout<<"Queue underflow\n";
            return;
        }

        s1.pop();
    }

    int top(){

        if(s1.empty()){
            cout<<"Queue underflow\n";
            return -1;
        }

        return s1.top();
    }

    int size(){
        return s1.size();
    }
};



//Queue using stack (method 2)
class QSt2{

private:
    stack<int> s1,s2;

public:

    void push(int x){
        s1.push(x);
    }

    void pop(){

        if(s1.empty() && s2.empty()){
            cout<<"Queue underflow\n";
            return;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int top(){

        if(s1.empty() && s2.empty()){
            cout<<"Queue underflow\n";
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

int main(){

    StImpl s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;

    QImpl q;
    q.push(5);
    q.push(6);
    cout << q.top() << endl;

    return 0;
}

#include<iostream>
using namespace std;
class QImpl{
   private:
   int mover =9;
   int top1 = -1;
   int q[10];

   public:
   void push(int x){
    if(mover<0) {
        cout << "Queue Overflow\n"; 
        return;
    }
    if(top1==-1){
        top1=mover;
    }
    q[mover] = x;
    --mover;
   }

   int top(){
    if(top1== -1)  {
        cout << "Q Empty\n";
        return -1;
    }
    return q[top1];;
   }
 
   int size(){
    return 9-mover;
   }

   void pop(){
    if(top1 == -1)   
    {
      cout << "Q Empty\n"; 
     return;
    }
    top1 = top1-1;
     if (top1 < mover + 1) {   // queue empty now
        top1 = -1;
        mover = 9;
    }
   }
    bool empty() {
        return top1 == -1;
    }
};