#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <windows.h>
#include <unistd.h>
#include<stdlib.h>

using namespace std;

class General{
      private :
              string username,password,role,name,address,contact,email,cropg,cropb,quantity,min_price,seedb,seeds;
               
      public :
              
              void choice();
              void multiplechoice();
              void firstregister();
              void registration();
              void login();
              void personaldata();
              void display();
              void search();
              void sort();
              void update();
              void deletefun();
};


int main()
{
    General obj;
    obj.choice();
    return 0;
}


void General :: choice()
{
     system("cls");
     cout<<"\n\n\n\n\t\t-------------------WELCOME----------------------\n\n"; 
     
     cabel :
        int d;
        cout<<"\n\n\n\t\tEnter 1 to go for registration";
        cout<<"\n\n\n\t\tEnter 2 to go for login";
        cout<<"\n\n\n\t\t\tYour Choice : ";
        cin>>d;
    
        switch(d)
        {
             case 1 : firstregister();
                      break;
             case 2 : login();
                      break;
             default : goto cabel;
                       break;
        }
}


void General :: firstregister()
{
    system("cls");
    string u,p;
    cout<<"\n\n\n\t\t-------------------REGISTRATION----------------------";
    cout<<"\n\n\n\n\t\t\tSet Your Username : ";
    cin>>username;
    cout<<"\n\n\t\t\tSet Your Password : ";
    cin>>password;
    

        ofstream myfile("frs.txt", ios :: app | ios :: out);
        myfile<<username<<"\t"<<password<<"\t";
        myfile.close();
        cout<<"\n\n\n\n\t\t\tYou have registered Successfully!";
    
   
    
       label :
       int a;
       cout<<"\n\n\n\n\t\t\tEnter 1 to go for further registration : ";
       cin>>a;
    
       switch(a)
       {
             case 1 : registration();
                      break;
             default : cout<<"\n\n\t\tEnter correct choice";
                       goto label;
                       break;
       }
   
}


void General :: registration()
{
    system("cls");
    cout<<"\n\n\n\t\t>>>>>>>>>>> WELCOME TO PRIVATE REGISTRATION <<<<<<<<<<<";
    
    cout<<"\n\n\n\n\n\t       Fill the information correctly as per your knowledge. While\n\tfilling if choice comes for which you are not eligible, then write\n\t'nil' in front of the choice. Thank you.";
    
    cout<<"\n\n\n\n\tEnter your role(farmer/retailer/seller) : ";
    cin>>role;
    
    cout<<"\n\n\tEnter your name : ";
    cin>>name;
    
    cout<<"\n\n\tEnter your address : ";
    cin>>address;
    
    cout<<"\n\n\tEnter your contact number : ";
    cin>>contact;
    
    cout<<"\n\n\tEnter your email address : ";
    cin>>email;
    
    cout<<"\n\n\tEnter the names of crops/vegetables that you grow\n\t(for farmers) : ";
    cin>>cropg;
    
    cout<<"\n\n\tEnter the names of crops/vegetables that you want to buy\n\t(for reatailers) : "; 
    cin>>cropb;
    
    cout<<"\n\n\tEnter the name of seeds that you want to buy\n\t(for farmers) : "; 
    cin>>seedb;
    
    cout<<"\n\n\tEnter the name of seeds that you want to sell\n\t(for sellers) : "; 
    cin>>seeds;
    
    cout<<"\n\n\tEnter the quantity to buy/sell : ";
    cin>>quantity;
    
    cout<<"\n\n\tEnter the minimum price of crop/vegetable/seed : ";
    cin>>min_price;
    
    cout<<"\n\n\n\t\t\tThank you for information!\n\n\t\t\tYour data saved successfully.";
    
    ofstream file2("frs.txt",ios::app);
    file2<<role<<"\t"<<name<<"\t"<<address<<"\t"<<contact<<"\t"<<email<<"\t"<<cropg<<"\t"<<cropb<<"\t"<<seedb<<"\t"<<seeds<<"\t"<<quantity<<"\t"<<min_price<<endl;
    file2.close();
    
     label :
       int a;
       cout<<"\n\n\t\t\tEnter 1 to go to the home page : ";
       cin>>a;
    
       switch(a)
       {
             case 1 : multiplechoice();
                      break;
             default : cout<<"\n\n\t\tEnter correct choice";
                       goto label;
                       break;
       }
}


void General :: login()
{
    system("cls");
    string user,pass;
    int exit;
    cout<<"\n\n\n\t\t----------------------LOGIN-------------------------";
    cout<<"\n\n\n\n\t\t\tEnter Your Username : ";
    cin>>user;
    cout<<"\n\n\t\t\tEnter Your Password : ";

    char ch;
    ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
    
    ifstream file1;
    file1.open("frs.txt",ios::in);
    
    file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
    while(!file1.eof())
    {
       if(user == username && pass == password)
       {
            exit=1;
       }
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
    }      
    if(exit==1)
    {
         cout<<"\n\n\t\t\tYou have logged in successfully!";
            
    
         label :
         int a;
         cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
         cin>>a;
    
         switch(a)
         {
             case 1 : multiplechoice();
                      break;
             default :  goto label;
                        break;
         }
         file1.close();
    } 
    else
    {
        cout<<"\n\n\n\n\t\t\t   Not registered enter 1";
        cout<<"\n\n\t\t\t   To login again enter 2";
        repeat :
        int n,i;
        cout<<"\n\n\t\t\t\tYour Choice : ";
        cin>>n;
        switch(n)
        {
            case 1 : firstregister();
                     break;
            case 2 : login();
                      break;
            default : goto repeat;
                      break;
       }
       file1.close();
    }  
}

void General :: multiplechoice()
{  
     system("cls");
    cout<<"\n\n\n\n\t\t\tSelect the correct choice";
    cout<<"\n\n\n\n\t\t\t[1] Display Private Data";
    cout<<"\n\n\t\t\t[2] Display All Data";
    cout<<"\n\n\t\t\t[3] Sort Data";
    cout<<"\n\n\t\t\t[4] Search Data";
    cout<<"\n\n\t\t\t[5] Update Data";
    cout<<"\n\n\t\t\t[6] Delete Data";
    cout<<"\n\n\t\t\t[7] New Registration";
    cout<<"\n\n\t\t\t[8] Login";
    repeat :
        int n;
        cout<<"\n\n\n\n\t\t\tYour Choice : ";
        cin>>n;
        switch(n)
        {
            case 1 : personaldata();
                     break;
            case 2 : display();
                      break;
            case 3  : sort();
                      break;
            case 4 : search();
                      break;
            case 5 : update();
                      break;
            case 6 : deletefun();
                      break;
            case 7 : firstregister();
                      break;
            case 8 : login();
                      break;
            default : goto repeat;
                      break;
       }
}


void General :: personaldata()
{
    system("cls");
    int found=0;
    fstream file1;
    file1.open("frs.txt",ios::in);

    if(!file1)
    {
              cout<<"No data is present.........";
    }
    else
    {
        string pass,user;
        cout<<"\n\n\n\t\t----------------------WELCOME-------------------------";
        cout<<"\n\n\n\n\t\t\tEnter Your Username Again : ";
        cin>>user;
        cout<<"\n\n\t\t\tEnter Your Password Again : ";
        char ch;
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }

       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
             if(user == username && pass == password)
             {
                  found=1;
              }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        if(found==1)
        {
                    cout<<"\n\n\n\t\t----------------------INFORMATION-------------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
             
                  label :
                  int a;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>a;
    
                  switch(a)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto label;
                                  break;
                  }
        }
        else
        {
            cabel :
            int d;
            cout<<"\n\n\n\t\tUsername and password not matched";
            cout<<"\n\n\n\t\tEnter 1 to go for registration";
            cout<<"\n\n\n\t\tEnter 2 to fill data again";
            cout<<"\n\n\n\t\t\tYour Choice : ";
            cin>>d;
    
           switch(d)
          {
             case 1 : firstregister();
                      break;
             case 2 : personaldata();
                      break;
             default : goto cabel;
                       break;
          }
            
         }
        
       file1.close();
   }

}


void General :: display()
{
  cout<<"\n\n\n\t\t\tCode";
  getch();
}

void General :: search()
{
    system("cls");
    fstream file1;
    file1.open("frs.txt",ios::in);

    if(!file1)
    {
              cout<<"No data is present.........";
    }
    else
    {
        string farm;
        cout<<"\n\n\n\t\t----------------------WELCOME-------------------------";
        cout<<"\n\n\n\n\t\t\tEnter Your role : ";
        cin>>farm;

       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
             if(farm==role)
             {
                     cout<<"\n\n\n\t\t----------------------INFORMATION-------------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
             
                  label :
                  int a;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>a;
    
                  switch(a)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto label;
                                  break;
                  }
             
              }
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;

         }
       file1.close();
   }
}
     
void General :: sort()
{
  cout<<"\n\n\n\t\t\tCode";
  getch();
}


void General :: update()
{
  cout<<"\n\n\n\t\t\tCode";
  getch();
}

void General :: deletefun()
{
  cout<<"\n\n\n\t\t\tCode";
  getch();
}
















