#include <string>
#include <iostream>
#include <sstream>

using namespace std;



class array{



public:

    int poly [10000] = {};

    array(){}

    friend void readPoly(string in);
    friend void writePoly(array writtenArray);

    void addPoly( array a2);

    void mulPoly( array a2);

    void squPoly();

};

    void readPoly(string in){

        array a1;
        array a2;
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
                //cout<<tempStore[1];
                //cout<<"\n";
                //cout<<tempStore[0];
                cout<<"\n";
                a1.poly[tempStore[1]] = tempStore[0];
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
                a2.poly[tempStore[1]] = tempStore[0];  
                s1noSpace = "";  
            }

        }

       
        //writePoly(a1);
        //cout<<"\n";
        //writePoly(a2);

        if(in.find("**") != string::npos){
            a1.mulPoly(a1);
        }   

        else if(in.find('*') != string::npos){
            a1.mulPoly(a2);
        }

        else if(in.find('+') != string::npos){
            a1.addPoly(a2);
        }


    }


    void writePoly(array writtenArray){
        string temp = "";
        for(int i =0; i < 10000; i++){
            if(writtenArray.poly[i] != 0){
                temp+= to_string(writtenArray.poly[i]);
                temp+= " ";
                temp+= to_string(i);
                temp+= " ";
            }
        }
        temp = temp.substr(0,temp.length() - 1);
        cout<<temp;

    }

    void array::addPoly( array a2){
       array result;
       
       for(int i = 0; i < 10000; i++){
           result.poly[i] = (this->poly[i] + a2.poly[i]) % 1000000;
       }

       writePoly(result);

    }

    void array::mulPoly( array a2){
        
        array finalArr; 
        for(int i = 0; i < 10000; i++){
            if(this->poly[i] == 0)
                continue;
            for(int j = 0; j < 10000; j++){
                if(a2.poly[j] == 0)
                    continue;
                finalArr.poly[(i+j) % 10000] += (this->poly[i] * a2.poly[j]) % 1000000;
                finalArr.poly[(i+j) % 10000] = finalArr.poly[(i+j) % 10000] % 1000000;

            }
        }
        writePoly(finalArr);
    }

  /*  void array::squPoly(){
        array squareTemp;

        for(int i =0; i < 10000; i++){
            this->poly[i] = squareTemp.poly[i];
        }
        mulPoly(squareTemp);

    }
    */

    int main(int argv, char** argc){

        if( argv != 2)  {
            return 1;
        }

        readPoly(argc[1]);
        
        return 0;
    }