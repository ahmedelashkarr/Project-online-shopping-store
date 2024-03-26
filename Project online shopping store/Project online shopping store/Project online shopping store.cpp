//The Project is required to show the available
//products for the users to buy with a valid
//Credit card, the Shopper can add his items in
//a shopping cart

//1 - Login @
//2 - Registration @
//3 - Management of data for both
//shoppers and owners @
//4 - Add new product @
//5 - Remove Product @
//6 - Search for A specific product @
//7 - View Products information @
//8 - Add items in a shopping cart  @
//9 - Allow user to check cart any time @
//allowing him to remove or add any
//item
//10 - Creating Receipt
//11 - You can add Any Additional
//Functionalities which serve your
//Project

//user account : id / username / password / first name / last name / products in carts
//owner account : id / username / name shop / password / login data / items in shop
//product : name / id / 
//items : name / id / price / 
//buy done
//creating recipt 


#include "userAccount.h"

static int usersAccount = 0;
static int usersOwner = 0;
static userAccount* arrU[50];
static ownerAccount* arrO[50];

int Login() ;
void Registration();
void Operation(int id);
void OperationOwner(int id);

int main()
{
  
    int logout = 0;

    while (logout == 0)
    {
        char ans = 'y';
        int id = NULL;
        int choos;
        system("cls");
        cout << "1- Login" << endl;
        cout << "2- Registration" << endl;
        cout << "The answer : ";
        cin >> choos;
        int error = 0;
        switch (choos)
        {
        case 1:
            system("cls");
            int again;
            again = 0;
            char anslog2;
            while (again == 0) {
                id = Login();

                if (id != NULL)break;
                cout << "Do you want try again ? (Y/N) : "; cin >> anslog2;
                if (anslog2 == 'N' || anslog2 == 'n')break;
            }

            break;
        case 2:
            system("cls");
            Registration();
            system("cls");
            cout << "****Your account is activated !****\a\n";
            int again2;
            again2 = 0;
            char anslog;
            while (again2 == 0) {
                id = Login();

                if (id != NULL)break;
                cout << "Do you want try again ? (Y/N) : "; cin >> anslog;
                if (anslog == 'N' || anslog == 'n')break;
            }

            break;
        default:
            error = 1;
            break;
        }
        if (error == 1) {
            cout << "The Wrong Answer :(";
            break;
        }
        else {

            int save = id;
            while ((ans == 'y' || ans == 'Y') && id != NULL) {
                system("cls");
                id = save;
                if (id >= 0) {
                    cout << "------------------ Welcome " << arrU[id - 1]->getFirstName() << " " << arrU[id - 1]->getLastName() << " ------------------" << endl;
                    Operation(id);
                }
                else {
                    id = -id;
                    cout << "------------------ Welcome " << arrO[id - 1]->getFirstName() << " " << arrO[id - 1]->getLastName() << " ------------------" << endl;
                    OperationOwner(id);
                }

                int flag = 0;
                while (flag == 0) {
                    cout << "Do you do another operation ? (Y/N) : ";
                    cin >> ans;
                    if (ans == 'n' || ans == 'N' || ans == 'y' || ans == 'Y')flag = 1;
                }
                if (ans == 'n' || ans == 'N') cout << "Thank you";

            }
            system("cls");
            char anslog;
            cout << "You logout ! Do you want CLOSE PROGRAM ? (Y/N) : "; cin >> anslog;
            if (anslog == 'Y' || anslog == 'y') logout = 1;

        }
    }
};
// Login Fun
int Login() {

    cout << "---------------- Login ----------------\n";
    string Username, password;
    cout << "UserName : ";
    cin >> Username;
    cout << "Password : ";
    cin >> password;
    int flagChek = 0;
    userAccount* curr = 0;
    int flagacc = 1;
    for (int i = 0; i < usersAccount; i++) {
        curr = arrU[i];
        if (curr->getUserName() == Username && curr->getPassword() == password) {
            flagChek = 1;
            break;
        }
    }

    if (flagChek == 0) {
        for (int i = 0; i < usersOwner; i++) {
            curr = arrO[i];
            if (curr->getUserName() == Username && curr->getPassword() == password) {
                flagChek = 1;
                flagacc = -1;
                break;
            }
        }
    }

    if (flagChek == 1 && flagacc == -1)return -curr->getId();
    else if (flagChek == 1)return curr->getId();
    else {
        system("cls");
        cout << "UserName or Password is wrong !" << endl;
        return NULL;
    };

}


// Registration Fun
void Registration() {
    cout << "---------------- Registration ---------------- \n";
    int acc;
    string Username, password, firstname, lastname, shopname;
    cout << "Choose Account Setting : " << endl;
    cout << "1- Shopper " << endl;
    cout << "2- Owner " << endl;
    cout << "Choose : "; cin >> acc;
    switch (acc)
    {
    case 1:
        system("cls");
        cout << "------------- Create Shopper Account -------------" << endl;
        userAccount* newAccount;
        newAccount = new userAccount;
        arrU[usersAccount] = newAccount;
        
        int user_pk;
        user_pk = 0;
        while (user_pk == 0)
        {

            cout << "UserName : "; cin >> Username;
            int flagChek = 0;
            userAccount* curr = 0;
            int flagacc = 1;
            for (int i = 0; i < usersAccount; i++) {
                curr = arrU[i];
                if (curr->getUserName() == Username) {
                    flagChek = 1;
                    break;
                }
            }

            if (flagChek == 0) {
                for (int i = 0; i < usersOwner; i++) {
                    curr = arrO[i];
                    if (curr->getUserName() == Username) {
                        flagChek = 1;
                        break;
                    }
                }
            }
            if (flagChek == 0)break;
            cout << "Sorry this username is already exist try another one "<<endl;

        }


        newAccount->setUserName(Username);

        cout << "First Name : "; cin >> firstname;
        newAccount->setFirstName(firstname);

        cout << "Last Name : "; cin >> lastname;
        newAccount->setLastName(lastname);

        cout << "Password : "; cin >> password;
        newAccount->setPassword(password);
        newAccount->setId(usersAccount + 1);

        usersAccount++;
        break;
    case 2:
        system("cls");
        cout << "------------- Create Owner Account -------------" << endl;
        ownerAccount* newObject;
        newObject = new ownerAccount;
        arrO[usersOwner] = newObject;


        int user_pk2;
        user_pk2 = 0;
        while (user_pk2 == 0)
        {

            cout << "UserName : "; cin >> Username;
            int flagChek = 0;
            userAccount* curr = 0;
            int flagacc = 1;
            for (int i = 0; i < usersAccount; i++) {
                curr = arrU[i];
                if (curr->getUserName() == Username) {
                    flagChek = 1;
                    break;
                }
            }

            if (flagChek == 0) {
                for (int i = 0; i < usersOwner; i++) {
                    curr = arrO[i];
                    if (curr->getUserName() == Username) {
                        flagChek = 1;
                        break;
                    }
                }
            }
            if (flagChek == 0)break;
            cout << "Sorry this username is already exist try another one " << endl;

        }

        newObject->setUserName(Username);

        cout << "First Name : "; cin >> firstname;
        newObject->setFirstName(firstname);

        cout << "Last Name : "; cin >> lastname;
        newObject->setLastName(lastname);

        cout << "Shop Name : "; cin >> shopname;
        Shop* newShop;
        newShop = new Shop;
        newObject->Shop = newShop;
        newShop->setShopName(shopname);


        cout << "Password : "; cin >> password;
        newObject->setPassword(password);
        newObject->setId(usersOwner + 1);

        usersOwner++;

        break;
    default:

        break;
    }
}
void addProduct(ownerAccount* arrO[], userAccount* obj, int usersOwner) {

    system("cls");
    if (usersOwner == 0)
    {
        cout << "No Product added yet :( \n";
    }
    else {
        for (int i = 0; i < usersOwner; i++) {
            cout << i + 1 << ") " << "The Shop Name : " << arrO[i]->Shop->getShopName() << endl;
            for (int j = 0; j < arrO[i]->counterItems; j++) {
                cout << "    " << j + 1 << "- " << arrO[i]->Items[j]->getItemName() << " " << arrO[i]->Items[j]->getItemPrice() << "$" << endl;
            }
        }
        int proNum , shopNum ;
        cout << "\n\nSelect product to add ";
        int flag = 0;
        while (flag == 0) {
            cout << "Shop number : "; cin >> shopNum;
            cout << "Product number : "; cin >> proNum;
          if (shopNum < 1 || shopNum > usersOwner)cout << "Wrong num of shop ! \n";
            else {
                flag = 1;
            }
        }
        
        try {
            if (proNum > arrO[shopNum - 1]->counterItems || proNum < 1 )throw exception();
            if (shopNum < 1 || shopNum > usersOwner)throw exception();
            obj->products[obj->counterPro] = arrO[shopNum - 1]->Items[proNum - 1];
            obj->counterPro++;
        }
        catch (exception a) {
            cout << "Wrong answer \n";
        }
    }
}
void Operation(int id )
{
    int select;
    cout << "----- Select Operation -----" << endl;
    cout << "1- Edit " << endl ;
    cout << "2- Details " << endl;
    cout << "3- Add Products " << endl;
    cout << "4- Check Cart " << endl;
    cout << "5- Serach Product" << endl;
    cout << "6- Create Recipt" << endl;
    cout << "Operation : "; cin >> select;
    userAccount* Account;
    Account = arrU[id - 1];
        string search;
    switch (select)
    {
    case 1:
        Account->Edit();
        break;
    case 2:
        Account->Details();
        break;
    case 3:
        addProduct(arrO, Account, usersOwner);
        break;
    case 4:
        system("cls");
        cout << "----------- Cart -----------" << endl;
        if (Account->counterPro == 0)cout << "Nothing Products here :( \n";

        for (int i = 0; i < Account->counterPro; i++) {
            Item* newItem = Account->products[i];
            cout << i + 1 << "- The Name : " << newItem->getItemName() << " | The Price : " << newItem->getItemPrice() << endl;
        }
        int ans;
        cout << "\n Operations : \n    1- Add\n    2- Remove\n    3- Nothing\nSelect One : "; cin >> ans;
        switch (ans)
        {
        case 1:
            addProduct(arrO, Account, usersOwner);
            break;
        case 2 :
            system("cls");
            for (int i = 0; i < Account->counterPro; i++) {
                Item* newItem = Account->products[i];
                cout << i + 1 << "- The Name : " << newItem->getItemName() << " | The Price : " << newItem->getItemPrice() << endl;
            }
            int numrv;
            cout << "Select number to REMOVE : "; cin >> numrv;
            if (numrv < 1 || numrv > Account->counterPro) {
                cout << "Wrong Num :(\n";
                break;
            }
            if (numrv == Account->counterPro) {
                Account->counterPro--;
                break;

            }
            else {
                for (int i = numrv - 1; i < Account->counterPro; i++)
                {
                    swap(Account->products[i], Account->products[i + 1]);
                }
            }
            Account->counterPro--;
            break;
        default:
            break;
        }
        break;
    case 5 :
        system("cls");
        cout << "Enter word of name product : ";
        cin >> search;
        int flag ;
        flag = 0;
        for (int i = 0; i < usersOwner; i++) {
            for (int j = 0; j < arrO[i]->counterItems; j++) {
                string ser = arrO[i]->Items[j]->getItemName();
                if (ser.compare(search) == 0) {
                    flag = 1;
                    cout << "- " << arrO[i]->Items[j]->getItemName() << " " << arrO[i]->Items[j]->getItemPrice() << "$" << endl;
                }
            }
        }
        if (flag == 0)cout << "No product have this name :(\n";
        break;
    case 6:
        system("cls");
        cout << "---------------- Recipt ----------------" << endl;
        if (Account->counterPro == 0)cout << "Nothing Items here :( \n";
        else {
            cout << "Customer : " << Account->getFirstName() << " " << Account->getLastName() << "      |       " ;
            cout << "Cashier : " << "Online shop" << endl << endl ;

            float total = 0;
            for (int i = 0; i < Account->counterPro; i++) {
                Item* newItem = Account->products[i];
                total += Account->products[i]->getItemPrice();
                cout << i + 1 << "- The Name : " << newItem->getItemName() << " | The Price : " << newItem->getItemPrice() << endl;
            }
            cout << endl << endl;
            cout << "Total befor Discount : " << total << endl; 
            cout << "Discount : 0.0%" << endl ; 
            cout << "Total after Discount : " << total << endl; 

        }
        break;
    default:
        break;
    }

}void OperationOwner(int id)
{
    int select = 0;
    cout << "----- Select Operation -----" << endl;
    cout << "1- Edit " << endl;
    cout << "2- Details " << endl;
    cout << "3- Add Items " << endl;
    cout << "4- Show Items " << endl;


    cout << "Operation : ";
    cin >> select;


    switch (select)
    {
    case 1:
        arrO[id - 1]->Edit(arrO[id - 1]);
        break;
    case 2:
        arrO[id - 1]->Details(arrO[id - 1]);
        break;
    case 3:
        arrO[id - 1]->AddItems(arrO[id - 1]);
        break;
    case 4:
        arrO[id - 1]->showItems(arrO[id - 1]);
        break;
    default:
        break;
    }
}
