poetryL2: poetry.c 
	gcc -Wall -std=c99 poetry.c -o poetryL2	
#poetry.o: poetry.c 
#	gcc -Wall -std=c99 -c poetry.c
clean:
	rm *.o poetryL2
