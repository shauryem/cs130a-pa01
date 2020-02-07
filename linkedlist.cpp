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
    ~linkedlist() {};
    void addNode(int c, int e);
    friend void readPoly(string in);
    friend void writePoly(linkedlist writtenLL);


    
};

void linkedlist::addNode(int c, int e){

    Node* temp = new Node;
    temp->coeff = c;
    temp->exp = e; 
    temp->next == NULL;

    if(this->head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
    }



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
         

        

    

}


int main(){

    readPoly("1 2 3 4 6 7 * 7 8 9 8 0 6");
}


