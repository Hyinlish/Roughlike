lib = ncursesw
target = src/main.o src/monsters.o

app: $(target)
	g++ -o $@ $^ -l $(lib)

%.o: src/%.cpp
	g++ -o $@ $^ -l $(lib)

.PHONY: clean
clean:
	rm -rf $(target)

.PHONY: run
run: app
	./app