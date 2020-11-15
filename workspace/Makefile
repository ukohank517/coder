open :
	code .
test:
	[ -f myApp ] && rm myApp # remove myApp if it exists

clean:
	rm ./*

r:
	rm -rf backup
	mkdir backup
	[-f a.cpp] && cp a.cpp backup/a.cpp
	[-f b.cpp] && cp b.cpp backup/b.cpp
	[-f c.cpp] && cp c.cpp backup/c.cpp
	[-f d.cpp] && cp d.cpp backup/d.cpp
	[-f e.cpp] && cp e.cpp backup/e.cpp
	[-f f.cpp] && cp f.cpp backup/f.cpp
	cp ../library/temp_at.cpp a.cpp
	cp ../library/temp_at.cpp b.cpp
	cp ../library/temp_at.cpp c.cpp
	cp ../library/temp_at.cpp d.cpp
	cp ../library/temp_at.cpp e.cpp
	cp ../library/temp_at.cpp f.cpp
	rm a.out *~ *#*

a:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration a.cpp 
	./a.out
b:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration b.cpp
	./a.out
c:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration c.cpp
	./a.out
d:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration d.cpp
	./a.out
e:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration e.cpp
	./a.out

