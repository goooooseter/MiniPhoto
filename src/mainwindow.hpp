#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSlider>
#include "image.hpp"
#include "filtermanager.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openImage();
    void saveImage();
    void applyFilter();

private:
    QLabel* imageLabel;
    QComboBox* filterSelector;
    QSlider* parameterSlider;
    QPushButton* openButton;
    QPushButton* saveButton;
    QPushButton* applyButton;

    Image image;
    FilterManager manager;

    void updateImageDisplay();
};
