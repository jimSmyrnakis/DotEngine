src=./source/
inc=./include/
obj=./object/
lib=./library/

stb_image.lib: stb_image.o 
	ar rcs $(lib)libstb_image.a $(obj)stb_image.o

stb_image.o: $(src)stb_image.cpp
	g++ -c $(src)stb_image.cpp -o $(obj)stb_image.o
