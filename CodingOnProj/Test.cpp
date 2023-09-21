#include <iostream>
#include <cstdint>
using namespace std;

enum SkillType
{
	ST_STUN = 0b00000001,
	ST_POISON = 0b00000010,
	ST_IMMORTAL = 0b00000100,
	ST_SILENCE = 0b00001000,
	ST_PORTIONSILENCE = 0b0010000,
	ST_HELLFIRE = 0b00100000,
	ST_UNDEAD = 0b01000000,

};
int main()
{

	int8_t a = 0b00000001;
	uint8_t b = 0b000;
	uint8_t c = ~b;

	cout << static_cast<int>(c);
	



	
	




}

