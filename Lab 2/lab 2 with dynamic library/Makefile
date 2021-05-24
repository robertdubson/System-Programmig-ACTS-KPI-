
binary: UserInterface.o lib1.so
	g++ -o binary UserInterface.o -L. lib1.so -Wl,--rpath -Wl,. 

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

lib1.so: DataBase.o InsurancePolicy.o
	g++ -shared -o lib1.so DataBase.o InsurancePolicy.o


DataBase.o: DataBase.cpp
	g++ -fPIC -c DataBase.cpp

InsurancePolicy.o: InsurancePolicy.cpp
	g++ -fPIC -c InsurancePolicy.cpp

clean: 
	rm -f *.o *.so binary

