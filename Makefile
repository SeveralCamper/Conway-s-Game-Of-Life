all:bin/main

bin/main: obj/src/main.o obj/lib/geometrylib.a
	gcc obj/src/main.o -Wall -Werror -L. obj/lib/geometrylib.a -o $@

obj/src/main.o:src/main.c
	gcc -c src/main.c -Wall -Werror -o $@

run:
	./bin/main

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	rm bin/main
	rm bin/test

.PHONY: clean run all