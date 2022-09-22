build: ./main.o
	g++ ./main.o

clean:
	$(RM) *.out main.o