bin_name=solver
target=src/main.cpp
CC_FLAG=-std=c++11

$(bin_name): $(target)
	g++ $(CC_FLAG) $(target) -o $(bin_name)

.PHONY: format
format:
	clang-format -i -style=file ./src/**/*.hpp ./src/**/*.cpp

.PHONY: clean
clean:
	$(RM) $(bin_name)