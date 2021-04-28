import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QDesktopWidget, QHBoxLayout, QPushButton, QWidget
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWebEngineWidgets import *
class Winform(QMainWindow):
    def __init__(self):
        super(QMainWindow, self).__init__()
        self.resize(1920, 1080)
        self.center()
        self.setWindowTitle("Google Translate")
        self.browser = QWebEngineView()
        self.browser.load(QUrl('https://translate.google.cn'))
        self.setCentralWidget(self.browser)


    def center(self):
        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move(int((screen.width() - size.width()) / 2.0), int((screen.height() - size.height()) / 2.0))
if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setWindowIcon(QIcon("beauty.ico"))
    form = Winform()
    form.show()
    sys.exit(app.exec_())
