AR :=ar
LIB :=student.a

$(LIB):student.o
	$(AR) -r $@  $^

student.o:student.c
	gcc -o $@ -c $^

.PHONY:clean
clean:
	rm   *.o

