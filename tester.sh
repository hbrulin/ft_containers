#!/bin/sh

rm output.txt

echo "#!#!#!#! LISTS #!#!#!#!" >> output.txt
echo "\n" >> output.txt
make list && ./test >> output.txt
echo "\n" >> output.txt
echo "-------------------------------------------------" >> output.txt
echo "\n" >> output.txt

echo "#!#!#!#! VECTORS  #!#!#!#!" >> output.txt
echo "\n" >> output.txt
make vector && ./test >> output.txt
echo "\n" >> output.txt
echo "-------------------------------------------------" >> output.txt
echo "\n" >> output.txt

echo "#!#!#!#! STACKS #!#!#!#!" >> output.txt
echo "\n" >> output.txt
make stack && ./test >> output.txt
echo "\n" >> output.txt
echo "-------------------------------------------------" >> output.txt
echo "\n" >> output.txt

echo "#!#!#!#! QUEUES #!#!#!#!" >> output.txt
echo "\n" >> output.txt
make queue && ./test >> output.txt
echo "\n" >> output.txt
echo "-------------------------------------------------" >> output.txt
echo "\n" >> output.txt

echo "#!#!#!#! MAPS #!#!#!#!" >> output.txt
echo "\n" >> output.txt
make map && ./test >> output.txt
echo "\n" >> output.txt
echo "-------------------------------------------------" >> output.txt
echo "\n" >> output.txt

make fclean 