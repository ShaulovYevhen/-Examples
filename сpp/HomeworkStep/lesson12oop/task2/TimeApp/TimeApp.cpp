#include <iostream>
#include "Time.h"

int main()
{
    Time t1(1, 2, 3);
    Time t2(23, 0, 0);
    Time t3;

    t2.Show();
    t1.Show();
    cout << t2.timeToSeconds(t2)<<endl;
    t3=t2+t1;
    t3.Show();
    t3 = t2 - t1;
    t3.Show();
    t3 = t2 + 1000;
    t3.Show();
    t3 = t2 - 1000;
    t3.Show();
    t2++;
    ++t2;
    t2.Show();
    t2--;
    --t2;
    --t2;
    t2.Show();
    cout << (t1 > t2) << endl;
    cout << (t1 < t2) << endl;
    cout << (t1 == t2) << endl;
    cout << (t1 >= t2) << endl;
    cout << (t1 <= t2) << endl;
    cout << (t1 != t2) << endl;
}

