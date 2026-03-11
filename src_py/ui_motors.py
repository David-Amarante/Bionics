from ports import Port
import tkinter as tk
from tkinter import ttk, messagebox


class ControlApp:
    def __init__(self, root, port: Port = None):
        self.root = root 
        self.root.title("Control App - Bionics Project")
        self.root.geometry("500x300")
        self.root.configure(bg="#09FC1D")  # Similar background from image
        self.port = port # Initialize the serial port connection
        
        self.step_size = tk.IntVar(value=10)  # Step size for angle changes

        self.m1_current_angle = tk.IntVar(value=90)  # Default angle for Motor 1

        self.setup_ui()


    #Function for Sliders and Buttons
    def decrease_angle(self):   
        current_value = self.m1_current_angle.get()
        new_value = max(0, current_value - self.step_size.get())  # Ensure it doesn't go below 0
        self.m1_current_angle.set(new_value)
        print("in")
        if self.port:
            self.port.write(f"UP-{new_value}")  # Send the new angle to the Arduino
        


    # UI Setup
    def setup_ui(self):
        # Main Frame
        main_frame = tk.Frame(self.root, bg="#09FC1D")
        main_frame.pack(expand=True, fill="both", padx=20, pady=20)

        # Title
        title_label = tk.Label(main_frame, text="MOTOR 1", font=("Arial", 16), bg="#FC0909", fg="black")
        title_label.pack(pady=(0, 20))

        # Control Row (Box with slider and buttons)
        control_row = tk.Frame(main_frame, bg="#09FC1D")        
        control_row.pack(fill="x")


        #Minus Button (-)
        btn_minus = tk.Button(control_row, text="➖", font=("Arial", 14, "bold"), 
                              bg="#C11B17", fg="white", activebackground="#E32636", # Red circle style
                              command=self.decrease_angle, relief="flat", width=3, height=1, bd=0)
        btn_minus.pack(side="left", padx=(0, 10))   