from SslConnection import SslConnection
import argparse
import time


parser = argparse.ArgumentParser(description='Parse input parameters.')

parser.add_argument('--ip', dest='ip_addr', nargs='?',
                    help='ip address of the remote device', action='store',
                    default='127.0.0.1')

parser.add_argument('--port', dest='port', nargs='?', type=int,
                    help='port', action='store',
                    default=4433)


args = parser.parse_args()

print(args.ip_addr, type(args.port))

conn = SslConnection(args.ip_addr, args.port)
print(conn.send_data(bytes([1,2,3,4])))
