#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

void appearance ();
void banner ();
void callChoice (int &choice);
void addTask (int &no, int choice);
void showTask ();
void searchTask(int no);
void deleteTask(int &no);
void updateTask (int no);
void markTask (int no);
string replaceWord(string& str, string& oldWord, string& newWord);

class Todolist
{
private:
	int no = 0;
    string task;
public:
	Todolist ()
	{}
	Todolist (string task)
	{
		this->task = task;
		no++;
	}
	void setNo (int x)
	{
		no = x;
	}
	int giveNo ()
	{
		return no;
	}
	void setTask (string s)
	{
		task = s;
	}
	string giveTask ()
	{
		return task;
	}
};

int main ()
{
	int choice;
	system("color 6A"); 
	while (true)
	{
        callChoice(choice);
        banner();   
        char exit;
        cout << "\n\nAre you want to return from home screen(y/n)? : ";
        cin >> exit;
        if (exit == 'y')
        {
        	break;
        }                                   
	}
	Sleep(800);
	system("cls");
	return 0;	
}

void appearance ()
{
	system("cls");
	cout << "\n\n================================================";
	cout << "\n\t\t  To Do List\n";
	cout << "================================================\n\n";
}

void banner ()
{
	appearance ();
	cout << "\n\t\t(1) Add task ";
	cout << "\n\t\t(2) Show task ";
	cout << "\n\t\t(3) Search task ";
	cout << "\n\t\t(4) Delete task ";
	cout << "\n\t\t(5) Update task ";
	cout << "\n\t\t(6) Mark as complete ";
}

void callChoice (int &choice)
{
	banner();
	cout << "\n\n\nEnter your choice - ";
	cin >> choice;
	int no = 0;
    ifstream fin;
    fin.open("todo.txt");
	if(fin)
	{
		string st;
	    while (!fin.eof())
	    {
		    fin >> no;
			fin.ignore();
			getline(fin,st);
	    }
	}
    while (!fin.eof()) 
	{
		int x;
		fin >> x;
		no = x; 
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    fin.close();
	switch (choice)
	{
	case 1:
		addTask(no, choice);
		break;
	case 2:
		showTask();
		break;
	case 3:
		searchTask(no);
		break;
	case 4:
		deleteTask(no);
		break;
	case 5:
		updateTask(no);
		break;
	case 6:
		markTask(no);
		break;
	default:
		cout << "\n\nyou entered wrong choice !!\n\n";
		Sleep(800);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		callChoice(choice);
	}
}

void addTask(int &no, int choice)
{
	system("cls");
	appearance ();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string task;
	cout << "\n\nEnter a task : ";
	getline(cin,task);
    Todolist todo(task);
    char save;
    cout << "\n\nIs you want to save the task (y/n)? : ";
    cin >> save;
    if (save == 'y')
    {
		no++;
    	ofstream fout;
    	fout.open("todo.txt", ios::app);
		todo.setNo(no);
    	fout << todo.giveNo() << endl;
    	fout << todo.giveTask() << "     [ NOT COMP ]" << endl;
    	fout.close();
    	char more;
    	cout << "\n\nAre you want to add more task (y/n)? : ";
    	cin >> more;
    	if (more == 'y')
    	{
    		addTask(no, choice);
    	}
    	else 
    	{
    		cout << "\n\nTask added successfully !!";
			Sleep(800);
			system("cls");
    		return;
    	}
    }
	else 
    {
		cout << "\n\nTask can not be added !!";
    	Sleep(800);
		system("cls");
		return;
	}
}

void showTask ()
{
	system("cls");
	appearance();
	bool flag = true;
	Todolist todo;
	ifstream fin;
	fin.open("todo.txt");
	cout << "Task : \n";
	while (!fin.eof())
	{
		int x;
		fin >> x;
		todo.setNo(x);
		fin.ignore();
		string s;
		getline(fin,s);
		todo.setTask(s);
		if (todo.giveTask() != "")
		{
			flag = false;
			cout << "\t( " << todo.giveNo() << " ) - " << todo.giveTask() << endl; 
		}
		else if (flag == true)
		{
			cout << "\n\nlist is empty !!\n\n";
		}
	}
    fin.close(); 
    char exit;
    cout << "\n\nAre you want to exit (y/n)? : ";
    cin >> exit;
    if (exit != 'y')
    {
    	showTask();
    }
    system("cls");
    return;
}

void searchTask(int no)
{
	system("cls");
	appearance();
	int target;
	cout << "\n\nEnter task number you want to search : ";
    cin >> target;
	Todolist todo;
	ifstream fin;
    fin.open("todo.txt");
	cin.clear();
	cin.ignore();
	target = (int)target;
	if ( target > 0 && target <= no)
    { 
		while (!fin.eof()) 
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			if(target == todo.giveNo())
			{
				cout << endl << endl << todo.giveTask();
			}
		}
		fin.close(); 
		char exit;
		cout << "\n\nAre you want to exit (y/n)? : ";
		cin >> exit;
		if (exit != 'y')
		{
			searchTask(no);
		}
	}
	 else
    {
    	cout << "\n\ntask is not added at this number !!\n\n";
		Sleep(800);
		system("cls");
		char exit;
		cout << "\n\nAre you want to exit (y/n)? : ";
		cin >> exit;
		if (exit != 'y')
		{
			searchTask(no);
		}
    }
	cin.clear();
    return;
}

void deleteTask(int &no)
{
	system("cls");
	int target;
	cout << "\n\nEnter task number you want to delete : ";
	cin >> target;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\n\nEnter task in number !!";
		Sleep(800);
		system("cls");
		appearance();
		char ex;
		cout << "\n\nAre you want to exit (y/n)? : ";
		cin >> ex;
		if (ex != 'y')
		{
			deleteTask(no);
		}	
        else
		    return;
	}
	Todolist todo;
	ifstream fin;
    fin.open("todo.txt");
	if ( target > 0 && target <= no)
	{
		ofstream fout;
	    fout.open("temp.txt");
		int i = 1;
		while(i != target)
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		int z;
		fin >> z;
		cout << "\n\nTask : " << endl;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		string s;
		getline(fin,s);
		todo.setTask(s);
		cout << "\t" << todo.giveTask();
		char check;
		cout << "\n\nAre you want to sure to delete task (y/n)?: ";
		cin >> check;
		if (check != 'y')
	    {
			cout << "\n\nTask can not be deleted !!";
		    system("cls");
			appearance();
			char ex;
		    cout << "\n\nAre you want to exit (y/n)? : ";
		    cin >> ex;
		    if (ex != 'y')
		    {
		    	deleteTask(no);
		    }	
		    return;
	    }
		while (i < no)
		{
			int x;
			fin >> x;
			todo.setNo(x-1);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		fin.close();
		fout.close();
		remove("todo.txt");
		rename("temp.txt", "todo.txt");
	    cout << "\n\ntask is deleted successfully !!";
		no--;
	}
	else
	{
		fin.close();
		cout << "\n\nTask is not found in the list !!";
	}
	Sleep(800);
	system("cls");
	char exit;
	cout << "\n\nAre you want to exit (y/n)? : ";
	cin >> exit;
	if (exit != 'y')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		deleteTask(no);
	}
	return;
}

void updateTask(int no)
{
	system("cls");
	appearance();
	int target;
	cout << "\n\nEnter task number you want to update : ";
	cin >> target;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\n\nEnter task in number !!";
		Sleep(800);
		system("cls");
		appearance();
		char ex;
		cout << "\n\nAre you want to exit (y/n)? : ";
		cin >> ex;
		if (ex != 'y')
		{
			deleteTask(no);
		}	
        else
		    return;
	}
	Todolist todo;
	ifstream fin;
    fin.open("todo.txt");
	if ( target > 0 && target <= no)
	{
		ofstream fout;
	    fout.open("temp.txt");
		int i = 1;
		while(i != target)
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		int z;
		fin >> z;
		todo.setNo(z);
		fout << todo.giveNo() << endl;
		cout << "\n\nTask : " << endl;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		string s;
		getline(fin,s);
		todo.setTask(s);
		cout << "\t" << todo.giveTask();
		string new_str;
		cout << "\n\nEnter new task : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin,new_str);
		todo.setTask(new_str);
		fout << todo.giveTask() << "     [ NOT COMP ]" << endl;
		char check;
		cout << "\n\nAre you want to sure to update task (y/n)?: ";
		cin >> check;
		if (check != 'y')
	    {
			cout << "\n\nTask can not be updated !!";
		    system("cls");
			appearance();
			char ex;
		    cout << "\n\nAre you want to exit (y/n)? : ";
		    cin >> ex;
		    if (ex != 'y')
		    {
		    	updateTask(no);
		    }	
		    return;
	    }
		i++;
		while (i <= no)
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		fin.close();
		fout.close();
		remove("todo.txt");
		rename("temp.txt", "todo.txt");
	    cout << "\n\ntask is updated successfully !!";
	}
	else
	{
		fin.close();
		cout << "\n\nTask is not found in the list !!";
	}
	Sleep(800);
	system("cls");
	char exit;
	cout << "\n\nAre you want to exit (y/n)? : ";
	cin >> exit;
	if (exit != 'y')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		updateTask(no);
	}
	return;
}

void markTask (int no)
{
	system("cls");
	appearance();
	int target;
	cout << "\n\nEnter task number you want to mark as completed : ";
	cin >> target;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\n\nEnter task in number !!";
		Sleep(800);
		system("cls");
		appearance();
		char ex;
		cout << "\n\nAre you want to exit (y/n)? : ";
		cin >> ex;
		if (ex != 'y')
		{
			markTask(no);
		}	
        else
		    return;
	}
	Todolist todo;
	ifstream fin;
    fin.open("todo.txt");
	if ( target > 0 && target <= no)
	{
		ofstream fout;
	    fout.open("temp.txt");
		int i = 1;
		while(i != target)
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		int z;
		fin >> z;
		todo.setNo(z);
		fout << todo.giveNo() << endl;
		cout << "\n\nTask : " << endl;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		string s;
		getline(fin,s);
		cout << "\t" << s;
		string s1 =  "     [ NOT COMP ]" ;
		string s2 =  "     [  COMP ]" ;
		s = replaceWord(s, s1, s2);
        todo.setTask(s);
		fout << todo.giveTask() << endl;
		char check;
		cout << "\n\nAre you want to sure to mark task as completed (y/n)?: ";
		cin >> check;
		if (check != 'y')
	    {
			cout << "\n\nTask can not marked as completed !!";
		    system("cls");
			appearance();
			char ex;
		    cout << "\n\nAre you want to exit (y/n)? : ";
		    cin >> ex;
		    if (ex != 'y')
		    {
		    	markTask(no);
		    }	
		    return;
	    }
		i++;
		while (i <= no)
		{
			int x;
			fin >> x;
			todo.setNo(x);
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			string s;
			getline(fin,s);
			todo.setTask(s);
			fout << todo.giveNo() << endl;
			fout << todo.giveTask() << endl;
			i++;
		}
		fin.close();
		fout.close();
		remove("todo.txt");
		rename("temp.txt", "todo.txt");
	    cout << "\n\ntask is marked as completed successfully !!";
	}
	else
	{
		fin.close();
		cout << "\n\nTask is not found in the list !!";
	}
	Sleep(800);
	system("cls");
	char exit;
	cout << "\n\nAre you want to exit (y/n)? : ";
	cin >> exit;
	if (exit != 'y')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		markTask(no);
	}
	return;
}

string replaceWord(string& str, string& oldWord, string& newWord) 
{
    string result = str;
    size_t pos = result.find(oldWord);
    if (pos != string::npos) {
        result.replace(pos, oldWord.length(), newWord);
    }
    return result;
}