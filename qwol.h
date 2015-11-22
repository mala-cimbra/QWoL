#ifndef QWOL_H
#define QWOL_H

#include <QMainWindow>
#include <QDebug>
#include <QUdpSocket>

namespace Ui {
class QWoL;
}

class QWoL : public QMainWindow
{
    Q_OBJECT

public:
    explicit QWoL(QWidget *parent = 0);
    ~QWoL();

private slots:
    void on_button_smp_clicked();

private:
    Ui::QWoL *ui;
};

#endif // QWOL_H
