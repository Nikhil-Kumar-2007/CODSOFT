#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

void calculate ( float num1, float num2, char op )
{  
   float ans;
   switch ( op )
   {
    case '+':
    	ans = num1 + num2;
    	cout << "addition of " << num1 << " and " << num2 << " is : " << ans;
    	break;
    case '-': 
    	ans = num1 - num2;
    	cout << "subtraction of " << num1 << " and " << num2 << " is : " << ans;
    	break;
    case '*':
    	ans = num1 * num2;
    	cout << "multiplication of " << num1 << " and " << num2 << " is : " << ans;
    	break;	
    case '/':
    	if(num2 == 0) 
    	{
    		cout << "division is not possible!!";
    		break;
    	}
    	ans = num1 / num2;
    	cout << num1 << " divide by " << num2 << " is : " << ans;
    	break;
    case '%':
    	if(num2 == 0) 
    	{
    		cout << "division is not possible!!";
    		break;
    	}
    	ans = int(num1) % int(num2);
    	cout << num1 << " is divide by " << num2 << " then remainder is : " << ans;
        break;
    case '^':
     	ans = pow(num1, num2);
    	cout << num1 << " raise to " << num2 << " is : " << ans;
        break;	
    default:
        cout << "operator is wrong!!";
        break;	
   }
	return;
}

int main ()
{
	system("cls");
	float num1, num2, ans;
	char op;
	cout << endl << "Enter first number : ";
	cin >> num1;
	cout << endl << "Enter second number : ";
	cin >> num2;
	cout << endl << "Enter operator(+,-,*,/,%,^) : ";
	cin >> op;
	cout << endl;
	calculate ( num1, num2, op );
	cout << endl << endl;
	Sleep(3000);
	system("cls");
	return 0;
}