target:	klotski

main:	klotski.h main.cpp
		g++ -std=c++11 -c main.cpp	klotski.cpp

klotski:	main
		g++ -std=c++11 main.cpp	klotski.cpp -o klotski
clean:
		rm klotski *.o