#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QQueue>

class Server: public QTcpServer
{
    Q_OBJECT
public:

    QTcpSocket *m_socket;
    int m_port;
 ///   QQueue<QTcpSocket*> sockets;
    QByteArray m_mat;
    QByteArray m_vec;
    quint64 m_nextBlockSize;

    Server(int port);
    void startServer();

private:
    void sendToClient(QTcpSocket *pSocket);

public slots:

    void slotNewConnection();
    void sockReady();
    void sockDisc();

};

#endif // SERVER_H
