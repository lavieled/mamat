CXX  =  g++
CXXLINK  =  $(CXX)
CXXFLAGS  =  -Wall -g -std=c++11
OBJS  =  main.o string.o field.o ip.o port.o
EXEC  =  firewall.exe

libfirewall.so : firewall.o
  $(CXXLINK) -shared string.o field.o ip.o port.o

firewall.o: string.o string.cpp field.o field.cpp ip.o ip.cpp port.o port.cpp
  $(CXX) -c -fpic string.cpp field.cpp ip.cpp port.cpp

string.o: string.h string.cpp
  $(CXX) $(CXXFLAGS) -c string.cpp

field.o: field.h field.cpp string.h
  $(CXX) $(CXXFLAGS) -c field.cpp

ip.o: ip.h ip.cpp string.h
  $(CXX) $(CXXFLAGS) -c ip.cpp

port.o: port.h port.cpp string.h field.h
  $(CXX) $(CXXFLAGS) -c port.cpp

main.o: main.cpp string.h ip.h port.h input.h
  $(CXX) $*CXXFLAGS) -c main.cpp

clean:
  rm -rf $(OBJS) libfirewall.so firewall.exe
