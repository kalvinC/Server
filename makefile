
main: main.o tcpserver_impl.o
	g++ -o main main.o tcpserver_impl.o

main.o: main.cpp 
	g++ -c $^ 

tcpserver_impl.o: communication/tcpserver_impl.cpp
	g++ -c $^ 

.PHONY: clean
clean:
	rm -f *.o main