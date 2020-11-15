open :
	code .

clean:
	ls | grep -v -E 'Makefile' | xargs rm -rf

r:
	rm -rf backup
	mkdir backup
	if [ -f a.cpp ]; then cp a.cpp backup/a.cpp; fi;
	if [ -f b.cpp ]; then cp b.cpp backup/b.cpp; fi;
	if [ -f c.cpp ]; then cp c.cpp backup/c.cpp; fi;
	if [ -f d.cpp ]; then cp d.cpp backup/d.cpp; fi;
	if [ -f e.cpp ]; then cp e.cpp backup/e.cpp; fi;
	if [ -f f.cpp ]; then cp f.cpp backup/f.cpp; fi;
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
