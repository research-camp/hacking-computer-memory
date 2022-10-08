compile:
	gcc -o main code/main.c

run: compile
	./main 123456789