#pragma once
#include "racionalis.h"

class bit
{
	private:
		bool value;
	public:
		bit(bool v);
		bit(int v);
		bit(racionalis v);
		bool GetValue();
		int GetIntValue();
		void SetValue (bool v);

		/*
		& - �S
		| - VAGY
		~ - NEG�L�S
		^ - KIZ�R� VAGY
		*/
		bit operator&(bit b);
		bit operator|(bit b);
		bit operator~();
		bit operator^(bit b);
};

// bit b =
// bit cel = ~b;