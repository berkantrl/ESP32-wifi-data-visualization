# ESP32 Wifi Data Visualization
This tool is designed to receive data over WiFi and create a real-time graph using Python, Matplotlib, and the socket library. It is intended for use in data visualization and analysis applications.

## Requirements
- Python 3.x
- Matplotlib library
- Socket library
## Setup
Clone or download this repository onto your local machine.
Install the required libraries by running the following command:

```pip install matplotlib```

Connect your device to the WiFi network that the data will be transmitted from.
Run the listener.py script to start receiving and graphing the data.

```python listener.py```
## Configuration
The following configuration options are available in the listener.py script:

- PORT: The port number to listen for data on. The default port is 1235.
- MAX_POINTS: The maximum number of data points to display on the graph at once. This value is set to 256 by default.
## Usage
1. Make sure that your device is connected to the correct WiFi network.
2. Run the listener.py script to start receiving and graphing data.
3. The graph will automatically update in real-time as new data is received.
4. The graph will be saved to a file called "graph.png" in the same directory as the listener.py script.
5. To stop the script, press CTRL+C on your keyboard.
