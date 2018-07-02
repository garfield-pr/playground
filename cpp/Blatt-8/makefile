CXXFLAGS = -std=c++11 -pthread

PROGRAM_LIST = calcpi.bin countwords.bin

all: $(PROGRAM_LIST)

clean:
	rm -rf *.o $(PROGRAM_LIST)

%.bin: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 
