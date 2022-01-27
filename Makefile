#
# Compiles class files into compiled object files and links compiled object files into the
# main program from a single runnable script. Class files can be compiled with an optional
# flag that activates the GNU debugger.
#
debug=-g
jobcomp: main.o strtoupper.o getJob.o Job.o Waged.o Salaried.o Contracted.o;
	g++ -o jobcomp main.o strtoupper.o getJob.o Job.o Waged.o Salaried.o Contracted.o
main.o: main.cpp Job.h;
	g++ ${debug} -c main.cpp
strtoupper.o: strtoupper.cpp;
	g++ ${debug} -c strtoupper.cpp
getJob.o: getJob.cpp Contracted.h Salaried.h Waged.h;
	g++ ${debug} -c getJob.cpp
Job.o: Job.cpp Job.h;
		g++ ${debug} -c Job.cpp
Waged.o: Waged.cpp Waged.h;
	g++ ${debug} -c Waged.cpp
Salaried.o: Salaried.cpp Salaried.h;
	g++ ${debug} -c Salaried.cpp
Contracted.o: Contracted.cpp Contracted.h;
	g++ ${debug} -c Contracted.cpp
clean: ;
	rm jobcomp main.o strtoupper.o getJob.o Job.o Waged.o Salaried.o Contracted.o

install: main;
	cp make Makeprogram
