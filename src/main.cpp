#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <utility>

std::string ceasar_cipher(const std::string& data, const int shift)
{
	std::string rawText{std::move(data)};
	std::string cipherText{};

 	for(auto& c:rawText)
 	{
 		if(c >= 97 && c <= 122)
 			c -= 32;
 	}
 	 
 	for(auto c:rawText)
 	{
 		
 		if(c + shift > 90)
 		{
 			auto addedShift = 90 - static_cast<int>(c);
 			std::cout << addedShift<< std::endl;
 			c = 65 + addedShift;
 		}
 		else 
 		{
 			c += shift;
 		}

 		cipherText+=c;

 	}

 	return cipherText;
}
void ceaser_decipher(const std::string& data)
{
	std::string rawText{data};
 	for(auto& c:rawText)
 	{
 		if(c >= 97 && c <= 122)
 			c -= 32;
 	}

 	std::string cipherText{rawText};


 	for(auto i =0; i <= 25; i++)
 	{
 		for(auto& c:cipherText)
 		{
 			if(c - i < 65)
 			{
 				auto resetShift = static_cast<int>(c) - 65;
 				c = 90 - resetShift;
 			}
 			else 
 			{
 				c -= i; 
 			}
 		}
 		std::cout << i << ":"<< cipherText << std::endl;
 		cipherText = rawText;
 	}

}
int main()
{
	bool bApplicationRunning{true};
	std::string text{};
	int shift{};
	while(bApplicationRunning)
	{
		std::cout << "Type : Application Console" << std::endl;
		std::cout << "1.Chiffrer une chaine de caractere" << std::endl;
		std::cout << "2.Dechiffrer une chaine de catere" << std::endl;
		std::cout << "3.Quitter" << std::endl;

 		auto input = std::cin.get();
	 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	 	switch(input)
	 	{
	 		case '1':
 	 			std::cout << "Saisir un mot ou un texte : ";
	 			std::getline(std::cin, text);

	 			do 
	 			{
	 		 	 	std::cout << "Saisir un decalage : ";
		 			std::cin >> shift;
		 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		 		}while(shift < 0 || shift > 25);

	 			std::cout << "Ciphered text : " << ceasar_cipher(text, shift) << std::endl;


 	 			break;
	 		case '2':
	 		 	std::cout << "Saisir un mot ou un texte : ";
	 			std::getline(std::cin, text);

	 			ceaser_decipher(text);
	 			break;
	 		case '3':
	 			bApplicationRunning = false;
	 			break;
	 		default:
	 			std::cerr << "Probleme de saisis, vous avez saisis une information invalide." << std::endl;
	 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	 			break;
	 	}

	}

	return 0;
}