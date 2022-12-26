import socket
import matplotlib.pyplot as plt

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('IP_adresses', 1235)
sock.bind(server_address)


# Initialize an empty lists
akim = []
vx = []

print('Waiting for a connection...')
while True:
    # Listen for incoming connections
    sock.listen(1)
    # Wait for a connection
    connection, client_address = sock.accept()
    try:
        # Receive data from the client
        data = connection.recv(1024)
        # Add the received data to the list
        data = data.decode()
        str_data = str(data)
        data_list= str_data.split(";")
        data_table = list(map(float,data_list))
        akim.append(data_table[0])
        vx.append(data_table[1])
        print('Data received:', data_table)

        # Keep track of the amount of data received
        data_received = len(vx)
        # Close the connection if the amount of data received is equal to or greater than 256 
        if data_received >= 256:
            break
    except :
        pass 

# Close the connection
print("Connection is closing,,,")
connection.close()

# Plot a single line using the values from list1 as the x-values and the values from list2 as the y-values
plt.plot(akim, vx)

# Add axis labels and a title
plt.xlabel('Akım')
plt.ylabel('Vx')
plt.title('Data from two lists')

# saves the graph to a png file.
plt.savefig("graph.png")  

# Show the plot
plt.show()
