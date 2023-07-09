#include <iostream>
using namespace std;


int calcAge(int birthYear) {

    const int currentYear = 2023;
    int age = currentYear - birthYear;
    
    return age;
}

int main(void) {

    string name;
    int birthAge;
	
    cout << "What's your name?";
    getline(cin, name);
	cout << "What year were you born?";
    cin >> birthAge;
	int age = calcAge(birthAge);
	cout << "You're name is " << name << " and you are currently " << age << " years old.";
	
    return(0);
}
