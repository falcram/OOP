g++ -c userinterface.cpp
g++ -c FileHosting.cpp
g++ -c SFTPservice.cpp -lssh -DLIBSSH_STATIC
g++ userinterface.o FileHosting.o SFTPservice.o -o FileHosting -lssh -DLIBSSH_STATIC
mv FileHosting.o ./build
mv SFTPservice.o ./build
mv userinterface.o ./build
mv FileHosting ./build
