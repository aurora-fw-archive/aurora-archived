```cpp
#include <iostream>
using namespace std;

bool isNumber(const string& str)
{
	bool __tmp = false;
  	for( char c : str )
  	{
    	if(c=='.' && !__tmp) __tmp = true;
    	else if(!isdigit(c)) return false;
  	}
  	return true;
}

bool isInteger(const string& str)
{
	bool __tmp = false;
  	for( char c : str )
  	{
    	if(c=='.' || !isdigit(c)) return false;
  	}
  	return true;
}

 
int main(int argc, char * argv[])
{
	cout << isInteger("13") << endl;
    cout << isInteger("hi") << endl;
    cout << isInteger("12a") << endl;
    cout << isNumber("123.4.3") << endl;
    cout << isNumber("1.3") << endl;
    cout << isInteger("1.2") << endl;
}
```