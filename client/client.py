from SslConnection import SslConnection
import argparse
import time

def get_header():
    return 1

def get_led_mode(led_mode):
    if(led_mode == 'off'):
        return 0
    elif(led_mode == 'on'):
        return 1
    elif(led_mode == 'blink'):
        return 2
    return 255  # not suported value

parser = argparse.ArgumentParser(description='Parse input parameters.')

parser.add_argument('--ip', dest='ip_addr', nargs='?',
                    help='ip address of the remote device', action='store',
                    default='127.0.0.1')

parser.add_argument('--port', dest='port', nargs='?', type=int,
                    help='port', action='store',
                    default=4433)

parser.add_argument('--led', dest='led', nargs='?', type=str,
                    help='led', action='store', choices=['on', 'off', 'blink'],
                    default='off')

args = parser.parse_args()

send_buff = list()

send_buff.append(get_header())
send_buff.append(get_led_mode(args.led))

print(send_buff)




conn = SslConnection(args.ip_addr, args.port)
print(conn.send_data(bytes(send_buff)))
