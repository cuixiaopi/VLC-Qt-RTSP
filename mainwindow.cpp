#include <vlcplayer.h>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_vplayer = new VLCPlayer(this);
    m_vplayer->Play("./1.mp4", static_cast<uint32_t>(ui->videoFrame->winId()));


//////    网络流
//    QString rtspUrl = "rtsp://rtspstream:dc4fec8e721e3701c219da70d8193bbd@zephyr.rtsp.stream/movie";
//    m_vplayer->Play_RTSP(rtspUrl, static_cast<uint32_t>(ui->videoFrame->winId()));

}

MainWindow::~MainWindow()
{
    m_vplayer->Stop();
    m_vplayer->Release();
    delete m_vplayer;

    delete ui;
}
