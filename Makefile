SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(wildcard *.o)

COMPILEFLAGS	 = -I"D:/Apps/SFMLlib/include" -DSFML_STATIC
LINKFLAGS	 = -o main -L"D:/Apps/SFMLlib/lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

all: preclean compile link clean run

compile:
	g++ $(COMPILEFLAGS) -c ${SRC_FILES} -O3

link:
	g++ ${OBJ_FILES} $(LINKFLAGS) -O3

clean:
	del *.o

preclean:
	del *.exe

run:
	main.exe