#!/bin/bash

cd ~/p1.2015s1/homework07/working_copy/

rm ~/p1.2015s1/homework07/working_copy/q02/hw07q01.c
rm ~/p1.2015s1/homework07/working_copy/q02/hw07q02.c
rm ~/p1.2015s1/homework07/working_copy/q03/hw07q03.c
rm ~/p1.2015s1/homework07/working_copy/q04/hw07q04.c
rm ~/p1.2015s1/homework07/working_copy/q05/hw07q05.c
rm ~/p1.2015s1/homework07/working_copy/q02/hw07q05.test.c
rm ~/p1.2015s1/homework07/working_copy/q06/hw07q06.c
rm ~/p1.2015s1/homework07/working_copy/q02/hw07q07.c

wget http://www.chadhao.com/sherry/homework07/hw07q01.c
wget http://www.chadhao.com/sherry/homework07/hw07q02.c
wget http://www.chadhao.com/sherry/homework07/hw07q03.c
wget http://www.chadhao.com/sherry/homework07/hw07q04.c
wget http://www.chadhao.com/sherry/homework07/hw07q05.c
wget http://www.chadhao.com/sherry/homework07/hw07q05.test.c
wget http://www.chadhao.com/sherry/homework07/hw07q06.c
wget http://www.chadhao.com/sherry/homework07/hw07q07.c

cp hw07q01.c ~/p1.2015s1/homework07/working_copy/q01/
cp hw07q02.c ~/p1.2015s1/homework07/working_copy/q02/
cp hw07q03.c ~/p1.2015s1/homework07/working_copy/q03/
cp hw07q04.c ~/p1.2015s1/homework07/working_copy/q04/
cp hw07q05.c ~/p1.2015s1/homework07/working_copy/q05/
cp hw07q05.test.c ~/p1.2015s1/homework07/working_copy/q05/
cp hw07q06.c ~/p1.2015s1/homework07/working_copy/q06/
cp hw07q07.c ~/p1.2015s1/homework07/working_copy/q07/

cd ~/p1.2015s1/homework07/working_copy/q01/
make
cd ~/p1.2015s1/homework07/working_copy/q02/
make
cd ~/p1.2015s1/homework07/working_copy/q03/
make
cd ~/p1.2015s1/homework07/working_copy/q04/
make
make test
cd ~/p1.2015s1/homework07/working_copy/q05/
make
make test
cd ~/p1.2015s1/homework07/working_copy/q06/
make
cd ~/p1.2015s1/homework07/working_copy/q07/
make

cd ~/p1.2015s1/homework07/working_copy/
rm hw07q0*.c

