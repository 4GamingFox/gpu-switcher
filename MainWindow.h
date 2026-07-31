#pragma once

#include <QMainWindow>
#include <QWidget>

class QLabel;
class QPushButton;
class QRadioButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QLabel* modeLabel;
    QLabel* statusLabel;

    QRadioButton* integrated;
    QRadioButton* hybrid;
    QRadioButton* ultimate;

    QPushButton* applyButton;

    void refreshStatus();

private slots:
    void applyClicked();
};
