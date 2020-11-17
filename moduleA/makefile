AR :=ar
LIB :=lib.a

$(LIB):course.o
	$(AR) -r $@ $^
course.o:course.c
	gcc -c $^ -o $@
.PHONY:clean
clean:
	rm  *.o
	
