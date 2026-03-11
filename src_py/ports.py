import serial
import time 


class Port: 
    def __init__(self, serial_port):
        self.port = serial.Serial(serial_port , 9600, timeout=1)  # arduino port
    
    def read(self):
        if self.port.in_waiting > 0:
            line = self.port.readline().decode().rstrip()
            print (line)
            return line
        return None
    
    def write(self, data):
        self.port.write((data + '\n').encode())
        self.port.flush()
        
    
