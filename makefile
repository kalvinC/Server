main: main.o tcpserver_impl.o kqueuemodel_impl.o
	g++ -o $@ $^

main.o: main.cpp 
	g++ -c $^ 

kqueuemodel_impl.o: communication/kqueuemodel_impl.cpp
	gcc -c $^

tcpserver_impl.o: communication/tcpserver_impl.cpp
	g++ -c $^ 


.PHONY: clean
clean:
	rm -f *.o main