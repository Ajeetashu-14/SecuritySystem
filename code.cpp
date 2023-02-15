#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>

using namespace std;

int main(){
    int ip;
    string text,oldpw,pw1,pw2,pass,name,pw0,uname,age,word,word1;
    string cred[2],cp[2];

    cout<<"     Security System"<<endl;
    cout<<"____________________________"<<endl<<endl;
    cout<<"|     1.Register            |"<<endl;
    cout<<"|     2.Login               |"<<endl;
    cout<<"|     3.Change Password     |"<<endl;
    cout<<"|_____4.End Program_________|"<<endl<<endl;

    do{
        cout<<endl;
        cout<<"Enter your choice :: ";
        cin>>ip;
        switch(ip){

            case 1:{
                   cout<<"________________________"<<endl<<endl;
                   cout<<"|<------Register------>|"<<endl;
                   cout<<"|______________________|"<<endl;
                   cout<<"Please enter username :: ";
                   cin>>name;
                   cout<<"Please enter password :: ";
                   cin>>pw0;
                   cout<<"Please enter your age :: ";
                   cin>>age;

                   //now storing these details in file
                   ofstream of1;  //of1 is an object of ofstream class which is used to open file to write something in it
                   of1.open("file.txt");
                   if(of1.is_open()){
                        of1<<name<<"\n";
                        of1<<pw0;
                        cout<<"  Registration Successfull!"<<endl;
                   }
                   of1.close();
                   break;}

            case 2:{
                   int i=0;
                   cout<<"_________________________"<<endl<<endl;
                   cout<<"|<--------Login-------->|"<<endl;
                   cout<<"|_______________________|"<<endl;
                   ifstream of2; //it is used to read from files
                   of2.open("file.txt");
                   cout<<"Please enter username :: ";
                   cin>>uname;
                   cout<<"Please enter password :: ";
                   cin>>pass;
                   if(of2.is_open()){
                        while(!of2.eof()){
                            while(getline(of2,text)){    //file will be read line by line
                                stringstream ss(text); //iss object is used to stream the string and store it using extraction operator   
                                ss>>word; //storing string
                                cred[i]=word;
                                i++;
                            }
                            if(uname==cred[0] && pass==cred[1]){
                                cout<<"  Login successfull!"<<endl<<endl;
                                cout<<"Details :: "<<endl;
                                cout<<"Username :: "+name<<endl;
                                cout<<"Password :: "+pass<<endl;
                                cout<<"Age :: "+age<<endl;
                            }
                            else{
                                cout<<"  Incorrect credentials!"<<endl;
                                cout<<"|         Press 2 to Login           |"<<endl;
                                cout<<"|     Press 3 to change password     |"<<endl;
                                break;
                            }
                        }
                   }
                   of2.close();
                   break;}

            case 3:{
                   int j=0;
                   cout<<"________________________________"<<endl<<endl;
                   cout<<"|<-------Change Password------->|"<<endl;
                   cout<<"|_______________________________|"<<endl;
                   ifstream of0;
                   of0.open("file.txt");
                   cout<<"Enter old password :: ";
                   cin>>oldpw;
                   if(of0.is_open()){
                        while(!of0.eof()){
                            while(getline(of0,text)){
                                stringstream ss(text);
                                ss>>word1;
                                cp[j]=word1;
                                j++;
                            }
                            
                            if(oldpw==cp[1]){
                                of0.close(); //close previous file to free up memory space
                                ofstream of1;
                                of1.open("file.txt");
                                if(of1.is_open()){
                                    cout<<"Enter your new password :: ";
                                    cin>>pw1;
                                    cout<<"Enter your password again :: ";
                                    cin>>pw2;
                                    if(pw1==pw2){
                                        of1<<cp[0]<<"\n";
                                        of1<<pw1;
                                        cout<<"  Password changed successfully!";
                                    }
                                    else{
                                        of1<<cp[0]<<"\n";
                                        of1<<oldpw;
                                        cout<<"  Password not matched!"<<endl;
                                    }
                                }
                            }
                            else{
                                cout<<"Please enter valid password";
                                break;
                            }
                        }
                   }
                   break;}
            case 4:{cout<<"|<--------Thank you!-------->|";    
                   break;}
            default:cout<<"Invalid choice!!..Enter a valid choice";    
        }
    }while(ip!=4);
}
