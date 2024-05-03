#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

using std:: string, std:: cout, std:: cin;

class inventory{
    private:
     int *productNum = new int();
     int *productQuant = new int();
     string *productName = new string{};
     string *productExp = new string{};

    public:
     int listNum[5000];
     int listQuant[5000];
     string listName[5000];
     string listExp[5000];
     int size[4] = {sizeof(listNum)/sizeof(listNum[0]), sizeof(listName)/sizeof(listName[0]), sizeof(listQuant)/sizeof(listQuant[0]), sizeof(listExp)/sizeof(listExp[0])};
    
    public:
     void menuFunc();
     void addFunc(); 
     void editFunc();
     void deleteFunc();
     void checkInventory();
};

int main (){

    inventory system;
    system.menuFunc();

   
    return 0;
}

void inventory :: menuFunc(){

    int *choice = new int();

    cout << "----------------------------------------------------\n";
    cout << "|\t\tINVENTORY SYSTEM MENU" << "              |\n";
    cout << "----------------------------------------------------\n";
    cout << "|\t\t[1]Add Product" << "                     |\n";
    cout << "|\t\t[2]Edit Product" << "                    |\n";
    cout << "|\t\t[3]Delete Product" << "                  |\n";
    cout << "|\t\t[4]Check Inventory" << "                 |\n";
    cout << "|\t\t[5]Exit" << "                            |\n";
    cout << "-----------------------------------------------------\n";

    cout << "Enter Choice: ";
    cin >> *choice;

    std:: cin.clear();
    fflush(stdin);

    switch (*choice)
    {
    case 1:
        
         addFunc();

        break;

    case 2: 

         editFunc();

        break;

    case 3: 

         deleteFunc();

        break;

    case 4: 

         checkInventory();

        break;

    case 5:

         cout << "----------------------------------\n";    
         cout << "|\tProgram Terminated       |\n";
         cout << "----------------------------------\n";

          delete productNum;
          productNum = nullptr;
    
          delete productName;
          productName = nullptr;

          delete productQuant;
          productQuant = nullptr;

          delete productExp;
          productExp = nullptr;

        break;
    
    default:

         cout << "Invalid Choice!\n";

         menuFunc();
        
        break;
    }

    delete choice;
    choice = nullptr;
}

void inventory :: addFunc(){

    fstream records;

    records.open("records.txt", ios::out | ios::app);

    if (!records.is_open())
    {
         cout << "------------------------------------------\n";
         cout << "|\tError_001 Has Been Occured!      |\n";
         cout << "------------------------------------------\n";
   
    }

    else 
    {
         cout << "--------------------------\n";
         cout << "|\tADD PRODUCT      |\n";
         cout << "--------------------------\n";

         cout << "Enter Product Number: ";
         cin >> *productNum;

         cout << "Enter Product Name: ";
         cin >> *productName;
         
         cout << "Enter Product Quantity: ";
         cin >> *productQuant;

         cout << "Enter Product Expiration Data (Month/Day/Year): ";
         cin >> *productExp;

         records << *productNum << " " << *productName << " " << *productQuant << " " << *productExp << "\n";

         cout << "-------------------------------------------------\n";
         cout << "|\tProduct Details Has Been Recorded!      |\n";
         cout << "-------------------------------------------------\n";

    }

     records.close();

     menuFunc();
}

void inventory :: editFunc(){

    fstream records, records2;

    int *tempNum = new int();
    int *tempQuant = new int();
    int *tempVar = new int ();
    string *tempName = new string{};
    string *tempExp = new string{};
    

    records.open("records.txt", ios::in);
    records >> *productNum >> *productName >> *productQuant >> *productExp;

    if (!records.is_open())
    {
         cout << "------------------------------------------\n";
         cout << "|\tError_002 Has Been Occured!      |\n";
         cout << "------------------------------------------\n";
   
    }

    else
    {    
         records2.open("records2.txt", ios::out | ios::app);

         cout << "---------------------------\n";
         cout << "|\tEDIT PRODUCT      |\n";
         cout << "---------------------------\n";

         cout << "Enter Product Number: ";
         cin >> *tempVar;
  
         do
         {

             if (*tempVar == *productNum)
             {
                 cout << "Enter New Product Number: ";
                 cin >> *tempNum;

                 cout << "Enter New Product Name: ";
                 cin >> *tempName;
                 
                 cout << "Enter New Product Quantity: ";
                 cin >> *tempQuant;

                 cout << "Enter New Expiration Date(Month/Day/Year): ";
                 cin >> *tempExp;

                 records2 << *tempNum << " " << *tempName << " " <<  *tempQuant << " " << *tempExp << "\n";

                 cout << "---------------------------------------------\n";
                 cout << "|\tNew Details Has Been Recorded!      |\n";
                 cout << "---------------------------------------------\n";
             }
             

             else
             {
                 records2 << *productNum << " " << *productName << " " << *productQuant << " " << *productExp << "\n";
             }
             
             records >> *productNum >> *productName >> *productQuant >> *productExp;
         } 
         
         while (!records.eof());

         if (*tempVar != *productNum)
         {
             cout << "--------------------------------------\n";
             cout << "|\tInvalid Product Number!      |\n";
             cout << "--------------------------------------\n";
         }   
    }

     records.close();
     records2.close();

     remove("records.txt");
     rename("records2.txt", "records.txt");
     
     delete tempVar;
     tempVar = nullptr;

     delete tempNum;
     tempNum = nullptr;

     delete tempQuant;
     tempQuant = nullptr;

     delete tempName;
     tempName = nullptr;

     delete tempExp;
     tempExp = nullptr;

     menuFunc();
}

void inventory :: deleteFunc(){
    
    fstream records, records2;

    int *tempVar = new int();
    int token = 0;

    records.open("records.txt", ios::in);
    records >> *productNum >> *productName >> *productQuant >> *productExp;
    
    if (!records.is_open())
    {
         cout << "------------------------------------------\n";
         cout << "|\tError_003 Has Been Occured!      |\n";
         cout << "------------------------------------------\n";
   
    }
    
    else
    {
         records2.open("records2.txt", ios::out | ios::app);

         cout << "-----------------------------\n";
         cout << "|\tDELETE PRODUCT      |\n";
         cout << "-----------------------------\n";

         cout << "Enter Product Number: ";
         cin >> *tempVar;

         do
         {
             if (*tempVar == *productNum)
             {
                 cout << "------------------------------------------------\n";
                 cout << "|\tProduct Details Has Been Deleted!      |\n";
                 cout << "------------------------------------------------\n";
                 token++;
             }

             else
             {
                 records2 << *productNum << " " << *productName << " " << *productQuant << " " << *productExp << "\n";
             }
             
             records >> *productNum >> *productName >> *productQuant >> *productExp;
         } 
         
         while (!records.eof());

    } 

     if (token == 0)
     {
         cout << "--------------------------------------\n";
         cout << "|\tInvalid Product Number!      |\n";
         cout << "--------------------------------------\n";
     }
     
     records.close();
     records2.close();

     remove("records.txt");
     rename("records2.txt", "records.txt");

     delete tempVar;
     tempVar = nullptr;
     
     menuFunc();
}

void inventory :: checkInventory(){

    fstream records;
    
    records.open("records.txt", ios::in);

    if (!records.is_open())
    {
         cout << "------------------------------------------\n";
         cout << "|\tError_004 Has Been Occured!      |\n";
         cout << "------------------------------------------\n";
   
    }
    
    else
    {  

     cout << "------------------------------------------------------------------------------------------------------\n";
     cout << "|\t\t\t\t        PRODUCT INVENTORY" << "                                            |\n";
     cout << "------------------------------------------------------------------------------------------------------\n";
     cout << "|Product Number.       |" << "Product Name.          |" << "Product Quantity.         |" << "Product Expiration        |\n";
     cout << "------------------------------------------------------------------------------------------------------\n";
    
        for (int i = 0; i < size[0]; i++)
        {
            records >> listNum[i] >> listName[i] >> listQuant[i] >> listExp[i];

            if (!listName[i].empty() && !listExp[i].empty())
            {
                cout << " #" << listNum[i] << "                      " << listName[i] << "                      " << listQuant[i] << "                      " << listExp[i] << "\n"; 
            }   

            listNum[i] = 0;
            listQuant[i] = 0;
            listName[i].clear();
            listName[i].clear();
        }   
    }
    
    records.close();

    menuFunc();
}