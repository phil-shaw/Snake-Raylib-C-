source = main.cpp
target = main

$(target): $(source) snake.h food.h globals.h

	g++ $(source) -o $(target) -Iinclude -Llib -lraylib -lm -lpthread -lGLESv2 -lEGL

run:
	@./$(target)

clean:
	@rm $(target) $(object)
