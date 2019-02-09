CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults: dominion.o rngs.o
	make clean
	gcc -Wextra -pedantic $(CFLAGS) dominion.c unittest1.c rngs.c -fpic -coverage -lm -o unittest1
	./unittest1
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c unittest2.c rngs.c -fpic -coverage -lm -o unittest2
	./unittest2
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c unittest3.c rngs.c -fpic -coverage -lm -o unittest3
	./unittest3
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c unittest4.c rngs.c -fpic -coverage -lm -o unittest4
	./unittest4
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c cardtest1.c rngs.c -fpic -coverage -lm -o cardtest1
	./cardtest1
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c cardtest2.c rngs.c -fpic -coverage -lm -o cardtest2
	./cardtest2
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c cardtest3.c rngs.c -fpic -coverage -lm -o cardtest3
	./cardtest3
	gcov -b ./dominion.c >> unittestresults.out
	gcc -Wextra -pedantic $(CFLAGS) dominion.c cardtest4.c rngs.c -fpic -coverage -lm -o cardtest4
	./cardtest4
	gcov -b ./dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
