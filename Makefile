$FLAGS= -W -Wextra -Wall -ansi -pedantic
$EXEC=afficheEnTeteBMP
$CC= gcc
$ADD= -I/home/pashmiii/Documents/IUT/S3/U2-S3-/C/BITMAP/enTeteBMP 


transforme:  transforme.c mainTransforme.c  enTeteBMP.c
	$(CC) -o $@ $^ $(FLAGS) $(ADD)
	shotwell avionCopie.bmp 
	
%.o: %.c enTeteBMP.h
	$(CC) -o $@ -c $^ $(FLAGS)  $(ADD)


clean:
	rm -f *~ *.o

mrproper: clean
	rm $(EXEC)
