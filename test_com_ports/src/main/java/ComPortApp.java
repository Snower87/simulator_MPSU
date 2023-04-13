import jssc.SerialPortList;

public class ComPortApp {
    /**
     * getNameComPorts - выводит список доступных COM-портов
     */
    public void getNameComPorts() {
        String[] portNames = SerialPortList.getPortNames();
        for (String str: portNames) {
            System.out.println(str);
        }
    }

    public static void main(String[] args) {
        new ComPortApp().getNameComPorts();
    }
}
