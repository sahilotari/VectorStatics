#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class General{
      private :
              string username,password,role,name,address,contact,email,cropg,cropb,quantity,min_price,seedb,seeds;
      public :
              
              void choice();
              void firstregister();
              void registration();
              void login();
              void display();
              void search();
              void sort();
              void update();
              void deletefun();
};

int main()
{
    General *ptr = new General();
    ptr->choice();
    return 0;
}

void General :: choice()
{
     system("cls");
     cout<<"\n\n\n\t\t-------------------WELCOME----------------------"; 
     
     cabel :
        int b;
        cout<<"\n\n\n\n\n\t\tEnter 1 to go for registration";
        cout<<"\n\n\n\t\tEnter 2 to go for login";
        cout<<"\n\n\n\t\t\tYour Choice : ";
        cin>>b;
    
        switch(b)
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
    
    ifstream file1("register.txt");
    int exit;
    while(file1>>u>>p)
    {
       if(u==username && p==password)
       {
            exit=1;
       }
    }
    if(exit==1)
    {
        cout<<"\n\n\t\t\tYou have already registered!";
        cabel :
        int b;
        cout<<"\n\n\t\t\tEnter 1 to go to login page";
        cout<<"\n\n\t\t\tEnter 2 to register with another data";
        cout<<"\n\n\n\t\t\tYour Choice : ";
        cin>>b;
    
        switch(b)
        {
             case 1 : login();
                      break;
             case 2 : firstregister();
                      break;
             default : cout<<"\n\n\t\tEnter correct choice";
                       goto cabel;
                       break;
        }
    }
    else
    {
        ofstream myfile("register.txt", ios :: app);
        myfile<<username<<"\t"<<password<<endl;
        myfile.close();
        cout<<"\n\n\n\t\t\tYou have registered Successfully!";
    
   
    
       label :
       int a;
       cout<<"\n\n\n\t\t\tEnter 1 to go for further registration : ";
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
}

void General :: registration()
{
    system("cls");
    cout<<"\n\n\n\t\t>>>>>>>>>>> WELCOME TO PRIVATE REGISTRATION <<<<<<<<<<<";
    
    cout<<"\n\n\n\n\n\t       Fill the information correctly as per your knowledge. While\n\tfilling if choice comes for which you are not eligible, then write\n\t'nil' in front of the choice. Thank you.";
    
    cout<<"\n\n\n\n\t\tEnter your role(farmer/retailer/seller) : ";
    cin>>role;
    
    cout<<"\n\n\t\tEnter your name : ";
    cin>>name;
    
    cout<<"\n\n\t\tEnter your address : ";
    cin>>address;
    
    cout<<"\n\n\t\tEnter your contact number : ";
    cin>>contact;
    
    cout<<"\n\n\t\tEnter your email address : ";
    cin>>email;
    
    cout<<"\n\n\tEnter the names of crops/vegetables that you grow(for farmers) : ";
    cin>>cropg;
    
    cout<<"\n\n\tEnter the names of crops/vegetables that you want to buy(for reatailers) : "; 
    cin>>cropb;
    
    cout<<"\n\n\tEnter the name of seeds that you want to buy(for farmers) : "; 
    cin>>seedb;
    
    cout<<"\n\n\tEnter the name of seeds that you want to sell(for sellers) : "; 
    cin>>seeds;
    
    cout<<"\n\n\t\tEnter the quantity to buy/sell : ";
    cin>>quantity;
    
    cout<<"\n\n\t\tEnter the minimum price of crop/vegetable : ";
    cin>>min_price;
    
    cout<<"\n\n\n\t\t\tThank you for information!\n\n\t\t\tYour data saved successfully.";
    
    ofstream file2("register.txt",ios::app);
    file2<<role<<"\t"<<name<<"\t"<<address<<"\t"<<contact<<"\t"<<email<<"\t"<<cropg<<"\t"<<cropb<<"\t"<<seedb<<"\t"<<seeds<<"\t"<<quantity<<"\t"<<min_price<<endl;
    file2.close();
    
     label :
       int a;
       cout<<"\n\n\t\t\tEnter 1 to go to your private page : ";
       cin>>a;
    
       switch(a)
       {
             case 1 : display();
                      break;
             default : cout<<"\n\n\t\tEnter correct choice";
                       goto label;
                       break;
       }
}

void General :: login()
{
    system("cls");
    string user,pass,u,p;
    int exit;
    cout<<"\n\n\n\t\t----------------------LOGIN-------------------------";
    cout<<"\n\n\n\n\t\t\tEnter Your Username : ";
    cin>>user;
    cout<<"\n\n\t\t\tEnter Your Password : ";
    cin>>pass;
    
    ifstream file1("register.txt");
    
    while(file1>>u>>p)
    {
       if(u==user && p==pass)
       {
            exit=1;
       }
    }      
    if(exit==1)
    {
         cout<<"\n\n\t\t\tYou have logged in successfully!";
            
    
         label :
         int a;
         cout<<"\n\n\t\t\tEnter 1 to go to your private page : ";
         cin>>a;
    
         switch(a)
         {
             case 1 : display();
                      break;
             default :  goto label;
                        break;
         }
    } 
    else
    {
        cout<<"\n\n\n\t\t\t   Not registered enter 1";
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
    }  
}

void General :: display()
{
    system("cls");
    string user,pass,u,p;
    int exit;
    cout<<"\n\n\n\t\t----------------------WELCOME-------------------------";
    cout<<"\n\n\n\n\t\t\tEnter Your Username Again : ";
    cin>>user;
    cout<<"\n\n\t\t\tEnter Your Password Again : ";
    cin>>pass;
    
    ifstream file1("register.txt");
    
    while(file1>>u>>p)
    {
       if(u==user && p==pass)
       {
            exit=1;
       }
    } 
    role,name,address,contact,email,cropg,cropb,quantity,min_price,seedb,seeds;
    if(exit==1)
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
          getch();
    
    }
    else
    {
        cout<<"\n\n\n\t\t\trdjzgbjhgjhz";
        getch();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
         
}

void General :: search()
{
  cout<<"\n\n\n\t\t\tCode";
  getch();
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
