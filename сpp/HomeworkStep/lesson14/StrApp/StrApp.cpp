#include <iostream>
using namespace std;

int main()
{
//1.Дана строка.Разрежьте ее на две равные части
//(если длина строки — четная, а если длина строки
//    нечетная, то длина первой части должна быть на
//    один символ больше).Переставьте эти две части
//    местами, результат запишите в новую строку и
//    выведите на экран.
	string d, f, rez;
	string s = "asdasdasdasdasdaa";
	cout << s << endl;
	cout << s.size()<<endl;
	f = s.substr(0, s.size() / 2);
	d = s.substr(f.size(), s.size());
	rez = d + " " + f;
	cout << rez << endl;
	rez = "";
	rez.insert(0, d);
	rez.insert(rez.size(), f);
	cout << rez << endl;
//    2.Дана строка, состоящая ровно из двух слов,
//    разделенных пробелом.Переставьте эти слова
//    местами.Результат запишите в строку и выведите
//    получившуюся строку.
	s = "Hello World";
	cout << s << endl;
	cout << s.find(" ") << endl;
	f = s.substr(0, s.find(" "));
	d = s.substr(s.find(" ")+1, s.size());
	rez = d + " " + f;
	cout << rez << endl;
//    3.Дана строка.Если в этой строке буква f
//    встречается только один раз, выведите её индекс.
//    Если она встречается два и более раз, выведите
//    индекс её первого и последнего появления.Если
//    буква f в данной строке не встречается, ничего
//    не выводите.
	 s = "ind find find";
	 cout << s << endl;
	 if (s.find("f") == -1)
	 {
		cout << "f not found" << endl;
	 }
	 else if (s.find("f") != s.rfind("f"))
	 {
		 cout << s.find("f") << endl;
		 cout << s.rfind("f") << endl;
	 }
	 else 
	 {
		 cout << s.find("f") << endl;
	 }
	 //    4.Дана строка.Найдите в этой строке второе
	 //    вхождение буквы f, и выведите индекс этого
	 //    вхождения.Если буква f в данной строке
	 //    встречается только один раз, выведите число - 1,
	 //    а если не встречается ни разу, выведите число - 2
	 s = "ind find indfind find";
	 cout << s << endl;
	 if (s.find("f") == -1)
	 {
		 cout << "2" << endl;
	 }
	 else if (s.find("f") == s.rfind("f"))
	 {
		 cout << "1" << endl;
	 }
	 else if (s.find("f") != -1)
	 {
		 cout << s.find_first_of("f", s.find("f")+1) << endl;
	 }
	 //    5.Дана строка, в которой буква h встречается
//    минимум два раза.Удалите из этой строки первое
//    и последнее вхождение буквы h, а также все
//    символы, находящиеся между ними.
	 s = "gdsfsdfhsdfsdfhsdfsdhdsfas";
	 cout << s << endl;
	 s.erase(s.begin() + s.find("h"), s.end() - (s.size() - s.rfind("h")-1));
	 cout << s << endl;
}