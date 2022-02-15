#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string GetRuler(const string& kingdom) {
	// TODO: implement this method to determine the ruler name, given the kingdom.
	string ruler = "";
	vector <char> vowels {'a','i','o','u','e'};
	
	if (tolower(kingdom.back()) == 'y')
		ruler = "nobody";
	
	else if (find(vowels.begin(),vowels.end(),tolower(kingdom.back())) != vowels.end())
		ruler="Alice";
	
	else
		ruler = "Bob";
		
	return ruler;
}

int main() {
	int testcases;
	cin >> testcases;
	string kingdom;
	
	for (int t = 1; t <= testcases; ++t) {
		cin >> kingdom;
		cout << "Case #" << t << ": " << kingdom << " is ruled by " << GetRuler(kingdom) << ".\n";
  }
  
  return 0;
}
