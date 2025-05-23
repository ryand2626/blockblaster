all: blockblaster

blockblaster: code.cpp
	g++ code.cpp -o blockblaster -lGL -lGLU -lglut

clean:
	rm -f blockblaster
