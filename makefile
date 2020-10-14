Makefile:

all: serverC serverG client run

serverC: ServerC.c
	g++ ServerC.c -o serverC -pthread

serverG: ServerG.c
	g++ ServerG.c -o serverG

client: Client.c
	g++ Client.c -o client

run: serverC
	./serverC

clean:
	rm -f serverC
	rm -f serverG
	rm -f client
