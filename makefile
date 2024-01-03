# # Compiler and linker configurations
# CC = g++
# CFLAGS = -c
# LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lpthread

# # Object files
# OBJS = main.o login.o text_field.o menu.o userlist.o room.o home.o socket.o route.o

# # Executable name
# EXEC = my_application

# # Default target
# all: $(EXEC)

# $(EXEC): $(OBJS)
# 	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

# # Individual source files
# main.o: main.cpp
# 	$(CC) $(CFLAGS) main.cpp -o main.o

# login.o: login.cpp
# 	$(CC) $(CFLAGS) login.cpp -o login.o

# text_field.o: text_field.cpp
# 	$(CC) $(CFLAGS) text_field.cpp -o text_field.o

# menu.o: menu.cpp
# 	$(CC) $(CFLAGS) menu.cpp -o menu.o

# userlist.o: userlist.cpp
# 	$(CC) $(CFLAGS) userlist.cpp -o userlist.o

# room.o: room.cpp
# 	$(CC) $(CFLAGS) room.cpp -o room.o

# home.o: home.cpp
# 	$(CC) $(CFLAGS) home.cpp -o home.o

# socket.o: socket.cpp
# 	$(CC) $(CFLAGS) socket.cpp -o socket.o

# route.o: route.cpp
# 	$(CC) $(CFLAGS) route.cpp -o route.o

# # Clean target
# clean:
# 	rm -f $(OBJS) $(EXEC)

# Compiler and linker configurations
CC = g++
CFLAGS = -c -I/usr/include/json-c
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lpthread -ljson-c

# Object files
OBJS = main.o login.o text_field.o menu.o userlist.o room.o home.o socket.o route.o

# Executable name
EXEC = my_application

# Default target
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

# Individual source files
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

login.o: login.cpp
	$(CC) $(CFLAGS) login.cpp -o login.o

text_field.o: text_field.cpp
	$(CC) $(CFLAGS) text_field.cpp -o text_field.o

menu.o: menu.cpp
	$(CC) $(CFLAGS) menu.cpp -o menu.o

userlist.o: userlist.cpp
	$(CC) $(CFLAGS) userlist.cpp -o userlist.o

room.o: room.cpp
	$(CC) $(CFLAGS) room.cpp -o room.o

home.o: home.cpp
	$(CC) $(CFLAGS) home.cpp -o home.o

socket.o: socket.cpp
	$(CC) $(CFLAGS) socket.cpp -o socket.o

route.o: route.cpp
	$(CC) $(CFLAGS) route.cpp -o route.o

# Clean target
clean:
	rm -f $(OBJS) $(EXEC)
