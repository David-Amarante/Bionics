from ports import Port   
import launch as Launch
from ui_motors import ControlApp
import tkinter as tk


#Serial Ports
serial_p1 = "COM18" #Serial Port for Arduino Uno

def main():

    Launch.launch()  # Build and upload the code to the Arduino
    port = Port(serial_p1)  # Initialize the serial port connection
    
    # Start the GUI of the Control App
    root = tk.Tk()
    app = ControlApp(root, port)
    root.mainloop()
    



if __name__ == "__main__":
    main()