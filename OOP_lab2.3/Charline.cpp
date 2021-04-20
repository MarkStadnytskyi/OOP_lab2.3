#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "CharLine.h"

CharLine::CharLine()
{
	setN(0);
	int _N = getN() + 1;
	char* _s = new char[_N];
	strcpy(_s, "");
	setS(_s);
	delete[] _s;
}

CharLine::CharLine(const char* s)
{
	setN((int)strlen(s));
	int _N = getN() + 1;
	char* _s = new char[_N];
	strcpy(_s, s);
	setS(_s);
	delete[] _s;
}

CharLine::CharLine(const char* s, int N)
{
	setN(N);
	int _N = getN() + 1;
	char* _s = new char[_N];
	strcpy(_s, s);
	setS(_s);
	delete[] _s;
}

CharLine::CharLine(const CharLine& c)
{
	setN(c.getN()); setS(c.getS());
}

CharLine::~CharLine()
{
	delete[] s;
}

bool CharLine::setN(int value)
{
	if (value >= 0)
	{
		N = value;
		return true;
	}
	else
		return false;
}

void CharLine::setS(char* value)
{

	int _N = getN() + 1;
	s = new char[_N];
	strncpy(s, value, getN());
	s[getN()] = '\0';
}

bool CharLine::Init(int N)
{
	setN(N);
	stringstream sout;
	for (int i = 0; i < N; i++)
	{
		sout << " ";
	}
	int _N = getN() + 1;
	char* _s = new char[_N];
	strncpy(_s, sout.str().c_str(), getN());
	_s[getN()] = '\0';
	setS(_s);
	delete[] _s;
	return true;
}

void CharLine::Read(int N)
{
	Init(N);
	int _N = getN() + 1;
	char* _s = new char[_N];
	cout << "Input string : ";
	int i = 0;
	cin >> _s;
	_s[_N - 1] = '\0';
	setS(_s);
	delete[] _s;
}

void CharLine::Display() const
{
	cout << "Display : ";
	cout << getS() << endl;
}

void CharLine::DisplaySn(int i) const
{
	cout << endl << "Display s[" << i << "] : " << s[i - 1] << endl;
}

string CharLine::toString() const
{
	stringstream sout;
	sout << "	N : " << getN() << endl
		<< "	s : \"" << getS() << "\""
		;
	return sout.str();
}

bool CharLine::CheckChar(char ch) const
{
	return (strchr(s, ch) != NULL) ? true : false;
}

CharLine Сoncatenation(const CharLine& s1, const CharLine& s2)
{
	char* _s1 = s1.getS();
	char* _s2 = s2.getS();
	int _N = (int)strlen(_s1) + (int)strlen(_s2) + 1;
	char* resStr = new char[_N];
	strcpy(resStr, _s1);
	strcat(resStr, _s2);
	resStr[_N - 1] = '\0';
	CharLine r(resStr, _N - 1);
	delete[] resStr;
	return r;
}

bool CompareStr(const CharLine& s1, const CharLine& s2)
{
	stringstream sout1, sout2;
	sout1 << s1.getS();
	sout2 << s2.getS();
	return ((sout1.str().find(sout2.str()) > s1.getN()
		&& sout2.str().find(sout1.str()) > s2.getN()) ? false : true);
}

bool CharLine::CheckSubStr(string search) const
{
	stringstream sout1, sout2;
	sout1 << getS();
	return ((sout1.str()).find(search) > 0 ? false : true);
}


CharLine& CharLine::operator --() // префіксний декремент
{
	--N; // модифікували поточний об'єкт
	setS(getS());
	return *this; // повернули модифікований об'єкт
}

CharLine& CharLine::operator ++() // префіксний інкремент
{
	setN(getN() + 1);
	//++_N; // модифікували поточний об'єкт
	int _N = getN() + 1;
	char* resStr = new char[_N];
	strcpy(resStr, getS());
	strcat(resStr, " ");
	setS(resStr);
	delete[] resStr;
	return *this; // повернули модифікований об'єкт
}

CharLine CharLine::operator --(int) // постфіксний декремент
{
	CharLine a(*this); // створили копію
	N--; // модифікували поточний об'єкт
	setS(getS());
	return a; // повернули копію
}

CharLine CharLine::operator ++(int) // постфіксний інкремент
{
	CharLine a(*this); // створили копію
	setN(getN() + 1);
	//N++; // модифікували поточний об'єкт
	int _N = getN() + 1;
	char* resStr = new char[_N];
	strcpy(resStr, getS());
	strcat(resStr, " ");
	setS(resStr);
	delete[] resStr;
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const CharLine& c)
{
	return out << "	N : " << c.getN() << endl
		<< "	s : \"" << c.getS() << "\"" << endl;
}

istream& operator >>(istream& in, CharLine& c)
{
	int _N;
	cout << ".N = "; in >> _N;
	c.setN(_N);
	char* _s;
	_s = new char[++_N];
	cout << ".s = "; in >> _s;
	c.setS(_s);
	cout << endl;
	delete[] _s;
	return in;
}

CharLine& CharLine::operator =(const CharLine& c)
{
	// змінили поле поточного об’єкта
	setN(c.getN());
	setS(c.getS());
	return *this; // повернули посилання на поточний об’єкт
}

CharLine::operator string() const
{
	stringstream sout;
	sout << "	N : " << getN() << endl
		<< "	s : \"" << getS() << "\""
		;
	return sout.str();
}
