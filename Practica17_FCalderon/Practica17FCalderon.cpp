// Practica17FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <tuple>
#include <cassert>

#define DECLARE_ENUM_VALUE_ACTION(_ENUM) _ENUM, 

#define ENUM_TO_STRING_ACTION(_ENUM) \
if (_eState == Enum::_ENUM) \
{ \
	return #_ENUM; \
}

#define STRING_TO_ENUM_ACTION(_STRING) \
if (strcmp(_sEnum, #_STRING) == 0) \
{ \
	return Enum::_STRING; \
}

#define DECLARE_ENUM(_NAME, _LIST) \
struct _NAME \
{ \
	enum Enum \
	{ \
		Invalid = -1, \
		_LIST(DECLARE_ENUM_VALUE_ACTION) \
		Count \
	}; \
	static const char* ToString(Enum _eState) \
	{ \
		_LIST(ENUM_TO_STRING_ACTION) \
		assert(false); \
		return "Invalid"; \
	} \
	static Enum ToEnum(const char* _sEnum) \
	{ \
		_LIST(STRING_TO_ENUM_ACTION) \
		assert(false); \
		return Enum::Invalid; \
	} \
}

#define STATE_ENUM_DEFINITION_LIST(_CALL) \
	_CALL(Idle) \
	_CALL(Chase) \
	_CALL(Attacking) \
	_CALL(Cover)



class Enemy
{
public:
DECLARE_ENUM(SState, STATE_ENUM_DEFINITION_LIST);
	
};

int main()
{
	//Enum eEnum = SState::ToEnum("Chase");

	printf("%s\n", Enemy::SState::ToString(Enemy::SState::Idle));
	printf("%s\n", Enemy::SState::ToString(Enemy::SState::Chase));
	printf("%s\n", Enemy::SState::ToString(Enemy::SState::Attacking));
}