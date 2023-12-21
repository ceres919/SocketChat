#pragma once

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void readMessage();
    void on_connectBtn_clicked();
    void on_sendBtn_clicked();
    void on_inputMessage_returnPressed();

private:
    void sendToServer(QString message);

private:
    Ui::ChatWindow *ui;
    QTcpSocket *socket_;
    QByteArray data_;
};
