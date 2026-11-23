// pp-23.11.cpp: definiuje punkt wejścia dla aplikacji.
//

#include <iostream>
#include <string>

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

}
int main()
{
	//zad1();
	//zad2();
	//zad3();
	//zad4();
	//zad5();
	//zad6();
	zad7();

	return 0;
}
