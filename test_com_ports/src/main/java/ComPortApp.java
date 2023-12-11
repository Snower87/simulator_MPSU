import jssc.SerialPort;
import jssc.SerialPortException;
import jssc.SerialPortList;
import jssc.SerialPortTimeoutException;

import java.io.UnsupportedEncodingException;

public class ComPortApp {
    public int numVer = 2;
    /**
     * getNameComPorts - выводит список доступных COM-портов
     */
    public void getNameComPorts() {
        String[] portNames = SerialPortList.getPortNames();
        System.out.println("Метод getNameComPorts() - вывод доступных СОМ-портов");
        for (String str: portNames) {
            System.out.println(str);
        }
    }

    /*
    * serialTXExample - пример выдачи посылки из 2х байт в линию RS-485
    */
    public void serialTXExample() {
        SerialPort serialPort = new SerialPort("COM10");
        System.out.println("Метод serialTXExample() - предача сообщения по COM-порту");
        try {
            //Открываем порт
            serialPort.openPort();

            //Выставляем параметры
            serialPort.setParams(SerialPort.BAUDRATE_57600,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);
            for (int i = 0; i < 100; i++) {
                //serialPort.writeString("Привет", "UTF-8");
                byte[] bufferTX = {0x11, 0x22};
                serialPort.writeBytes(bufferTX);
            }
            //Закрываем порт
            serialPort.closePort();
        } catch (SerialPortException e) {
            e.printStackTrace();
        }
    }

    public void serialRXExample() {
        SerialPort serialPort = new SerialPort("COM10");
        System.out.println("Метод serialRXExample() - прием сообщения по COM-порту");

        try {
            //Открываем порт
            serialPort.openPort();

            //Выставляем параметры
            serialPort.setParams(SerialPort.BAUDRATE_57600,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);
            byte[] readRX = new byte[10];
            for (int i = 0; i < 1; i++) {
                //serialPort.writeString("Привет", "UTF-8");
                byte[] bufferTX = {0x11, 0x22};
                //serialPort.writeBytes(bufferTX);
                try {
                    readRX = serialPort.readBytes(10, 5000);
                } catch (SerialPortTimeoutException e) {
                    e.printStackTrace();
                }
            }
            System.out.println(System.out.format("0x%02X", readRX[0]));
            //Закрываем порт
            serialPort.closePort();

        } catch (SerialPortException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        ComPortApp comApp = new ComPortApp();
        comApp.getNameComPorts();
        //comApp.serialTXExample();
        comApp.serialRXExample();
    }
}
