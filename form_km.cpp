#include "form_km.h"
#include "ui_form_km.h"

Form_KM::Form_KM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_KM)
{
    ui->setupUi(this);
    ui->label_Scale->setStyleSheet("border-image:url(:/KM/Images/Km/Km_background.png)");
    m_pointX = 200;
    m_pointY = 200;
    m_degreespeed = 0;
    m_degreeRotate = 0;
}

Form_KM::~Form_KM()
{
    delete ui;
}

void Form_KM::paintEvent(QPaintEvent *)
{
    QImage imagePointer(":/KM/Images/Km/Point.png");
    QPainter painter(this);

#if 0
    painter.translate(m_pointX, m_pointY);
    painter.save();
    painter.rotate(-14+m_degreespeed);
    QRect rect(32, 39, 324, 324);
    QRect source(0,0, 324, 324);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    painter.drawPixmap(rect, QPixmap::fromImage(imagePointer),source);
    painter.restore();
#else
    painter.save();
    QRect rct(32,39,324,324);
    painter.translate(m_pointX,m_pointY);
    painter.rotate(-14+m_degreespeed);
    painter.translate((0 - m_pointX),(0-m_pointY));
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    painter.drawImage(rct,imagePointer);
    painter.restore();
#endif
}

void Form_KM::change_Speed(float temp)
{
    m_degreespeed = temp;
    update();
}
