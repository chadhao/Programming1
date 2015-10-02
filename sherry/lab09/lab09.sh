#!/bin/bash

cd ~/p1.2015s1/lab09/working_copy/

rm ~/p1.2015s1/lab09/working_copy/ex03/lab09ex03.c
rm ~/p1.2015s1/lab09/working_copy/ex04/lab09ex04.c

wget http://www.chadhao.com/sherry/lab09/lab09ex03.c
wget http://www.chadhao.com/sherry/lab09/lab09ex04.c

cp lab09ex03.c ~/p1.2015s1/lab09/working_copy/ex03/
cp lab09ex04.c ~/p1.2015s1/lab09/working_copy/ex04/

cd ~/p1.2015s1/lab09/working_copy/ex03/
make
./lab09ex03
cd ~/p1.2015s1/lab09/working_copy/ex04/
make
./lab09ex04 3 Hello 5 Programming 2 Students! 10 :-\)

cd ~/p1.2015s1/lab09/working_copy/
rm lab09ex0*.c