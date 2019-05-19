import socket
import ssl


class SslConnection(object):
    def __init__(self, ip_addr, port, tx_len=1028, rx_len=1028):
        self.ip_addr = ip_addr
        self.port = port
        self.tx_len = tx_len
        self.rx_len = rx_len

    def __del__(self):
        pass

    def send_data(self, data):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(10)
        self.wrappedSocket = ssl.wrap_socket(sock, ssl_version=ssl.PROTOCOL_TLSv1)
        self.wrappedSocket.connect((self.ip_addr, self.port))
        self.wrappedSocket.send(data)
        recv = self.wrappedSocket.recv(self.rx_len)
        self.wrappedSocket.close()
        return recv
