open :
	code .

r:
	rm -rf backup
	mkdir backup
	cp a.cpp backup/a.cpp
	cp b.cpp backup/b.cpp
	cp c.cpp backup/c.cpp
	cp d.cpp backup/d.cpp
	cp ../../temp_at.cpp a.cpp
	cp ../../temp_at.cpp b.cpp
	cp ../../temp_at.cpp c.cpp
	cp ../../temp_at.cpp d.cpp
	cp ../../temp_at.cpp e.cpp
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

