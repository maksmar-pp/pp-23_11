// pp-23.11.cpp: definiuje punkt wejścia dla aplikacji.
//

#include <iostream>
#include <string>
#include <vector>
void clear() {
	std::cout << "\x1b[2J\x1b[H";
}

void zad1() {
	int a = 7, b = 2;
	std::cout << "a/b: " << a / b << "\n";
	std::cout << "stati_cast<double>(a)/b: " << static_cast<double>(a) / b << "\n";
	std::cout << "stati_cast<double>(a/b): " << static_cast<double>(a / b) << "\n";

}
void zad2() {
	double x = 3.99, y = -3.99;
	int ix = x;
	int cix = static_cast<double>(x);
	std::cout << "ix: " << ix << " cix: " << cix << "\n";
	int iy= y;
	int ciy = static_cast<double>(y);
	std::cout << "iy: " << iy << " ciy: " << ciy << "\n";
}
void zad3(){
	char A = 'A';
	int a = A;
	std::cout << "char >> int: " << a << '\n';
	int b = 66;
	char B = b;
	std::cout << "int >> char: " << B << '\n';

}
void zad4() {
	int sum = 10, count = 4;
	double avg = sum / count;
	double avg_cast = sum / static_cast<double>(count);
	std::cout << "avg: " << avg << " avg_cast: " << avg_cast << '\n';

}
void zad5() {
	int done, todo;
	std::cout << "done: ";
	std::cin >> done;
	std::cout << "to do: ";
	std::cin >> todo;
	if (todo <= 0) {
		std::cout << "zle dane\n";
		return;
	}

	double procent = static_cast<double>(done) / todo;
	std::cout << "procent: " << procent *100 << "%\n";
}

void zad6() {
	std::cout << "Podaj: ";
	std::string text;
	std::getline(std::cin, text);
	std::cout << "length: " << text.length() << "\n";
}
void zad7() {
	std::cout << "Podaj: ";

	std::string text;
	std::getline(std::cin, text);
	int start, length;
	std::cout << "start: ";
	std::cin >> start;
	std::cout << "length: ";
	std::cin >> length;

	std::cout << "Sub: " << text.substr(start, length) << "\n";
}	

void zad8() {
	std::string text = "2026-11-10";

	std::size_t first = text.find('-');
	std::size_t second = text.find('-', first+1);

	std::string year = text.substr(0, first);
	std::string month = text.substr(first+1, second - first - 1);
	std::string day = text.substr(second + 1);
	std::cout 
			<< "Rok:     " << year << '\n'
			<< "Miesiac: " << month << '\n'
			<< "Dzien:   " << day << '\n';
}
void zad9() {
	std::string text, searched;
	std::cout << "Tekst: ";
	std::getline(std::cin, text);
	std::cout << "Szukane: ";
	std::getline(std::cin, searched);

	std::size_t found = text.find(searched);
	if (found == std::string::npos) {
		std::cout << "Nie znaleziono";
		return;
	}

	std::cout << found << "\n";
}
void zad10() {
	std::string email;
	std::cout << "Adres: ";
	std::cin >> email;
	std::size_t at = email.find("@");
	if (at == std::string::npos) {
		std::cout << "Zly adres\n";
		return;
	}
	std::string username = email.substr(0, at);
	std::string domain = email.substr(at + 1);
	std::cout
		<< "user: " << username
		<< "\ndomain: " << domain;
}
void zad11() {
	std::string name, lastName;
	std::cout << "name: ";
	std::cin >> name;
	std::cout << "lastname: ";
	std::cin >> lastName;
	std::string fullName = name + " " + lastName;
	std::cout << fullName << " length: " << fullName.length() << '\n';
}
void zad12() {
	std::string number;
	std::cout << "numer: ";
	std::cin >> number;
	int n;
	try {
		n = std::stoi(number);
		int dn = n * 2;
		int tn = n + 10;
		std::cout << "n: " << n
			<< "\n podwojona: " << dn
			<< "\nplus 10: " << tn << '\n';
	}
	catch (std::invalid_argument error) {
		std::cout << "error: " << error.what();
	}
}
void zad13() {
	std::string number;
	std::cout << "numer: ";
	std::cin >> number;
	try {
	double 	price  = std::stod(number);
	double whole = price * 5;
	int iprice = (int)price;
	std::cout << "price: " << price
		<< "\n5 sztuk: " << whole
		<< "iprice: " << iprice << "\n";
	}
	catch (std::invalid_argument error) {
		std::cout << "error: " << error.what();
	}
}
void zad14() {
	std::vector<std::string> tests = { "123", "123abc", "abc123", "12.5" };

	for (const auto& s : tests) {
		try {
			std::size_t pos = 0;
			int val = std::stoi(s, &pos);
			std::cout << "\"" << s << "\" wynik: " << val
				<< " znaki: " << pos << "/" << s.size() << ")\n";
		}
		catch (const std::exception& e) {
			std::cout << "\"" << s << "\"error: " << e.what() << "\n";
		}
	}
}
void zad15() {
	std::string input;
	std::cout << "Podaj tekst: ";
	std::getline(std::cin, input);

	try {
		int number = std::stoi(input);
		std::cout << "liczba: " << number << '\n';
	}
	catch (const std::invalid_argument&) {
		std::cout << "tekst nie reprezentuje liczby.\n";
	}
	catch (const std::out_of_range&) {
		std::cout << "liczba poza zakresem typu int.\n";
	}
}
void zad16() {
	std::string input;
	std::cout << "Podaj wiek: ";
	std::getline(std::cin, input);

	try {
		std::size_t pos = 0;
		int age = std::stoi(input, &pos);

		if (pos != input.size()) {
			std::cout << "tekst zawiera niedozwolone znaki po liczbie\n";
		}
		else if (age >= 0 && age <= 150) {
			std::cout << "Poprawny wiek: " << age << '\n';
		}
		else {
			std::cout << "Wiek spoza dopuszczalnego zakresu (0-150)\n";
		}
	}
	catch (const std::exception&) {
		std::cout << "nie mozna przekonwertowac tekstu na liczbe\n";
	}
}
void zad17() {
	std::string line;
	std::cout << "Imie Nazwisko;Wiek: ";
	std::getline(std::cin, line);

	std::size_t sep = line.find(';');
	if (sep == std::string::npos) {
		std::cout << "brak srednika\n";
		return;
	}

	std::string full_name = line.substr(0, sep);
	std::string age_str = line.substr(sep + 1);

	try {
		int age = std::stoi(age_str);
		std::cout << "Imię i nazwisko: " << full_name << '\n'
			<< "Wiek: " << age << '\n';

		if (age >= 0 && age <= 150) {
			std::cout << "wiek w dopuszczalnym przedziale\n";
		}
		else {
			std::cout << "wiek spoza przedziału 0-150\n";
		}
	}
	catch (const std::exception&) {
		std::cout << "nieprawidłowy zapis wieku.\n";
	}
}
int main()
{
	//zad1();
	//zad2();
	//zad3();
	//zad4();
	//zad5();
	//zad6();
	//zad7();
	//zad8();
	//zad9();
	//zad10();
	//zad11();
	//zad12();
	//zad13();
	//zad14();
	//zad15();
	//zad16();
		zad17();
	return 0;
}
