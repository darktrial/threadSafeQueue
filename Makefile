All:
	$(CXX) -o test test.cpp -lpthread
clean:
	rm -rf *.o test 