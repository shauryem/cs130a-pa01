#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class Node {

public:
    int coeff;
    int exp;
    Node* next;
    Node(){
        coeff =0;
        exp =0;
        next = NULL;
    }
    ~Node(){
        next = NULL;
    }
};

class linkedlist{
public:
    Node* head;
    Node* tail;

    int arr [10000];

    linkedlist() { 
        head = NULL;
        tail = NULL;
    }
    ~linkedlist();
    void addNode(int c, int e);
    friend void readPoly(string in);
    friend void writePoly(linkedlist& writtenLL);
    void mulPoly(linkedlist& l2);
    void addPoly(linkedlist& l2);


    
};

linkedlist::~linkedlist(){

    Node* p1 = this->head;
    Node* tmp;
    while(p1) {
        tmp = p1;
        p1 = p1->next;
        delete tmp;
    }
    head = NULL;
    tail = NULL;
}
void linkedlist::mulPoly(linkedlist& l2){

    linkedlist newList;
    Node * p1 = new Node;
    Node * p2 = new Node;
    p1 = this->head;
    p2 = l2.head;

    while(p1 != NULL){
        p2 = l2.head;
        while(p2 != NULL){
           newList.addNode((p1->coeff * p2->coeff) % 1000000, (p1->exp + p2->exp) % 10000);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    writePoly(newList);
    

}
void linkedlist::addPoly(linkedlist& l2){
    
    
    
    linkedlist newList;
    Node * p1 = new Node;
    Node * p2 = new Node;
    p1 = this->head;
    p2 = l2.head;


    while(p1 != NULL && p2 != NULL){
        if(p1->exp > p2->exp){
            newList.addNode(p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else if(p1->exp < p2->exp){
            newList.addNode(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else{
            newList.addNode((p1->coeff + p2->coeff) % 1000000, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        newList.addNode(p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while(p2 != NULL){
        newList.addNode(p2->coeff, p2->exp);
        p2 = p2->next;
    }


    writePoly(newList);
}

void linkedlist::addNode(int c, int e){

    Node* temp = new Node;
    temp->coeff = c % 1000000;
    temp->exp = e; 
    temp->next == NULL;

    if(this->head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    // add at start
    else if(temp->exp < head->exp){
        temp->next = head;
        head = temp;
    }
    // add at end
    else if(temp->exp > tail->exp){
        tail->next = temp;
        tail = temp;
    }
    else{
        Node* p = new Node;
        p = head;
        while(p->next != NULL && temp->exp > p->exp){
            p = p->next;
        }
        if(temp->exp = p->exp){
            p->coeff = (p->coeff + temp->coeff) % 1000000;
            delete temp;
        }
        else{
            temp->next = p->next;
            p->next = temp;
        }
    }
    


}

void writePoly(linkedlist& writtenLL){
    Node *p = new Node;
    p = writtenLL.head;
    string temp = "";
    while(p != NULL){
        temp += to_string(p->coeff);
        temp += " ";
        temp += to_string(p->exp);
        temp += " "; 
        p = p->next;
    }
    temp = temp.substr(0, temp.length()-1);
    
    cout<<temp;
}

void readPoly(string in){

    linkedlist l1;
    linkedlist l2;

        string s1 = "";
        string s2 = "";
        string s1noSpace = "";
        int tempStore [2] = {0,0};
        int lever = 1;
        

        
        if(in.find("**") != string::npos){
            s1 = in.substr(0, in.find("**") );
        }   

        else if(in.find('*') != string::npos){
            in += " ";
            s1 = in.substr(0, in.find('*') );
            s2 = in.substr(in.find('*') + 2);
        }

        else if(in.find('+') != string::npos){
            in += " ";
            s1 = in.substr(0, in.find('+')  );
            s2 = in.substr(in.find('+') + 2);
        }
        else{
            in += " ";
            s1 = in;
        }
       

        
        for(int i=0; i < s1.length(); i++){
            if(s1[i] != ' '){
                s1noSpace += s1[i];
                continue;
                
            }
            if (lever % 2 == 1){
                //cout<<s1noSpace;
                //cout<<"\n";
                tempStore[0] = stoi(s1noSpace);
                lever++;
                s1noSpace = "";
            }
            else{

                tempStore[1] = stoi(s1noSpace);
                lever++;
               /* cout<<tempStore[1];
                cout<<"\n";
                cout<<tempStore[0];
                cout<<"\n";
              */   
                l1.addNode(tempStore[0], tempStore[1]);
                s1noSpace = "";    
            }

        }

        lever = 1;
        s1noSpace = "";

        for(int i=0; i < s2.length(); i++){
            if(s2[i] != ' '){
                s1noSpace += s2[i];
                continue;
                
            }
            if (lever % 2 == 1){
                //cout<<s1noSpace;
                //cout<<"\n";
                tempStore[0] = stoi(s1noSpace);
                lever++;
                s1noSpace = "";
            }
            else{
                //cout<<s1noSpace;
                //cout<<"\n";
                tempStore[1] = stoi(s1noSpace);
                lever++;
                l2.addNode(tempStore[0], tempStore[1]);  
                s1noSpace = "";  
            }
        }
         

        if(in.find("**") != string::npos){
            linkedlist squ;
            Node * temp = new Node;
            temp = l1.head;

            while(temp != NULL){
                squ.addNode(temp->coeff, temp->exp);
                temp = temp->next;
            }

            l1.mulPoly(squ);
        }   

        else if(in.find('*') != string::npos){
            l1.mulPoly(l2);
        }

        else if(in.find('+') != string::npos){
            l1.addPoly(l2);
        }
   /* Node *p = new Node;
    p = l2.head;
    while(p != NULL){
        cout<<p->exp;
        cout<<"\n";
        cout<<p->coeff;
        cout<<"\n";

        p = p->next;
  */  
        

    

}


int main(int argv, char** argc){

        if( argv != 2)  {
            return 1;
        }

        readPoly(argc[1]);
        
        return 0;
}


