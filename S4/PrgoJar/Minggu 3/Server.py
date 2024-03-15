import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = 'localhost'
PORT = 12345

server_socket.bind((HOST, PORT))
server_socket.listen(1)

print("Waiting...\n")

client_socket, client_address = server_socket.accept()

data = client_socket.recv(1024)
karakter = data.decode('utf-8')

print("Request dari client :", karakter, "\nIP client :", client_address)

response = "jumlah karakter yang di minta : " + str(len(karakter))

client_socket.sendall(response.encode())

client_socket.close()
server_socket.close()