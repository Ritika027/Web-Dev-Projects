#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;
int main(){
    int a, i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];
    cout<<"    Security System "<<endl;
    
    cout<<"_____________________________"<<endl<<endl;
    cout<<"|          1.Register        |"<<endl;
    cout<<"|          2.login           |"<<endl;
    cout<<"|          3.Change password |"<<endl;
    cout<<"|_________ 4.End Program_____|"<<endl<<endl;
    
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch(a){
            case 1:{
                cout<<"_________________________________"<<endl<<endl;
                cout<<"|-----------Register-------------"<<endl;
                cout<<"|________________________________"<<endl;
                cout<<"Please enter username:- ";
                cin>>name;
                cout<<"Please enter the password:- "<<"\n";
                cin>>password0;
                cout<<"Please enter your age:- "<<"\n";
                cin>>age;
                
                ofstream of1;
                of1.open("File.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successfull"<<endl;
                    
                    
                }
                
            break;  
            }
            case 2:{
                i=0;
                cout<<"_________________________________|"<<endl<<endl;
                cout<<"|-----------login----------------|"<<endl<<endl;
                cout<<"|________________________________|"<<endl<<endl;
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:-  ";
                cin>>user;
                cout<<"Please enter the password:- ";
                cin>>pass;
                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                             iss>>word;
                             creds[i]=word;
                             i++;
                        }
                        
                        if(user==creds[0] && pass==creds[1] ){
                            cout<<"---log in successfull----";
                            cout<<endl<<endl;
                            
                            cout<<" Details: "<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"password: "+ pass<<endl;
                            cout<<"Age: "+age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|    1.Press 2 to login              |"<<endl;
                            cout<<"|    1.Press 3 to Change password    |"<<endl;
                            break;
                            
                            
                        }
                        
                    }
                }
            break;
            }
            case 3:{
                i=0;
                cout<<"-----------Change password----------------"<<endl;
                 ifstream of0;
                 of0.open("file.txt");
                 cout<<"enter the old password"<<endl;
                 cin>>old;
                 if(of0.is_open())
                 {
                     while(of0.eof()){
                         while(getline(of0,text)){
                             istringstream iss(text);
                             iss>>word1;
                             cp[i]=word1;
                             i++;
                         }
                         if(old==cp[1]){
                            of0.close();
                            
                            ofstream of1;
                            if(of1.is_open()){
                                cout<<"enter your new password:- "<<"\n";
                                cin>>password1;
                                cout<<"Enter your password again:- "<<"\n";
                                cin>>password2;
                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password change successfull"<<"\n";
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match"<<"\n";
                                }
                            }
                         }
                         else{
                             cout<<"Please enter the valid Password"<<endl;
                             break;
                         }
                     }
                 }
                 break;
                
            }
            case 4:{
                cout<<"_____________Thank you______________";
                break;
            }
            default:
                cout<<"Enter a valid choice";
            
        }
    }
    while(a!=4);
    return 0;
    
    
}