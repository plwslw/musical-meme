pid: pid.c
	gcc -o pid pid.c

clean: 
	rm pid
	rm *~

run: pid 
	./pid
