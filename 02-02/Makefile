#make ndebug=1 ej5 	// ndebug ON
#make ej5 		// ndebug OFF
ej5:
ifdef ndebug
	g++ -DNDEBUG ejercicio5.cpp
else
	g++ ejercicio5.cpp
endif
clean:
	rm -r a.out