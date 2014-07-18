# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC=src
OUT=target
HDR=headers
FLA=-I$(HDR) -std=c++11
CXX=g++ $(FLA)

FILES:=$(call rwildcard,$(SRC)/,*.cpp)
OBJ:=$(FILES:$(SRC)/%.cpp=$(OUT)/%.o)

.SILENT:

build: $(OUT)/application $(OUT)/Test2 $(OUT)/Test3 $(OUT)/Test4

$(OUT)/application: main.cpp $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^

$(OUT)/Test%: Test%.cpp $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^

$(OUT)/%.o: $(SRC)/%.cpp $(HDR)/%.hpp
	echo Compiling $@...
	$(CXX) -c -o $@ $<

clean:
	echo Cleaning...
	rm -rf $(OUT)/
	echo Recreating empty tree...
	mkdir $(OUT)
	xcopy /T $(SRC) $(OUT)

debug:
	echo $(OBJ)
