
#include "year.h"
#include "login.h"
using namespace std;
int main()
{
    LinkedList<Year> ListYear;
    login(ListYear);
    deleteAll(ListYear);
}

/*
2021
1
CS162
introduce to CS1
Dinh Ba Tien
4
MON
S1
TUE
S2
1
CM101
comunication M
Duong Nguyen Vu
4
MON
S3
TUE
S4
2
1
21CTT1
1
21CTN1
2
21CTT1
1
1
21CTT1
*/

/*

1
CS162
Intro to CS 2
Dinh Ba Tien
4
TUE
S1
SAT
S1

1
MTH252
Calculus2
Nguyen Huu Anh
4
TUE
S2
THU
S2

1
PH212
General Physics 2
Nguyen Huu Nha
4
WED
S3
THU
S3

1
BAA00001
Intro to Laws
NN Phuong Hong
2
TUE
S3
TUE
S4

1
BAA00102
Economics
Ngo Tuan Phuong
2
WED
S1
WED
S2

1
BAA00101
Philosophy
Ngo Quang Huy
2
TUE
S1
TUE
S2

1
PH251
General Physics 1
Vu Thi Hanh Thu
4
FRI
S1
SAT
S3

1
MTH251
Calculus 1
Nguyen Huu Anh
4
FRI
S1
SAT
S4




*/