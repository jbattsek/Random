#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//HELLO WORLD

//Doesn't yet check for input errors on hex conversions
//Doesn't enforce boundries presented by int max (should use long)
//to add: twos complement

enum options { Nand, And, Or, Xor, ShiftLeft, ShiftRight, BaseConversion, End};
void run(bool &started, int &choice);
void decimal();
void binary();
void hex();
void PrintBinary(int n);

int main(){
	bool started = false;
	int choice = -1;

	cout << "Welcome to the Bitwise Operations Program!\n\n";
	while (1){
		run(started, choice);
		
		if (choice == 7){
			cout << "Goodbye" << endl;
			break;
		}

		if (cin.fail()){
			cin.clear();
			string junk;
			getline(cin, junk);
		}
	}
	return 0;
}

void run(bool &started, int &choice){
	if (!started){
		cout << "Which operation would you like to do?\n";
		cout << "\n1. Nand\n";
		cout << "2. And\n";
		cout << "3. Or\n";
		cout << "4. Xor\n";
		cout << "5. Shift Left\n";
		cout << "6. Shift Right\n";
		cout << "7. Convert Base \n";
		cout << "8. Quit\n\n"; 
		cout << "(Enter a number): ";
		cin >> choice;
		cout << endl;
		if ((choice < 1 || choice > 8) || cin.fail()){
			cout << "Please choose a number valid option.\n\n";
			cin.clear();
			string junk;
			getline(cin, junk);
			run(started, choice);
			return;
		}
		started = true;
		choice--;
		string junk;
		getline(cin, junk);
	}

	if (choice == End){
		
		return;
	}
	else if (choice == Nand){

		int x, y;
		cout <<"Enter the first number you would like to nand: ";
		cin >> x;
		cout <<"\nEnter the second number you would like to nand: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;	
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " nand " << y << " = " << ~(x&y) << endl << endl;
		cout << "Would you like to nand again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == And){

		int x, y;
		cout <<"Enter the first number you would like to and: ";
		cin >> x;
		cout <<"\nEnter the second number you would like to and: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " and " << y << " = " << (x&y) << endl << endl;
		cout << "Would you like to and again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == Xor){

		int x, y;
		cout <<"Enter the first number you would like to Xor: ";
		cin >> x;
		cout <<"\nEnter the second number you would like to Xor: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " Xor " << y << " = " << (x^y) << endl << endl;
		cout << "Would you like to Xor again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == Or){

		int x, y;
		cout <<"Enter the first number you would like to or: ";
		cin >> x;
		cout <<"\nEnter the second number you would like to or: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " or " << y << " = " << (x|y) << endl << endl;
		cout << "Would you like to or again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == ShiftLeft){

		int x, y;
		cout <<"Enter the number you would shift: ";
		cin >> x;
		cout <<"\nEnter the number of bits you would like to shift by: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " shifted left " << y << " bits = " << (x << y) << endl << endl;
		cout << "Would you like to shift left again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == ShiftRight){

		int x, y;
		cout <<"Enter the number you would shift: ";
		cin >> x;
		cout <<"\nEnter the number of bits you would like to shift by: ";
		cin >> y;

		if(cin.fail()){
			cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
			started = false;
			run(started, choice);
			return;
		}

		cout << endl << endl;
		cout <<'\t' << x << " shifted right " << y << " bits = " << (x >> y) << endl << endl;
		cout << "Would you like to shift right again?\n1. Yes\n2. No\n\n(Enter a number): ";
		int next;
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
	else if (choice == BaseConversion){
		int next = -1;
		cout << "What type of number would you like to convert?\n\n";
		cout << "1. Decimal\n2. Binary\n3. Hexadecimal\n\n(Enter a number): ";
		cin >> next;
		cout << endl;
		if ((next < 1 || next > 3) || cin.fail()){
			cout << "ERROR: invalid option.\n\n";
			cin.clear();
			string junk;
			getline(cin, junk);
			started = false;
			run(started, choice);
			return;
		}
		if (next == 1){
			decimal();
		}
		else if (next == 2){
			binary();
		}
		else if (next == 3){
			hex();
		}

		cout << "\nWould you like to base convert again?\n1. Yes\n2. No\n\n(Enter a number): ";
		
		cin >> next;
		cout << endl;
		
		if (next == 1){
			run(started, choice);
			return;
		}
		else {
			started = false;
			run(started, choice);
			return;
		}
	}
}

void PrintBinary(int n)
{
    if (n / 2 != 0) {
        PrintBinary(n / 2);
    }
    cout << n % 2;
}

void decimal(){
	int decimal;
	cout << "Enter the positive decimal number you would like to convert: ";
	cin >> decimal;
	if(cin.fail() || decimal < 0){
		cout << endl << endl <<"ERROR: One or more invalid inputs. \n";
		string junk;
		getline(cin, junk);
		return;
	}
	cout << "\n\tDecimal: " << decimal << endl; 
	cout << "\tBinary: 0x0";
	PrintBinary(decimal);
	cout << endl;
	cout << "\tHexadecimal: 0x0" << hex << decimal << dec <<endl;
}


void binary(){
	string byNum;
	cout << "Enter the binary number you would like to convert: 0x0";
	cin >> byNum;
	int num = 0;
	for (int i = 0; i < byNum.size(); i++){
		if (byNum[i] != '1' && byNum[i] != '0'){
			//ERROR
			return;
		}
	}
	for (int i = 0; i < byNum.size(); i++){
		if(byNum[i] == '1'){
			num += pow(2,byNum.size() - 1 - i);
		}
	}
	int decimal = num;
	cout << "\n\tDecimal: " << decimal << endl; 
	cout << "\tBinary: 0x0";
	PrintBinary(decimal);
	cout << endl;
	cout << "\tHexadecimal: 0x0" << hex << decimal << dec <<endl;

}
void hex(){
	cout << "Enter the hexadecimal number you would like to convert: 0x";
	string byNum;
	cin >> byNum;
	int num = 0;
	for (int i = 0; i < byNum.size(); i++){
		if(byNum[i] != '0'){
			int add = pow(16,byNum.size() - 1 - i);
			if (byNum[i] == 'F' || byNum[i] == 'f'){
				add *= 15;
			}
			else if (byNum[i] == 'E' || byNum[i] == 'e'){
				add *= 14;
			}
			else if (byNum[i] == 'D' || byNum[i] == 'd'){
				add *= 13;
			}
			else if (byNum[i] == 'C' || byNum[i] == 'c'){
				add *= 12;
			}
			else if (byNum[i] == 'B' || byNum[i] == 'b'){
				add *= 11;
			}
			else if (byNum[i] == 'A' || byNum[i] == 'a'){
				add *= 10;
			}
			else if (byNum[i] == '9'){
				add *= 9;
			}
			else if (byNum[i] == '8'){
				add *= 8;
			}
			else if (byNum[i] == '7'){
				add *= 7;
			}
			else if (byNum[i] == '6'){
				add *= 6;
			}
			else if (byNum[i] == '5'){ 
				add *= 5;
			}
			else if (byNum[i] == '4'){
				add *= 4;
			}
			else if (byNum[i] == '3'){
				add *= 3;
			}
			else if (byNum[i] == '2'){
				add *= 2;
			}
			else if (byNum[i] == '1'){
				add *= 1;
			}
			num += add;
		}
	}
	int decimal = num;
	cout << "\n\tDecimal: " << decimal << endl; 
	cout << "\tBinary: 0x0";
	PrintBinary(decimal);
	cout << endl;
	cout << "\tHexadecimal: 0x0" << hex << decimal << dec <<endl;

}









