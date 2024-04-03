CXX  =  g++
CXXLINK  =  $(CXX)
CXXFLAGS  =  -Wall -g -std=c++11
OBJS  =  main.o string.o ip.o port.o string-array.o
EXEC  =  firewall.exe

$(EXEC): main.o libfirewall.so
        $(CXXLINK) $(OBJS) -o $(EXEC) -lfirewall -linput -L.

libfirewall.so : firewall.o
        $(CXXLINK) -shared string.o string-array.o ip.o port.o -o libfirewall.so

firewall.o: string.o string.cpp string-array.o string-array.cpp ip.o ip.cpp port.o port.cpp
        $(CXX) -c -fpic string.cpp ip.cpp port.cpp

string.o: string.h string.cpp
        $(CXX) $(CXXFLAGS) -c string.cpp

string-array.o: string-array.h string-array.cpp string.h
        $(CXX) $(CXXFLAGS) -c string-array.cpp

ip.o: ip.h ip.cpp string.h string-array.h
        $(CXX) $(CXXFLAGS) -c ip.cpp

port.o: port.h port.cpp string.h string-array.h
        $(CXX) $(CXXFLAGS) -c port.cpp

main.o: main.cpp string.h string-array.h ip.h port.h input.h
        $(CXX) $(CXXFLAGS) -c main.cpp

clean:
        rm -rf $(OBJS) libfirewall.so firewall.exe
