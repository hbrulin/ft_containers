#!/bin/sh

echo "TESTER LISTS" >> output
make list && ./test >> output
echo "\n" >> output

echo "TESTER VECTOR" >> output
make vector && ./test >> output
echo "\n" >> output

echo "TESTER STACK" >> output
make stack && ./test >> output
echo "\n" >> output

echo "TESTER QUEUE" >> output
make queue && ./test >> output
echo "\n" >> output

echo "TESTER MAP" >> output
make map && ./test >> output
echo "\n" >> output

make fclean