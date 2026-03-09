from ports import Port   
import launch as Launch


def main():

    Launch.launch()  # Build and upload the code to the Arduino
    port = Port()

    while True:
        data = port.read()
        if data != None:
            print(f"Received: {data}")
    






if __name__ == "__main__":
    main()