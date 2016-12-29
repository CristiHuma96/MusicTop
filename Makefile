#fisier folosit pentru compilarea serverului&clientului TCP iterativ

all: Main_server.cpp Connection.cpp Client_Manager.cpp Main_client.cpp Client.cpp Bazadedate.cpp LogIn.cpp
	g++ Main_server.cpp Client_Manager.cpp SignUp.cpp Connection.cpp Bazadedate.cpp LogIn.cpp -lsqlite3 -o server
	g++ Main_client.cpp Client.cpp -o client