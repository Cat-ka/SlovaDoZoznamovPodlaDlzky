#pragma once
class Slovo //uloha 2
{
	char * aSlovo = nullptr;
public:
	Slovo(char * pSlovo) { aSlovo = pSlovo; };
	~Slovo() { delete[] aSlovo; };
	char * getSlovo() { return aSlovo; };
};

