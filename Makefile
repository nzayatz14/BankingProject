CC=g++
OUTFILE=RunBank

SRC=BankingProject.cpp Person.cpp InternalAccount.cpp Client.cpp ExternalAccount.cpp Bank.cpp Admin.cpp AccountAccessor.cpp
OBJ=$(SRC:.cpp=.o)	

all: main

main: $(OBJ)
		$(CC) $(OBJ) -o $(OUTFILE)
clean:
	-rm *.o $(OUTFILE)	
