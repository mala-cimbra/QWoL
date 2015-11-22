#include "qwol.h"
#include "ui_qwol.h"

QWoL::QWoL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWoL)
{
    ui->setupUi(this);
}

QWoL::~QWoL()
{
    delete ui;
}

void QWoL::on_button_smp_clicked()
{
    QUdpSocket uSocket; // crea il socket
    QString mac_address = ui->line_mac->text(); // prendi il mac address
    QString mac_add_sedicivolte_qstring = mac_address.remove(QRegularExpression("[:]")).remove(QRegularExpression("[-]")); // togli : o -
    QString ma_sedici;

    for (int i = 1; i <= 16; i++)
    {
        ma_sedici += mac_add_sedicivolte_qstring; // 16 volte il mac address
    }

    QByteArray mac_per_sedici_volte_qba = QByteArray::fromHex(ma_sedici.toUtf8()); // trasforma tutto in byte
    //qDebug().noquote().nospace() << ma_sedici;
    QHostAddress broadcast = QHostAddress("255.255.255.255"); // tira fuori il broadcast
    quint16 porta = 9; // porta del wakeonlan
    QByteArray magic_packet; // creazione del magic_packet
    magic_packet.append(QByteArray::fromHex("ffffffffffff")); // sync-stream
    magic_packet.append(mac_per_sedici_volte_qba); // appendi 16 volte il mac
    uSocket.writeDatagram(magic_packet, broadcast, porta); // manda il packetto
    uSocket.waitForBytesWritten(500); // aspetta massimo mezzo secondo
    uSocket.flush(); // flusha
    uSocket.close(); // chiudi il socket
}
