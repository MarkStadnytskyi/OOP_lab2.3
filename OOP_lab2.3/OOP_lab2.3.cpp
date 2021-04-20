#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "CharLine.h"

int main()
{
	cout << " : Lab 2.3 - Output : ";

	cout << " : constructors : " << endl;
	cout << "CharLine *a0 = new CharLine(); : " << endl;
	CharLine* a0 = new CharLine();
	cout << " a0 : " << (*a0) << endl;
	cout << "CharLine a1; : " << endl;
	CharLine a1;
	cout << " a1 : " << a1 << endl;
	cout << "CharLine a2(\"abc\"); : " << endl;
	CharLine a2("abc");
	cout << " a2 : " << a2 << endl;
	cout << "CharLine e(\"abcde\", 5); : " << endl;
	CharLine e("abcde", 5);
	e.Display();
	cout << " e : " << e << endl;
	cout << "CharLine d(e); : " << endl;
	CharLine d(e);
	d.Display();
	cout << " d : " << d << endl;
	cout << endl;

	cout << " : operator increment/decrement : " << endl;
	cout << "++e : " << ++e << endl;
	cout << " e : " << e << endl;
	cout << " e++ : " << e++ << endl;
	cout << " e : " << e << endl;
	cout << "--e : " << --e << endl;
	cout << " e : " << e << endl;
	cout << " e-- : " << e-- << endl;
	cout << " e : " << e << endl;
	cout << endl;

	cout << " : operator Type() : " << endl;
	cout << "string(e) : " << endl << string(e) << endl;
	cout << "e.toString() : " << endl << e.toString() << endl;
	cout << endl;

	cout << " : operator input/output : " << endl;
	CharLine g1, g2, g3;
	cin >> g1 >> g2 >> g3;
	cout << g1 << g2 << g3 << endl;

	cout << " : operator = : " << endl;
	g3 = g2 = d;
	cout << " g3 : " << d << endl;
	cout << " g2 : " << d << endl;
	cout << " d : " << d << endl;
	cout << endl;

	cout << " : Size = " << sizeof(e) << endl;

	system("pause");

	cout << " : Lab 1.3 - Output : " << endl;

	CharLine c;
	int N;
	cout << "Enter N : ";
	cin >> N;
	c.Read(N);
	c.Display();
	cout << "toString() = " << endl << c.toString();

	c.DisplaySn(2);

	char ch;
	cout << "Enter symbol for test : ";
	cin >> ch;
	cout << "Symbol '" << ch << "' "
		<< (c.CheckChar(ch) ? "exists" : "not exist")
		<< " in the String \"" << c.getS() << "\"" << endl;

	CharLine c2;
	c2.Read(5);
	cout << " Concatenation strings : " << Сoncatenation(c, c2).getS() << endl;

	cout << " Strings '" << c.getS() << "' and '" << c2.getS() << "' are "
		<< (CompareStr(c, c2) ? "" : "not ")
		<< "equal" << endl;

	cout << " Substring '" << c2.getS() << "' is "
		<< (c.CheckSubStr(c2.getS()) ? "" : "not ")
		<< "found in the String '" << c.getS() << "'" << endl;

	system("pause");

	return 0;
}
