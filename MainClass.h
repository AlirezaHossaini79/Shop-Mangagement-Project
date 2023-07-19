#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdexcept>

using namespace std;

// Name , price , id , stock 

class Shop
{
private:
	string name;
	size_t stock, price, id;
public:
	Shop() :name(""), price(0), id(0), stock(0) {}
	~Shop(){}

	void Set_Name(string Name)
	{
		name = Name;
	}

	void Set_ID(size_t ID)
	{
		id = ID;
	}

	void Set_Price(size_t PRICE)
	{
		price = PRICE;
	}

	void Set_Stock(size_t STOCK)
	{
		stock = STOCK;
	}

	string Get_Name()
	{
		return name;
	}

	size_t Get_ID()
	{
		return id;
	}

	size_t Get_Price()
	{
		return price;
	}

	size_t Get_Stock()
	{
		return stock;
	}

	void Display_Info()
	{
		cout << " - Name: " << name << " - ID: " << id << " - Price: " << price << " - Stock:  " << stock;
	}
};