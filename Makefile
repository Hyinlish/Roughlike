lib = ncursesw
	
app: src/*.cpp
	g++ -o $@ $^ -l $(lib)

.PHONY: clean
clean:
	rm -rf src/*.o

.PHONY: run
run: app
	./app