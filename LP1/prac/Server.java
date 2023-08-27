package prac;

import java.io.*;
import java.lang.reflect.Constructor;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class Server {

    public static void main(String[] args) {
        ServerSocket server = null;
        try {
            server = new ServerSocket(1234);
            server.setReuseAddress(true);
            while (true) {
                Socket client = server.accept();
                System.out.println("\nNew Client Connected : " + client.getInetAddress().getHostAddress());
                ClientHandler clientsoc = new ClientHandler(client);
                new Thread(clientsoc).start();
            }
        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        } finally {
            try {
                if (server != null) {
                    server.close();
                }
            } catch (IOException e) {
                // TODO: handle exception
                e.printStackTrace();
            }

        }
    }

    private static class ClientHandler implements Runnable {
        private final Socket clientsocket;

        // Constructor
        ClientHandler(Socket client) {
            this.clientsocket = client;
        }

        public void run() {
            PrintWriter out = null;
            BufferedReader in = null;
            try {
                out = new PrintWriter(clientsocket.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(clientsocket.getInputStream()));
                String line;
                while ((line = in.readLine()) != null) {
                    System.out.printf("\nSent from client : %s", line);
                    out.println(line);
                }

            } catch (IOException e) {
                // TODO: handle exception
                e.printStackTrace();
            } finally {
                try {
                    if (out != null) {
                        out.close();
                    }
                    if (in != null) {
                        in.close();
                        clientsocket.close();
                    }
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }
            }
        }
    }

}
