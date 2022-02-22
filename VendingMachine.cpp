// This program simulates the payment section of a vending machine.
// The vending machine only dispenses sodas which are priced at $1.30

#include <iostream>
using namespace std;

// Create an enumeration data type called Money
enum class Money { nickel = 5, dime = 10, quarter = 25, dollar = 100 };

const int MAXSIZE = 26;
const int PRICE = 130;

// Prints price to the screen in the format: $X.XX
// price represents an amount of money, in pennies
void PrintPrice(int price);

// Takes user input (1, 2, 3, 4) and converts it to a Money type
Money ConvertToMoney(int x);

// Prints a word to the screen stating what the Money type is
void PrintMoney(Money x);

// Prints the coins to dispense, which add up to amount
// Note: This will never need to dispense a dollar
void DispenseChange(int amount);

int main()
{
	// TODO: Write main program code
	Money deposit, y; 
	int input = 0, cents = 0, price = 130;
	
	cout << "Vending Machine" << endl << endl;

	cout << "Deposit $1.30 for a soda" << endl << endl;
	
	do
	{
		cout << "1: Deposit Nickel 2: Deposit Dime 3: Deposit quarter 4: Deposit dollar 5: Cancel transaction" << endl;
		
		cout << "Enter: ";
		
		cin >> input;
		if (input == 5)
		{
			cout << "Transaction Cancelled." << endl;
			return 0;
		}
		else if (input > 5 && input < 1)
		{
			cout << "ERROR: Invalid Input. Please enter a number 1-4";
		}
		else
		{
			//Convert input into money data type 
			y = ConvertToMoney((int)input);

			price = price - (int)y;

			PrintPrice((int)price);
		}
		
		if (price < 0)
		{
			for(int i = 0; i < 1; i++ )
			{
				DispenseChange(price);
			}
			
			return 0;
		}
		else if (price == 0)
		{
			return 0;
		}

	} while (price >= 0);
}

void PrintPrice(int price)
{
	// TODO: Write code for the printPrice function
	
	int cents = (price % 100);
	cents = abs(cents);
	int dollars = (price / 100);
	
	cout << "Amount remaining: $" << dollars<<"."<<cents << endl;
}

void DispenseChange(int change)
{
	// TODO: Write code for the DispenseChange function
	int changeQuarter, changeDime, changeNickel ;
	change = abs(change);
	if(change >=25)
	{
		changeQuarter = change / (int)Money::quarter;
		for (int i = 0; i < changeQuarter; i++)
		{
			PrintMoney(Money::quarter);
		}
		change = change - (changeQuarter * 25);
	}
	if (change >= 10 )
	{
		changeDime = change / (int)Money::dime;
		for (int i = 0; i < changeDime; i++)
		{
			PrintMoney(Money::dime);
		}
		change = change - (changeDime * 10);
	}
	if (change >= 5)
	{
		changeNickel = change / (int)Money::nickel;
		for (int i = 0; i < changeNickel; i++)
		{
			PrintMoney(Money::nickel);
		}
		change = change - (changeNickel * 5);
	}
}

Money ConvertToMoney(int x)
{
	Money totalP;
	int change;

	if (x == 1)
	{
		totalP = Money::nickel;
	}
	else if (x == 2)
	{
		totalP = Money::dime;
	}
	else if (x == 3)
	{
		totalP = Money::quarter;
	}
	else if (x == 4)
	{
		totalP = Money::dollar;
	}

	return totalP;
}

//Prints work for dollar, nickel, dime, quarter for change

void PrintMoney(Money x)
{
	//cout << "Change dispensing: ";
	switch(x)
	{
		case Money::dollar:
			cout << "dollar, ";
			break;
		case Money::nickel:
			cout << "nickel, ";
			break;
		case Money::dime:
			cout << "dime, ";
			break;
		case Money::quarter:
			cout << "quarter, ";
			break;
	}
	
	cout << endl;
}