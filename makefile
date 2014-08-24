# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC=src
OUT=target
HDR=headers
FLA=-I$(HDR) -std=c++11
CXX=g++ $(FLA)

FILES:=$(call rwildcard,$(SRC)/,*.cpp)
OBJ:=$(FILES:$(SRC)/%.cpp=$(OUT)/%.o)

SRC_DIRS:=$(sort $(wildcard $(SRC)/*/))
OUT_DIRS:=$(SRC_DIRS:$(SRC)%=$(OUT)%)

.PHONY: build clean debug mkdir
.SILENT:

build: $(OUT)/application $(OUT)/Test2 $(OUT)/Test3 $(OUT)/Test4 $(OUT)/Test5 $(OUT)/Test6 $(OUT)/Test7

$(OUT)/application: main.cpp $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^

$(OUT)/Test%: Test%.cpp $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^

$(OUT)/%.o: $(SRC)/%.cpp $(HDR)/%.hpp
	echo Compiling $@...
	$(CXX) -c -o $@ $<

clean: | del mkdir

del:
	echo Cleaning...
	rm -rf $(OUT)/

mkdir:
	echo Recreating empty tree...
ifeq ($(OS),Windows_NT)
	mkdir $(OUT)
	xcopy /T $(SRC) $(OUT)
else
	mkdir -p $(OUT_DIRS)
endif

debug:
	echo $(OBJ)
	echo $(OS)
	echo $(OUT_DIRS)
