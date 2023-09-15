#include <string>

void storeByValue(std::string s)
{
	std::string b = s;
};

void storeByLRef(std::string& s)
{
	std::string b = s;
};

void storeByRRef(std::string&& s)
{
	// std::string b = s; // wrong! s를  다시 지칭할수있기때문에 잘못된거야
	 std::string b = std::move(s); 

}
int main()
{
	std::string a = "abc";
	storeByValue(a);
	storeByLRef(a);
	storeByRRef(std::move(a));  
	storeByRRef("abc");
}



#include <iostream>
#include <string>


class Cat
{
public:
	/*void setName(std::string name)
	{
		mName = name;
	};*/
	void setName(std::string && name)
	{
		mName = name;
	};

private:
	std::string mName;
};

int main()
{
	//std::string a = "nocodingprogram";
	//std::cout << "a:" << a << std::endl; //nocodingprogram

	//std::string b = std::move(a);
	//std::cout << "b:" << b << std::endl; //nocodingprogram
	//std::cout << "a:" << a << std::endl; //""


	Cat kitty;
	std::string s = "kitty";
	kitty.setName(s); // l value / 2copy
	kitty.setName("nabi"); // r value 
	
	// 어느게 더 효율적일까?

}