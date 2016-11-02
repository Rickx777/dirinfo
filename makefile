dirstats: main.c
	gcc main.c -o dirstats

run: dirstats
	./dirstats

clean:
	rm *~
