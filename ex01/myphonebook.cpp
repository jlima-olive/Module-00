#include <iostream>
#include <unistd.h>
#include <string>

class Contact
{
private:
	std::string	str[4];
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	long		phone_number;

	void	put(std::string &in, int i)
	{
		std::cout << str[i];
		std::cin >> in;
		if (in.length() > 10)
		{
			in.at(9) = '.';
			in.erase(in.begin() + 10, in.end());
		}
	}
	void	put_nbr(long &numb)
	{
		std::cout << "Hand over the phone number: ";
		std::cin >> numb;
	}
public:
	Contact()
	{
		str[0] = "\nHand over the first name: ";
		str[1] = "\nHand over the last name: ";
		str[2] = "\nHand over the nickname: ";
		str[3] = "\nHand over the darkest secret: ";
	}
	void	add_info()
	{
		put(first_name, 0);
		put(last_name, 1);
		put(nickname, 2);
		put_nbr(phone_number);
		put(darkest_secret, 3);
	}
	void	format(std::string temp)
	{
		for (int i = temp.length(); i < 10; i++)
			std::cout << ' ';
		std::cout << temp << "|";
			
	}
	void	print_info(int ind)
	{
		if (first_name.length())
		{
			std::cout << "| " << ind << '|';
			format(first_name);
			format(last_name);
			format(nickname);
			format(darkest_secret);
			std::cout << std::endl;
		}
		else
		{
			std::cout << "| " << ind;
			for (int i = -1; i < 3; i++)
				std::cout << '|' << "          ";
			std::cout << '|' << std::endl;
		}
	}
};

class PhoneBook
{
private:
	Contact ctt[8];
	int		calls;
public:
	PhoneBook()
	{
		calls = 0;
	}
	void	add()
	{
		ctt[calls % 8].add_info();
		calls++;
	}
	void search()
	{
		for(int ind = 0; ind < 8; ind++)
			ctt[ind].print_info(ind + 1);
	}
};

int main(void)
{
	PhoneBook	phone;
	std::string	str;

	while (1)
	{
		std::cin.clear();
		std::cout << "OPTIONS: \n";
		std::cout << "ADD, SEARCH, EXIT\n";
		std::cin >> str;
		if (std::cin.eof())
			exit (0);
		if (str.compare("ADD") == 0)
			phone.add();
		else if (str.compare("SEARCH") == 0)
			phone.search();
		else if (str.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Thats... not one of the options my man\n";
	}
	return (0);
}
