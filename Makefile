IncludeRaylib = -lraylib
IncludeCurrentPath = -I ./
board.o: board.cpp board.hpp
	g++ -c $< $(IncludeRaylib)

main.o: main.cpp board.hpp
	g++ -c $< $(IncludeRaylib) $(IncludeCurrentPath)

prog:
	g++ *.o -o prog $(IncludeRaylib) $(IncludeCurrentPath)

clean:
	rm -rf *.o prog *.gch