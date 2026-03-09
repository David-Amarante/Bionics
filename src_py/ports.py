import serial
import time 


class Port: 
    def __init__(self):
        self.port = serial.Serial("COM18", 9600, timeout=1)  # arduino port
    
    def read(self):
        if self.port.in_waiting > 0:
            line = self.port.readline().decode().rstrip()
            print (line)
            return line
        
        return None
    
