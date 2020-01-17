.PHONY:xbox.h
xbox.h:
	gcc -o xbox.h -x c -P -E -Iinclude xbox.cpp
	g++ -o xbox -DTEST_COMPILE=1 -Iinclude xbox.cpp
