#include<bits/stdc++.h>	
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<unistd.h>
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
              void update();
              void deletefun();
              void displaywhole();
              void displayfarmer();
              void displayretailer();
              void displayseller();
              void namesearch();
              void cropgsearch();
              void cropbsearch();
              void seedbsearch();
              void seedssearch();
              void exit();
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
    cout<<"\n\n\n\t\t-------------------REGISTRATION----------------------";
    cout<<"\n\n\n\n\t\t\tSet Your Username : ";
    cin>>username;
    fflush(stdin);
    cout<<"\n\n\t\t\tSet Your Password : ";
    cin>>password;
    /*char ch;
    ch = _getch();
        while (ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }*/
    

        ofstream myfile("frs.txt", ios :: app | ios :: out);
        myfile<<username<<"\t"<<password<<"\t";
        myfile.close();
        password='\0';
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
    
    cout<<"\n\n\tEnter the name of seeds/chemicals/pasticides that you want\n\t to buy(for farmers) : "; 
    cin>>seedb;
    
    cout<<"\n\n\tEnter the name of seeds/chemicals/pasticides that you want\n\t to sell(for sellers) : "; 
    cin>>seeds;
    
    cout<<"\n\n\tEnter the quantity to buy/sell : ";
    cin>>quantity;
    
    cout<<"\n\n\tEnter the minimum price of crop/vegetable/seed in Rs. : ";
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
         cout<<"\n\n\n\n\t\t\tYou have logged in successfully!";
            
    
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
    cout<<"\n\n\t\t\t[3] Search Data";
    cout<<"\n\n\t\t\t[4] Update Data";
    cout<<"\n\n\t\t\t[5] Delete Data";
    cout<<"\n\n\t\t\t[6] New Registration";
    cout<<"\n\n\t\t\t[7] Login";
    cout<<"\n\n\t\t\t[8] Exit";
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
            case 3 : search();
                      break;
            case 4 : update();
                      break;
            case 5 : deletefun();
                      break;
            case 6 : firstregister();
                      break;
            case 7 : login();
                      break;
            case 8 : exit();
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
              }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
        
       file1.close();
   }




void General :: display()
{
  system("cls");
  int a;
  cout<<"\n\n\n\t\t------------------ DISPLAY ---------------------";
  cout<<"\n\n\n\t\tSelect the choice to display data accordingly";
  cout<<"\n\n\t\t[1] Display whole data";
  cout<<"\n\n\t\t[2] Display farmer's data";
  cout<<"\n\n\t\t[3] Display retailer's data";
  cout<<"\n\n\t\t[4] Display seller's data";
  cout<<"\n\n\t\t[5] Go to home page";
  ciao :
  cout<<"\n\n\t\tYour Choice : ";
  cin>>a;
  
  switch(a)
  {
  	case 1 : displaywhole();
  	         break;
            
            
    case 2 : displayfarmer();    
              break; 
            
    case 3 :  displayretailer();  
				break;       
            
    case 4 : displayseller();  
	    	  break;    
				  
	case 5 : multiplechoice();  
	    	  break; 
	    	  
	default :  goto ciao;
	           break;  			  			    
  }
}
  
  void General :: displaywhole()
  {
  	  system("cls");
  	        cout<<"\n\n\n\t\t----------------- WHOLE DATA --------------------";
  	        int z=1;
  	        fstream file3;
            file3.open("frs.txt",ios::in);
            file3>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            while(!file3.eof())
            {
                   cout<<"\n\n\n\n\t\t----------------- Data "<<z<<" --------------------"; 
          
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
               
                  file3>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
                  z++;
            }
            file3.close();
            abel :
                  int b;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>b;
    
                  switch(b)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto abel;
                                 break;
                  }
  }
  
  void General :: displayfarmer()
  {
  	        system("cls");
  	        cout<<"\n\n\n\t\t----------------- FARMER'S DATA ---------------------";
  	        int y=1;
  	        fstream file2;
            file2.open("frs.txt",ios::in);
            file2>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            while(!file2.eof())
            {
            	if(role=="farmer")
            	{
                   cout<<"\n\n\n\n\t\t----------------- Data "<<y<<" --------------------"; 
          
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
                   y++;
                }
                file2>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            }
            file2.close();
            wabel :
                  int c;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>c;
    
                  switch(c)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto wabel;
                                 break;
                  }
  }
  
  
  void General :: displayretailer()
  {
        system("cls");
  	        cout<<"\n\n\n\t\t----------------- RETAILER'S DATA ---------------------";
  	        int z=1;
  	        fstream file1;
            file1.open("frs.txt",ios::in);
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            while(!file1.eof())
            {
            	if(role=="retailer")
            	{
                   cout<<"\n\n\n\n\t\t----------------- Data "<<z<<" --------------------"; 
          
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
                   z++;
                }
                file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            }
            file1.close();
            label :
                  int b;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>b;
    
                  switch(b)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto label;
                                 break;
                  }	
  } 
  
  
  void General :: displayseller()
  {
  	   system("cls");
  	        cout<<"\n\n\n\t\t------------------ SELLER'S DATA ---------------------";
  	        int z=1;
  	        fstream file1;
            file1.open("frs.txt",ios::in);
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            while(!file1.eof())
            {
            	if(role=="seller")
            	{
                   cout<<"\n\n\n\n\t\t----------------- Data "<<z<<" --------------------"; 
          
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
                   z++;
                }
                file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
            }
            file1.close();
            label :
                  int b;
                  cout<<"\n\n\n\n\t\t\tEnter 1 to go to the home page : ";
                  cin>>b;
    
                  switch(b)
                  {
                       case 1 : multiplechoice();
                                break;
                       default :  goto label;
                                 break;
                  }
  	
  }
  

void General :: search()
{
  system("cls");
  int a;
  cout<<"\n\n\n\t\t-------------- SEARCH AT AN INSTANCE ---------------";
  cout<<"\n\n\n\t\tSelect the choice to search data accordingly";
  cout<<"\n\n\t\t[1] Search by role";
  cout<<"\n\n\t\t[2] Search by name";
  cout<<"\n\n\t\t[3] Search by farmer growing crop";
  cout<<"\n\n\t\t[4] Search by retailer buying crop";
  cout<<"\n\n\t\t[5] Search by farmer needing seed/pasticide";
  cout<<"\n\n\t\t[6] Search by seller selling seed/pasticide";
  cout<<"\n\n\t\t[7] Go to home page";
  ciao :
  cout<<"\n\n\t\tYour Choice : ";
  cin>>a;
  
  switch(a)
  {
  	case 1 : display();
  	         break;
            
            
    case 2 : namesearch();    
              break; 
            
    case 3 :  cropgsearch();  
				break;       
            
    case 4 : cropbsearch();  
	    	  break;  
			  
	case 5 : seedbsearch();  
	    	  break;
			  
	case 6 : seedssearch();  
	    	  break;  
				  
	case 7 : multiplechoice();  
	    	  break;
	    	  
	default :  goto ciao;
	           break;  			  			    
  }
    
}

void General :: namesearch()
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
        string myname;
        cout<<"\n\n\n\t\t----------------- SEARCH BY NAME ----------------------";
        cout<<"\n\n\n\n\t\t\tEnter name to search data : ";
        cin>>myname;
        int z=1;
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
             if(myname == name)
             {
                  found=1;
                  if(found==1)
                  {
                    cout<<"\n\n\n\t\t---------------------- DATA "<<z<<" -------------------------"; 
          
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
                   z++;
                  
              }
          
              }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
         if(found==0)
          {
            cabel :
            int d;
            cout<<"\n\n\n\t\tName is not matched";
            cout<<"\n\n\n\t\tEnter 1 to go to search page";
            cout<<"\n\n\n\t\tEnter 2 to fill data again";
            cout<<"\n\n\n\t\t\tYour Choice : ";
            cin>>d;
    
           switch(d)
           {
             case 1 : search();
                      break;
             case 2 : namesearch();
                      break;
             default : goto cabel;
                       break;
           }
            
          }
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
		
}


void General :: cropgsearch()
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
        string mycrop;
        cout<<"\n\n\n\t\t----------------- SEARCH BY CROP ----------------------";
        cout<<"\n\n\n\n\t\tEnter crop name that farmer want to sell : ";
        cin>>mycrop;
        int z=1;
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
             if(mycrop == cropg)
             {
                  found=1;
                  if(found==1)
                  {
                    cout<<"\n\n\n\t\t---------------- DATA "<<z<<" Crop("<<mycrop<<")-------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
//                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
//                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
                   z++;
                  
              }
          
              }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
         if(found==0)
          {
            cabel :
            int d;
            cout<<"\n\n\n\t\tName is not matched";
            cout<<"\n\n\n\t\tEnter 1 to go to search page";
            cout<<"\n\n\n\t\tEnter 2 to fill data again";
            cout<<"\n\n\n\t\t\tYour Choice : ";
            cin>>d;
    
           switch(d)
           {
             case 1 : search();
                      break;
             case 2 : cropgsearch();
                      break;
             default : goto cabel;
                       break;
           }
            
          }
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
}

void General :: cropbsearch()
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
        string mycrop;
        cout<<"\n\n\n\t\t----------------- SEARCH BY CROP ----------------------";
        cout<<"\n\n\n\n\t\tEnter crop name that retailer wants to buy  : ";
        cin>>mycrop;
        int z=1;
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
            if(mycrop == cropb)
            {
                  found=1;
                  if(found==1)
                  {
                    cout<<"\n\n\n\t\t---------------- DATA "<<z<<" Crop("<<mycrop<<")-------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
//                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
//                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
//                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
                   z++;
                }
               
            }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
        if(found==0)
            {
                cabel :
                int d;
                cout<<"\n\n\n\t\tName is not matched";
                cout<<"\n\n\n\t\tEnter 1 to go to search page";
                cout<<"\n\n\n\t\tEnter 2 to fill data again";
                cout<<"\n\n\n\t\t\tYour Choice : ";
                cin>>d;
    
               switch(d)
               {
                case 1 : search();
                         break;
                case 2 : cropbsearch();
                         break;
                default : goto cabel;
                          break;
               }
            
            }
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
}

void General :: seedbsearch()
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
        string mycrop;
        cout<<"\n\n\n\t\t----------------- SEARCH BY SEED ----------------------";
        cout<<"\n\n\n\n\t\tEnter seed name that farmer wants to buy  : ";
        cin>>mycrop;
        int z=1;
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
            if(mycrop == seedb)
            {
                  found=1;
                  if(found==1)
                  {
                    cout<<"\n\n\n\t\t---------------- DATA "<<z<<" Seed("<<mycrop<<")-------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
//                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
//                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
                   z++;
                }
               
            }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
        if(found==0)
            {
                cabel :
                int d;
                cout<<"\n\n\n\t\tName is not matched";
                cout<<"\n\n\n\t\tEnter 1 to go to search page";
                cout<<"\n\n\n\t\tEnter 2 to fill data again";
                cout<<"\n\n\n\t\t\tYour Choice : ";
                cin>>d;
    
               switch(d)
               {
                case 1 : search();
                         break;
                case 2 : seedbsearch();
                         break;
                default : goto cabel;
                          break;
               }
            
            }
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
}

 void General :: seedssearch()
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
        string mycrop;
        cout<<"\n\n\n\t\t----------------- SEARCH BY SEED ----------------------";
        cout<<"\n\n\n\n\t\tEnter seed/pasticide name that seller wants to sell  : ";
        cin>>mycrop;
        int z=1;
       file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
       while(!file1.eof())
       {
            if(mycrop == seeds)
            {
                  found=1;
                  if(found==1)
                  {
                    cout<<"\n\n\n\t\t---------------- DATA "<<z<<" Seed("<<mycrop<<")-------------------"; 
          
                   cout<<"\n\n\n\n\t\t\tRole : "<<role;
                   cout<<"\n\n\t\t\tName : "<<name;   
                   cout<<"\n\n\t\t\tAddress : "<<address;
                   cout<<"\n\n\t\t\tContact : "<<contact;
                   cout<<"\n\n\t\t\tEmail : "<<email;
//                   cout<<"\n\n\t\t\tCrops that you grow : "<<cropg;
//                   cout<<"\n\n\t\t\tCrops that you buy : "<<cropb;
//                   cout<<"\n\n\t\t\tSeed that you buy : "<<seedb;
                   cout<<"\n\n\t\t\tSeed that you sell : "<<seeds;
                   cout<<"\n\n\t\t\tQuantity : "<<quantity;
                   cout<<"\n\n\t\t\tMin_price : "<<min_price;
                   z++;
                }
               
            }
               
            file1>>username>>password>>role>>name>>address>>contact>>email>>cropg>>cropb>>seedb>>seeds>>quantity>>min_price;
       
        }
        
        if(found==0)
            {
                cabel :
                int d;
                cout<<"\n\n\n\t\tName is not matched";
                cout<<"\n\n\n\t\tEnter 1 to go to search page";
                cout<<"\n\n\n\t\tEnter 2 to fill data again";
                cout<<"\n\n\n\t\t\tYour Choice : ";
                cin>>d;
    
               switch(d)
               {
                case 1 : search();
                         break;
                case 2 : seedssearch();
                         break;
                default : goto cabel;
                          break;
               }
            
            }
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


void General :: exit()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t    THANK YOU FOR VISITING\n\n\n\n\n\n";
	getch();
}


