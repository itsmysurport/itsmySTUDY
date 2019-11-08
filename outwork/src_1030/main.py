from main_gui import *
import requests
import time

import pymongo
from pymongo import MongoClient

conn = MongoClient('127.0.0.1', 27017)
db = conn.sample
collect = db.file

def ipInit(self):
    self.ipEdit.setText("127")
    self.ipEdit_2.setText("0")
    self.ipEdit_3.setText("0")
    self.ipEdit_4.setText("1")
    self.networkEdit.setText("5000")
    self.domainEdit.setText("http://127.0.0.1:5000")

def ipConnect(self):
    self.url = self.domainEdit.text()
    self.username = self.userEdit.text()
    self.data = {'username': self.username}
    self.success = '<Response [200]>'
    if str(requests.post(self.url, json = self.data)) == self.success:
        self.stackedWidget.setCurrentIndex(1)
        print('Hello, %s! Success to Connected!'% self.username)

def newFile(self):
    self.url = self.domainEdit.text() + '/write'
    print(self.url)
    self.success = '<Response [200]>'
    self.data = {'title': self.lineEdit.text(), 'contents': self.textEdit.toPlainText(), 'username': self.userEdit.text(), 'time': time.strftime('%c', time.localtime(time.time()))}
    if str(requests.post(self.url, json = self.data)) == self.success:
        self.stackedWidget.setCurrentIndex(1)
        print('Hello, %s! Success to Upload!'% self.username)
        collect.insert_one(self.data)
    self.lineEdit.clear()
    self.textEdit.clear()

def s_init(self):
    print("Start")
    self.ipInit()
    self.domainButton.clicked.connect(self.ipInit)
    self.connectButton.clicked.connect(self.ipConnect)
    self.newButton.clicked.connect(lambda x: self.stackedWidget.setCurrentIndex(2))
    self.submitButton.clicked.connect(self.newFile)
    self.newButton_2.clicked.connect(self.refresh)

def refresh(self):
    self.list = [
        ['title1', 'contents1', 'username1', 'time1'],
        ['title1_2', 'contents1_2', 'username1_2', 'time1_2'],
        ['title1_3', 'contents1_3', 'username1_3', 'time1_3'],
        ['title1_4', 'contents1_4', 'username1_4', 'time1_4'],
        ['title1_5', 'contents1_5', 'username1_5', 'time1_5'],
    ]
    self.docs = collect.find()
    self.last_5 = []
    for doc in self.docs:
        self.last_5.append(doc)
    print(self.last_5)
    if len(self.last_5) > 5:
        self.last_5 = self.last_5[(len(self.last_5) - 5):]
    print()
    print(self.last_5)
    i = 0
    for dic in self.last_5:
        if i == 0:
            self.title1.setText(dic['title'])
            self.contents1.setText(dic['contents'])
            self.username1.setText(dic['username'])
            self.time1.setText(dic['time'])
        elif i == 1:
            self.title1_2.setText(dic['title'])
            self.contents1_2.setText(dic['contents'])
            self.username1_2.setText(dic['username'])
            self.time1_2.setText(dic['time'])
        elif i == 2:
            self.title1_3.setText(dic['title'])
            self.contents1_3.setText(dic['contents'])
            self.username1_3.setText(dic['username'])
            self.time1_3.setText(dic['time'])
        elif i == 3:
            self.title1_4.setText(dic['title'])
            self.contents1_4.setText(dic['contents'])
            self.username1_4.setText(dic['username'])
            self.time1_4.setText(dic['time'])
        elif i == 4:
            self.title1_5.setText(dic['title'])
            self.contents1_5.setText(dic['contents'])
            self.username1_5.setText(dic['username'])
            self.time1_5.setText(dic['time'])
        i += 1


Ui_MainWindow.ipInit = ipInit
Ui_MainWindow.s_init = s_init
Ui_MainWindow.ipConnect = ipConnect
Ui_MainWindow.newFile = newFile
Ui_MainWindow.refresh = refresh

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    ui.s_init()
    sys.exit(app.exec_())
