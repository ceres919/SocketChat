#include "chatwindow.hpp"
#include "./ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    socket_ = new QTcpSocket(this);
    connect(socket_, &QTcpSocket::readyRead, this, &ChatWindow::readMessage);
    connect(socket_, &QTcpSocket::disconnected, socket_, &QTcpSocket::deleteLater);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_connectBtn_clicked()
{
//    if (!ui->name->text().isEmpty()) {
        socket_->connectToHost(ui->address->text(), ui->port->text().toInt());
        if (socket_->waitForConnected()) {
            QMessageBox::information(this, "Success", "Connected to Server");
//            socket_->write(ui->name->text().append("\n").toStdString().c_str());
        }
        else {
            QMessageBox::critical(this,
                                  "QTCPClient",
                                  QString("The following error occurred: %1.")
                                      .arg(socket_->errorString()));
            ui->settings->show();
        }
//    }
//    else {
//        QMessageBox::critical(this,
//                              "QTCPClient",
//                              QString("Имя не может быть пустым"));
//        ui->settings->show();
//    }
}

void ChatWindow::readMessage()
{
    QByteArray buffer = socket_->readAll();
    ui->dialogHistory->append(buffer.trimmed());
}

void ChatWindow::sendToServer(QString message)
{
    socket_->write(message.append("\n").toStdString().c_str());
    ui->inputMessage->clear();
}

void ChatWindow::on_sendBtn_clicked()
{
    sendToServer(ui->inputMessage->text());
}

void ChatWindow::on_inputMessage_returnPressed()
{
    sendToServer(ui->inputMessage->text());
}
