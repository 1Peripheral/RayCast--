default:
	g++ ../src/*.cpp -o Game.exe -O2 -Wall -Wno-missing-braces -I ../include -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	
windowless:
	g++ ../src/*.cpp -o Game.exe -O2 -Wall -Wno-missing-braces -I ../include -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
	
clean:
	rm Game.exe

	g++ ../src/*.cpp -o Game.exe -O2 -Wall -Wno-missing-braces -I ../include -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
run: 
	./Game.exe
