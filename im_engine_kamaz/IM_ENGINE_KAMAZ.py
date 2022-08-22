from PyQt5 import QtCore, QtWidgets 
import sys 

print('123')

app = QtWidgets.QApplication(sys.argv) 
window = QtWidgets.QWidget() 
window.setWindowTitle("IM_ENGINE_KAMAZ") 
window.resize(300, 70) 
label = QtWidgets.QLabel("<center>Имитатор для испытания двигателей Камаз</center>") 
btnQuit = QtWidgets.QPushButton("Выход") 
vbox = QtWidgets.QVBoxLayout() 
vbox.addWidget(label) 
vbox.addWidget(btnQuit) 
window.setLayout(vbox) 
btnQuit.clicked.connect(app.quit) 
window.show() 
sys.exit(app.exec_())