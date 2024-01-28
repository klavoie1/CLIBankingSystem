#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void MainMenu()
{
	std::cout << "Welcome to banking" << std::endl;
	std::cout << "1. Add Transaction" << std::endl;
	std::cout << "2. Delete Transaction" << std::endl;
	std::cout << "3. View Transactions" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

int UserChoice()
{
	int UserChoice = {};

	std::cout << "Select a choice: " << std::endl;
	std::cin >> UserChoice;

	return UserChoice;
}

void AddTransaction()
{
	std::ofstream TransactionFile;
	// Gives a random seed based on time of creation
	srand(time(0));

	TransactionFile.open("C:\\cpluspluscoding\\BankingSystem\\TransactionFile.txt", std::ios_base::app);

	// Find a way to prevent two transactions from having the same ID
	int Id = rand();
	std::string TransactionName = "";
	float TransactionAmount = {};
	std::string TransactionDate = "";


	std::cout << "Enter the name of the Transaction: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, TransactionName);
	std::cout << "Enter the transaction Amount (+ for Income, - for Expense): " << std::endl;
	std::cin >> TransactionAmount;
	std::cout << "Enter the transaction date (mmddyyyy): " << std::endl;
	std::cin >> TransactionDate;

	TransactionFile << Id << ". " << TransactionName << ", " << TransactionAmount << ", " << TransactionDate << std::endl;;

	TransactionFile.close();
}

void DeleteTransaction()
{
	std::string RemoveId = "";
	std::string Line = "";

	std::cout << "What Transaction would you like to remove (Enter the ID): " << std::endl;
	std::cin >> RemoveId;

	std::ifstream TransactionFile("C:\\cpluspluscoding\\BankingSystem\\TransactionFile.txt");
	std::ofstream TempFile("C:\\cpluspluscoding\\BankingSystem\\TempFile.txt");

	while (std::getline(TransactionFile, Line))
	{
		if (Line != RemoveId)
		{
			TempFile << Line << std::endl;
		}
	}

	TransactionFile.close();
	TempFile.close();



	if (rename("C:\\cpluspluscoding\\BankingSystem\\TempFile.txt", "C:\\cpluspluscoding\\BankingSystem\\TransactionFile.txt") == -1)
		std::cout << "File name change worked!" << std::endl;
	else
		std::cout << "File name did not work!" << std::endl;
}

void ViewTransactions()
{
	std::ifstream TransactionFile("C:\\cpluspluscoding\\BankingSystem\\TransactionFile.txt");

	std::string TransactionText;

	while (std::getline(TransactionFile, TransactionText))
	{
		std::cout << TransactionText << std::endl;
	}

	TransactionFile.close();
}

int main() 
{
	std::ofstream TransactionFile("C:\\cpluspluscoding\\BankingSystem");

	bool running = true;

	while (running)
	{
		MainMenu();

		switch (UserChoice())
		{
		case(1):
			AddTransaction();
			continue;
		case(2):
			DeleteTransaction();
			continue;
		case(3):
			ViewTransactions();
			continue;
		case(4):
			TransactionFile.close();
			break;
		}
		running = false;
	}
	return 1;
}