#include "mainwindow.hpp"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QImage>
#include <QPixmap>
#include "filters/grayscalefilter.hpp"
#include "filters/blurfilter.hpp"
#include "filters/brightnessfilter.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    imageLabel = new QLabel("No Image", this);
    filterSelector = new QComboBox(this);
    parameterSlider = new QSlider(Qt::Horizontal, this);
    openButton = new QPushButton("Open", this);
    saveButton = new QPushButton("Save", this);
    applyButton = new QPushButton("Apply", this);

    filterSelector->addItem("Grayscale");
    filterSelector->addItem("Blur");
    filterSelector->addItem("Brightness");

    layout->addWidget(openButton);
    layout->addWidget(saveButton);
    layout->addWidget(filterSelector);
    layout->addWidget(parameterSlider);
    layout->addWidget(applyButton);
    layout->addWidget(imageLabel);
    setCentralWidget(central);

    connect(openButton, &QPushButton::clicked, this, &MainWindow::openImage);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(applyButton, &QPushButton::clicked, this, &MainWindow::applyFilter);
}

void MainWindow::openImage() {
    QString path = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg)");
    if (!path.isEmpty() && image.load(path.toStdString())) {
        updateImageDisplay();
    }
}

void MainWindow::saveImage() {
    QString path = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg)");
    if (!path.isEmpty()) {
        image.save(path.toStdString());
    }
}

void MainWindow::applyFilter() {
    manager.clear();
    int index = filterSelector->currentIndex();
    int value = parameterSlider->value();

    switch (index) {
        case 0: manager.addFilter(std::make_unique<GrayscaleFilter>()); break;
        case 1: manager.addFilter(std::make_unique<BlurFilter>(value)); break;
        case 2: manager.addFilter(std::make_unique<BrightnessFilter>(value)); break;
    }
    manager.applyAll(image.getData());
    updateImageDisplay();
}

void MainWindow::updateImageDisplay() {
    cv::Mat rgb;
    cv::cvtColor(image.getData(), rgb, cv::COLOR_BGR2RGB);
    QImage qimg(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
    imageLabel->setPixmap(QPixmap::fromImage(qimg).scaled(400, 400, Qt::KeepAspectRatio));
}
