import java.io.*;

import java.net.*;

// Server class
class Server {
	public static void main(String[] args) {
		ServerSocket server = null;
		int id = 0;
		try {

			// server is listening on port 1234
			server = new ServerSocket(1234);
			server.setReuseAddress(true);

			// running infinite loop for getting
			// client request
			while (true) {

				// socket object to receive incoming client
				// requests
				Socket client = server.accept();
				id++;

				// Displaying that new client is connected
				// to server
				System.out.println("New client " + id + " connected  :   "
						+ client.getInetAddress()
								.getHostAddress());

				// create a new thread object
				ClientHandler clientSock = new ClientHandler(client, id);

				// This thread will handle the client
				// separately
				new Thread(clientSock).start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (server != null) {
				try {
					server.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// ClientHandler class
	private static class ClientHandler implements Runnable {
		private final Socket clientSocket;
		private final int id;

		// Constructor
		public ClientHandler(Socket socket, int id) {
			this.clientSocket = socket;
			this.id = id;
		}

		public void run() {
			PrintWriter out = null;
			BufferedReader in = null;
			try {

				// get the outputstream of client
				out = new PrintWriter(
						clientSocket.getOutputStream(), true);

				// get the inputstream of client
				in = new BufferedReader(
						new InputStreamReader(
								clientSocket.getInputStream()));

				String line;
				while ((line = in.readLine()) != null) {

					// writing the received message from
					// client
					System.out.println(" Sent from the client " + id + " : " + line);
					out.println(line);
				}
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				try {
					if (out != null) {
						out.close();
					}
					if (in != null) {
						in.close();
						clientSocket.close();
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
}