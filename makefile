All: array.out linkedlist.out

array.out: array.cpp
	g++ -o array.out array.cpp
linkedlist.out: linkedlist.cpp
	g++ -o linkedlist.out linkedlist.cpp