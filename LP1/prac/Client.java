package prac;

import java.io.*;
import java.net.Socket;
import java.util.*;

public class Client {

    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 1234)) {
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String line = null;
            Scanner sc = new Scanner(System.in);
            while (!"exit".equalsIgnoreCase(line)) {
                line = sc.nextLine();
                out.println(line);
                out.flush();
                System.out.println("Server Replied : " + in.readLine());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
