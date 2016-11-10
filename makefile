pid: pid.c
	gcc -o pid pid.c

clean:
	rm log.txt
	rm pid
	rm *~

run: pid 
	./pid
