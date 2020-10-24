/*
 *
 */
#pragma once

#include <QtWidgets/QMainWindow>
#include <QCheckBox>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent = Q_NULLPTR);
    ~MainWindow();

    void adjustWindowSize();
    void addToolbarWidgets();
    void connectSlots();

private:
    void closeEvent(QCloseEvent * event) override;

public slots:
    void init(bool success);
    void tick();
    void render(ID3D12GraphicsCommandList * cl);

private:
    Ui::MainWindowClass * ui;

    QDirect3D12Widget * m_pScene;
    QSize               m_WindowSize;
    QCheckBox *         m_pCbxDoFrames;
};
