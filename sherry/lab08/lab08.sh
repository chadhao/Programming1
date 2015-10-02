#!/bin/bash

cd ~/p1.2015s1/lab08/working_copy/

rm ~/p1.2015s1/lab08/working_copy/ex02/lab08ex02.c
rm ~/p1.2015s1/lab08/working_copy/ex03/lab08ex03.c
rm ~/p1.2015s1/lab08/working_copy/ex04/lab08ex04.c
rm ~/p1.2015s1/lab08/working_copy/ex05/lab08ex05.c
rm ~/p1.2015s1/lab08/working_copy/ex06/lab08ex06.c

wget http://www.chadhao.com/sherry/lab08/lab08ex02.c
wget http://www.chadhao.com/sherry/lab08/lab08ex03.c
wget http://www.chadhao.com/sherry/lab08/lab08ex04.c
wget http://www.chadhao.com/sherry/lab08/lab08ex05.c
wget http://www.chadhao.com/sherry/lab08/lab08ex06.c

cp lab08ex02.c ~/p1.2015s1/lab08/working_copy/ex02/
cp lab08ex03.c ~/p1.2015s1/lab08/working_copy/ex03/
cp lab08ex04.c ~/p1.2015s1/lab08/working_copy/ex04/
cp lab08ex05.c ~/p1.2015s1/lab08/working_copy/ex05/
cp lab08ex06.c ~/p1.2015s1/lab08/working_copy/ex06/

cd ~/p1.2015s1/lab08/working_copy/ex02/
make
cd ~/p1.2015s1/lab08/working_copy/ex03/
make
cd ~/p1.2015s1/lab08/working_copy/ex04/
make
cd ~/p1.2015s1/lab08/working_copy/ex05/
make
cd ~/p1.2015s1/lab08/working_copy/ex06/
make

cd ~/p1.2015s1/lab08/working_copy/
rm lab08ex0*.c