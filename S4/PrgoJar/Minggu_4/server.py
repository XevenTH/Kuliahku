import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 12345)
sock.bind(server_address)

while True:
 print('Menunggu pesan dari client...')
 data, address = sock.recvfrom(4096)
 
 print('Menerima pesan dari client: ', data.decode())
 
 message = 'Pesan diterima oleh server!'
 sock.sendto(message.encode(), address)