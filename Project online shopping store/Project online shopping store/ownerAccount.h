//#pragma once
//#include <iostream>
//#include "userAccount.h"
//using namespace std;
//
//
//
//class Shop{
//private:
//	string shopName;
//
//public:
//	void setShopName(string name) {
//		shopName = name;
//	}
//	string getShopName() {
//		return shopName ;
//	}
//	Shop() {
//		shopName = "NULL";
//	}
//
//};
//class ownerAccount : public userAccount{
//
//public:
//	Shop* Shop;
//	Item* Items[50];
//	int counterItems = 0;
//
//	ownerAccount() {
//		Shop = 0;
//		Items[0] = { 0 };
//	}
//
//	void Details(ownerAccount* obj) {
//		system("cls");
//		cout << "1- UserName : " + obj->getUserName() << endl;
//		cout << "2- First Name : " + obj->getFirstName() << endl;
//		cout << "3- Last Name : " + obj->getLastName() << endl;
//		cout << "4- Shop Name : " + obj->Shop->getShopName() << endl;
//		cout << "5- Password : " + obj->getPassword() << endl;
//	}
//
//
//	void Edit(ownerAccount* obj) {
//		system("cls");
//		cout << "1- UserName : " + obj->getUserName() << endl;
//		cout << "2- First Name : " + obj->getFirstName() << endl;
//		cout << "3- Last Name : " + obj->getLastName() << endl;
//		cout << "4- Shop Name : " + obj->Shop->getShopName() << endl;
//		cout << "5- Password : " + obj->getPassword() << endl;
//		int choos;
//		string editing;
//		cout << "What do you want to edit ? "; cin >> choos;
//		switch (choos)
//		{
//		case 1:
//			cout << "New UserName : "; cin >> editing;
//			setUserName(editing);
//			break;
//		case 2:
//			cout << "New First Name : "; cin >> editing;
//			setFirstName(editing);
//			break;
//		case 3:
//			cout << "New Last Name : "; cin >> editing;
//			setLastName(editing);
//			break;
//		case 4:
//			cout << "New Shop Name : "; cin >> editing;
//			Shop->setShopName(editing);
//			break;
//		case 5:
//			cout << "New Password : "; cin >> editing;
//			setPassword(editing);
//			break;
//		default:
//			break;
//		}
//
//	}
//	void AddItems(ownerAccount* obj) {
//		string nameitem; float price;
//		Item* newItem = new Item;
//		obj->Items[obj->counterItems] = newItem;
//		obj->counterItems++; // 1
//		system("cls");
//		cout << "----------- Add Items -----------" << endl;
//		cout << "Name of item : " ; cin >> nameitem;
//		cout << "price for item : " ; cin >> price;
//		newItem->setItemName(nameitem);
//		newItem->setItemPrice(price);
//		newItem->setItemId(obj->counterItems);
//
//	}
//	void showItems(ownerAccount* obj) {
//		system("cls");
//		cout << "----------- Show Items -----------" << endl;
//		for (int i = 0; i < obj->counterItems; i++) {
//			Item* newItem = obj->Items[i];
//
//			cout << i + 1 << "- The Name : " << newItem->getItemName() << " | The Price : " << newItem->getItemPrice() << endl;
//		}
//	}
//
//};
//
