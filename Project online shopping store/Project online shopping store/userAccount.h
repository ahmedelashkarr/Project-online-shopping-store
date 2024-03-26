#pragma once
#include <iostream>
#include <string>
using namespace std;
//user account : id / username / password / first name / last name / products in carts
//void addProduct(ownerAccount* arrO[], userAccount* obj, int usersOwner) {};

class Item {
private:
	string itemName;
	int itemId;
	float itemPrice;
public:
	void setItemName(string name) {
		itemName = name;
	}
	string getItemName() {
		return itemName;
	}
	void setItemId(int id) {
		itemId = id;
	}
	int getItemId() {
		return itemId;
	}
	void setItemPrice(float price) {
		itemPrice = price;
	}
	float getItemPrice() {
		return itemPrice;
	}
	Item() {
		itemName = "NULL";
		itemId = NULL;
		itemPrice = NULL;
	}
};


class userAccount
{
private:
	int id;
	string userName, password, firstName, lastName;
public:
	Item * products[50] ;
	int counterPro = 0;

	void setUserName(string userName) {
		this->userName = userName;
	}
	void setLastName(string lastName) {
		this->lastName = lastName;
	}
	void setFirstName(string firstName) {
		this->firstName = firstName;
	}
	void setPassword(string pass) {
		this->password = pass;
	}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}
	string getUserName() {
		return userName;
	}
	string getLastName() {
		return lastName;
	}
	string getFirstName() {
		return firstName;
	}
	string getPassword() {
		return password;
	}
	void Edit() {
		system("cls");
		cout << "1- UserName : " + this->userName << endl;
		cout << "2- First Name : " + this->firstName << endl;
		cout << "3- Last Name : " + this->lastName << endl;
		cout << "4- Password : " + this->password << endl;
		int choos;
		string editing;
		cout << "What do you want to edit ? "; cin >> choos;
		switch (choos)
		{
		case 1:
			cout << "New UserName : "; cin >> editing;
			setUserName(editing);
			break;
		case 2:
			cout << "New First Name : "; cin >> editing;
			setFirstName(editing);
			break;
		case 3:
			cout << "New Last Name : "; cin >> editing;
			setLastName(editing);
			break;
		case 4:
			cout << "New Password : "; cin >> editing;
			setPassword(editing);
			break;
		default:
			break;
		}
	}

	void Details() {
		system("cls");
		cout << "1- UserName : " + this->userName << endl;
		cout << "2- First Name : " + this->firstName << endl;
		cout << "3- Last Name : " + this->lastName << endl;
		cout << "4- Password : " + this->password << endl;
	}
	userAccount() {
		id = NULL;
		userName = "UnKnown";
		firstName = "UnKnown";
		lastName = "UnKnown";
		password = "Null";
		products[0] = {0};
	}
};



// ----------- Shop class -----------
class Shop {
private:
	string shopName;

public:
	void setShopName(string name) {
		shopName = name;
	}
	string getShopName() {
		return shopName;
	}
	Shop() {
		shopName = "NULL";
	}

};

// ------------- Owner Class -------------
class ownerAccount : public userAccount {

public:
	Shop* Shop;
	Item* Items[50];
	int counterItems = 0;

	ownerAccount() {
		Shop = 0;
		Items[0] = { 0 };
	}

	void Details(ownerAccount* obj) {
		system("cls");
		cout << "1- UserName : " + obj->getUserName() << endl;
		cout << "2- First Name : " + obj->getFirstName() << endl;
		cout << "3- Last Name : " + obj->getLastName() << endl;
		cout << "4- Shop Name : " + obj->Shop->getShopName() << endl;
		cout << "5- Password : " + obj->getPassword() << endl;
	}


	void Edit(ownerAccount* obj) {
		system("cls");
		cout << "1- UserName : " + obj->getUserName() << endl;
		cout << "2- First Name : " + obj->getFirstName() << endl;
		cout << "3- Last Name : " + obj->getLastName() << endl;
		cout << "4- Shop Name : " + obj->Shop->getShopName() << endl;
		cout << "5- Password : " + obj->getPassword() << endl;
		int choos;
		string editing;
		cout << "What do you want to edit ? "; cin >> choos;
		switch (choos)
		{
		case 1:
			cout << "New UserName : "; cin >> editing;
			setUserName(editing);
			break;
		case 2:
			cout << "New First Name : "; cin >> editing;
			setFirstName(editing);
			break;
		case 3:
			cout << "New Last Name : "; cin >> editing;
			setLastName(editing);
			break;
		case 4:
			cout << "New Shop Name : "; cin >> editing;
			Shop->setShopName(editing);
			break;
		case 5:
			cout << "New Password : "; cin >> editing;
			setPassword(editing);
			break;
		default:
			break;
		}

	}
	void AddItems(ownerAccount* obj) {
		string nameitem; float price;
		Item* newItem = new Item;
		obj->Items[obj->counterItems] = newItem;
		obj->counterItems++; // 1
		system("cls");
		cout << "----------- Add Items -----------" << endl;
		cout << "Name of item : "; cin >> nameitem;
		cout << "price for item : "; cin >> price;
		newItem->setItemName(nameitem);
		newItem->setItemPrice(price);
		newItem->setItemId(obj->counterItems);

	}
	void showItems(ownerAccount* obj) {
		system("cls");
		cout << "----------- Show Items -----------" << endl;
		if (obj->counterItems == 0)cout << "Nothing Items here :( \n";

		for (int i = 0; i < obj->counterItems; i++) {
			Item* newItem = obj->Items[i];

			cout << i + 1 << "- The Name : " << newItem->getItemName() << " | The Price : " << newItem->getItemPrice() << endl;
		}
	}

};



