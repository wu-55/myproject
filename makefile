TARGET:=main
SOURCE:=../myproject/RELEASE/main.o
$(TARGET):$(SOURCE)
	gcc  $^ -o $@

$(SOURCE):main.c
	gcc -c $< -o $@

.PHONY:clean
clean:
	rm $(SOURCE)  $(TARGET)

