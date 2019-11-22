FLAGS= -W -Wextra -Wall -ansi -pedantic
EXEC=transforme afficheEnTeteBMP
CC= gcc
ADD= -I/home/pashmiii/Documents/IUT/S3/U2-S3-/C/BITMAP/enTeteBMP

all: $(EXEC)

transforme: transforme.c mainTransforme.c enTeteBMP.c
afficheEnTeteBMP: enTeteBMP.c afficheEnTeteBMP.c

$(EXEC):
	$(CC) -o $@ $^ $(FLAGS)  

%.o: %.c enTeteBMP.h
	$(CC) -o $@ -c $^ $(FLAGS)

clean:
	rm -f *~ *.o

mrproper: clean
	rm -f $(EXEC)
