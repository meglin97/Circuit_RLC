all: circuitRLC.c circuitRLC.o
	gcc -Wall circuitRLC.c -o circuitRLC.o -lm
	./circuitRLC.o
	python3 plot_system.py
clean:
	rm *.o *.png *.txt