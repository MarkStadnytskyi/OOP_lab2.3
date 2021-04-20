#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class CharLine
{
private:
	int N;
	char* s;

public:
	bool setN(int value);
	void setS(char* value);
	int getN() const { return N; };
	char* getS() const { return s; };

	bool Init(int N);
	void Read(int N);
	void Display() const;
	void DisplaySn(int i) const;
	bool CheckChar(char ch) const;
	friend CharLine Ñoncatenation(const CharLine& s1, const CharLine& s2);
	friend bool CompareStr(const CharLine& s1, const CharLine& s2);
	bool CheckSubStr(string search) const;
	string toString() const;

	CharLine();
	CharLine(const char* s);
	CharLine(const char* s, int N);
	CharLine(const CharLine& c);
	~CharLine();

	CharLine& operator --();
	CharLine& operator ++();
	CharLine operator --(int);
	CharLine operator ++(int);

	friend ostream& operator <<(ostream& out, const CharLine& c);
	friend istream& operator >>(istream& in, CharLine& c);

	CharLine& operator =(const CharLine& c);
	operator string() const;

};
