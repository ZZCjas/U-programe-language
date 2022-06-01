#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;
void out()
{
	string s;
	cin>>s;
	cout<<s;
}
void end()
{
	cout<<endl;
}
void cmd()
{
	string s;
	cin>>s;
	system(s.c_str());
}
void bell()
{
	cout<<'\a';
}
char* File(const char* filename)
{
	char* text;
	FILE *pf = freopen(filename,"r",stdin);
	fseek(pf,0,SEEK_END);
	long lSize = ftell(pf);
	text=(char*)malloc(lSize+1);
	rewind(pf); 
	fread(text,sizeof(char),lSize,pf);
	text[lSize] = '\0';
	freopen("CON","r",stdin);
	return text;
}
void f_r()
{
	string s;
	cin>>s;
	cout<<File(s.c_str())<<endl;
}
void del()
{
	string s;
	cin>>s;
	remove(s.c_str());
}
int pause()
{
	return getch();
}
void color(int x)
{
	if(x>=0 && x<=15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
string s;
string p;
int re;
int main(int argc,char**argv)
{
	if(argc==2)
	{
		freopen(argv[1],"r",stdin);
	}
	else
	{
		cout<<"Please input the path of the source code:\n";
		cin>>p;
		freopen(p.c_str(),"r",stdin);
	}
	for(register long long i=1;;i++)
	{
		s="";
		cin>>s;
		if(s=="remove")
		{
			del();
		}
		else if(s=="print")
		{
			out();
		}
		else if(s=="endl")
		{
			end(); 
			continue;
		}
		else if(s=="cmd")
		{
			cmd();
		}
		else if(s=="bell")
		{
			bell();
		}
		else if(s=="file_read")
		{
			f_r();
		}
		else if(s=="pause")
		{
			pause();
		}
		else if(s=="color")
		{
			int z;
			cin>>z;
			color(z);
		}
		else if(s=="return")
		{
			cin>>re;
			break;
		}
		else if(s[0]!='/'&&s[1]!='/')
		{
			color(4);
			cout<<"Syntax error in line "<<i<<endl;
			color(7);
			break;
		}
	}
	color(7);
	cout<<endl;
	cout<<"--------------------------------\n";
	cout<<"Process exited with return value "<<re<<endl<<"Press any key to continue. . .";
	getch();
	return 0;
}
