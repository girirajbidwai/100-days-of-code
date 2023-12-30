#include <iostream>
int main() {
	int t, s;
	char c;
	std::cin >> t;
	while (t-- != 0) {
		s = 657; 	
		for (int i = 0; i < 9; ++i) {
			std::cin >> c;
			s -= c; 
		}
		std::cout << char(s) << "\n";
	}
	return 0;
}
