IncludeRaylib = -I /Users/mangofamergoose/Libraries/raylib/src
IncludeCurrentPath = -I ./

control.o: control.cpp control.hpp
	clang++ -std=c++11 -c $< $(IncludeRaylib) $(IncludeCurrentPath)

card.o: card.cpp control.hpp card.hpp
	clang++ -std=c++11 -c $< $(IncludeRaylib) $(IncludeCurrentPath)

board.o: board.cpp board.hpp control.hpp
	clang++ -std=c++11 -c $< $(IncludeRaylib) $(IncludeCurrentPath)

main.o: main.cpp board.hpp card.hpp
	clang++ -std=c++11 -c $< $(IncludeRaylib) $(IncludeCurrentPath)

prog: control.o card.o board.o main.o
	clang++ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a *.o -std=c++11 -g -o prog -I /Users/mangofamergoose/Libraries/raylib/src

clean:
	rm -rf *.o prog