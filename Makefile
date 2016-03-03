# makefile: Traveling Salesman Problem
# Alejandro Garbi

FLAGS   := -DNDEBUG -Wall
OBJS := main.o algorithms.o

GA: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o GA

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp
	
algorithms.o: algorithms.cpp
	g++ $(FLAGS) -c algorithms.cpp

clean:
	rm -rf *o GA