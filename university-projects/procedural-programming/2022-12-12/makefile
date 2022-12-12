main: main.c test.c functions.c
	gcc -o main main.c functions.c -I.
	.\main
	
test: test.c functions.c
	gcc -o test test.c functions.c -I.
	test.exe < tests/make_list_test.txt > tests/dump.txt