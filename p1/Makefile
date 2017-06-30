CC=g++
CFLAGS=-ansi -Wall -g
OBJS=main.o day.o calendar.o appt.o time.o
calendar.out: $(OBJS)
	$(CC) -o calendar.out -Wall -g $(OBJS)

main.o: main.cpp calendar.h
	$(CC) -c $(CFLAGS) main.cpp

calendar.o: calendar.cpp calendar.h day.h
	$(CC) -c $(CFLAGS) calendar.cpp

day.o: day.cpp day.h appt.h
	$(CC) -c $(CFLAGS) day.cpp

appt.o: appt.cpp appt.h time.h
	$(CC) -c $(CFLAGS) appt.cpp

time.o: time.cpp time.h
	$(CC) -c $(CFLAGS) time.cpp

test:
	./calendar.out

clean:
	rm -f $(OBJS) calendar.out
