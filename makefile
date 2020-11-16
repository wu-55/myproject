main:../myproject/RELEASE/main.o
	gcc  $< -o $@

../myproject/RELEASE/main.o:main.c
	gcc -c $< -o $@

.PHONY:clean
clean:
	rm ../myproject/RELEASE/*.o  main

