a:
	g++ -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration work.cpp 
	./a.out

open :
	open -a xcode work.cpp
#	atom .

r:
	cp work.cpp backup.cpp
	cp ../workspace/temp_at.cpp .
	rm a.out* *~ *#*
rollback:
	cp backup.cpp work.cpp



