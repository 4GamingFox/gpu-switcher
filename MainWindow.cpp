#include "MainWindow.h"
#include "backend.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GPU Switcher");
    setFixedSize(320, 270);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *layout = new QVBoxLayout(central);

    QLabel *title = new QLabel("<b>Current Mode</b>");
    layout->addWidget(title);

    modeLabel = new QLabel("🟢 Integrated");
    layout->addWidget(modeLabel);

    integrated = new QRadioButton("Integrated");
    hybrid = new QRadioButton("Hybrid");
    ultimate = new QRadioButton("Ultimate");

    integrated->setChecked(true);

    layout->addWidget(integrated);
    layout->addWidget(hybrid);
    layout->addWidget(ultimate);

    applyButton = new QPushButton("Apply");
    layout->addWidget(applyButton);

    statusLabel = new QLabel("✓ dGPU Powered Off");
    layout->addWidget(statusLabel);

    connect(applyButton,
            &QPushButton::clicked,
            this,
            &MainWindow::applyClicked);

    refreshStatus();
}

void MainWindow::refreshStatus()
{
    QString mode = Backend::currentMode();
    if(mode=="Integrated"){integrated->setChecked(true);modeLabel->setText("🟢 Integrated");statusLabel->setText("✓ dGPU Powered Off");}
    else if(mode=="Hybrid"){hybrid->setChecked(true);modeLabel->setText("🟡 Hybrid");statusLabel->setText("✓ dGPU Available");}
    else if(mode=="Ultimate"){ultimate->setChecked(true);modeLabel->setText("🔴 Ultimate");statusLabel->setText("✓ dGPU Active");}
    else {modeLabel->setText("⚪ Unknown");statusLabel->setText("Unable to detect GPU mode");}
}

void MainWindow::applyClicked()
{
    QString mode;
    if(integrated->isChecked()) mode="Integrated";
    else if(hybrid->isChecked()) mode="Hybrid";
    else mode="AsusMuxDgpu";

    if(Backend::switchMode(mode))
        QMessageBox::information(this,"GPU Switcher","GPU mode changed successfully.\n\nPlease reboot.");
    else
        QMessageBox::critical(this,"GPU Switcher","Failed to change GPU mode.");

    refreshStatus();
}
