all:
	g++ -c main.cpp -o obj/main.o
	g++ -c sources/interfazUsuario.cpp -o obj/interfazUsuario.o
	g++ -c sources/juegoGato.cpp -o obj/juegoGato.o
	g++ -o release/programa obj/main.o obj/interfazUsuario.o obj/juegoGato.o
	clear
	./release/programa

clean:
	rm obj/*.o release/programa
	clear